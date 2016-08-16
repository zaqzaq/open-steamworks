; generated with lots of hate and some black magic

include 'win64a.inc'
format MS64 COFF
use64

macro SaveReg
{
	push	rcx
	push	rdx
	push	r8
	push	r9
}

macro RestoreReg
{
	pop	r9
	pop	r8
	pop	rdx
	pop	rcx
}

extrn '__imp_GetModuleHandleA' as GetModuleHandleA:qword
extrn '__imp_GetProcAddress' as GetProcAddress:qword



section '.text' code readable executable

	public _Breakpad_SteamMiniDumpInit
	public __imp_Breakpad_SteamMiniDumpInit
	public _Breakpad_SteamSetAppID
	public __imp_Breakpad_SteamSetAppID
	public _Breakpad_SteamSetSteamID
	public __imp_Breakpad_SteamSetSteamID
	public _Breakpad_SteamWriteMiniDumpSetComment
	public __imp_Breakpad_SteamWriteMiniDumpSetComment
	public _Breakpad_SteamWriteMiniDumpUsingExceptionInfoWithBuildId
	public __imp_Breakpad_SteamWriteMiniDumpUsingExceptionInfoWithBuildId
	public _CreateInterface
	public __imp_CreateInterface
	public _Steam_BConnected
	public __imp_Steam_BConnected
	public _Steam_BGetCallback
	public __imp_Steam_BGetCallback
	public _Steam_BLoggedOn
	public __imp_Steam_BLoggedOn
	public _Steam_BReleaseSteamPipe
	public __imp_Steam_BReleaseSteamPipe
	public _Steam_ConnectToGlobalUser
	public __imp_Steam_ConnectToGlobalUser
	public _Steam_CreateGlobalUser
	public __imp_Steam_CreateGlobalUser
	public _Steam_CreateLocalUser
	public __imp_Steam_CreateLocalUser
	public _Steam_CreateSteamPipe
	public __imp_Steam_CreateSteamPipe
	public _Steam_FreeLastCallback
	public __imp_Steam_FreeLastCallback
	public _Steam_GSBLoggedOn
	public __imp_Steam_GSBLoggedOn
	public _Steam_GSBSecure
	public __imp_Steam_GSBSecure
	public _Steam_GSGetSteam2GetEncryptionKeyToSendToNewClient
	public __imp_Steam_GSGetSteam2GetEncryptionKeyToSendToNewClient
	public _Steam_GSGetSteamID
	public __imp_Steam_GSGetSteamID
	public _Steam_GSLogOff
	public __imp_Steam_GSLogOff
	public _Steam_GSLogOn
	public __imp_Steam_GSLogOn
	public _Steam_GSRemoveUserConnect
	public __imp_Steam_GSRemoveUserConnect
	public _Steam_GSSendSteam2UserConnect
	public __imp_Steam_GSSendSteam2UserConnect
	public _Steam_GSSendSteam3UserConnect
	public __imp_Steam_GSSendSteam3UserConnect
	public _Steam_GSSendUserDisconnect
	public __imp_Steam_GSSendUserDisconnect
	public _Steam_GSSendUserStatusResponse
	public __imp_Steam_GSSendUserStatusResponse
	public _Steam_GSSetServerType
	public __imp_Steam_GSSetServerType
	public _Steam_GSSetSpawnCount
	public __imp_Steam_GSSetSpawnCount
	public _Steam_GSUpdateStatus
	public __imp_Steam_GSUpdateStatus
	public _Steam_GetAPICallResult
	public __imp_Steam_GetAPICallResult
	public _Steam_GetGSHandle
	public __imp_Steam_GetGSHandle
	public _Steam_InitiateGameConnection
	public __imp_Steam_InitiateGameConnection
	public _Steam_LogOff
	public __imp_Steam_LogOff
	public _Steam_LogOn
	public __imp_Steam_LogOn
	public _Steam_ReleaseThreadLocalMemory
	public __imp_Steam_ReleaseThreadLocalMemory
	public _Steam_ReleaseUser
	public __imp_Steam_ReleaseUser
	public _Steam_SetLocalIPBinding
	public __imp_Steam_SetLocalIPBinding
	public _Steam_TerminateGameConnection
	public __imp_Steam_TerminateGameConnection
	public _hid_close
	public __imp_hid_close
	public _hid_enumerate
	public __imp_hid_enumerate
	public _hid_error
	public __imp_hid_error
	public _hid_exit
	public __imp_hid_exit
	public _hid_free_enumeration
	public __imp_hid_free_enumeration
	public _hid_get_feature_report
	public __imp_hid_get_feature_report
	public _hid_get_indexed_string
	public __imp_hid_get_indexed_string
	public _hid_get_manufacturer_string
	public __imp_hid_get_manufacturer_string
	public _hid_get_product_string
	public __imp_hid_get_product_string
	public _hid_get_serial_number_string
	public __imp_hid_get_serial_number_string
	public _hid_init
	public __imp_hid_init
	public _hid_open
	public __imp_hid_open
	public _hid_open_path
	public __imp_hid_open_path
	public _hid_read
	public __imp_hid_read
	public _hid_read_timeout
	public __imp_hid_read_timeout
	public _hid_send_feature_report
	public __imp_hid_send_feature_report
	public _hid_set_nonblocking
	public __imp_hid_set_nonblocking
	public _hid_write
	public __imp_hid_write


	_Breakpad_SteamMiniDumpInit:
		SaveReg
		invoke	GetModuleHandleA,clientDll
		invoke	GetProcAddress,rax,Breakpad_SteamMiniDumpInit
		mov	[__imp_Breakpad_SteamMiniDumpInit], rax
		RestoreReg
		jmp	rax

	_Breakpad_SteamSetAppID:
		SaveReg
		invoke	GetModuleHandleA,clientDll
		invoke	GetProcAddress,rax,Breakpad_SteamSetAppID
		mov	[__imp_Breakpad_SteamSetAppID], rax
		RestoreReg
		jmp	rax

	_Breakpad_SteamSetSteamID:
		SaveReg
		invoke	GetModuleHandleA,clientDll
		invoke	GetProcAddress,rax,Breakpad_SteamSetSteamID
		mov	[__imp_Breakpad_SteamSetSteamID], rax
		RestoreReg
		jmp	rax

	_Breakpad_SteamWriteMiniDumpSetComment:
		SaveReg
		invoke	GetModuleHandleA,clientDll
		invoke	GetProcAddress,rax,Breakpad_SteamWriteMiniDumpSetComment
		mov	[__imp_Breakpad_SteamWriteMiniDumpSetComment], rax
		RestoreReg
		jmp	rax

	_Breakpad_SteamWriteMiniDumpUsingExceptionInfoWithBuildId:
		SaveReg
		invoke	GetModuleHandleA,clientDll
		invoke	GetProcAddress,rax,Breakpad_SteamWriteMiniDumpUsingExceptionInfoWithBuildId
		mov	[__imp_Breakpad_SteamWriteMiniDumpUsingExceptionInfoWithBuildId], rax
		RestoreReg
		jmp	rax

	_CreateInterface:
		SaveReg
		invoke	GetModuleHandleA,clientDll
		invoke	GetProcAddress,rax,CreateInterface
		mov	[__imp_CreateInterface], rax
		RestoreReg
		jmp	rax

	_Steam_BConnected:
		SaveReg
		invoke	GetModuleHandleA,clientDll
		invoke	GetProcAddress,rax,Steam_BConnected
		mov	[__imp_Steam_BConnected], rax
		RestoreReg
		jmp	rax

	_Steam_BGetCallback:
		SaveReg
		invoke	GetModuleHandleA,clientDll
		invoke	GetProcAddress,rax,Steam_BGetCallback
		mov	[__imp_Steam_BGetCallback], rax
		RestoreReg
		jmp	rax

	_Steam_BLoggedOn:
		SaveReg
		invoke	GetModuleHandleA,clientDll
		invoke	GetProcAddress,rax,Steam_BLoggedOn
		mov	[__imp_Steam_BLoggedOn], rax
		RestoreReg
		jmp	rax

	_Steam_BReleaseSteamPipe:
		SaveReg
		invoke	GetModuleHandleA,clientDll
		invoke	GetProcAddress,rax,Steam_BReleaseSteamPipe
		mov	[__imp_Steam_BReleaseSteamPipe], rax
		RestoreReg
		jmp	rax

	_Steam_ConnectToGlobalUser:
		SaveReg
		invoke	GetModuleHandleA,clientDll
		invoke	GetProcAddress,rax,Steam_ConnectToGlobalUser
		mov	[__imp_Steam_ConnectToGlobalUser], rax
		RestoreReg
		jmp	rax

	_Steam_CreateGlobalUser:
		SaveReg
		invoke	GetModuleHandleA,clientDll
		invoke	GetProcAddress,rax,Steam_CreateGlobalUser
		mov	[__imp_Steam_CreateGlobalUser], rax
		RestoreReg
		jmp	rax

	_Steam_CreateLocalUser:
		SaveReg
		invoke	GetModuleHandleA,clientDll
		invoke	GetProcAddress,rax,Steam_CreateLocalUser
		mov	[__imp_Steam_CreateLocalUser], rax
		RestoreReg
		jmp	rax

	_Steam_CreateSteamPipe:
		SaveReg
		invoke	GetModuleHandleA,clientDll
		invoke	GetProcAddress,rax,Steam_CreateSteamPipe
		mov	[__imp_Steam_CreateSteamPipe], rax
		RestoreReg
		jmp	rax

	_Steam_FreeLastCallback:
		SaveReg
		invoke	GetModuleHandleA,clientDll
		invoke	GetProcAddress,rax,Steam_FreeLastCallback
		mov	[__imp_Steam_FreeLastCallback], rax
		RestoreReg
		jmp	rax

	_Steam_GSBLoggedOn:
		SaveReg
		invoke	GetModuleHandleA,clientDll
		invoke	GetProcAddress,rax,Steam_GSBLoggedOn
		mov	[__imp_Steam_GSBLoggedOn], rax
		RestoreReg
		jmp	rax

	_Steam_GSBSecure:
		SaveReg
		invoke	GetModuleHandleA,clientDll
		invoke	GetProcAddress,rax,Steam_GSBSecure
		mov	[__imp_Steam_GSBSecure], rax
		RestoreReg
		jmp	rax

	_Steam_GSGetSteam2GetEncryptionKeyToSendToNewClient:
		SaveReg
		invoke	GetModuleHandleA,clientDll
		invoke	GetProcAddress,rax,Steam_GSGetSteam2GetEncryptionKeyToSendToNewClient
		mov	[__imp_Steam_GSGetSteam2GetEncryptionKeyToSendToNewClient], rax
		RestoreReg
		jmp	rax

	_Steam_GSGetSteamID:
		SaveReg
		invoke	GetModuleHandleA,clientDll
		invoke	GetProcAddress,rax,Steam_GSGetSteamID
		mov	[__imp_Steam_GSGetSteamID], rax
		RestoreReg
		jmp	rax

	_Steam_GSLogOff:
		SaveReg
		invoke	GetModuleHandleA,clientDll
		invoke	GetProcAddress,rax,Steam_GSLogOff
		mov	[__imp_Steam_GSLogOff], rax
		RestoreReg
		jmp	rax

	_Steam_GSLogOn:
		SaveReg
		invoke	GetModuleHandleA,clientDll
		invoke	GetProcAddress,rax,Steam_GSLogOn
		mov	[__imp_Steam_GSLogOn], rax
		RestoreReg
		jmp	rax

	_Steam_GSRemoveUserConnect:
		SaveReg
		invoke	GetModuleHandleA,clientDll
		invoke	GetProcAddress,rax,Steam_GSRemoveUserConnect
		mov	[__imp_Steam_GSRemoveUserConnect], rax
		RestoreReg
		jmp	rax

	_Steam_GSSendSteam2UserConnect:
		SaveReg
		invoke	GetModuleHandleA,clientDll
		invoke	GetProcAddress,rax,Steam_GSSendSteam2UserConnect
		mov	[__imp_Steam_GSSendSteam2UserConnect], rax
		RestoreReg
		jmp	rax

	_Steam_GSSendSteam3UserConnect:
		SaveReg
		invoke	GetModuleHandleA,clientDll
		invoke	GetProcAddress,rax,Steam_GSSendSteam3UserConnect
		mov	[__imp_Steam_GSSendSteam3UserConnect], rax
		RestoreReg
		jmp	rax

	_Steam_GSSendUserDisconnect:
		SaveReg
		invoke	GetModuleHandleA,clientDll
		invoke	GetProcAddress,rax,Steam_GSSendUserDisconnect
		mov	[__imp_Steam_GSSendUserDisconnect], rax
		RestoreReg
		jmp	rax

	_Steam_GSSendUserStatusResponse:
		SaveReg
		invoke	GetModuleHandleA,clientDll
		invoke	GetProcAddress,rax,Steam_GSSendUserStatusResponse
		mov	[__imp_Steam_GSSendUserStatusResponse], rax
		RestoreReg
		jmp	rax

	_Steam_GSSetServerType:
		SaveReg
		invoke	GetModuleHandleA,clientDll
		invoke	GetProcAddress,rax,Steam_GSSetServerType
		mov	[__imp_Steam_GSSetServerType], rax
		RestoreReg
		jmp	rax

	_Steam_GSSetSpawnCount:
		SaveReg
		invoke	GetModuleHandleA,clientDll
		invoke	GetProcAddress,rax,Steam_GSSetSpawnCount
		mov	[__imp_Steam_GSSetSpawnCount], rax
		RestoreReg
		jmp	rax

	_Steam_GSUpdateStatus:
		SaveReg
		invoke	GetModuleHandleA,clientDll
		invoke	GetProcAddress,rax,Steam_GSUpdateStatus
		mov	[__imp_Steam_GSUpdateStatus], rax
		RestoreReg
		jmp	rax

	_Steam_GetAPICallResult:
		SaveReg
		invoke	GetModuleHandleA,clientDll
		invoke	GetProcAddress,rax,Steam_GetAPICallResult
		mov	[__imp_Steam_GetAPICallResult], rax
		RestoreReg
		jmp	rax

	_Steam_GetGSHandle:
		SaveReg
		invoke	GetModuleHandleA,clientDll
		invoke	GetProcAddress,rax,Steam_GetGSHandle
		mov	[__imp_Steam_GetGSHandle], rax
		RestoreReg
		jmp	rax

	_Steam_InitiateGameConnection:
		SaveReg
		invoke	GetModuleHandleA,clientDll
		invoke	GetProcAddress,rax,Steam_InitiateGameConnection
		mov	[__imp_Steam_InitiateGameConnection], rax
		RestoreReg
		jmp	rax

	_Steam_LogOff:
		SaveReg
		invoke	GetModuleHandleA,clientDll
		invoke	GetProcAddress,rax,Steam_LogOff
		mov	[__imp_Steam_LogOff], rax
		RestoreReg
		jmp	rax

	_Steam_LogOn:
		SaveReg
		invoke	GetModuleHandleA,clientDll
		invoke	GetProcAddress,rax,Steam_LogOn
		mov	[__imp_Steam_LogOn], rax
		RestoreReg
		jmp	rax

	_Steam_ReleaseThreadLocalMemory:
		SaveReg
		invoke	GetModuleHandleA,clientDll
		invoke	GetProcAddress,rax,Steam_ReleaseThreadLocalMemory
		mov	[__imp_Steam_ReleaseThreadLocalMemory], rax
		RestoreReg
		jmp	rax

	_Steam_ReleaseUser:
		SaveReg
		invoke	GetModuleHandleA,clientDll
		invoke	GetProcAddress,rax,Steam_ReleaseUser
		mov	[__imp_Steam_ReleaseUser], rax
		RestoreReg
		jmp	rax

	_Steam_SetLocalIPBinding:
		SaveReg
		invoke	GetModuleHandleA,clientDll
		invoke	GetProcAddress,rax,Steam_SetLocalIPBinding
		mov	[__imp_Steam_SetLocalIPBinding], rax
		RestoreReg
		jmp	rax

	_Steam_TerminateGameConnection:
		SaveReg
		invoke	GetModuleHandleA,clientDll
		invoke	GetProcAddress,rax,Steam_TerminateGameConnection
		mov	[__imp_Steam_TerminateGameConnection], rax
		RestoreReg
		jmp	rax

	_hid_close:
		SaveReg
		invoke	GetModuleHandleA,clientDll
		invoke	GetProcAddress,rax,hid_close
		mov	[__imp_hid_close], rax
		RestoreReg
		jmp	rax

	_hid_enumerate:
		SaveReg
		invoke	GetModuleHandleA,clientDll
		invoke	GetProcAddress,rax,hid_enumerate
		mov	[__imp_hid_enumerate], rax
		RestoreReg
		jmp	rax

	_hid_error:
		SaveReg
		invoke	GetModuleHandleA,clientDll
		invoke	GetProcAddress,rax,hid_error
		mov	[__imp_hid_error], rax
		RestoreReg
		jmp	rax

	_hid_exit:
		SaveReg
		invoke	GetModuleHandleA,clientDll
		invoke	GetProcAddress,rax,hid_exit
		mov	[__imp_hid_exit], rax
		RestoreReg
		jmp	rax

	_hid_free_enumeration:
		SaveReg
		invoke	GetModuleHandleA,clientDll
		invoke	GetProcAddress,rax,hid_free_enumeration
		mov	[__imp_hid_free_enumeration], rax
		RestoreReg
		jmp	rax

	_hid_get_feature_report:
		SaveReg
		invoke	GetModuleHandleA,clientDll
		invoke	GetProcAddress,rax,hid_get_feature_report
		mov	[__imp_hid_get_feature_report], rax
		RestoreReg
		jmp	rax

	_hid_get_indexed_string:
		SaveReg
		invoke	GetModuleHandleA,clientDll
		invoke	GetProcAddress,rax,hid_get_indexed_string
		mov	[__imp_hid_get_indexed_string], rax
		RestoreReg
		jmp	rax

	_hid_get_manufacturer_string:
		SaveReg
		invoke	GetModuleHandleA,clientDll
		invoke	GetProcAddress,rax,hid_get_manufacturer_string
		mov	[__imp_hid_get_manufacturer_string], rax
		RestoreReg
		jmp	rax

	_hid_get_product_string:
		SaveReg
		invoke	GetModuleHandleA,clientDll
		invoke	GetProcAddress,rax,hid_get_product_string
		mov	[__imp_hid_get_product_string], rax
		RestoreReg
		jmp	rax

	_hid_get_serial_number_string:
		SaveReg
		invoke	GetModuleHandleA,clientDll
		invoke	GetProcAddress,rax,hid_get_serial_number_string
		mov	[__imp_hid_get_serial_number_string], rax
		RestoreReg
		jmp	rax

	_hid_init:
		SaveReg
		invoke	GetModuleHandleA,clientDll
		invoke	GetProcAddress,rax,hid_init
		mov	[__imp_hid_init], rax
		RestoreReg
		jmp	rax

	_hid_open:
		SaveReg
		invoke	GetModuleHandleA,clientDll
		invoke	GetProcAddress,rax,hid_open
		mov	[__imp_hid_open], rax
		RestoreReg
		jmp	rax

	_hid_open_path:
		SaveReg
		invoke	GetModuleHandleA,clientDll
		invoke	GetProcAddress,rax,hid_open_path
		mov	[__imp_hid_open_path], rax
		RestoreReg
		jmp	rax

	_hid_read:
		SaveReg
		invoke	GetModuleHandleA,clientDll
		invoke	GetProcAddress,rax,hid_read
		mov	[__imp_hid_read], rax
		RestoreReg
		jmp	rax

	_hid_read_timeout:
		SaveReg
		invoke	GetModuleHandleA,clientDll
		invoke	GetProcAddress,rax,hid_read_timeout
		mov	[__imp_hid_read_timeout], rax
		RestoreReg
		jmp	rax

	_hid_send_feature_report:
		SaveReg
		invoke	GetModuleHandleA,clientDll
		invoke	GetProcAddress,rax,hid_send_feature_report
		mov	[__imp_hid_send_feature_report], rax
		RestoreReg
		jmp	rax

	_hid_set_nonblocking:
		SaveReg
		invoke	GetModuleHandleA,clientDll
		invoke	GetProcAddress,rax,hid_set_nonblocking
		mov	[__imp_hid_set_nonblocking], rax
		RestoreReg
		jmp	rax

	_hid_write:
		SaveReg
		invoke	GetModuleHandleA,clientDll
		invoke	GetProcAddress,rax,hid_write
		mov	[__imp_hid_write], rax
		RestoreReg
		jmp	rax



section '.data' data readable writeable

	clientDll db 'steamclient64.dll', 0
	Breakpad_SteamMiniDumpInit db 'Breakpad_SteamMiniDumpInit', 0
	__imp_Breakpad_SteamMiniDumpInit dq _Breakpad_SteamMiniDumpInit
	Breakpad_SteamSetAppID db 'Breakpad_SteamSetAppID', 0
	__imp_Breakpad_SteamSetAppID dq _Breakpad_SteamSetAppID
	Breakpad_SteamSetSteamID db 'Breakpad_SteamSetSteamID', 0
	__imp_Breakpad_SteamSetSteamID dq _Breakpad_SteamSetSteamID
	Breakpad_SteamWriteMiniDumpSetComment db 'Breakpad_SteamWriteMiniDumpSetComment', 0
	__imp_Breakpad_SteamWriteMiniDumpSetComment dq _Breakpad_SteamWriteMiniDumpSetComment
	Breakpad_SteamWriteMiniDumpUsingExceptionInfoWithBuildId db 'Breakpad_SteamWriteMiniDumpUsingExceptionInfoWithBuildId', 0
	__imp_Breakpad_SteamWriteMiniDumpUsingExceptionInfoWithBuildId dq _Breakpad_SteamWriteMiniDumpUsingExceptionInfoWithBuildId
	CreateInterface db 'CreateInterface', 0
	__imp_CreateInterface dq _CreateInterface
	Steam_BConnected db 'Steam_BConnected', 0
	__imp_Steam_BConnected dq _Steam_BConnected
	Steam_BGetCallback db 'Steam_BGetCallback', 0
	__imp_Steam_BGetCallback dq _Steam_BGetCallback
	Steam_BLoggedOn db 'Steam_BLoggedOn', 0
	__imp_Steam_BLoggedOn dq _Steam_BLoggedOn
	Steam_BReleaseSteamPipe db 'Steam_BReleaseSteamPipe', 0
	__imp_Steam_BReleaseSteamPipe dq _Steam_BReleaseSteamPipe
	Steam_ConnectToGlobalUser db 'Steam_ConnectToGlobalUser', 0
	__imp_Steam_ConnectToGlobalUser dq _Steam_ConnectToGlobalUser
	Steam_CreateGlobalUser db 'Steam_CreateGlobalUser', 0
	__imp_Steam_CreateGlobalUser dq _Steam_CreateGlobalUser
	Steam_CreateLocalUser db 'Steam_CreateLocalUser', 0
	__imp_Steam_CreateLocalUser dq _Steam_CreateLocalUser
	Steam_CreateSteamPipe db 'Steam_CreateSteamPipe', 0
	__imp_Steam_CreateSteamPipe dq _Steam_CreateSteamPipe
	Steam_FreeLastCallback db 'Steam_FreeLastCallback', 0
	__imp_Steam_FreeLastCallback dq _Steam_FreeLastCallback
	Steam_GSBLoggedOn db 'Steam_GSBLoggedOn', 0
	__imp_Steam_GSBLoggedOn dq _Steam_GSBLoggedOn
	Steam_GSBSecure db 'Steam_GSBSecure', 0
	__imp_Steam_GSBSecure dq _Steam_GSBSecure
	Steam_GSGetSteam2GetEncryptionKeyToSendToNewClient db 'Steam_GSGetSteam2GetEncryptionKeyToSendToNewClient', 0
	__imp_Steam_GSGetSteam2GetEncryptionKeyToSendToNewClient dq _Steam_GSGetSteam2GetEncryptionKeyToSendToNewClient
	Steam_GSGetSteamID db 'Steam_GSGetSteamID', 0
	__imp_Steam_GSGetSteamID dq _Steam_GSGetSteamID
	Steam_GSLogOff db 'Steam_GSLogOff', 0
	__imp_Steam_GSLogOff dq _Steam_GSLogOff
	Steam_GSLogOn db 'Steam_GSLogOn', 0
	__imp_Steam_GSLogOn dq _Steam_GSLogOn
	Steam_GSRemoveUserConnect db 'Steam_GSRemoveUserConnect', 0
	__imp_Steam_GSRemoveUserConnect dq _Steam_GSRemoveUserConnect
	Steam_GSSendSteam2UserConnect db 'Steam_GSSendSteam2UserConnect', 0
	__imp_Steam_GSSendSteam2UserConnect dq _Steam_GSSendSteam2UserConnect
	Steam_GSSendSteam3UserConnect db 'Steam_GSSendSteam3UserConnect', 0
	__imp_Steam_GSSendSteam3UserConnect dq _Steam_GSSendSteam3UserConnect
	Steam_GSSendUserDisconnect db 'Steam_GSSendUserDisconnect', 0
	__imp_Steam_GSSendUserDisconnect dq _Steam_GSSendUserDisconnect
	Steam_GSSendUserStatusResponse db 'Steam_GSSendUserStatusResponse', 0
	__imp_Steam_GSSendUserStatusResponse dq _Steam_GSSendUserStatusResponse
	Steam_GSSetServerType db 'Steam_GSSetServerType', 0
	__imp_Steam_GSSetServerType dq _Steam_GSSetServerType
	Steam_GSSetSpawnCount db 'Steam_GSSetSpawnCount', 0
	__imp_Steam_GSSetSpawnCount dq _Steam_GSSetSpawnCount
	Steam_GSUpdateStatus db 'Steam_GSUpdateStatus', 0
	__imp_Steam_GSUpdateStatus dq _Steam_GSUpdateStatus
	Steam_GetAPICallResult db 'Steam_GetAPICallResult', 0
	__imp_Steam_GetAPICallResult dq _Steam_GetAPICallResult
	Steam_GetGSHandle db 'Steam_GetGSHandle', 0
	__imp_Steam_GetGSHandle dq _Steam_GetGSHandle
	Steam_InitiateGameConnection db 'Steam_InitiateGameConnection', 0
	__imp_Steam_InitiateGameConnection dq _Steam_InitiateGameConnection
	Steam_LogOff db 'Steam_LogOff', 0
	__imp_Steam_LogOff dq _Steam_LogOff
	Steam_LogOn db 'Steam_LogOn', 0
	__imp_Steam_LogOn dq _Steam_LogOn
	Steam_ReleaseThreadLocalMemory db 'Steam_ReleaseThreadLocalMemory', 0
	__imp_Steam_ReleaseThreadLocalMemory dq _Steam_ReleaseThreadLocalMemory
	Steam_ReleaseUser db 'Steam_ReleaseUser', 0
	__imp_Steam_ReleaseUser dq _Steam_ReleaseUser
	Steam_SetLocalIPBinding db 'Steam_SetLocalIPBinding', 0
	__imp_Steam_SetLocalIPBinding dq _Steam_SetLocalIPBinding
	Steam_TerminateGameConnection db 'Steam_TerminateGameConnection', 0
	__imp_Steam_TerminateGameConnection dq _Steam_TerminateGameConnection
	hid_close db 'hid_close', 0
	__imp_hid_close dq _hid_close
	hid_enumerate db 'hid_enumerate', 0
	__imp_hid_enumerate dq _hid_enumerate
	hid_error db 'hid_error', 0
	__imp_hid_error dq _hid_error
	hid_exit db 'hid_exit', 0
	__imp_hid_exit dq _hid_exit
	hid_free_enumeration db 'hid_free_enumeration', 0
	__imp_hid_free_enumeration dq _hid_free_enumeration
	hid_get_feature_report db 'hid_get_feature_report', 0
	__imp_hid_get_feature_report dq _hid_get_feature_report
	hid_get_indexed_string db 'hid_get_indexed_string', 0
	__imp_hid_get_indexed_string dq _hid_get_indexed_string
	hid_get_manufacturer_string db 'hid_get_manufacturer_string', 0
	__imp_hid_get_manufacturer_string dq _hid_get_manufacturer_string
	hid_get_product_string db 'hid_get_product_string', 0
	__imp_hid_get_product_string dq _hid_get_product_string
	hid_get_serial_number_string db 'hid_get_serial_number_string', 0
	__imp_hid_get_serial_number_string dq _hid_get_serial_number_string
	hid_init db 'hid_init', 0
	__imp_hid_init dq _hid_init
	hid_open db 'hid_open', 0
	__imp_hid_open dq _hid_open
	hid_open_path db 'hid_open_path', 0
	__imp_hid_open_path dq _hid_open_path
	hid_read db 'hid_read', 0
	__imp_hid_read dq _hid_read
	hid_read_timeout db 'hid_read_timeout', 0
	__imp_hid_read_timeout dq _hid_read_timeout
	hid_send_feature_report db 'hid_send_feature_report', 0
	__imp_hid_send_feature_report dq _hid_send_feature_report
	hid_set_nonblocking db 'hid_set_nonblocking', 0
	__imp_hid_set_nonblocking dq _hid_set_nonblocking
	hid_write db 'hid_write', 0
	__imp_hid_write dq _hid_write
