#define STEAMWORKS_CLIENT_INTERFACES

#include "Steamworks.h"
#include <time.h>
#include <strsafe.h>
//#include <shellapi.h>

class TestClient
{
public:
	TestClient(): m_cbLoggedOn(this, &TestClient::OnLoggedOn),
		m_cbLogOnfailed(this, &TestClient::OnLogOnFailed),
		m_cbAppInstallProgress(this, &TestClient::OnAppInstallProgress),
		m_cbAppBackupStatus(this, &TestClient::OnAppBackupStatus)

	{}

	~TestClient() {}

	bool Init();
	void SetLogOnInfo(const char* username, const char* password, bool save);
	void Connect();
	
	void RunCallbacks();

private:
	IClientEngine* m_pClientEngine;
	IClientUser* m_pClientUser;
	IClientFriends* m_pClientFriends;
	IClientAppManager* m_pClientAppManager;

	HSteamPipe m_hPipe;
	HSteamUser m_hUser;

	STEAM_CALLBACK(TestClient, OnLoggedOn, SteamServersConnected_t, m_cbLoggedOn);
	STEAM_CALLBACK(TestClient, OnLogOnFailed, SteamServerConnectFailure_t, m_cbLogOnfailed);

	STEAM_CALLBACK_MANUAL(TestClient, OnLoggedOnManual, SteamServersConnected_t, m_cbLoggedOn2);

	STEAM_CALLBACK(TestClient, OnAppInstallProgress, AppInfoUpdateProgress_t, m_cbAppInstallProgress);
	STEAM_CALLBACK(TestClient, OnAppBackupStatus, AppBackupStatus_t, m_cbAppBackupStatus);

};

bool TestClient::Init()
{

	//SetEnvironmentVariableA("SteamAppId", "1097150");
	//SetEnvironmentVariableA("SteamGameId", "1097150");

	m_pClientEngine = (IClientEngine*)SteamInternal_CreateInterface(CLIENTENGINE_INTERFACE_VERSION);
	if (!m_pClientEngine)
	{
		fprintf(stderr, "Unable to get the client engine.\n");
		return false;
	}

	//m_hUser = m_pClientEngine->CreateLocalUser(&m_hPipe, k_EAccountTypeIndividual);
	m_hUser = m_pClientEngine->CreateGlobalUser(&m_hPipe);

	if (!m_hUser || !m_hPipe)
	{
		fprintf(stderr, "Unable to create the global user.\n");
		return false;
	}
	//m_pClientEngine->CreatePipeToLocalUser(m_hUser, &m_hPipe);

	m_pClientUser = (IClientUser*)m_pClientEngine->GetIClientUser(m_hUser, m_hPipe);
	if (!m_pClientUser)
	{
		fprintf(stderr, "Unable to get the client user interface.\n");
		return false;
	}

    m_pClientFriends = (IClientFriends*)m_pClientEngine->GetIClientFriends(m_hUser, m_hPipe);
	if (!m_pClientFriends)
	{
		fprintf(stderr, "Unable to get the client friends interface.\n");
		return false;
	}
	m_pClientAppManager = (IClientAppManager*)m_pClientEngine->GetIClientAppManager(m_hUser, m_hPipe);
	if (!m_pClientAppManager)
	{
		fprintf(stderr, "Unable to get the client appManager interface.\n");
		return false;
	}

	//m_pClientEngine->RunFrame();
	//m_pClientEngine->GetIClientApps(m_hUser, m_hPipe);

	return true;
}

void TestClient::Connect()
{
	CSteamID steamID = m_pClientUser->GetSteamID();
	m_pClientUser->LogOn(steamID);
}

void TestClient::RunCallbacks()
{
	Steam_RunCallbacks(m_hPipe, false);
}

void TestClient::SetLogOnInfo(const char * username, const char * password, bool save)
{
	m_pClientUser->SetLoginInformation(username, password, save);
}

void TestClient::OnLoggedOn(SteamServersConnected_t* cbMsg)
{
	printf("TestClient::OnLoggedOn Logged in\n");
	m_cbLoggedOn2.Register(this, &TestClient::OnLoggedOnManual);
	//CHAR szBuf[MAX_PATH];
	//StringCchPrintfA(szBuf, MAX_PATH, "steam://rungameid/%s", "1097150");
	//ShellExecuteA(NULL, "open", szBuf, NULL, NULL, SW_SHOW);
	//printf("TestClient::start Fall Guys\n");

}

void TestClient::OnAppBackupStatus(AppBackupStatus_t* cbMsg) {

	printf("APP:%d retult:%d,Install Progress :%d %d %d %d  \n",cbMsg->m_nAppID, cbMsg->m_eResult, cbMsg->m_unBytesFailed, cbMsg->m_unBytesProcessed, cbMsg->m_unBytesToProcess, cbMsg->m_unTotalBytesWritten);

}

void TestClient::OnAppInstallProgress(AppInfoUpdateProgress_t* cbMsg) {

	printf("Install Progress :%d %d %d %d  \n", cbMsg->m_cAppsRequested, cbMsg->m_cPackagesRequested, cbMsg->m_cAppsUpdated, cbMsg->m_cPackagesUpdated);

}

void TestClient::OnLoggedOnManual(SteamServersConnected_t* cbMsg)
{
	printf("TestClient::OnLoggedOnManual Logged in\n");
	m_pClientFriends->SetPersonaState(k_EPersonaStateOnline);
	
	printf("start call install APP:%d  \n", 730);
	EAppUpdateError appUpdateError = m_pClientAppManager->InstallApp(730,1,true);
	printf("end call install APP:%d res:%d \n", 730, appUpdateError);

	//uint32  downloadingAppID=m_pClientAppManager->GetDownloadingAppID();
	//printf("downloading App ID:%d \n", downloadingAppID);

	/*
	AppUpdateInfo_s pAppUpdateInfo_s;
	while (true) {
		m_pClientAppManager->GetUpdateInfo(730, &pAppUpdateInfo_s);

		printf("TestClient::GetUpdateInfo %I64d  %I64d   %I64d  %I64d %I64d   %lld \n", pAppUpdateInfo_s.m_unBytesDownloaded, pAppUpdateInfo_s.m_unBytesToDownload,  pAppUpdateInfo_s.m_unBytesProcessed,  pAppUpdateInfo_s.m_unBytesToProcess,  pAppUpdateInfo_s.m_timeUpdateStart,pAppUpdateInfo_s.m_unEstimatedSecondsRemaining);
		Sleep(5000);

	}

	DownloadStats_s pDownloadStats;
	m_pClientAppManager->GetDownloadStats(&pDownloadStats);
	while (true) {
		int downKbps = m_pClientAppManager->GetDownloadThrottleRateKbps(true);
		m_pClientAppManager->GetDownloadStats(&pDownloadStats);
		printf("TestClient::GetDownloadStats %I64d  %I64d   %I64d  %I64d kbps\n", pDownloadStats.m_unTotalBytesDownload, pDownloadStats.m_unBandwidthUsage, pDownloadStats.m_unCurrentConnections,downKbps);

		Sleep(1000);
	}
	

	//DWORD ProcessID = GetCurrentProcessId();
	/*
	int32 appId = 730;
	CGameID* gameID = new CGameID(appId);
	appUpdateError = m_pClientAppManager->LaunchApp(*gameID, 1, 0, "");
	delete(gameID);

	if (appUpdateError == k_EAppUpdateErrorNoError) {
		printf("start APP:%d Success \n", appId);
	}
	else {
		printf("appUpdateError:%d \n", appUpdateError);
	}*/


	/*int32 appId = 1097150;
	CGameID* gameID = new CGameID(appId);
	appUpdateError = m_pClientAppManager->LaunchApp(*gameID,1, 0,"");
	delete(gameID);

	printf("TestClient::start Fall Guys\n");
	if (appUpdateError== k_EAppUpdateErrorNoError) {
		printf("start APP:%d Success \n", appId);
	}
	else {
		printf("appUpdateError:%d \n", appUpdateError);
	}*/
}

void TestClient::OnLogOnFailed(SteamServerConnectFailure_t* cbMsg)
{
	switch (cbMsg->m_eResult)
	{
		case k_EResultAccountLogonDenied:
			{
				printf("Steam guard code required: ");
				char szAuthCode[8] = "";
				if (fgets(szAuthCode, sizeof(szAuthCode), stdin))
				{
					szAuthCode[strlen(szAuthCode) - 1] = 0;
				}

				m_pClientUser->Set2ndFactorAuthCode(szAuthCode, true);
				Connect();
			}
			break;
		case k_EResultAccountLoginDeniedNeedTwoFactor:
			{
				printf("Steam 2FA code required: ");
				char sz2FACode[8] = "";
				if (fgets(sz2FACode, sizeof(sz2FACode), stdin))
				{
					sz2FACode[strlen(sz2FACode) - 1] = 0;
				}

				m_pClientUser->SetTwoFactorCode(sz2FACode);
				Connect();
			}
			break;
		default:
			printf("Log on failed with EResult %d\n", cbMsg->m_eResult);
	}
}

int main()
{
	if ( !OpenAPI_LoadLibrary())
	{
		fprintf(stderr, "Unable to load steamclient library.\n");
		return 1;
	}

	char szUsername[128] = "parmlf3017";
	char szPassword[128] = "gf2A3L8Ye2Jl";

	/*
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
*/
	TestClient testClient;
	if(!testClient.Init()) 
	{
		fprintf(stderr, "Could not initialize steamclient\n");
		return 1;
	}

	testClient.SetLogOnInfo(szUsername, szPassword, false);
	testClient.Connect();
		
	while ( true )
	{
		testClient.RunCallbacks();

#ifdef _WIN32
		Sleep(100);
#else
		usleep(100000);
#endif
	}

	return 0;
}
