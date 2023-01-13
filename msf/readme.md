## nasm function

nasm -f bin -o asm0X.bin asm0X.s

## msfvenom functions

msfvenom -e x86/shikata_ga_nai -f c -a x86 --platform linux -o asm0X_x86.shellcode < asm0X.bin

cat asm0X_x86.shellcode 

