#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
	pid_t pidFork = fork();

	if(pidFork == -1){
		perror("fork");
		return 1;
	}
	else if(pidFork == 0){
		printf("Child process is running: below the ls of the current directory: \n");
		execl("/bin/ls", "ls", NULL);
		perror("execl");
	}
	else{
		printf("Parent process done!\n");
	}

	return 0;
}
