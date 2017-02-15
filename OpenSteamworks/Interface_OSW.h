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

#if !defined(INTERFACEOSW_H) && !defined(_S4N_)
#define INTERFACEOSW_H
#ifdef _WIN32
#pragma once
#endif


#ifdef _WIN32
	#include "Win32Library.h"
	static const int k_iPathMaxSize = MAX_PATH;

	#ifdef _WIN64
		static const char* k_cszSteam3LibraryName = "steamclient64.dll";
	#else
		static const char* k_cszSteam3LibraryName = "steamclient.dll";
	#endif
#elif defined(__APPLE_CC__)
	#include "POSIXLibrary.h"
	#include <sys/param.h>
	#include "OSXPathHelper.h"

	static const int k_iPathMaxSize = MAXPATHLEN;
	static const char* k_cszSteam3LibraryName = "steamclient.dylib";
#elif defined(__linux__)
	#include "POSIXLibrary.h"
	#include <limits.h>
	#include <sys/param.h>
	#include <sys/types.h>
	#include <sys/stat.h>
	#include <pwd.h>

	static const int k_iPathMaxSize = PATH_MAX;
	static const char* k_cszSteam3LibraryName = "steamclient.so";
#else
	#error Unsupported platform
#endif


class CSteamAPILoader
{
public:
	enum ESearchOrder
	{
		k_ESearchOrderLocalFirst,
		k_ESearchOrderSteamInstallFirst,
	};

	CSteamAPILoader(ESearchOrder eSearchOrder = k_ESearchOrderLocalFirst);

	~CSteamAPILoader();

	bool Load();

	CreateInterfaceFn GetSteam3Factory();

	const char* GetSteamDir();

	const DynamicLibrary *GetSteamClientModule();

private:

	void TryGetSteamDir();

	void TryLoadLibraries();
	
	char m_szSteamPath[k_iPathMaxSize];

	DynamicLibrary* m_pSteamclient;

	ESearchOrder m_eSearchOrder;
};

#endif // INTERFACEOSW_H
