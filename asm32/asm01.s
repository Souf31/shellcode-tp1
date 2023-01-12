extern printf

section .text

global main

main:
    mov eax, 0
    mov ebx, 1
    int 80h
