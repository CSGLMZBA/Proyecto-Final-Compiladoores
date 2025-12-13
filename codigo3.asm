TITLE	codigo3.c
.686
.XMM
.model 	flat
_DATA	SEGMENT
_DATA	ENDS
_CONST	SEGMENT
??@1@@	DB	, 00H
??@3@@	DB	, 00H
??@5@@	DB	, 00H
??@7@@	DB	, 00H
??@9@@	DB	, 00H
??@11@@	DB	, 00H
??@26@@	DB	, 00H
??@15@@	DB	, 00H
??@18@@	DB	, 00H
??@21@@	DB	, 00H
??@24@@	DB	, 00H
_CONST	ENDS
_TEXT	SEGMENT
_c$ = -4
_@2$ = -8
_@4$ = -12
_@6$ = -16
_@8$ = -20
_@10$ = -24
_@12$ = -28
_@27$ = -32
_@16$ = -36
_@19$ = -40
_@22$ = -44
_@25$ = -48
_main	PROC
	push	ebp
	mov		ebp, esp
	sub		esp, 112
	push	ebx	
	push	esi	
	push	edi	
	mov		DWORD PTR _c$[ebp], 0
	push	OFFSET _??@1@@
	call	_printf
	add		esp, 4
	mov		_$[ebp], eax
	push	OFFSET _??@3@@
	call	_printf
	add		esp, 4
	mov		_$[ebp], eax
	push	OFFSET _??@5@@
	call	_printf
	add		esp, 4
	mov		_$[ebp], eax
	push	OFFSET _??@7@@
	call	_printf
	add		esp, 4
	mov		_$[ebp], eax
	push	OFFSET _??@9@@
	call	_printf
	add		esp, 4
	mov		_$[ebp], eax
	push	OFFSET _??@11@@
	call	_printf
	add		esp, 4
	mov		_$[ebp], eax
	cmp		DWORD PTR _@13$[ebp], 16640
	jne		SHORT $LN16@main
	jmp		SHORT $LN36@main
$LN16@main:
	cmp		DWORD PTR _@14$[ebp], 65
	je		SHORT $LN18@main
	jmp		SHORT $LN21@main
$LN18@main:
	push	OFFSET _??@15@@
	call	_printf
	add		esp, 4
	mov		_$[ebp], eax
	jmp		SHORT $LN38@main
$LN21@main:
	cmp		DWORD PTR _@17$[ebp], 66
	je		SHORT $LN23@main
	jmp		SHORT $LN26@main
$LN23@main:
	push	OFFSET _??@18@@
	call	_printf
	add		esp, 4
	mov		_$[ebp], eax
	jmp		SHORT $LN38@main
$LN26@main:
	cmp		DWORD PTR _@20$[ebp], 79
	je		SHORT $LN28@main
	jmp		SHORT $LN31@main
$LN28@main:
	push	OFFSET _??@21@@
	call	_printf
	add		esp, 4
	mov		_$[ebp], eax
	jmp		SHORT $LN38@main
$LN31@main:
	cmp		DWORD PTR _@23$[ebp], 73
	je		SHORT $LN33@main
	jmp		SHORT $LN38@main
$LN33@main:
	push	OFFSET _??@24@@
	call	_printf
	add		esp, 4
	mov		_$[ebp], eax
	jmp		SHORT $LN38@main
$LN36@main:
	push	OFFSET _??@26@@
	call	_printf
	add		esp, 4
	mov		_$[ebp], eax
$LN38@main:
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

