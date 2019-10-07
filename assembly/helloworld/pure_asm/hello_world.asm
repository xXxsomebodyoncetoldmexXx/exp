; hello world assembly
;
;	Author: WhiteFox
; Date: 07/09/2019
;
; ---COMPILE TO OBJECT FILE---
; nasm -f elf32 -o <NAME>.o <NAME>.asm


GLOBAL _start

section .text:

_start:
	mov eax, 0x4			;use write syscall
	mov ebx, 1				;use stdout as fd
	mov ecx, message 	;use message as buffer
	mov edx, msg_len 	;supply the lenght of the buffer
	int 0x80					

	mov eax, 0x1			;use exit syscal
	mov ebx, 0				;return value
	int 0x80

section .data:
	message: db "Hello world!", 0xA
	msg_len: equ $-message
