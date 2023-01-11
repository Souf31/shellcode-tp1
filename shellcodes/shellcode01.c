#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main()
{
        execve("/bin/sh", NULL, NULL);
        return 0;
}
