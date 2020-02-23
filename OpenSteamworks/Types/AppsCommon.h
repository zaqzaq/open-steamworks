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

#ifndef APPSCOMMON_H
#define APPSCOMMON_H
#ifdef _WIN32
#pragma once
#endif



#define CLIENTAPPS_INTERFACE_VERSION "CLIENTAPPS_INTERFACE_VERSION001"
#define CLIENTAPPMANAGER_INTERFACE_VERSION "CLIENTAPPMANAGER_INTERFACE_VERSION001"

#define CLIENTAPPDISABLEUPDATE_INTERFACE_VERSION "ClientAppDisableUpdate001"

#define STEAMAPPS_INTERFACE_VERSION_001 "STEAMAPPS_INTERFACE_VERSION001"
#define STEAMAPPS_INTERFACE_VERSION_002 "STEAMAPPS_INTERFACE_VERSION002"
#define STEAMAPPS_INTERFACE_VERSION_003 "STEAMAPPS_INTERFACE_VERSION003"
#define STEAMAPPS_INTERFACE_VERSION_004 "STEAMAPPS_INTERFACE_VERSION004"
#define STEAMAPPS_INTERFACE_VERSION_005 "STEAMAPPS_INTERFACE_VERSION005"
#define STEAMAPPS_INTERFACE_VERSION_006 "STEAMAPPS_INTERFACE_VERSION006"
#define STEAMAPPS_INTERFACE_VERSION_007 "STEAMAPPS_INTERFACE_VERSION007"
#define STEAMAPPS_INTERFACE_VERSION_008 "STEAMAPPS_INTERFACE_VERSION008"

#define STEAMAPPLIST_INTERFACE_VERSION_001 "STEAMAPPLIST_INTERFACE_VERSION001"

#define STEAMAPPDISABLEUPDATE_INTERFACE_VERSION_001 "SteamAppDisableUpdate001"

enum EAppState
{
	k_EAppStateInvalid			= 0,
	k_EAppStateUninstalled		= 1 << 0,
	k_EAppStateUpdateRequired	= 1 << 1,
	k_EAppStateFullyInstalled	= 1 << 2,
	k_EAppStateUpdateQueued		= 1 << 3,
	k_EAppStateUpdateOptional	= 1 << 4,
	k_EAppStateFilesMissing		= 1 << 5,
	k_EAppStateSharedOnly		= 1 << 6,
	k_EAppStateFilesCorrupt		= 1 << 7,
	k_EAppStateUpdateRunning	= 1 << 8,
	k_EAppStateUpdatePaused		= 1 << 9,
	k_EAppStateUpdateStarted	= 1 << 10,
	k_EAppStateUninstalling		= 1 << 11,
	k_EAppStateBackupRunning	= 1 << 12,
	k_EAppStateAppRunning		= 1 << 13,
	k_EAppStateComponentInUse	= 1 << 14,
	k_EAppStateMovingFolder		= 1 << 15,
	k_EAppStateUpdateHidden		= 1 << 16,
};

enum EAppUpdateState
{
	k_EAppUpdateStateNone			= 0,
	k_EAppUpdateStateRunning		= 1 << 0,
	k_EAppUpdateStateReconfiguring	= 1 << 1,
	k_EAppUpdateStateValidating		= 1 << 2,
	k_EAppUpdateStateAddingFiles	= 1 << 3,
	k_EAppUpdateStatePreallocating	= 1 << 4,
	k_EAppUpdateStateDownloading	= 1 << 5,
	k_EAppUpdateStateStaging		= 1 << 6,
	k_EAppUpdateStateVerifying		= 1 << 7,
	k_EAppUpdateStateCommitting		= 1 << 8,
	k_EAppUpdateStateStopping		= 1 << 9,
};

enum EAppEvent
{
	k_EAppEventDownloadComplete = 2,
};

enum EAppInfoSection
{
	k_EAppInfoSectionUnknown = 0,
	k_EAppInfoSectionAll,
	k_EAppInfoSectionCommon,
	k_EAppInfoSectionExtended,
	k_EAppInfoSectionConfig,
	k_EAppInfoSectionStats,
	k_EAppInfoSectionInstall,
	k_EAppInfoSectionDepots,
	k_EAppInfoSectionVac,
	k_EAppInfoSectionDrm,
	k_EAppInfoSectionUfs,
	k_EAppInfoSectionOgg,
	k_EAppInfoSectionItems,
	k_EAppInfoSectionPolicies,
	k_EAppInfoSectionSysreqs,
	k_EAppInfoSectionCommunity,
	k_EAppInfoSectionStore,
	k_EAppInfoSectionLocalization,
	k_EAppInfoSectionBroadcastgamedata,
	k_EAppInfoSectionComputed,
	k_EAppInfoSectionAlbummetadata,
};

enum EAppType
{
	k_EAppTypeInvalid		= 0,
	k_EAppTypeGame			= 1 << 0,
	k_EAppTypeApplication	= 1 << 1,
	k_EAppTypeTool			= 1 << 2,
	k_EAppTypeDemo			= 1	<< 3,
	k_EAppTypeMedia			= 1 << 4,
	k_EAppTypeDlc			= 1 << 5,
	k_EAppTypeGuide			= 1 << 6,
	k_EAppTypeDriver		= 1 << 7,
	k_EAppTypeConfig		= 1 << 8,
	k_EAppTypeHardware		= 1 << 9,
	k_EAppTypeFranchise		= 1 << 10,
	k_EAppTypeVideo			= 1 << 11,
	k_EAppTypePlugin		= 1 << 12,
	k_EAppTypeMusic			= 1 << 13,
	k_EAppTypeSeries		= 1 << 14,
	k_EAppTypeComic			= 1 << 15,
	k_EAppTypeBeta			= 1 << 16,
	k_EAppTypeShortcut		= 1 << 30,
	k_EAppTypeDepotonly		= 1 << 31,
};

#pragma pack( push, 1 )
struct AppUpdateInfo_s
{
	RTime32 m_timeUpdateStart;
	uint32 m_uUnk1; // Update state?
	uint64 m_unBytesToDownload;
	uint64 m_unBytesDownloaded;
	uint64 m_unBytesToProcess;
	uint64 m_unBytesProcessed;
	int32 m_unEstimatedSecondsRemaining;
	char m_cUnk[12];
};
#pragma pack( pop )

struct DownloadStats_s
{
	uint32 m_unCurrentConnections;
	uint32 m_unBandwidthUsage;
	uint64 m_unTotalBytesDownload;
};

enum EAppDownloadPriority
{
	k_EAppDownloadPriorityNone = 0,
	k_EAppDownloadPriorityFirst = 1,
	k_EAppDownloadPriorityUp = 2,
	k_EAppDownloadPriorityDown = 3,
	k_EAppDownloadPriorityLast = 4,
	k_EAppDownloadPriorityPaused = 5,
};

enum EAppUpdateError
{
	k_EAppUpdateErrorNoError, // No Error
	k_EAppUpdateErrorUnspecifiedError, // Unspecified Error
	k_EAppUpdateErrorPaused, // Paused
	k_EAppUpdateErrorCanceled, // Canceled
	k_EAppUpdateErrorSuspended, // Suspended
	k_EAppUpdateErrorNoSubscription, // No subscription
	k_EAppUpdateErrorNoConnection, // No connection
	k_EAppUpdateErrorConnectionTimeout, // Connection timeout
	k_EAppUpdateErrorMissingDecryptionKey, // Missing decryption key
	k_EAppUpdateErrorMissingConfiguration, // Missing configuration
	k_EAppUpdateErrorDiskReadFailure, // Disk read failure
	k_EAppUpdateErrorDiskWriteFailure, // Disk write failure
	k_EAppUpdateErrorNotEnoughDiskSpace, // Not enough disk space
	k_EAppUpdateErrorCorruptGameFiles, // Corrupt game files
	k_EAppUpdateErrorWaitingForDisk, // Waiting for disk
	k_EAppUpdateErrorInvalidInstallPath, // Invalid install path
	k_EAppUpdateErrorApplicationRunning, // Application running
	k_EAppUpdateErrorDependencyFailure, // Dependency failure
	k_EAppUpdateErrorNotInstalled, // Not installed
	k_EAppUpdateErrorUpdateRequired, // Update required
	k_EAppUpdateErrorStillBusy, // Still busy
	k_EAppUpdateErrorNoConnectionToContentServers, // No connection to content servers
	k_EAppUpdateErrorInvalidApplicationConfiguration, // Invalid application configuration
	k_EAppUpdateErrorInvalidContentConfiguration, // Invalid content configuration
	k_EAppUpdateErrorManifestUnavailable, // Manifest unavailable
	k_EAppUpdateErrorNotReleased, // Not released
	k_EAppUpdateErrorRegionRestricted, // Region restricted
	k_EAppUpdateErrorCorruptDepotCache, // Corrupt depot cache
	k_EAppUpdateErrorMissingExecutable, // Missing executable
	k_EAppUpdateErrorInvalidPlatform, // Invalid platform
	k_EAppUpdateErrorInvalidFileSystem, // Invalid file system
	k_EAppUpdateErrorCorruptUpdateFiles, // Corrupt update files
	k_EAppUpdateErrorDownloadDisabled, // Download disabled
	k_EAppUpdateErrorSharedLibraryLocked, // Shared library locked
	k_EAppUpdateErrorPurchasePending, // Purchase pending
	k_EAppUpdateErrorOtherSessionPlaying, // Other session playing
	k_EAppUpdateErrorCorruptDownload, // Corrupt download
	k_EAppUpdateErrorCorruptDisk, // Corrupt disk
	k_EAppUpdateErrorMissingFilePermissions, // Missing file permissions
	k_EAppUpdateErrorFileLocked, // File locked
	k_EAppUpdateErrorContentUnavailable, // Content unavailable
	k_EAppUpdateErrorRequires64bitOperatingSystem, // Requires 64bit operating system
	k_EAppUpdateErrorMissingUpdateFiles, // Missing update files
	k_EAppUpdateErrorNotEnoughDiskQuota, // Not enough disk quota
	k_EAppUpdateErrorSiteLicenseLocked, // Site License locked
	k_EAppUpdateErrorParentalControlBlocked, // Parental control blocked
	k_EAppUpdateErrorCreateProcessFailed, // Create process failed
	k_EAppUpdateErrorSteamClientOutOfDate, // Steam client out of date
	k_EAppUpdateErrorAllowedPlaytimeExceeded, // Allowed playtime exceeded
	k_EAppUpdateErrorSteamClientFilesCorrupt, // Steam client files corrupt
};

//-----------------------------------------------------------------------------
// Purpose: possible results when registering an activation code
//-----------------------------------------------------------------------------
enum ERegisterActivactionCodeResult
{
	k_ERegisterActivactionCodeResultOK = 0,
	k_ERegisterActivactionCodeResultFail = 1,
	k_ERegisterActivactionCodeResultAlreadyRegistered = 2,
	k_ERegisterActivactionCodeResultTimeout = 3,
	k_ERegisterActivactionCodeAlreadyOwned = 4
};

enum EAppOwnershipFlags
{
	k_EAppOwnershipFlagsNone				= 0,
	k_EAppOwnershipFlagsOwnsLicense			= 1 << 0,
	k_EAppOwnershipFlagsFreeLicense			= 1 << 1,
	k_EAppOwnershipFlagsRegionRestricted	= 1 << 2,
	k_EAppOwnershipFlagsLowViolence			= 1 << 3,
	k_EAppOwnershipFlagsInvalidPlatform		= 1 << 4,
	k_EAppOwnershipFlagsSharedLicense		= 1 << 5,
	k_EAppOwnershipFlagsFreeWeekend			= 1 << 6,
	k_EAppOwnershipFlagsRetail				= 1 << 7,
	k_EAppOwnershipFlagsLockedLicense		= 1 << 8,
	k_EAppOwnershipFlagsPending				= 1 << 9,
	k_EAppOwnershipFlagsExpired				= 1 << 10,
	k_EAppOwnershipFlagsPermanent			= 1 << 11,
	k_EAppOwnershipFlagsRecurring			= 1 << 12,
	k_EAppOwnershipFlagsCanceled			= 1 << 13,
	k_EAppOwnershipFlagsAutoGrant			= 1 << 14,
	k_EAppOwnershipFlagsPendingGift			= 1 << 15,
	k_EAppOwnershipFlagsRentalnotActivated	= 1 << 16,
	k_EAppOwnershipFlagsRental				= 1 << 17,
	k_EAppOwnershipFlagsSiteLicense			= 1 << 18,
	k_EAppOwnershipFlagsLegacyFreeSub		= 1 << 19,
	k_EAppOwnershipFlagsInvalidOSType		= 1 << 20,
};

enum EAppReleaseState
{
	k_EAppReleaseStateUnknown = 0,
	k_EAppReleaseStateUnavailable,
	k_EAppReleaseStatePrerelease,
	k_EAppReleaseStatePreloadonly,
	k_EAppReleaseStateReleased,
};

enum EAppAutoUpdateBehavior
{
	k_EAppAutoUpdateBehaviorDefault = 0,
	k_EAppAutoUpdateBehaviorDisabled,
	k_EAppAutoUpdateBehaviorHighPriority,
};

enum EAppAllowDownloadsWhileRunningBehavior
{
	// TODO: Reverse this enum
};

enum EAppDownloadQueuePlacement
{
	k_EAppDownloadQueuePlacementNone = 0,
	k_EAppDownloadQueuePlacementFirst,
	k_EAppDownloadQueuePlacementUserInitiated,
	k_EAppDownloadQueuePlacementUp,
	k_EAppDownloadQueuePlacementDown,
	k_EAppDownloadQueuePlacementLast,
	k_EAppDownloadQueuePlacementPaused,
};

enum ELanguage
{
	// TODO: Reverse this enum
};

struct SHADigestWrapper_t
{
	uint32 A;
	uint32 B;
	uint32 C;
	uint32 D;
	uint32 E;
};

const int k_cubAppProofOfPurchaseKeyMax = 64;			// max bytes of a legacy cd key we support

#pragma pack( push, 8 )
//-----------------------------------------------------------------------------
// Purpose: called when new information about an app has arrived
//-----------------------------------------------------------------------------
struct AppInfoChanged_t
{
	enum { k_iCallback = k_iSteamAppsCallbacks + 1 };

	AppId_t m_nAppID;
};

struct RequestAppCallbacksComplete_t
{
	enum { k_iCallback = k_iSteamAppsCallbacks + 2 };
};

struct AppInfoUpdateComplete_t
{
	enum { k_iCallback = k_iSteamAppsCallbacks + 3 };

	EResult m_EResult;
	uint32 m_cAppsUpdated;
	uint32 m_cPackagesUpdated;
};

struct AppEventTriggered_t
{
	enum { k_iCallback = k_iSteamAppsCallbacks + 4 };

	AppId_t m_nAppID;
	EAppEvent m_eAppEvent;
};

//-----------------------------------------------------------------------------
// Purpose: posted after the user gains ownership of DLC & that DLC is installed
//-----------------------------------------------------------------------------
struct DlcInstalled_t
{
	enum { k_iCallback = k_iSteamAppsCallbacks + 5 };

	AppId_t m_nAppID;		// AppID of the DLC
};

struct AppEventStateChange_t
{
	enum { k_iCallback = k_iSteamAppsCallbacks + 6 };

	AppId_t m_nAppID;
	uint32 m_eOldState;
	uint32 m_eNewState;
	EAppUpdateError m_eAppError;
};

struct AppValidationComplete_t
{
	enum { k_iCallback = k_iSteamAppsCallbacks + 7 };

	AppId_t m_nAppID;
	bool m_bFinished;

	uint64 m_TotalBytesValidated;
	uint64 m_TotalBytesFailed;
	uint32 m_TotalFilesValidated;
	uint32 m_TotalFilesFailed;
	uint32 m_TotalFilesFailedCEGFiles;
};

//-----------------------------------------------------------------------------
// Purpose: response to RegisterActivationCode()
//-----------------------------------------------------------------------------
struct RegisterActivationCodeResponse_t
{
	enum { k_iCallback = k_iSteamAppsCallbacks + 8 };

	ERegisterActivactionCodeResult m_eResult;
	uint32 m_unPackageRegistered;						// package that was registered. Only set on success
};

struct DownloadScheduleChanged_t
{
	enum { k_iCallback = k_iSteamAppsCallbacks + 9 };

	bool m_bDownloadEnabled;
	uint32 m_nTotalAppsScheduled;
	unsigned int m_rgunAppSchedule[32];
};

struct AppUpdateStateChange_t
{
	enum { k_iCallback = k_iSteamAppsCallbacks + 10 };

	AppId_t m_nAppID;
	uint32 m_eOldState;
	uint32 m_eNewState;
};

struct AppLaunchTenFootOverlay_t
{
	enum { k_iCallback = k_iSteamAppsCallbacks + 11 };

	CGameID m_GameID;
	uint64 m_nPid;
	bool m_bCanShareSurfaces;
};

struct AppBackupStatus_t
{
	enum { k_iCallback = k_iSteamAppsCallbacks + 12 };

	AppId_t m_nAppID;
	EResult m_eResult;
	
	uint64 m_unBytesToProcess;
	uint64 m_unBytesProcessed;
	uint64 m_unTotalBytesWritten;
	uint64 m_unBytesFailed;
};

struct RequestAppProofOfPurchaseKeyResponse_t
{
	enum { k_iCallback = k_iSteamAppsCallbacks + 13 };

	EResult m_eResult;
	AppId_t m_nAppID;
	char m_rgchKey[ k_cubAppProofOfPurchaseKeyMax ];	
};

struct AppAutoUpdateBehaviorChanged_t
{
	enum { k_iCallback = k_iSteamAppsCallbacks + 16 };

	AppId_t m_nAppID;
	EAppAutoUpdateBehavior m_eNewBehavior;
};

struct AppInfoUpdateProgress_t
{
	enum { k_iCallback = k_iSteamAppsCallbacks + 17 };

	uint32 m_cAppsRequested;
	uint32 m_cAppsUpdated;
	uint32 m_cPackagesRequested;
	uint32 m_cPackagesUpdated;
};

struct AppUpdateStopped_t
{
	enum { k_iCallback = k_iSteamAppsCallbacks + 18 };

	AppId_t m_nAppID;
	AppUpdateInfo_s m_UpdateState;
};

struct AppConfigChanged_t
{
	enum { k_iCallback = k_iSteamAppsCallbacks + 19 };

	AppId_t m_nAppID;
};

struct CheckAppBetaPasswordResponse_t
{
	enum { k_iCallback = k_iSteamAppsCallbacks + 20 };

	AppId_t m_nAppID;
	EResult m_eResult;
	char m_szBetaName[64];
};

struct AppUpdateProgress_t
{
	enum { k_iCallback = k_iSteamAppsCallbacks + 25 };

	AppId_t m_nAppID;
};

struct AppLaunchResult_t
{
	enum { k_iCallback = k_iSteamAppsCallbacks + 27 };

	CGameID m_GameID;
	EAppUpdateError m_eAppError;
	char m_szErrorDetail[512];
};

struct AppStateInfo_s
{
	// reverse me
};

#pragma pack( pop )

#endif // APPSCOMMON_H
