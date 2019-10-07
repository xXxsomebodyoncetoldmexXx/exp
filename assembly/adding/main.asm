; Hello world using c function
; 
; ===COMPILE TO OBJECT FILE===
; nasm main.asm -f elf32 -o main.o
; 
; ===LINK TO LIBRARY===
; gcc -m32 -o main main.o

extern printf

SECTION .data
	msg:	db "Hello world", 0
	fmt:	db "%s", 0xA, 0
	res: 	db "= %d", 0

SECTION .text

GLOBAL main

	main:
	push ebp			;Save stack

	push msg 			;Dest
	push fmt 			;Source
	mov eax, 0		;Init return value
	call printf

	pop ebp				;Get Source
	pop ebp				;Overwrite with Dest
	pop ebp				;Overwrite with original ebp

	mov eax, 0
	ret
