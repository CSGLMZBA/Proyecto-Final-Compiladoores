TITLE	codigo2.c
.686
.XMM
.model 	flat
_DATA	SEGMENT
_DATA	ENDS
_CONST	SEGMENT
??@0@@	DB	, 00H
??@104@@	DB	, 00H
??@107@@	DB	, 00H
??@110@@	DB	, 00H
??@113@@	DB	, 00H
??@116@@	DB	, 00H
??@119@@	DB	, 00H
??@122@@	DB	, 00H
??@125@@	DB	, 00H
??@128@@	DB	, 00H
??@68@@	DB	, 00H
??@71@@	DB	, 00H
??@74@@	DB	, 00H
??@77@@	DB	, 00H
??@80@@	DB	, 00H
??@83@@	DB	, 00H
??@86@@	DB	, 00H
??@89@@	DB	, 00H
??@92@@	DB	, 00H
??@32@@	DB	, 00H
??@35@@	DB	, 00H
??@38@@	DB	, 00H
??@41@@	DB	, 00H
??@44@@	DB	, 00H
??@47@@	DB	, 00H
??@50@@	DB	, 00H
??@53@@	DB	, 00H
??@56@@	DB	, 00H
??@20@@	DB	, 00H
??@23@@	DB	, 00H
??@26@@	DB	, 00H
_CONST	ENDS
_TEXT	SEGMENT
_numero$ = -4
_unidades$ = -8
_decenas$ = -12
_centenas$ = -16
_millar$ = -20
_@1$ = -24
_@4$ = -28
_@6$ = -32
_@8$ = -36
_@10$ = -40
_@12$ = -44
_@14$ = -48
_@16$ = -52
_@18$ = -56
_@105$ = -60
_@108$ = -64
_@111$ = -68
_@114$ = -72
_@117$ = -76
_@120$ = -80
_@123$ = -84
_@126$ = -88
_@129$ = -92
_@69$ = -96
_@72$ = -100
_@75$ = -104
_@78$ = -108
_@81$ = -112
_@84$ = -116
_@87$ = -120
_@90$ = -124
_@93$ = -128
_@33$ = -132
_@36$ = -136
_@39$ = -140
_@42$ = -144
_@45$ = -148
_@48$ = -152
_@51$ = -156
_@54$ = -160
_@57$ = -164
_@21$ = -168
_@24$ = -172
_@27$ = -176
_main	PROC
	push	ebp
	mov		ebp, esp
	sub		esp, 240
	push	ebx	
	push	esi	
	push	edi	
	push	OFFSET _??@0@@
	call	_printf
	add		esp, 4
	mov		_$[ebp], eax
	mov		DWORD PTR _numero$[ebp], 58
	mov		eax, DWORD PTR _@3$[ebp]
	cdq
	idiv	10
	mov		DWORD PTR _@3$[ebp], edx
	mov		eax, DWORD PTR _@4$[ebp]
	mov		DWORD PTR _unidades$[ebp], eax
	xor		edx, edx
	mov		eax, DWORD PTR _@5$[ebp]
	div		10
	mov		DWORD PTR _@5$[ebp], eax
	mov		eax, DWORD PTR _@6$[ebp]
	mov		DWORD PTR _numero$[ebp], eax
	mov		eax, DWORD PTR _@7$[ebp]
	cdq
	idiv	10
	mov		DWORD PTR _@7$[ebp], edx
	mov		eax, DWORD PTR _@8$[ebp]
	mov		DWORD PTR _decenas$[ebp], eax
	xor		edx, edx
	mov		eax, DWORD PTR _@9$[ebp]
	div		10
	mov		DWORD PTR _@9$[ebp], eax
	mov		eax, DWORD PTR _@10$[ebp]
	mov		DWORD PTR _numero$[ebp], eax
	mov		eax, DWORD PTR _@11$[ebp]
	cdq
	idiv	10
	mov		DWORD PTR _@11$[ebp], edx
	mov		eax, DWORD PTR _@12$[ebp]
	mov		DWORD PTR _centenas$[ebp], eax
	xor		edx, edx
	mov		eax, DWORD PTR _@13$[ebp]
	div		10
	mov		DWORD PTR _@13$[ebp], eax
	mov		eax, DWORD PTR _@14$[ebp]
	mov		DWORD PTR _numero$[ebp], eax
	mov		eax, DWORD PTR _@15$[ebp]
	cdq
	idiv	10
	mov		DWORD PTR _@15$[ebp], edx
	mov		eax, DWORD PTR _@16$[ebp]
	mov		DWORD PTR _millar$[ebp], eax
	xor		edx, edx
	mov		eax, DWORD PTR _@17$[ebp]
	div		10
	mov		DWORD PTR _@17$[ebp], eax
	mov		eax, DWORD PTR _@18$[ebp]
	mov		DWORD PTR _numero$[ebp], eax
	jmp		SHORT $LN31@main
$LN21@main:
	push	OFFSET _??@20@@
	call	_printf
	add		esp, 4
	mov		_$[ebp], eax
	jmp		SHORT $LN34@main
$LN24@main:
	push	OFFSET _??@23@@
	call	_printf
	add		esp, 4
	mov		_$[ebp], eax
	jmp		SHORT $LN34@main
$LN27@main:
	push	OFFSET _??@26@@
	call	_printf
	add		esp, 4
	mov		_$[ebp], eax
	jmp		SHORT $LN34@main
	jmp		SHORT $LN34@main
$LN31@main:
	cmp		DWORD PTR _@28$[ebp], 1
	je		SHORT $LN21@main
	cmp		DWORD PTR _@29$[ebp], 2
	je		SHORT $LN24@main
	cmp		DWORD PTR _@30$[ebp], 3
	je		SHORT $LN27@main
$LN34@main:
	jmp		SHORT $LN63@main
$LN35@main:
	push	OFFSET _??@32@@
	call	_printf
	add		esp, 4
	mov		_$[ebp], eax
	jmp		SHORT $LN72@main
$LN38@main:
	push	OFFSET _??@35@@
	call	_printf
	add		esp, 4
	mov		_$[ebp], eax
	jmp		SHORT $LN72@main
$LN41@main:
	push	OFFSET _??@38@@
	call	_printf
	add		esp, 4
	mov		_$[ebp], eax
	jmp		SHORT $LN72@main
$LN44@main:
	push	OFFSET _??@41@@
	call	_printf
	add		esp, 4
	mov		_$[ebp], eax
	jmp		SHORT $LN72@main
$LN47@main:
	push	OFFSET _??@44@@
	call	_printf
	add		esp, 4
	mov		_$[ebp], eax
	jmp		SHORT $LN72@main
$LN50@main:
	push	OFFSET _??@47@@
	call	_printf
	add		esp, 4
	mov		_$[ebp], eax
	jmp		SHORT $LN72@main
$LN53@main:
	push	OFFSET _??@50@@
	call	_printf
	add		esp, 4
	mov		_$[ebp], eax
	jmp		SHORT $LN72@main
$LN56@main:
	push	OFFSET _??@53@@
	call	_printf
	add		esp, 4
	mov		_$[ebp], eax
	jmp		SHORT $LN72@main
$LN59@main:
	push	OFFSET _??@56@@
	call	_printf
	add		esp, 4
	mov		_$[ebp], eax
	jmp		SHORT $LN72@main
	jmp		SHORT $LN72@main
$LN63@main:
	cmp		DWORD PTR _@58$[ebp], 1
	je		SHORT $LN35@main
	cmp		DWORD PTR _@59$[ebp], 2
	je		SHORT $LN38@main
	cmp		DWORD PTR _@60$[ebp], 3
	je		SHORT $LN41@main
	cmp		DWORD PTR _@61$[ebp], 4
	je		SHORT $LN44@main
	cmp		DWORD PTR _@62$[ebp], 5
	je		SHORT $LN47@main
	cmp		DWORD PTR _@63$[ebp], 6
	je		SHORT $LN50@main
	cmp		DWORD PTR _@64$[ebp], 7
	je		SHORT $LN53@main
	cmp		DWORD PTR _@65$[ebp], 8
	je		SHORT $LN56@main
	cmp		DWORD PTR _@66$[ebp], 9
	je		SHORT $LN59@main
$LN72@main:
	jmp		SHORT $LN101@main
$LN73@main:
	push	OFFSET _??@68@@
	call	_printf
	add		esp, 4
	mov		_$[ebp], eax
	jmp		SHORT $LN110@main
$LN76@main:
	push	OFFSET _??@71@@
	call	_printf
	add		esp, 4
	mov		_$[ebp], eax
	jmp		SHORT $LN110@main
$LN79@main:
	push	OFFSET _??@74@@
	call	_printf
	add		esp, 4
	mov		_$[ebp], eax
	jmp		SHORT $LN110@main
$LN82@main:
	push	OFFSET _??@77@@
	call	_printf
	add		esp, 4
	mov		_$[ebp], eax
	jmp		SHORT $LN110@main
$LN85@main:
	push	OFFSET _??@80@@
	call	_printf
	add		esp, 4
	mov		_$[ebp], eax
	jmp		SHORT $LN110@main
$LN88@main:
	push	OFFSET _??@83@@
	call	_printf
	add		esp, 4
	mov		_$[ebp], eax
	jmp		SHORT $LN110@main
$LN91@main:
	push	OFFSET _??@86@@
	call	_printf
	add		esp, 4
	mov		_$[ebp], eax
	jmp		SHORT $LN110@main
$LN94@main:
	push	OFFSET _??@89@@
	call	_printf
	add		esp, 4
	mov		_$[ebp], eax
	jmp		SHORT $LN110@main
$LN97@main:
	push	OFFSET _??@92@@
	call	_printf
	add		esp, 4
	mov		_$[ebp], eax
	jmp		SHORT $LN110@main
	jmp		SHORT $LN110@main
$LN101@main:
	cmp		DWORD PTR _@94$[ebp], 1
	je		SHORT $LN73@main
	cmp		DWORD PTR _@95$[ebp], 2
	je		SHORT $LN76@main
	cmp		DWORD PTR _@96$[ebp], 3
	je		SHORT $LN79@main
	cmp		DWORD PTR _@97$[ebp], 4
	je		SHORT $LN82@main
	cmp		DWORD PTR _@98$[ebp], 5
	je		SHORT $LN85@main
	cmp		DWORD PTR _@99$[ebp], 6
	je		SHORT $LN88@main
	cmp		DWORD PTR _@100$[ebp], 7
	je		SHORT $LN91@main
	cmp		DWORD PTR _@101$[ebp], 8
	je		SHORT $LN94@main
	cmp		DWORD PTR _@102$[ebp], 9
	je		SHORT $LN97@main
$LN110@main:
	jmp		SHORT $LN139@main
$LN111@main:
	push	OFFSET _??@104@@
	call	_printf
	add		esp, 4
	mov		_$[ebp], eax
	jmp		SHORT $LN148@main
$LN114@main:
	push	OFFSET _??@107@@
	call	_printf
	add		esp, 4
	mov		_$[ebp], eax
	jmp		SHORT $LN148@main
$LN117@main:
	push	OFFSET _??@110@@
	call	_printf
	add		esp, 4
	mov		_$[ebp], eax
	jmp		SHORT $LN148@main
$LN120@main:
	push	OFFSET _??@113@@
	call	_printf
	add		esp, 4
	mov		_$[ebp], eax
	jmp		SHORT $LN148@main
$LN123@main:
	push	OFFSET _??@116@@
	call	_printf
	add		esp, 4
	mov		_$[ebp], eax
	jmp		SHORT $LN148@main
$LN126@main:
	push	OFFSET _??@119@@
	call	_printf
	add		esp, 4
	mov		_$[ebp], eax
	jmp		SHORT $LN148@main
$LN129@main:
	push	OFFSET _??@122@@
	call	_printf
	add		esp, 4
	mov		_$[ebp], eax
	jmp		SHORT $LN148@main
$LN132@main:
	push	OFFSET _??@125@@
	call	_printf
	add		esp, 4
	mov		_$[ebp], eax
	jmp		SHORT $LN148@main
$LN135@main:
	push	OFFSET _??@128@@
	call	_printf
	add		esp, 4
	mov		_$[ebp], eax
	jmp		SHORT $LN148@main
	jmp		SHORT $LN148@main
$LN139@main:
	cmp		DWORD PTR _@130$[ebp], 1
	je		SHORT $LN111@main
	cmp		DWORD PTR _@131$[ebp], 2
	je		SHORT $LN114@main
	cmp		DWORD PTR _@132$[ebp], 3
	je		SHORT $LN117@main
	cmp		DWORD PTR _@133$[ebp], 4
	je		SHORT $LN120@main
	cmp		DWORD PTR _@134$[ebp], 5
	je		SHORT $LN123@main
	cmp		DWORD PTR _@135$[ebp], 6
	je		SHORT $LN126@main
	cmp		DWORD PTR _@136$[ebp], 7
	je		SHORT $LN129@main
	cmp		DWORD PTR _@137$[ebp], 8
	je		SHORT $LN132@main
	cmp		DWORD PTR _@138$[ebp], 9
	je		SHORT $LN135@main
$LN148@main:
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

