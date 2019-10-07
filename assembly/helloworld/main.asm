extern printf

SECTION .data
	msg:	db "Hello world", 0
	fmt:	db "%s", 0xA, 0
	res: 	db "= %d", 0

SECTION .text

GLOBAL main

	main:
	push ebp

	; mov edi, fmt
	; mov esi, msg
	push msg
	push fmt
	mov eax, 0
	call printf
	
	pop ebp
	pop ebp
	pop ebp

	mov eax, 0
	ret
