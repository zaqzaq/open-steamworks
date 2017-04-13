//==========================  Open Steamworks  ================================
//
// This file is part of the Open Steamworks project. All individuals associated
// with this project do not claim ownership of the contents
// 
// The code, comments, and all related files, projects, resources,
// redistributables included with this project are Copyright Valve Corporation.
// Additionally, Valve, the Valve logo, Half-Life, the Half-Life logo, the
// Lambda logo, Steam, the Steam logo, Team Fortress, the Team Fortress logo,
// Opposing Force, Day of Defeat, the Day of Defeat logo, Counter-Strike, the
// Counter-Strike logo, Source, the Source logo, and Counter-Strike Condition
// Zero are trademarks and or registered trademarks of Valve Corporation.
// All other trademarks are property of their respective owners.
//
//=============================================================================

#include "Steamworks.h"
#include "Interface_OSW.h"

static CSteamAPILoader ClientLoader;
static CreateInterfaceFn pClientCreateInterface = NULL;
static SteamBGetCallbackFn pSteamBGetCallback = NULL;
static SteamFreeLastCallbackFn pSteamFreeLastCallback = NULL;
static SteamGetAPICallResultFn pSteamGetAPICallResult = NULL;

HSteamPipe __g_hPipe = NULL;
HSteamUser __g_hUser = NULL;

ISteamClient017 *__g_pSteamClient = NULL;
ISteamUtils008 *__g_pSteamUtils = NULL;
ISteamController005 *__g_p_SteamController = NULL;

S_API bool STEAM_CALL OpenAPI_LoadLibrary()
{
	if (ClientLoader.Load())
	{
		pClientCreateInterface = (CreateInterfaceFn)ClientLoader.GetSteamClientModule()->GetSymbol("CreateInterface");
		if (!pClientCreateInterface)
			return false;

		pSteamBGetCallback = (SteamBGetCallbackFn)ClientLoader.GetSteamClientModule()->GetSymbol("Steam_BGetCallback");
		if (!pSteamBGetCallback)
			return false;

		pSteamFreeLastCallback = (SteamFreeLastCallbackFn)ClientLoader.GetSteamClientModule()->GetSymbol("Steam_FreeLastCallback");
		if (!pSteamFreeLastCallback)
			return false;

		pSteamGetAPICallResult = (SteamGetAPICallResultFn)ClientLoader.GetSteamClientModule()->GetSymbol("Steam_GetAPICallResult");
		if (!pSteamGetAPICallResult)
			return false;

		return true;
	}

	return false;
}

S_API void* STEAM_CALL OpenAPI_CreateInterface(const char *pName, int *pReturnCode)
{
	return pClientCreateInterface(pName, pReturnCode);
}

S_API bool STEAM_CALL Steam_BGetCallback(HSteamPipe hSteamPipe, CallbackMsg_t *pCallbackMsg)
{
	return pSteamBGetCallback(hSteamPipe, pCallbackMsg);
}

S_API void STEAM_CALL Steam_FreeLastCallback(HSteamPipe hSteamPipe)
{
	pSteamFreeLastCallback(hSteamPipe);
}

S_API bool STEAM_CALL Steam_GetAPICallResult(HSteamPipe hSteamPipe, SteamAPICall_t hSteamAPICall, void* pCallback, int cubCallback, int iCallbackExpected, bool* pbFailed)
{
	return pSteamGetAPICallResult(hSteamPipe, hSteamAPICall, pCallback, cubCallback, iCallbackExpected, pbFailed);
}

S_API bool STEAM_CALL SteamAPI_Init()
{
	if (!OpenAPI_LoadLibrary())
	{
		return false;
	}

	__g_pSteamClient = (ISteamClient017*)OpenAPI_CreateInterface(STEAMCLIENT_INTERFACE_VERSION_017, NULL);
	if (!__g_pSteamClient)
	{
		return false;
	}

	__g_hPipe = __g_pSteamClient->CreateSteamPipe();
	if (!__g_hPipe)
	{
		return false;
	}

	__g_hUser = __g_pSteamClient->ConnectToGlobalUser(__g_hPipe);
	if (!__g_hUser)
	{
		return false;
	}

	__g_pSteamUtils = (ISteamUtils008*)__g_pSteamClient->GetISteamUtils(__g_hPipe, STEAMUTILS_INTERFACE_VERSION_008);
	if (!__g_pSteamUtils)
	{
		return false;
	}

	__g_p_SteamController = (ISteamController005*)__g_pSteamClient->GetISteamController(__g_hUser, __g_hPipe, STEAMCONTROLLER_INTERFACE_VERSION_005);
	if (!__g_p_SteamController)
	{
		return false;
	}

	return true;
}

S_API HSteamPipe STEAM_CALL SteamAPI_GetHSteamPipe()
{
	return __g_hPipe;
}

S_API HSteamUser STEAM_CALL SteamAPI_GetHSteamUser()
{
	return __g_hUser;
}

S_API_UNSAFE ISteamClient017* STEAM_CALL SteamClient()
{
	return __g_pSteamClient;
}


