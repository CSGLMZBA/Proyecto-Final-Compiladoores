TITLE	codigo4.c
.686
.XMM
.model 	flat
_DATA	SEGMENT
_DATA	ENDS
_CONST	SEGMENT
??@3@@	DB	, 00H
??@19@@	DB	, 00H
??@21@@	DB	, 00H
_CONST	ENDS
_TEXT	SEGMENT
_palabra$ = -50
_f$ = -54
_vocales$ = -58
_consonantes$ = -62
_@4$ = -66
_@7$ = -70
_@20$ = -74
_@22$ = -78
_@9$ = -82
_@10$ = -83
_@16$ = -87
_@17$ = -91
_main	PROC
	push	ebp
	mov		ebp, esp
	sub		esp, 152
	push	ebx	
	push	esi	
	push	edi	
	mov		DWORD PTR _vocales$[ebp], 0
	mov		DWORD PTR _consonantes$[ebp], 0
	push	OFFSET _??@3@@
	call	_printf
	add		esp, 4
	mov		_$[ebp], eax
	mov		DWORD PTR _f$[ebp], 0
$LN6@main:
	cmp		DWORD PTR _@6$[ebp], 50
	jl		SHORT $LN11@main
	jmp		SHORT $LN23@main
$LN8@main:
	mov		eax, DWORD PTR _f$[ebp]
	mov		DWORD PTR _@7$[ebp], eax
	mov		eax, DWORD PTR _f$[ebp]
	add		eax, 1
	mov		DWORD PTR _f$[ebp], eax
	jmp		SHORT $LN6@main
$LN11@main:
	mov		eax, DWORD PTR _@8$[ebp]
	mul		1
	mov		DWORD PTR _@8$[ebp], eax
	mov		eax, DWORD PTR _@9$[ebp]
	mov		ebx, DWORD PTR _palabra$[ebp+eax]
	mov		DWORD PTR _@10$[ebp], ebx
	jmp		SHORT $LN20@main
$LN14@main:
	mov		eax, DWORD PTR _vocales$[ebp]
	mov		DWORD PTR _@16$[ebp], eax
	mov		eax, DWORD PTR _vocales$[ebp]
	add		eax, 1
	mov		DWORD PTR _vocales$[ebp], eax
	jmp		SHORT $LN22@main
$LN17@main:
	mov		eax, DWORD PTR _consonantes$[ebp]
	mov		DWORD PTR _@17$[ebp], eax
	mov		eax, DWORD PTR _consonantes$[ebp]
	add		eax, 1
	mov		DWORD PTR _consonantes$[ebp], eax
	jmp		SHORT $LN22@main
$LN20@main:
	cmp		DWORD PTR _@18$[ebp], 97
	je		SHORT $LN14@main
	jmp		SHORT $LN17@main
$LN22@main:
	jmp		SHORT $LN8@main
$LN23@main:
	push	DWORD PTR _vocales$[ebp]
	push	OFFSET _??@19@@
	call	_printf
	add		esp, 8
	mov		_$[ebp], eax
	push	DWORD PTR _consonantes$[ebp]
	push	OFFSET _??@21@@
	call	_printf
	add		esp, 8
	mov		_$[ebp], eax
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

