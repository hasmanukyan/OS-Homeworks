#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>

int main() {
	pid_t f1 = fork();

	if(f1<0){
		perror("fork");
		return 1;
	}
	else if (f1 ==0){
		printf("Child process that finds main word in test.txt\n");
		int ret = execl("/bin/grep", "grep", "main", "test.txt", NULL);
		if(ret == -1){
			perror("execl");
		}
	}
	else{
		wait(NULL);
		printf("Parent process completed!\n");
	}

	return 0;
}
