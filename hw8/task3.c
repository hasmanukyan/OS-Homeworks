#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int main() 
{
	char path[256];
	char ch;

	printf("Enter file path: ");
	if (scanf("%225s", path) != 1) 
	{
		perror("Failed to read input\n");
		return 1;
	}
	
	int fd = open(path, O_RDONLY);
	if (fd < 0) 
	{
		perror("Failed opening file\n");
		return 1;
	}

	off_t size = lseek(fd, 0, SEEK_END);
	if (size == -1) 
	{
		perror("Failed determining file size\n");
		close(fd);
		return 1;
	}

	if (size == 0) 
	{
		printf("\n");
		close(fd);
		return 0;
	}

	for (off_t pos = size - 1; pos >= 0; pos--) 
	{
		if(lseek(fd, pos, SEEK_SET) == -1) 
		{
			perror("lseek error");
			return 1;
		};
		if (read(fd, &ch, 1) != 1) 
		{
			perror("read error");
			close(fd);
			return 1;
		}
		printf("%c", ch);
	}

	printf("\n");
	close(fd);
	return 0;
}

