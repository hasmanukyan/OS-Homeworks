#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

#define BUF_SIZE 1024

int main () 
{
	char srcFilePath[256], destFilePath[256], buf[BUF_SIZE];
	printf("Enter source file path: ");
	scanf("%255s", srcFilePath);

	printf("Enter Destination file path: ");
	scanf("%255s", destFilePath);

	int srcFd = open(srcFilePath, O_RDONLY);
	if (srcFd == -1) 
	{
		perror("Error opening file");
		return 1;
	}

	int destFd = open(destFilePath, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (destFd == -1) 
	{
		perror("Error creating file");
		return 1;
	}

	ssize_t bytesRead, nr;
	ssize_t total = 0;
	while ((bytesRead = read (srcFd, buf, BUF_SIZE))> 0) 
	{
		nr = write(destFd, buf, bytesRead);
		if (nr == -1) 
		{
			perror("Error writing to file");
			close(srcFd);
			close(destFd);
			return 1;
		}
		total += nr;
	}

	if (bytesRead < 0) 
	{
		perror("Error reading from file");
	}
	
	printf("\nTotal number of bytes copied: %zd \n", total);
	close(srcFd);
	close(destFd);

	return 0;
}
