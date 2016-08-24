BITS 64

extern _dlclose
extern _dlopen
extern _dlsym


global _Steam_FreeLastCallback
global _Steam_BGetCallback
global _Steam_GetAPICallResult


%macro saveReg 0
	push	rdi
	push	rsi
	push	rdx
	push	rcx
	push	r8
	push	r9
%endmacro

%macro restoreReg 0
	pop 	r9
	pop		r8
	pop		rcx
	pop		rdx
	pop		rsi
	pop		rdi
%endmacro


section .data

szModulePath:  db '@loader_path/steamclient.dylib', 0
phModule: dq 0
szSteam_GetAPICallResult: db 'Steam_GetAPICallResult', 0
pSteam_GetAPICallResult: dq 0
szSteam_FreeLastCallback: db 'Steam_FreeLastCallback', 0
pSteam_FreeLastCallback: dq 0
szSteam_BGetCallback: db 'Steam_BGetCallback', 0
pSteam_BGetCallback: dq 0

section .text

_Steam_FreeLastCallback:
	mov		rax, [rel pSteam_FreeLastCallback]
	cmp		rax, 0
	jz		.Steam_FreeLastCallback_loader
	jmp		rax
.Steam_FreeLastCallback_loader:
	saveReg
	mov		rsi, 1
	lea		rdi, [rel szModulePath]
    sub     rsp, 56
	call	_dlopen
	lea		rcx, [rel phModule]
	mov		[rcx], rax
	lea		rsi, [rel szSteam_FreeLastCallback]
	mov		rdi, rax
	call	_dlsym
	lea		rcx, [rel pSteam_FreeLastCallback]
	mov		[rcx], rax
	mov		rdi, [rel phModule]
	call	_dlclose
    add     rsp, 56
	restoreReg
	jmp		[rel pSteam_FreeLastCallback]

_Steam_BGetCallback:
	mov		rax, [rel pSteam_BGetCallback]
	cmp		rax, 0
	jz		.Steam_BGetCallback_loader
	jmp		rax
.Steam_BGetCallback_loader:
	saveReg
	mov		rsi, 1
	lea		rdi, [rel szModulePath]
    sub     rsp, 56
	call	_dlopen
	lea		rcx, [rel phModule]
	mov		[rcx], rax
	lea		rsi, [rel szSteam_BGetCallback]
	mov		rdi, rax
	call	_dlsym
	lea		rcx, [rel pSteam_BGetCallback]
	mov		[rcx], rax
	mov		rdi, [rel phModule]
	call	_dlclose
    add     rsp, 56
	restoreReg
	jmp		[rel pSteam_BGetCallback]

_Steam_GetAPICallResult:
	mov		rax, [rel pSteam_GetAPICallResult]
	cmp		rax, 0
	jz		.Steam_GetAPICallResult_loader
	jmp		rax
.Steam_GetAPICallResult_loader:
	saveReg
	mov		rsi, 1
	lea		rdi, [rel szModulePath]
    sub     rsp, 56
	call	_dlopen
	lea		rcx, [rel phModule]
	mov		[rcx], rax
	lea		rsi, [rel szSteam_GetAPICallResult]
	mov		rdi, rax
	call	_dlsym
	lea		rcx, [rel pSteam_GetAPICallResult]
	mov		[rcx], rax
	mov		rdi, [rel phModule]
	call	_dlclose
    add     rsp, 56
	restoreReg
	jmp		[rel pSteam_GetAPICallResult]
