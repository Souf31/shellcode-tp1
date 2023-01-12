SECTION .DATA
	number:     db '1337',10
	numberLen:  equ $-number

; Code goes in the text section
SECTION .TEXT
	GLOBAL _start

_start:
	mov eax,4
	mov ebx,1
	mov ecx,number
	mov edx,numberLen
	int 80h

	mov eax,1
	mov ebx,0
	int 80h
