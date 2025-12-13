TITLE	codigo.c
.686
.XMM
.model 	flat
_DATA	SEGMENT
COMM	?r@@:DWORD
COMM	?h@@:DWORD:02H
COMM	?i@@:DWORD
_DATA	ENDS
_CONST	SEGMENT
__real@9999999a	DD	09999999ar
__real@00000000	DD	000000000r
__real@00000000	DD	000000000r
??@18@@	DB	05H, 00H
??@21@@	DB	05H, 00H
??@27@@	DB	, 00H
_CONST	ENDS
_TEXT	SEGMENT
_a$ = 8
_b$ = 12
_@1$ = 16
_myfunc	PROC
	push	ebp
	mov		ebp, esp
	sub		esp, 64
	push	ebx	
	push	esi	
	push	edi	
	mov		eax, DWORD PTR _b$[ebp]
	mul		DWORD PTR _b$[ebp]
	mov		DWORD PTR _b$[ebp], eax
	mov		eax, DWORD PTR _@1$[ebp]
	fld		eax
	jmp		SHORT $exit@myfunc
$exit@myfunc:
	pop		edi
	pop		esi
	pop		ebx
	mov		esp, ebp
	pop		ebp
	ret		0
_myfunc	ENDP
_TEXT	ENDS
_TEXT	SEGMENT
_x$ = -8
_@5$ = -12
_y$ = -16
_@8$ = -20
_z$ = -24
_@11$ = -28
_@13$ = -32
_@14$ = -36
_@16$ = -44
_@20$ = -48
_@23$ = -52
_@26$ = -56
_@31$ = -60
_@32$ = -64
_@34$ = -68
_@28$ = -72
_main	PROC
	push	ebp
	mov		ebp, esp
	sub		esp, 136
	push	ebx	
	push	esi	
	push	edi	
	movss	xmm0, DWORD PTR __real@9999999a
	movss	DWORD PTR _x$[ebp], xmm0
	mov		DWORD PTR _@4$[ebp], 0
	movss	xmm0, DWORD PTR _@5$[ebp]
	movss	DWORD PTR _y$[ebp], xmm0
	mov		eax, 6
	add		eax, 5
	mov		DWORD PTR _@7$[ebp], eax
	mov		eax, DWORD PTR _@8$[ebp]
	mov		DWORD PTR _z$[ebp], eax
	mov		DWORD PTR _@10$[ebp], 12
	xor		edx, edx
	mov		eax, DWORD PTR _@12$[ebp]
	div		2
	mov		DWORD PTR _@12$[ebp], eax
	mov		eax, DWORD PTR _@13$[ebp]
	sub		eax, DWORD PTR _@13$[ebp]
	mov		DWORD PTR _@13$[ebp], eax
	mov		eax, DWORD PTR _@14$[ebp]
	mov		DWORD PTR ?r@@, eax
	movss	xmm0, DWORD PTR _@15$[ebp]
	mulss	xmm0, DWORD PTR __real@00000000
	movss	DWORD PTR _@15$[ebp], xmm0
	movss	xmm0, DWORD PTR _@16$[ebp]
	movss	DWORD PTR _y$[ebp], xmm0
	mov		eax, 0
	cmp		eax, 3
	jg		SHORT $LN18@main
	jmp		SHORT $LN22@main
$LN18@main:
	push	5
	push	OFFSET _??@18@@
	call	_printf
	add		esp, 8
	mov		_$[ebp], eax
	jmp		SHORT $LN25@main
$LN22@main:
	push	5
	push	OFFSET _??@21@@
	call	_printf
	add		esp, 8
	mov		_$[ebp], eax
$LN25@main:
	mov		DWORD PTR ?i@@, 0
$LN26@main:
	cmp		DWORD PTR _@25$[ebp], 5
	jl		SHORT $LN31@main
	jmp		SHORT $LN35@main
$LN28@main:
	mov		eax, DWORD PTR ?i@@
	mov		DWORD PTR _@26$[ebp], eax
	mov		eax, DWORD PTR ?i@@
	add		eax, 1
	mov		DWORD PTR ?i@@, eax
	jmp		SHORT $LN26@main
$LN31@main:
	push	DWORD PTR ?i@@
	push	OFFSET _??@27@@
	call	_printf
	add		esp, 8
	mov		_$[ebp], eax
	jmp		SHORT $LN28@main
$LN35@main:
	mov		DWORD PTR _@30$[ebp], 4
	mov		eax, DWORD PTR _@31$[ebp]
	mov		ebx, DWORD PTR _?h@@$[ebp+eax]
	mov		DWORD PTR _@32$[ebp], ebx
	push	5
	push	DWORD PTR _@32$[ebp]
	call	_myfunc
	add		esp, 8
	fstp	_$[ebp]
	mov		eax, DWORD PTR _@34$[ebp]
	mov		DWORD PTR _z$[ebp], eax
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

