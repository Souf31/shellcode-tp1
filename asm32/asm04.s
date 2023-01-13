section .data                           ;Data segment
   userMsg db 'Please enter a number: ' ;Ask the user to enter a number
   lenUserMsg equ $-userMsg             ;The length of the message
   number:     db '1337', 4
 	 numberLen:  equ $-number

section .bss           ;Uninitialized data
  num resb 5

section .text          ;Code Segment
  global _start

_start:                ;User prompt
  mov eax, 4
  mov ebx, 1
  mov ecx, userMsg
  mov edx, lenUserMsg
  int 80h

  ;Read and store the user input
  mov eax, 3
  mov ebx, 0
  mov ecx, num
  mov edx, 5          ;5 bytes (numeric, 1 for sign) of that information
  int 80h

  mov ecx, 16

.loop:
  mov al, [num + ecx]
  cmp al, 10
  je check_if_pair
  dec ecx
  cmp ecx, 0
  je end
  jmp .loop

check_if_pair:
  mov eax, num
  add eax, ecx
  dec eax
  mov bl, [eax]
  and bl, 1
  ;cmp bl, 1


end:
  mov eax, 1
  int 80h
