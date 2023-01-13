section  .rodata
msg: db "1337", 10
msglen: equ $ - msg


segment .bss
input resd 13

segment .text
    global _start

_start:
    mov rax, 1
    mov rdi, 1
    mov rsi, msg
    mov rdx, msglen
    syscall

    mov rax, 0
    mov rdi, 1
    mov rsi, input
    mov rdx, 15
    syscall

    mov al, [input]
    cmp al, '4'
    jne exit

    mov al, [input+1]
    cmp al, '2'
    jne exit

    mov al, [input+2]
    cmp al, 10
    jne exit

    mov rax,60
    mov rdi,0
    syscall



exit:
    mov rax,60
    mov rdi,1
    syscall
