#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // getpid

int main(int argc, char *argv[])
{
	pid_t pid = getpid();
	printf("My process is: %d\n", pid);
	return 0;
}
