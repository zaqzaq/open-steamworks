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
#include "CCallbackMgr.h"

CSteamAPILoader g_ClientLoader;

CreateInterfaceFn g_pClientCreateInterface = NULL;
SteamBGetCallbackFn g_pSteamBGetCallback = NULL;
SteamFreeLastCallbackFn g_pSteamFreeLastCallback = NULL;
SteamGetAPICallResultFn g_pSteamGetAPICallResult = NULL;
SteamReleaseThreadLocalMemoryFn g_pSteamReleaseThreadLocalMemory = NULL;


bool LoadClientLibrary()
{
	if (g_ClientLoader.Load())
	{
		g_pClientCreateInterface = (CreateInterfaceFn)g_ClientLoader.GetSteamClientModule()->GetSymbol("CreateInterface");
		if (!g_pClientCreateInterface)
			return false;

		g_pSteamBGetCallback = (SteamBGetCallbackFn)g_ClientLoader.GetSteamClientModule()->GetSymbol("Steam_BGetCallback");
		if (!g_pSteamBGetCallback)
			return false;

		g_pSteamFreeLastCallback = (SteamFreeLastCallbackFn)g_ClientLoader.GetSteamClientModule()->GetSymbol("Steam_FreeLastCallback");
		if (!g_pSteamFreeLastCallback)
			return false;

		g_pSteamGetAPICallResult = (SteamGetAPICallResultFn)g_ClientLoader.GetSteamClientModule()->GetSymbol("Steam_GetAPICallResult");
		if (!g_pSteamGetAPICallResult)
			return false;

		g_pSteamReleaseThreadLocalMemory = (SteamReleaseThreadLocalMemoryFn)g_ClientLoader.GetSteamClientModule()->GetSymbol("Steam_ReleaseThreadLocalMemory");

		return true;
	}

	return false;
}

S_API bool STEAM_CALL OpenAPI_LoadLibrary()
{
	if (LoadClientLibrary())
	{
		GCallbackMgr().Init();
		return true;
	}

	return false;
}

S_API void STEAM_CALL SteamAPI_RegisterCallback(CCallbackBase *pCallback, int iCallback)
{
	GCallbackMgr().RegisterCallback(pCallback, iCallback);
}

S_API void STEAM_CALL SteamAPI_UnregisterCallback(CCallbackBase *pCallback)
{
	GCallbackMgr().UnregisterCallback(pCallback);
}

S_API void STEAM_CALL SteamAPI_RegisterCallResult(CCallbackBase *pCallback, SteamAPICall_t hAPICall)
{
	GCallbackMgr().RegisterCallResult(pCallback, hAPICall);
}

S_API void STEAM_CALL SteamAPI_UnregisterCallResult(CCallbackBase *pCallback, SteamAPICall_t hAPICall)
{
	GCallbackMgr().UnregisterCallResult(pCallback, hAPICall);
}

S_API void* STEAM_CALL SteamInternal_CreateInterface(const char *pName)
{
	return g_pClientCreateInterface(pName, NULL);
}

S_API bool STEAM_CALL Steam_BGetCallback(HSteamPipe hSteamPipe, CallbackMsg_t *pCallbackMsg)
{
	return g_pSteamBGetCallback(hSteamPipe, pCallbackMsg);
}

S_API void STEAM_CALL Steam_FreeLastCallback(HSteamPipe hSteamPipe)
{
	g_pSteamFreeLastCallback(hSteamPipe);
}

S_API bool STEAM_CALL Steam_GetAPICallResult(HSteamPipe hSteamPipe, SteamAPICall_t hSteamAPICall, void* pCallback, int cubCallback, int iCallbackExpected, bool* pbFailed)
{
	return g_pSteamGetAPICallResult(hSteamPipe, hSteamAPICall, pCallback, cubCallback, iCallbackExpected, pbFailed);
}

S_API void STEAM_CALL Steam_RunCallbacks(HSteamPipe hPipe, bool bGameServer)
{
	GCallbackMgr().RunCallbacks(hPipe, bGameServer);
}

S_API void STEAM_CALL Steam_ReleaseThreadLocalMemory(bool smth)
{
	if (g_pSteamReleaseThreadLocalMemory != NULL)
	{
		g_pSteamReleaseThreadLocalMemory(smth);
	}
}