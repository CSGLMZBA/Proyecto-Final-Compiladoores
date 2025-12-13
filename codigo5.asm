TITLE	codigo5.c
.686
.XMM
.model 	flat
_DATA	SEGMENT
_DATA	ENDS
_CONST	SEGMENT
??@0@@	DB	, 00H
??@2@@	DB	, 00H
??@4@@	DB	, 00H
??@6@@	DB	, 00H
??@8@@	DB	, 00H
??@12@@	DB	, 00H
??@15@@	DB	, 00H
??@18@@	DB	, 00H
_CONST	ENDS
_TEXT	SEGMENT
_seleccion$ = -1
_@1$ = -5
_@3$ = -9
_@5$ = -13
_@7$ = -17
_@9$ = -21
_@13$ = -25
_@16$ = -29
_@19$ = -33
_main	PROC
	push	ebp
	mov		ebp, esp
	sub		esp, 96
	push	ebx	
	push	esi	
	push	edi	
$LN1@main:
	push	OFFSET _??@0@@
	call	_printf
	add		esp, 4
	mov		_$[ebp], eax
	push	OFFSET _??@2@@
	call	_printf
	add		esp, 4
	mov		_$[ebp], eax
	push	OFFSET _??@4@@
	call	_printf
	add		esp, 4
	mov		_$[ebp], eax
	push	OFFSET _??@6@@
	call	_printf
	add		esp, 4
	mov		_$[ebp], eax
	push	OFFSET _??@8@@
	call	_printf
	add		esp, 4
	mov		_$[ebp], eax
	mov		DWORD PTR _seleccion$[ebp], 4
	jmp		SHORT $LN22@main
$LN13@main:
	push	OFFSET _??@12@@
	call	_printf
	add		esp, 4
	mov		_$[ebp], eax
	jmp		SHORT $LN25@main
$LN16@main:
	push	OFFSET _??@15@@
	call	_printf
	add		esp, 4
	mov		_$[ebp], eax
	jmp		SHORT $LN25@main
$LN19@main:
	push	OFFSET _??@18@@
	call	_printf
	add		esp, 4
	mov		_$[ebp], eax
	jmp		SHORT $LN25@main
$LN22@main:
	cmp		DWORD PTR _@20$[ebp], 49
	je		SHORT $LN13@main
	cmp		DWORD PTR _@21$[ebp], 50
	je		SHORT $LN16@main
	cmp		DWORD PTR _@22$[ebp], 51
	je		SHORT $LN19@main
$LN25@main:
	cmp		DWORD PTR _@23$[ebp], 52
	jne		SHORT $LN1@main
	jmp		SHORT $LN27@main
$LN27@main:
	mov		eax, 0
	jmp		SHORT $exit@main
$exit@main:
	pop		edi
	pop		esi
	pop		ebx
	mov		esp, ebp
	pop		ebp
	ret		0
_main	ENDP
_TEXT	ENDS
END

