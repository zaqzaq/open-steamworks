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

#include <map>
#include "Steamworks.h"

// whole thing looks more like an ugly stub atm
// if you know a better way to do it please let me know...

std::multimap<int, CCallbackBase*> g_ManagedCallbacks;

S_API void SteamAPI_RegisterCallback(class CCallbackBase *pCallback, int iCallback)
{
	g_ManagedCallbacks.insert(std::pair<int, CCallbackBase*>(iCallback, pCallback));
}

S_API void SteamAPI_UnregisterCallback(class CCallbackBase *pCallback)
{
	for (auto& it = g_ManagedCallbacks.begin();
		it != g_ManagedCallbacks.end();
		)
	{
		if (it->second == pCallback)
		{
			g_ManagedCallbacks.erase(it++);
		}
		else
		{
			++it;
		}
	}
}

S_API void Steam_RunCallbacks(HSteamPipe hSteamPipe, bool bGameServerCallbacks)
{
	if (!hSteamPipe)
	{
		return;
	}

	CallbackMsg_t msg;
	while (Steam_BGetCallback(hSteamPipe, &msg))
	{
		auto range = g_ManagedCallbacks.equal_range(msg.m_iCallback);
		for (auto& it = range.first;
			it != range.second;
			++it
			)
		{
			it->second->Run(msg.m_pubParam);
		}
		Steam_FreeLastCallback(hSteamPipe);
	}
}
