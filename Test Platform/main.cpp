#define STEAMWORKS_CLIENT_INTERFACES

#include "Steamworks.h"
#include <time.h>

#ifdef _WIN32
	#ifndef _WIN64
		#pragma comment( lib, "../OpenSteamAPI/lib/Win32/OpenSteamAPI.lib" )
	#else
		#pragma comment( lib, "../OpenSteamAPI/lib/Win64/OpenSteamAPI64.lib" )
	#endif
#endif

int main()
{
	if ( !OpenAPI_LoadLibrary())
	{
		fprintf(stderr, "Unable to load steamclient factory.\n");
		return 1;
	}

	IClientEngine *pClientEngine = (IClientEngine *)OpenAPI_CreateInterface( CLIENTENGINE_INTERFACE_VERSION, NULL );
	if ( !pClientEngine )
	{
		fprintf(stderr, "Unable to get the client engine.\n");
		return 1;
	}
	
	HSteamPipe hPipe;
	HSteamUser hUser = pClientEngine->CreateLocalUser(&hPipe, k_EAccountTypeIndividual);
	if ( !hUser || !hPipe )
	{
		fprintf(stderr, "Unable to create the global user.\n");
		return 1;
	}

	IClientUser *pClientUser = (IClientUser *)pClientEngine->GetIClientUser( hUser, hPipe, CLIENTUSER_INTERFACE_VERSION );
	if ( !pClientUser )
	{
		fprintf(stderr, "Unable to get the client user interface.\n");
		pClientEngine->ReleaseUser(hPipe, hUser);
		pClientEngine->BReleaseSteamPipe(hPipe);
		pClientEngine->BShutdownIfAllPipesClosed();
		return 1;
	}
	
	IClientFriends *pClientFriends = (IClientFriends *)pClientEngine->GetIClientFriends( hUser, hPipe, CLIENTFRIENDS_INTERFACE_VERSION );
	if ( !pClientFriends )
	{
		fprintf(stderr, "Unable to get the client friends interface.\n");
		pClientEngine->ReleaseUser(hPipe, hUser);
		pClientEngine->BReleaseSteamPipe(hPipe);
		pClientEngine->BShutdownIfAllPipesClosed();
		return 1;
	}
	
	char szUsername[128] = "";
	char szPassword[128] = "";

	printf("Enter your username: ");
	if(fgets(szUsername, sizeof(szUsername), stdin))
	{
		szUsername[strlen(szUsername) - 1] = 0;
	}
	
	printf("Enter your password: ");
	if(fgets(szPassword, sizeof(szPassword), stdin))
	{
		szPassword[strlen(szPassword) - 1] = 0;
	}

	pClientUser->LogOnWithPassword(false, szUsername, szPassword);

	CallbackMsg_t callBack;
	CSteamID adminID;

	while ( true )
	{
		while ( Steam_BGetCallback( hPipe, &callBack ) )
		{
			switch (callBack.m_iCallback)
			{
			case SteamServersConnected_t::k_iCallback:
				{
					printf("Successfully logged on!\n");

					pClientUser->SetSelfAsPrimaryChatDestination();
					pClientFriends->SetPersonaState( k_EPersonaStateOnline );

					CSteamID friendID;
					for (int i = 0; i < pClientFriends->GetFriendCount(k_EFriendFlagImmediate); i++)
					{
						friendID = pClientFriends->GetFriendByIndex(i, k_EFriendFlagImmediate);

						if(strcmp(pClientFriends->GetFriendPersonaName(friendID), "Didrole") == 0) // Put the persona name of the friend to use as the 'front end' here.
						{
							const char* cszMessage = "I'm logged on!";
							pClientFriends->SendMsgToFriend(friendID, k_EChatEntryTypeChatMsg, cszMessage, strlen(cszMessage));
							adminID = friendID;

							break;
						}
					}
					break;
				}

			case SteamServerConnectFailure_t::k_iCallback:
				{
					SteamServerConnectFailure_t *pConnectFailureInfo = (SteamServerConnectFailure_t *)callBack.m_pubParam;

					if(pConnectFailureInfo->m_eResult == k_EResultAccountLogonDenied)
					{
						printf("Steam guard code required: ");
						char szAuthCode[8] = "";

						if(fgets(szAuthCode, sizeof(szAuthCode), stdin))
						{
							szAuthCode[strlen(szAuthCode) - 1] = 0;
						}

						pClientUser->Set2ndFactorAuthCode(szAuthCode, true);
						pClientUser->LogOnWithPassword(false, szUsername, szPassword);
					}
					else if (pConnectFailureInfo->m_eResult == k_EResultAccountLoginDeniedNeedTwoFactor)
					{
						printf("Steam 2FA code required: ");
						char sz2FACode[8] = "";

						if (fgets(sz2FACode, sizeof(sz2FACode), stdin))
						{
							sz2FACode[strlen(sz2FACode) - 1] = 0;
						}

						pClientUser->SetTwoFactorCode(sz2FACode);
						pClientUser->LogOnWithPassword(false, szUsername, szPassword);
					}
					else
					{
						fprintf(stderr, "Logon failed with eResult %u !\n", pConnectFailureInfo->m_eResult);

						pClientEngine->ReleaseUser(hPipe, hUser);
						pClientEngine->BReleaseSteamPipe(hPipe);
						pClientEngine->BShutdownIfAllPipesClosed();

						return 1;
					}
				}

			case FriendChatMsg_t::k_iCallback:
				{
					FriendChatMsg_t *pFriendMessageInfo = (FriendChatMsg_t *)callBack.m_pubParam;

					if(pFriendMessageInfo->m_ulSenderID != pClientUser->GetSteamID())
					{
						EChatEntryType eMsgType;
						CSteamID chatter;
						RTime32 uMsgTime;
						char szData[k_cchFriendChatMsgMax];  
						memset(szData, 0, k_cchFriendChatMsgMax);  

						int iLength = pClientFriends->GetChatMessage(pFriendMessageInfo->m_ulFriendID, pFriendMessageInfo->m_iChatID, szData, sizeof(szData), &eMsgType, &chatter, &uMsgTime);  

						if (eMsgType == k_EChatEntryTypeChatMsg || eMsgType == k_EChatEntryTypeEmote)  
						{
							time_t uTime = uMsgTime;
							tm *pTM = localtime(&uTime);
							char szTime[20];
							strftime(szTime, sizeof(szTime), "%X", pTM);

							printf("[%s] %s: %s\n", szTime, pFriendMessageInfo->m_ulSenderID.Render(), szData);
							
							if (strcmp(szData, "quit") == 0 && pFriendMessageInfo->m_ulSenderID == adminID)
							{
								pClientFriends->SetPersonaState( k_EPersonaStateOffline );
								pClientUser->LogOff();

								while(pClientUser->GetLogonState() == k_ELogonStateLoggingOff)
								{
									#ifdef _WIN32
											Sleep(100);
									#else
											usleep(100000);
									#endif
								}

								pClientEngine->ReleaseUser(hPipe, hUser);
								pClientEngine->BReleaseSteamPipe(hPipe);
								pClientEngine->BShutdownIfAllPipesClosed();

								return 0;
							}

							pClientFriends->SendMsgToFriend(pFriendMessageInfo->m_ulFriendID, eMsgType, szData, iLength);
						}
					}
					break;
				}
			}

			Steam_FreeLastCallback( hPipe );
		}

#ifdef _WIN32
		Sleep(100);
#else
		usleep(100000);
#endif
	}

	return 0;
}
