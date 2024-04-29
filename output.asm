sys_exit	equ 1
sys_read	equ 3
sys_write	equ 4
stdin		equ 0
stdout		equ 1
stderr		equ 3

section .data
	userMsg			db	'Enter an integer(less than 32,765): '
	lenUserMsg		equ	$-userMsg
	displayMsg		db	'You entered: '
	lenDisplayMsg	equ	$-displayMsg
	newline			db	0xA


	Ten				DW	10


	Result			db	'Ans= '
	ResultValue		db	'aaaaa'
	db	0xA
	ResultEnd		equ	$-Result


	num				times	6	db'ABCDEF'
	numEnd			equ	$-num


	J			DW	1
	Lit1			DW	1
	Lit2			DW	2
	Lit3			DW	3
	Lit4			DW	4
section .bss
	TempChar	RESB	1
	testchar	RESB	1
	ReadInt		RESW	1
	tempint		RESW	1
	negflag		RESB	1
	A		RESW	1
	B		RESW	1
	C		RESW	1
	D		RESW	1
	E		RESW	1
	ANSWER		RESW	1
	Temp1		RESW	1
	Temp2		RESW	1
	Temp3		RESW	1
	Temp4		RESW	1
	Temp5		RESW	1
	Temp6		RESW	1
	Temp7		RESW	1
	Temp8		RESW	1
	Temp9		RESW	1
	Temp10		RESW	1


global _start
section .text
_start: nop
	call PrintString
	call GetAnInteger
	mov ax, [ReadInt]
	mov [A], ax

	call PrintString
	call GetAnInteger
	mov ax, [ReadInt]
	mov [B], ax

	call PrintString
	call GetAnInteger
	mov ax, [ReadInt]
	mov [C], ax

	call PrintString
	call GetAnInteger
	mov ax, [ReadInt]
	mov [D], ax

	call PrintString
	call GetAnInteger
	mov ax, [ReadInt]
	mov [E], ax

W1:

	mov ax, [A]
	cmp ax, [J] 
	JLE L1

W2:

	mov ax, [B]
	cmp ax, [A] 
	JLE L2

W3:

	mov ax, [C]
	cmp ax, [B] 
	JLE L3

W4:

	mov ax, [D]
	cmp ax, [C] 
	JLE L4

W5:

	mov ax, [E]
	cmp ax, [D] 
	JLE L5

	mov ax, [E]
	sub ax, [Lit1]
	mov [Temp1], ax

	mov ax, [Temp1]
	mov [E], ax

	jmp W5

L5: nop

	mov ax, [D]
	sub ax, [Lit2]
	mov [Temp2], ax

	mov ax, [Temp2]
	mov [D], ax

	jmp W4

L4: nop

	mov ax, [C]
	sub ax, [Lit3]
	mov [Temp3], ax

	mov ax, [Temp3]
	mov [C], ax

	jmp W3

L3: nop

	mov ax, [B]
	sub ax, [Lit4]
	mov [Temp4], ax

	mov ax, [Temp4]
	mov [B], ax

	jmp W2

L2: nop

	mov ax, [A]
	sub ax, [Lit1]
	mov [Temp5], ax

	mov ax, [Temp5]
	mov [ANSWER], ax

	jmp W1

L1: nop

	mov ax, [ANSWER]
	call ConvertIntegerToString

	mov eax, 4
	mov ebx, 1
	mov ecx, Result
	mov edx, ResultEnd
	int 80h


fini:
	mov	eax, sys_exit
	xor	ebx, ebx
	int	80h

PrintString:
	push	ax
	push	dx
	mov	eax, 4
	mov	ebx, 1

	mov	ecx, userMsg
	mov	edx, lenUserMsg
	int	80h
	pop	dx
	pop	ax
	ret

GetAnInteger:
	mov	eax, 3
	mov	ebx, 2
	mov	ecx, num
	mov	edx, 6
	int	0x80

	mov	edx, eax
	mov	eax, 4
	mov	ebx, 1
	mov	ecx, num
	int	80h

ConvertStringToInteger:
	mov	ax, 0
	mov	[ReadInt],ax
	mov	ecx, num
	mov	bx, 0
	mov	bl, byte [ecx]
Next:
	sub	bl,'0'
	mov	ax, [ReadInt]
	mov	dx, 10
	mul	dx
	add	ax, bx
	mov	[ReadInt],ax

	mov bx, 0
	add ecx, 1
	mov	bl, byte [ecx]

	cmp	bl,0xA
	jne	Next
	ret

ConvertIntegerToString:
	mov	ebx, ResultValue + 4
ConvertLoop:
	sub	dx, dx
	mov	cx, 10
	div	cx
	add	dl, '0'
	mov	[ebx], dl
	dec	ebx
	cmp	ebx, ResultValue
	jge	ConvertLoop
	ret

