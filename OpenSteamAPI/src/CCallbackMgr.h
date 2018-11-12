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

#ifndef CCALLBACKMGR_H
#define CCALLBACKMGR_H
#pragma once

#include <atomic>
#include <map>
#include "Steamworks.h"

class CCallbackMgr
{
public:
	CCallbackMgr();
	~CCallbackMgr();

	void Init();

	bool BRunningCallbacks();
	void RunCallbacks(HSteamPipe hPipe, bool bServer);

	void RegisterCallback(CCallbackBase *pCallback, int iCallback);
	void UnregisterCallback(CCallbackBase *pCallback);

	void RegisterCallResult(CCallbackBase *pCallback, SteamAPICall_t hCallResult);
	void UnregisterCallResult(CCallbackBase *pCallResult, SteamAPICall_t hCallResult);

private:
	std::atomic<bool> m_bRunning;
	bool m_bInitialized;

	HSteamPipe m_hCurrentPipe;

	std::multimap<int, CCallbackBase*> m_registeredCallbacks;
	std::multimap<SteamAPICall_t, CCallbackBase*> m_registeredCallResults;

	STEAM_CALLBACK_MANUAL(CCallbackMgr, OnAPICallComplete, SteamAPICallCompleted_t, m_steamApiCallCompleteCb);
};

CCallbackMgr& GCallbackMgr();

#endif // !CCALLBACKMGR_H