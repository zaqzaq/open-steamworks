; handmade with lots of hate

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

	public _CreateInterface
	public __imp_CreateInterface
	public _Steam_BGetCallback
	public __imp_Steam_BGetCallback
	public _Steam_FreeLastCallback
	public __imp_Steam_FreeLastCallback
	public _Steam_GetAPICallResult
	public __imp_Steam_GetAPICallResult


	_CreateInterface:
		SaveReg
		invoke	GetModuleHandleA,clientDll
		invoke	GetProcAddress,rax,CreateInterface
		mov	[__imp_CreateInterface], rax
		RestoreReg
		jmp	rax

	_Steam_BGetCallback:
		SaveReg
		invoke	GetModuleHandleA,clientDll
		invoke	GetProcAddress,rax,Steam_BGetCallback
		mov	[__imp_Steam_BGetCallback], rax
		RestoreReg
		jmp	rax

	_Steam_FreeLastCallback:
		SaveReg
		invoke	GetModuleHandleA,clientDll
		invoke	GetProcAddress,rax,Steam_FreeLastCallback
		mov	[__imp_Steam_FreeLastCallback], rax
		RestoreReg
		jmp	rax

	_Steam_GetAPICallResult:
		SaveReg
		invoke	GetModuleHandleA,clientDll
		invoke	GetProcAddress,rax,Steam_GetAPICallResult
		mov	[__imp_Steam_GetAPICallResult], rax
		RestoreReg
		jmp	rax




section '.data' data readable writeable

	clientDll db 'steamclient64.dll', 0
	CreateInterface db 'CreateInterface', 0
	__imp_CreateInterface dq _CreateInterface
	Steam_BGetCallback db 'Steam_BGetCallback', 0
	__imp_Steam_BGetCallback dq _Steam_BGetCallback
	Steam_FreeLastCallback db 'Steam_FreeLastCallback', 0
	__imp_Steam_FreeLastCallback dq _Steam_FreeLastCallback
	Steam_GetAPICallResult db 'Steam_GetAPICallResult', 0
	__imp_Steam_GetAPICallResult dq _Steam_GetAPICallResult
