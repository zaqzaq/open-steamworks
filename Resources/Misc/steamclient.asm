; generated

format MS COFF

extrn '_GetModuleHandleA@4' as GetModuleHandleA:dword
extrn '_GetProcAddress@8' as GetProcAddress:dword



section '.text' code readable executable

	public _Breakpad_SteamMiniDumpInit
	public __imp__Breakpad_SteamMiniDumpInit
	public _Breakpad_SteamSetAppID
	public __imp__Breakpad_SteamSetAppID
	public _Breakpad_SteamSetSteamID
	public __imp__Breakpad_SteamSetSteamID
	public _Breakpad_SteamWriteMiniDumpSetComment
	public __imp__Breakpad_SteamWriteMiniDumpSetComment
	public _Breakpad_SteamWriteMiniDumpUsingExceptionInfoWithBuildId
	public __imp__Breakpad_SteamWriteMiniDumpUsingExceptionInfoWithBuildId
	public _CreateInterface
	public __imp__CreateInterface
	public _Steam_BConnected
	public __imp__Steam_BConnected
	public _Steam_BGetCallback
	public __imp__Steam_BGetCallback
	public _Steam_BLoggedOn
	public __imp__Steam_BLoggedOn
	public _Steam_BReleaseSteamPipe
	public __imp__Steam_BReleaseSteamPipe
	public _Steam_ConnectToGlobalUser
	public __imp__Steam_ConnectToGlobalUser
	public _Steam_CreateGlobalUser
	public __imp__Steam_CreateGlobalUser
	public _Steam_CreateLocalUser
	public __imp__Steam_CreateLocalUser
	public _Steam_CreateSteamPipe
	public __imp__Steam_CreateSteamPipe
	public _Steam_FreeLastCallback
	public __imp__Steam_FreeLastCallback
	public _Steam_GSBLoggedOn
	public __imp__Steam_GSBLoggedOn
	public _Steam_GSBSecure
	public __imp__Steam_GSBSecure
	public _Steam_GSGetSteam2GetEncryptionKeyToSendToNewClient
	public __imp__Steam_GSGetSteam2GetEncryptionKeyToSendToNewClient
	public _Steam_GSGetSteamID
	public __imp__Steam_GSGetSteamID
	public _Steam_GSLogOff
	public __imp__Steam_GSLogOff
	public _Steam_GSLogOn
	public __imp__Steam_GSLogOn
	public _Steam_GSRemoveUserConnect
	public __imp__Steam_GSRemoveUserConnect
	public _Steam_GSSendSteam2UserConnect
	public __imp__Steam_GSSendSteam2UserConnect
	public _Steam_GSSendSteam3UserConnect
	public __imp__Steam_GSSendSteam3UserConnect
	public _Steam_GSSendUserDisconnect
	public __imp__Steam_GSSendUserDisconnect
	public _Steam_GSSendUserStatusResponse
	public __imp__Steam_GSSendUserStatusResponse
	public _Steam_GSSetServerType
	public __imp__Steam_GSSetServerType
	public _Steam_GSSetSpawnCount
	public __imp__Steam_GSSetSpawnCount
	public _Steam_GSUpdateStatus
	public __imp__Steam_GSUpdateStatus
	public _Steam_GetAPICallResult
	public __imp__Steam_GetAPICallResult
	public _Steam_GetGSHandle
	public __imp__Steam_GetGSHandle
	public _Steam_InitiateGameConnection
	public __imp__Steam_InitiateGameConnection
	public _Steam_LogOff
	public __imp__Steam_LogOff
	public _Steam_LogOn
	public __imp__Steam_LogOn
	public _Steam_ReleaseThreadLocalMemory
	public __imp__Steam_ReleaseThreadLocalMemory
	public _Steam_ReleaseUser
	public __imp__Steam_ReleaseUser
	public _Steam_SetLocalIPBinding
	public __imp__Steam_SetLocalIPBinding
	public _Steam_TerminateGameConnection
	public __imp__Steam_TerminateGameConnection
	public _hid_close
	public __imp__hid_close
	public _hid_enumerate
	public __imp__hid_enumerate
	public _hid_error
	public __imp__hid_error
	public _hid_exit
	public __imp__hid_exit
	public _hid_free_enumeration
	public __imp__hid_free_enumeration
	public _hid_get_feature_report
	public __imp__hid_get_feature_report
	public _hid_get_indexed_string
	public __imp__hid_get_indexed_string
	public _hid_get_manufacturer_string
	public __imp__hid_get_manufacturer_string
	public _hid_get_product_string
	public __imp__hid_get_product_string
	public _hid_get_serial_number_string
	public __imp__hid_get_serial_number_string
	public _hid_init
	public __imp__hid_init
	public _hid_open
	public __imp__hid_open
	public _hid_open_path
	public __imp__hid_open_path
	public _hid_read
	public __imp__hid_read
	public _hid_read_timeout
	public __imp__hid_read_timeout
	public _hid_send_feature_report
	public __imp__hid_send_feature_report
	public _hid_set_nonblocking
	public __imp__hid_set_nonblocking
	public _hid_write
	public __imp__hid_write


	_Breakpad_SteamMiniDumpInit:
		push	clientDll
		call	GetModuleHandleA
		push	Breakpad_SteamMiniDumpInit
		push	eax
		call	GetProcAddress
		mov	[__imp__Breakpad_SteamMiniDumpInit], eax
		jmp	eax

	_Breakpad_SteamSetAppID:
		push	clientDll
		call	GetModuleHandleA
		push	Breakpad_SteamSetAppID
		push	eax
		call	GetProcAddress
		mov	[__imp__Breakpad_SteamSetAppID], eax
		jmp	eax

	_Breakpad_SteamSetSteamID:
		push	clientDll
		call	GetModuleHandleA
		push	Breakpad_SteamSetSteamID
		push	eax
		call	GetProcAddress
		mov	[__imp__Breakpad_SteamSetSteamID], eax
		jmp	eax

	_Breakpad_SteamWriteMiniDumpSetComment:
		push	clientDll
		call	GetModuleHandleA
		push	Breakpad_SteamWriteMiniDumpSetComment
		push	eax
		call	GetProcAddress
		mov	[__imp__Breakpad_SteamWriteMiniDumpSetComment], eax
		jmp	eax

	_Breakpad_SteamWriteMiniDumpUsingExceptionInfoWithBuildId:
		push	clientDll
		call	GetModuleHandleA
		push	Breakpad_SteamWriteMiniDumpUsingExceptionInfoWithBuildId
		push	eax
		call	GetProcAddress
		mov	[__imp__Breakpad_SteamWriteMiniDumpUsingExceptionInfoWithBuildId], eax
		jmp	eax

	_CreateInterface:
		push	clientDll
		call	GetModuleHandleA
		push	CreateInterface
		push	eax
		call	GetProcAddress
		mov	[__imp__CreateInterface], eax
		jmp	eax

	_Steam_BConnected:
		push	clientDll
		call	GetModuleHandleA
		push	Steam_BConnected
		push	eax
		call	GetProcAddress
		mov	[__imp__Steam_BConnected], eax
		jmp	eax

	_Steam_BGetCallback:
		push	clientDll
		call	GetModuleHandleA
		push	Steam_BGetCallback
		push	eax
		call	GetProcAddress
		mov	[__imp__Steam_BGetCallback], eax
		jmp	eax

	_Steam_BLoggedOn:
		push	clientDll
		call	GetModuleHandleA
		push	Steam_BLoggedOn
		push	eax
		call	GetProcAddress
		mov	[__imp__Steam_BLoggedOn], eax
		jmp	eax

	_Steam_BReleaseSteamPipe:
		push	clientDll
		call	GetModuleHandleA
		push	Steam_BReleaseSteamPipe
		push	eax
		call	GetProcAddress
		mov	[__imp__Steam_BReleaseSteamPipe], eax
		jmp	eax

	_Steam_ConnectToGlobalUser:
		push	clientDll
		call	GetModuleHandleA
		push	Steam_ConnectToGlobalUser
		push	eax
		call	GetProcAddress
		mov	[__imp__Steam_ConnectToGlobalUser], eax
		jmp	eax

	_Steam_CreateGlobalUser:
		push	clientDll
		call	GetModuleHandleA
		push	Steam_CreateGlobalUser
		push	eax
		call	GetProcAddress
		mov	[__imp__Steam_CreateGlobalUser], eax
		jmp	eax

	_Steam_CreateLocalUser:
		push	clientDll
		call	GetModuleHandleA
		push	Steam_CreateLocalUser
		push	eax
		call	GetProcAddress
		mov	[__imp__Steam_CreateLocalUser], eax
		jmp	eax

	_Steam_CreateSteamPipe:
		push	clientDll
		call	GetModuleHandleA
		push	Steam_CreateSteamPipe
		push	eax
		call	GetProcAddress
		mov	[__imp__Steam_CreateSteamPipe], eax
		jmp	eax

	_Steam_FreeLastCallback:
		push	clientDll
		call	GetModuleHandleA
		push	Steam_FreeLastCallback
		push	eax
		call	GetProcAddress
		mov	[__imp__Steam_FreeLastCallback], eax
		jmp	eax

	_Steam_GSBLoggedOn:
		push	clientDll
		call	GetModuleHandleA
		push	Steam_GSBLoggedOn
		push	eax
		call	GetProcAddress
		mov	[__imp__Steam_GSBLoggedOn], eax
		jmp	eax

	_Steam_GSBSecure:
		push	clientDll
		call	GetModuleHandleA
		push	Steam_GSBSecure
		push	eax
		call	GetProcAddress
		mov	[__imp__Steam_GSBSecure], eax
		jmp	eax

	_Steam_GSGetSteam2GetEncryptionKeyToSendToNewClient:
		push	clientDll
		call	GetModuleHandleA
		push	Steam_GSGetSteam2GetEncryptionKeyToSendToNewClient
		push	eax
		call	GetProcAddress
		mov	[__imp__Steam_GSGetSteam2GetEncryptionKeyToSendToNewClient], eax
		jmp	eax

	_Steam_GSGetSteamID:
		push	clientDll
		call	GetModuleHandleA
		push	Steam_GSGetSteamID
		push	eax
		call	GetProcAddress
		mov	[__imp__Steam_GSGetSteamID], eax
		jmp	eax

	_Steam_GSLogOff:
		push	clientDll
		call	GetModuleHandleA
		push	Steam_GSLogOff
		push	eax
		call	GetProcAddress
		mov	[__imp__Steam_GSLogOff], eax
		jmp	eax

	_Steam_GSLogOn:
		push	clientDll
		call	GetModuleHandleA
		push	Steam_GSLogOn
		push	eax
		call	GetProcAddress
		mov	[__imp__Steam_GSLogOn], eax
		jmp	eax

	_Steam_GSRemoveUserConnect:
		push	clientDll
		call	GetModuleHandleA
		push	Steam_GSRemoveUserConnect
		push	eax
		call	GetProcAddress
		mov	[__imp__Steam_GSRemoveUserConnect], eax
		jmp	eax

	_Steam_GSSendSteam2UserConnect:
		push	clientDll
		call	GetModuleHandleA
		push	Steam_GSSendSteam2UserConnect
		push	eax
		call	GetProcAddress
		mov	[__imp__Steam_GSSendSteam2UserConnect], eax
		jmp	eax

	_Steam_GSSendSteam3UserConnect:
		push	clientDll
		call	GetModuleHandleA
		push	Steam_GSSendSteam3UserConnect
		push	eax
		call	GetProcAddress
		mov	[__imp__Steam_GSSendSteam3UserConnect], eax
		jmp	eax

	_Steam_GSSendUserDisconnect:
		push	clientDll
		call	GetModuleHandleA
		push	Steam_GSSendUserDisconnect
		push	eax
		call	GetProcAddress
		mov	[__imp__Steam_GSSendUserDisconnect], eax
		jmp	eax

	_Steam_GSSendUserStatusResponse:
		push	clientDll
		call	GetModuleHandleA
		push	Steam_GSSendUserStatusResponse
		push	eax
		call	GetProcAddress
		mov	[__imp__Steam_GSSendUserStatusResponse], eax
		jmp	eax

	_Steam_GSSetServerType:
		push	clientDll
		call	GetModuleHandleA
		push	Steam_GSSetServerType
		push	eax
		call	GetProcAddress
		mov	[__imp__Steam_GSSetServerType], eax
		jmp	eax

	_Steam_GSSetSpawnCount:
		push	clientDll
		call	GetModuleHandleA
		push	Steam_GSSetSpawnCount
		push	eax
		call	GetProcAddress
		mov	[__imp__Steam_GSSetSpawnCount], eax
		jmp	eax

	_Steam_GSUpdateStatus:
		push	clientDll
		call	GetModuleHandleA
		push	Steam_GSUpdateStatus
		push	eax
		call	GetProcAddress
		mov	[__imp__Steam_GSUpdateStatus], eax
		jmp	eax

	_Steam_GetAPICallResult:
		push	clientDll
		call	GetModuleHandleA
		push	Steam_GetAPICallResult
		push	eax
		call	GetProcAddress
		mov	[__imp__Steam_GetAPICallResult], eax
		jmp	eax

	_Steam_GetGSHandle:
		push	clientDll
		call	GetModuleHandleA
		push	Steam_GetGSHandle
		push	eax
		call	GetProcAddress
		mov	[__imp__Steam_GetGSHandle], eax
		jmp	eax

	_Steam_InitiateGameConnection:
		push	clientDll
		call	GetModuleHandleA
		push	Steam_InitiateGameConnection
		push	eax
		call	GetProcAddress
		mov	[__imp__Steam_InitiateGameConnection], eax
		jmp	eax

	_Steam_LogOff:
		push	clientDll
		call	GetModuleHandleA
		push	Steam_LogOff
		push	eax
		call	GetProcAddress
		mov	[__imp__Steam_LogOff], eax
		jmp	eax

	_Steam_LogOn:
		push	clientDll
		call	GetModuleHandleA
		push	Steam_LogOn
		push	eax
		call	GetProcAddress
		mov	[__imp__Steam_LogOn], eax
		jmp	eax

	_Steam_ReleaseThreadLocalMemory:
		push	clientDll
		call	GetModuleHandleA
		push	Steam_ReleaseThreadLocalMemory
		push	eax
		call	GetProcAddress
		mov	[__imp__Steam_ReleaseThreadLocalMemory], eax
		jmp	eax

	_Steam_ReleaseUser:
		push	clientDll
		call	GetModuleHandleA
		push	Steam_ReleaseUser
		push	eax
		call	GetProcAddress
		mov	[__imp__Steam_ReleaseUser], eax
		jmp	eax

	_Steam_SetLocalIPBinding:
		push	clientDll
		call	GetModuleHandleA
		push	Steam_SetLocalIPBinding
		push	eax
		call	GetProcAddress
		mov	[__imp__Steam_SetLocalIPBinding], eax
		jmp	eax

	_Steam_TerminateGameConnection:
		push	clientDll
		call	GetModuleHandleA
		push	Steam_TerminateGameConnection
		push	eax
		call	GetProcAddress
		mov	[__imp__Steam_TerminateGameConnection], eax
		jmp	eax

	_hid_close:
		push	clientDll
		call	GetModuleHandleA
		push	hid_close
		push	eax
		call	GetProcAddress
		mov	[__imp__hid_close], eax
		jmp	eax

	_hid_enumerate:
		push	clientDll
		call	GetModuleHandleA
		push	hid_enumerate
		push	eax
		call	GetProcAddress
		mov	[__imp__hid_enumerate], eax
		jmp	eax

	_hid_error:
		push	clientDll
		call	GetModuleHandleA
		push	hid_error
		push	eax
		call	GetProcAddress
		mov	[__imp__hid_error], eax
		jmp	eax

	_hid_exit:
		push	clientDll
		call	GetModuleHandleA
		push	hid_exit
		push	eax
		call	GetProcAddress
		mov	[__imp__hid_exit], eax
		jmp	eax

	_hid_free_enumeration:
		push	clientDll
		call	GetModuleHandleA
		push	hid_free_enumeration
		push	eax
		call	GetProcAddress
		mov	[__imp__hid_free_enumeration], eax
		jmp	eax

	_hid_get_feature_report:
		push	clientDll
		call	GetModuleHandleA
		push	hid_get_feature_report
		push	eax
		call	GetProcAddress
		mov	[__imp__hid_get_feature_report], eax
		jmp	eax

	_hid_get_indexed_string:
		push	clientDll
		call	GetModuleHandleA
		push	hid_get_indexed_string
		push	eax
		call	GetProcAddress
		mov	[__imp__hid_get_indexed_string], eax
		jmp	eax

	_hid_get_manufacturer_string:
		push	clientDll
		call	GetModuleHandleA
		push	hid_get_manufacturer_string
		push	eax
		call	GetProcAddress
		mov	[__imp__hid_get_manufacturer_string], eax
		jmp	eax

	_hid_get_product_string:
		push	clientDll
		call	GetModuleHandleA
		push	hid_get_product_string
		push	eax
		call	GetProcAddress
		mov	[__imp__hid_get_product_string], eax
		jmp	eax

	_hid_get_serial_number_string:
		push	clientDll
		call	GetModuleHandleA
		push	hid_get_serial_number_string
		push	eax
		call	GetProcAddress
		mov	[__imp__hid_get_serial_number_string], eax
		jmp	eax

	_hid_init:
		push	clientDll
		call	GetModuleHandleA
		push	hid_init
		push	eax
		call	GetProcAddress
		mov	[__imp__hid_init], eax
		jmp	eax

	_hid_open:
		push	clientDll
		call	GetModuleHandleA
		push	hid_open
		push	eax
		call	GetProcAddress
		mov	[__imp__hid_open], eax
		jmp	eax

	_hid_open_path:
		push	clientDll
		call	GetModuleHandleA
		push	hid_open_path
		push	eax
		call	GetProcAddress
		mov	[__imp__hid_open_path], eax
		jmp	eax

	_hid_read:
		push	clientDll
		call	GetModuleHandleA
		push	hid_read
		push	eax
		call	GetProcAddress
		mov	[__imp__hid_read], eax
		jmp	eax

	_hid_read_timeout:
		push	clientDll
		call	GetModuleHandleA
		push	hid_read_timeout
		push	eax
		call	GetProcAddress
		mov	[__imp__hid_read_timeout], eax
		jmp	eax

	_hid_send_feature_report:
		push	clientDll
		call	GetModuleHandleA
		push	hid_send_feature_report
		push	eax
		call	GetProcAddress
		mov	[__imp__hid_send_feature_report], eax
		jmp	eax

	_hid_set_nonblocking:
		push	clientDll
		call	GetModuleHandleA
		push	hid_set_nonblocking
		push	eax
		call	GetProcAddress
		mov	[__imp__hid_set_nonblocking], eax
		jmp	eax

	_hid_write:
		push	clientDll
		call	GetModuleHandleA
		push	hid_write
		push	eax
		call	GetProcAddress
		mov	[__imp__hid_write], eax
		jmp	eax



section '.data' data readable writeable

	clientDll db 'steamclient.dll', 0
	Breakpad_SteamMiniDumpInit db 'Breakpad_SteamMiniDumpInit', 0
	__imp__Breakpad_SteamMiniDumpInit dd _Breakpad_SteamMiniDumpInit
	Breakpad_SteamSetAppID db 'Breakpad_SteamSetAppID', 0
	__imp__Breakpad_SteamSetAppID dd _Breakpad_SteamSetAppID
	Breakpad_SteamSetSteamID db 'Breakpad_SteamSetSteamID', 0
	__imp__Breakpad_SteamSetSteamID dd _Breakpad_SteamSetSteamID
	Breakpad_SteamWriteMiniDumpSetComment db 'Breakpad_SteamWriteMiniDumpSetComment', 0
	__imp__Breakpad_SteamWriteMiniDumpSetComment dd _Breakpad_SteamWriteMiniDumpSetComment
	Breakpad_SteamWriteMiniDumpUsingExceptionInfoWithBuildId db 'Breakpad_SteamWriteMiniDumpUsingExceptionInfoWithBuildId', 0
	__imp__Breakpad_SteamWriteMiniDumpUsingExceptionInfoWithBuildId dd _Breakpad_SteamWriteMiniDumpUsingExceptionInfoWithBuildId
	CreateInterface db 'CreateInterface', 0
	__imp__CreateInterface dd _CreateInterface
	Steam_BConnected db 'Steam_BConnected', 0
	__imp__Steam_BConnected dd _Steam_BConnected
	Steam_BGetCallback db 'Steam_BGetCallback', 0
	__imp__Steam_BGetCallback dd _Steam_BGetCallback
	Steam_BLoggedOn db 'Steam_BLoggedOn', 0
	__imp__Steam_BLoggedOn dd _Steam_BLoggedOn
	Steam_BReleaseSteamPipe db 'Steam_BReleaseSteamPipe', 0
	__imp__Steam_BReleaseSteamPipe dd _Steam_BReleaseSteamPipe
	Steam_ConnectToGlobalUser db 'Steam_ConnectToGlobalUser', 0
	__imp__Steam_ConnectToGlobalUser dd _Steam_ConnectToGlobalUser
	Steam_CreateGlobalUser db 'Steam_CreateGlobalUser', 0
	__imp__Steam_CreateGlobalUser dd _Steam_CreateGlobalUser
	Steam_CreateLocalUser db 'Steam_CreateLocalUser', 0
	__imp__Steam_CreateLocalUser dd _Steam_CreateLocalUser
	Steam_CreateSteamPipe db 'Steam_CreateSteamPipe', 0
	__imp__Steam_CreateSteamPipe dd _Steam_CreateSteamPipe
	Steam_FreeLastCallback db 'Steam_FreeLastCallback', 0
	__imp__Steam_FreeLastCallback dd _Steam_FreeLastCallback
	Steam_GSBLoggedOn db 'Steam_GSBLoggedOn', 0
	__imp__Steam_GSBLoggedOn dd _Steam_GSBLoggedOn
	Steam_GSBSecure db 'Steam_GSBSecure', 0
	__imp__Steam_GSBSecure dd _Steam_GSBSecure
	Steam_GSGetSteam2GetEncryptionKeyToSendToNewClient db 'Steam_GSGetSteam2GetEncryptionKeyToSendToNewClient', 0
	__imp__Steam_GSGetSteam2GetEncryptionKeyToSendToNewClient dd _Steam_GSGetSteam2GetEncryptionKeyToSendToNewClient
	Steam_GSGetSteamID db 'Steam_GSGetSteamID', 0
	__imp__Steam_GSGetSteamID dd _Steam_GSGetSteamID
	Steam_GSLogOff db 'Steam_GSLogOff', 0
	__imp__Steam_GSLogOff dd _Steam_GSLogOff
	Steam_GSLogOn db 'Steam_GSLogOn', 0
	__imp__Steam_GSLogOn dd _Steam_GSLogOn
	Steam_GSRemoveUserConnect db 'Steam_GSRemoveUserConnect', 0
	__imp__Steam_GSRemoveUserConnect dd _Steam_GSRemoveUserConnect
	Steam_GSSendSteam2UserConnect db 'Steam_GSSendSteam2UserConnect', 0
	__imp__Steam_GSSendSteam2UserConnect dd _Steam_GSSendSteam2UserConnect
	Steam_GSSendSteam3UserConnect db 'Steam_GSSendSteam3UserConnect', 0
	__imp__Steam_GSSendSteam3UserConnect dd _Steam_GSSendSteam3UserConnect
	Steam_GSSendUserDisconnect db 'Steam_GSSendUserDisconnect', 0
	__imp__Steam_GSSendUserDisconnect dd _Steam_GSSendUserDisconnect
	Steam_GSSendUserStatusResponse db 'Steam_GSSendUserStatusResponse', 0
	__imp__Steam_GSSendUserStatusResponse dd _Steam_GSSendUserStatusResponse
	Steam_GSSetServerType db 'Steam_GSSetServerType', 0
	__imp__Steam_GSSetServerType dd _Steam_GSSetServerType
	Steam_GSSetSpawnCount db 'Steam_GSSetSpawnCount', 0
	__imp__Steam_GSSetSpawnCount dd _Steam_GSSetSpawnCount
	Steam_GSUpdateStatus db 'Steam_GSUpdateStatus', 0
	__imp__Steam_GSUpdateStatus dd _Steam_GSUpdateStatus
	Steam_GetAPICallResult db 'Steam_GetAPICallResult', 0
	__imp__Steam_GetAPICallResult dd _Steam_GetAPICallResult
	Steam_GetGSHandle db 'Steam_GetGSHandle', 0
	__imp__Steam_GetGSHandle dd _Steam_GetGSHandle
	Steam_InitiateGameConnection db 'Steam_InitiateGameConnection', 0
	__imp__Steam_InitiateGameConnection dd _Steam_InitiateGameConnection
	Steam_LogOff db 'Steam_LogOff', 0
	__imp__Steam_LogOff dd _Steam_LogOff
	Steam_LogOn db 'Steam_LogOn', 0
	__imp__Steam_LogOn dd _Steam_LogOn
	Steam_ReleaseThreadLocalMemory db 'Steam_ReleaseThreadLocalMemory', 0
	__imp__Steam_ReleaseThreadLocalMemory dd _Steam_ReleaseThreadLocalMemory
	Steam_ReleaseUser db 'Steam_ReleaseUser', 0
	__imp__Steam_ReleaseUser dd _Steam_ReleaseUser
	Steam_SetLocalIPBinding db 'Steam_SetLocalIPBinding', 0
	__imp__Steam_SetLocalIPBinding dd _Steam_SetLocalIPBinding
	Steam_TerminateGameConnection db 'Steam_TerminateGameConnection', 0
	__imp__Steam_TerminateGameConnection dd _Steam_TerminateGameConnection
	hid_close db 'hid_close', 0
	__imp__hid_close dd _hid_close
	hid_enumerate db 'hid_enumerate', 0
	__imp__hid_enumerate dd _hid_enumerate
	hid_error db 'hid_error', 0
	__imp__hid_error dd _hid_error
	hid_exit db 'hid_exit', 0
	__imp__hid_exit dd _hid_exit
	hid_free_enumeration db 'hid_free_enumeration', 0
	__imp__hid_free_enumeration dd _hid_free_enumeration
	hid_get_feature_report db 'hid_get_feature_report', 0
	__imp__hid_get_feature_report dd _hid_get_feature_report
	hid_get_indexed_string db 'hid_get_indexed_string', 0
	__imp__hid_get_indexed_string dd _hid_get_indexed_string
	hid_get_manufacturer_string db 'hid_get_manufacturer_string', 0
	__imp__hid_get_manufacturer_string dd _hid_get_manufacturer_string
	hid_get_product_string db 'hid_get_product_string', 0
	__imp__hid_get_product_string dd _hid_get_product_string
	hid_get_serial_number_string db 'hid_get_serial_number_string', 0
	__imp__hid_get_serial_number_string dd _hid_get_serial_number_string
	hid_init db 'hid_init', 0
	__imp__hid_init dd _hid_init
	hid_open db 'hid_open', 0
	__imp__hid_open dd _hid_open
	hid_open_path db 'hid_open_path', 0
	__imp__hid_open_path dd _hid_open_path
	hid_read db 'hid_read', 0
	__imp__hid_read dd _hid_read
	hid_read_timeout db 'hid_read_timeout', 0
	__imp__hid_read_timeout dd _hid_read_timeout
	hid_send_feature_report db 'hid_send_feature_report', 0
	__imp__hid_send_feature_report dd _hid_send_feature_report
	hid_set_nonblocking db 'hid_set_nonblocking', 0
	__imp__hid_set_nonblocking dd _hid_set_nonblocking
	hid_write db 'hid_write', 0
	__imp__hid_write dd _hid_write
