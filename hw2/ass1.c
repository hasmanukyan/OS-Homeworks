#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
	int f1 = fork();
	if(f1 == 0){
		printf("F1: child process, PID = %d, PPID = %d\n", getpid(), getppid());	
	}
	else {
		printf("F1: parent process, PID = %d, PPID = %d\n", getpid(), getppid());
	}

	int f2 = fork();
	if(f2 ==0){
		printf("F2: child process, PID = %d, PPID = %d\n", getpid(), getppid());
	}
	else{
		printf("F2: parent process, PID = %d, PPID = %d\n", getpid(), getppid());
	}

	int f3 = fork();
	if(f3==0){
		printf("F3: child process, PID = %d, PPID = %d\n", getpid(), getppid());
	}
	else{
		printf("F3: parent process, PID = %d, PPID %d\n", getpid(), getppid());
	}

	return 0;

}
