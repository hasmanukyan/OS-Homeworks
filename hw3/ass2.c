#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

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
		exit(10);
	}
	else
	{
		pid_t f2 = fork();

		if (f2 < 0)
		{
			perror("fork");
			return 1;
		}
		else if (f2 == 0)
		{
			printf("2nd child's PID = %d\n", getpid());
			exit(15);
		}
		else
		{
			int status;
			waitpid(f1, &status, 0);
			if (WIFEXITED(status))
			{
				printf("Parent process: 1st Child is exited with status %d\n", WEXITSTATUS(status));
			}

			wait(&status);
			if (WIFEXITED(status))
			{
				printf("Parent process: 2nd child is exited with status %d\n", WEXITSTATUS(status));
			}
		}
	}

	return 0;
}
