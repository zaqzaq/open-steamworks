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

#ifndef SHAREDCONNECTIONCOMMON_H
#define SHAREDCONNECTIONCOMMON_H
#ifdef _WIN32
#pragma once
#endif

#define CLIENTSHAREDCONNECTION_INTERFACE_VERSION "CLIENTSHAREDCONNECTION_INTERFACE_VERSION001"

typedef uint32 HSharedConnection;

struct SharedConnectionMessageReady_t
{
	enum { k_iCallback = k_iClientSharedConnectionCallbacks + 1 };

	int32 m_hResult;
};

#endif //SHAREDCONNECTIONCOMMON_H
