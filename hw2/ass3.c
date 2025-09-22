#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
	pid_t f1 = fork();

	if(f1 < 0){
		perror("fork");
		return 1;
	}
	else if(f1 == 0){
		printf("First child of fork:\n");
		int ret = execl("/bin/ls", "ls", NULL);
		if(ret == -1){
			perror("execl");
		}
	}
	else{
		wait(NULL);
		pid_t f2 = fork();
		
		if(f2<0){
			perror("fork");
			return 1;
		}
		else if (f2 == 0){
			printf("Second child of fork:\n");
			int ret = execl("/bin/date", "date", NULL);
			if (ret == -1){
				perror("execl");
			}
		}
		else {
			wait(NULL);
			printf("Parent Process Done!\n");
		}
	}

	return 0;
}
