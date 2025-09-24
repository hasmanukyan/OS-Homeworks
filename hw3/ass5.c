#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
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
		printf("Child process, PID = %d\n", getpid());
		exit(0);
	}
       	else
	{
		printf("Parent process, PID = %d\n", getpid());
		sleep(20);
		//wait(NULL);
		printf("Parent process finished");
		//sleep(10);
	}

	return 0;
}

// for no zombie program, open the comments, and comment sleep(20) 

