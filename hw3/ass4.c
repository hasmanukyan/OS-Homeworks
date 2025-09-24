#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
	pid_t f1 = fork();
	int status;
	
	if (f1 < 0)
	{
		perror("fork");
		return 1;
	}
	else if (f1 == 0)
	{
		printf("1st child process, PID = %d\n", getpid());
		exit(10);
	}
	else {
		waitpid(f1, &status, 0);
		if (WIFEXITED(status))
		{
			printf("Parent of 1st child, 1st child exited NORMALLY with exit status %d\n", WEXITSTATUS(status));
		}
	       	else
		{
			printf("1st child exited with error or signal");
		}
	}	

	pid_t f2 = fork();
	if (f2 < 0)
	{
		perror("fork");
		return 1;
	}
	else if (f2 == 0)
	{
		printf("2nd child process: PID = %d\n", getpid());
		exit(15);
	}
	else
	{
		waitpid(f2, &status, 0);
		if (WIFEXITED(status))
		{
			printf("Parent of 2nd child, 2nd child exited NORMALLY  with exit status %d\n", WEXITSTATUS(status));
		}
	       	else
		{
			printf("2nd child exited with error or signal\n");
		}
	}

	printf("Parent process is done, PID = %d\n", getpid());

	return 0;
}
