#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{

	pid_t f1 = fork();

	if (f1 < 0)
	{
		perror("fork");
		return 1;
	}
	else if (f1 == 0)
	{
		printf("Child's PID = %d\n", getpid());
		exit(0);
	}
	else
	{
		printf("Parent's PID = %d\n", getpid());
	}

	return 0;
}
