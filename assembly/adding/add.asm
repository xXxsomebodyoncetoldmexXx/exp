extern printf, scanf

SECTION .bss
	x resb 4
	y resb 4

SECTION .text
GLOBAL main

main:
	push ebp			;Save stack

	push msg 			;Dest
	xor eax, eax  ;Clear return value
	call printf
	; pop eax				;Clear stack
	; add esp, 4		;Clear stack

	push prmp
	xor eax, eax
	call printf

	push y 				;Source
	push x 				;Source
	push fmt 			;Dest
	xor eax, eax 	;Clear return value
	call scanf
	; pop eax 			;Clear stack
	; pop eax				;Clear stack
	; add esp, 8		;Clear stack

	mov eax, [x]	;Get value of x
	mov ebx, [y]	;Get value of y
	add eax, ebx	;Add together to eax

	push eax 			;Source
	push omt 			;Dest
	xor eax, eax	;Clear return value
	call printf
	; pop eax				;Clear stack
	; pop eax				;Clear stack
	add esp, 4*7;Clear stack

	pop ebp				;Return stack pointer

	xor eax, eax	;Return value good
	ret

SECTION .data
	msg:	db	"Adding machine", 0xA, 0
	prmp: db	">> ", 0
	fmt:	db	"%d %d", 0
	omt:	db	"= %d", 0xA, 0
