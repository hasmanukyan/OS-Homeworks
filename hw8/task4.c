#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

int main() 
{
	char buffer[1024];
	char entry[1200];
	pid_t pid = getpid();

	int fd = open("log.txt", O_WRONLY | O_CREAT | O_APPEND, 0644);
	
	if (fd < 0) 
	{
		perror("Error opening log.txt");
		return 1;
	}

	ssize_t len = read(0, buffer, sizeof(buffer) - 1);
	if (len < 0) 
	{
		perror("Error reading input");
		close(fd);
		return 1;
	}

	buffer[len] = '\0';

	snprintf(entry, sizeof(entry), "PID=%d: %s", pid, buffer);
	if (entry[strlen(entry) - 1] != '\n') 
	{
		strcat(entry, "\n");
	}

	if (write(fd, entry, strlen(entry)) < 0) 
	{
		perror("Error writing to log.txt");
		close(fd);
		return 1;
	}

	off_t pos = lseek(fd, 0, SEEK_CUR);
	if (pos == -1) 
	{
		perror("lseek error");
		close(fd);
		return 1;
	}

	printf("Final file offset: %ld\n", (long)pos);
	close(fd);
	return 0;
}

