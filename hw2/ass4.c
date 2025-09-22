#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main (){
	pid_t f1 = fork();

	if(f1 <0){
		perror("fork");
		return 1;
	}
	else if (f1==0){
		printf("Child process:\n");
		int ret = execl("/bin/echo", "echo", "Hello from the child process", NULL);
		if (ret == -1){
			perror("execl");
		}
	}
	else {
		wait(NULL);
		printf("Parent Process Done!\n");
	}

	return 0;
}
