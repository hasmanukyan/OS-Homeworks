#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

int main() 
{
	char buffer[4096];
	ssize_t n;
	off_t offset = 0;
	int line_count = 1;

	int fd = open("numbers.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0) 
	{
		perror("Error creating numbers.txt");
		return 1;
	}
	
	for (int i = 1; i <= 10; i++) 
	{
		char line[16];
		snprintf(line, sizeof(line), "%d\n", i);
		write(fd, line, strlen(line));
	}
	close(fd);

	fd = open("numbers.txt", O_RDWR);
	if (fd < 0) 
	{
		perror("Error opening numbers.txt");
		return 1;
	}

	while ((n = read(fd, buffer, 1)) == 1) 
	{
		if (line_count == 4) break;
		offset++;
		if (buffer[0] == '\n') line_count++;
	}

	char remainder[4096];
	ssize_t rem_len = read(fd, remainder, sizeof(remainder));

	if (lseek(fd, offset, SEEK_SET) == -1) 
	{
		perror("lseek error");
		close(fd);
		return 1;
	}

	const char *new_line = "100\n";
	write(fd, new_line, strlen(new_line));

	if (rem_len > 0) 
	{
		write(fd, remainder, rem_len);
	}

	close(fd);

	fd = open("numbers.txt", O_RDONLY);
	if (fd < 0) 
	{
		perror("Error reopening for print");
		return 1;
	}

	printf("Final file content:\n");
	while ((n = read(fd, buffer, sizeof(buffer))) > 0) 
	{
		write(1, buffer, n);
	}

	close(fd);
	return 0;
}

