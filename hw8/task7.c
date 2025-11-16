#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

#define BUF_SIZE 1024

int main() 
{
	char path1[256], path2[256];
	ssize_t n1, n2;
	unsigned char buf1[BUF_SIZE], buf2[BUF_SIZE];
	long long index = 0;

	printf("Enter first file path: ");
	scanf("%255s", path1);

	printf("Enter second file path: ");
	scanf("%255s", path2);
			
	int fd1 = open(path1, O_RDONLY);
	if (fd1 < 0) 
	{
		perror("Error opening first file");
		return 1;
	}

	int fd2 = open(path2, O_RDONLY);
	if (fd2 < 0) 
	{
		perror("Error opening second file");
		close(fd1);
		return 1;
	}

	while (1) 
	{
		n1 = read(fd1, buf1, BUF_SIZE);
		n2 = read(fd2, buf2, BUF_SIZE);

		if (n1 < 0 || n2 < 0) {
			perror("Error reading files");
			close(fd1);
			close(fd2);
			return 1;
        	}

		ssize_t min = (n1 < n2) ? n1 : n2;
		for (ssize_t i = 0; i < min; i++, index++) 
		{
			if (buf1[i] != buf2[i]) 
			{
				printf("Files differ at byte %lld\n", index);
				close(fd1);
				close(fd2);
				return 1;
			}
		}

		if (n1 != n2) 
		{
			printf("Files differ at byte %lld\n", index);
			close(fd1);
			close(fd2);
			return 1;
		}
		
		if (n1 == 0 && n2 == 0) 
		{
			break;
		}

		index += (min - 0);
	}

	printf("Files are identical\n");
	close(fd1);
	close(fd2);
	return 0;
}

