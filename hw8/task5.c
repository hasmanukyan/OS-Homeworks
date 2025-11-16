#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/types.h>

int main() 
{
	off_t size;
	int fd = open("sparse.bin", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0) 
	{
		perror("Error creating sparse.bin");
		return 1;
	}

	if (write(fd, "START", 5) != 5)
	{	
		perror("Error writing START");
		close(fd);
		return 1;
	}

	if (lseek(fd, 1024 * 1024, SEEK_CUR) == -1) 
	{
		perror("Error seeking");
		close(fd);
		return 1;
	}

	if (write(fd, "END", 3) != 3) 
	{
		perror("Error writing END");
		close(fd);
		return 1;
	}
	close(fd);
	
	fd = open("sparse.bin", O_RDONLY);
	if (fd < 0) 
	{
		perror("Error reopening sparse.bin");
		return 1;
	}

	size = lseek(fd, 0, SEEK_END);
	if (size == -1) 
	{
		perror("Error getting file size");
		close(fd);
		return 1;
	}
	
	printf("Apparent file size: %ld bytes\n", (long)size);
	close(fd);
	return 0;
}

