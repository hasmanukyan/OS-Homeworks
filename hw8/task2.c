#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main () 
{
	char *filename = "data.txt";
	char *text = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	int fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1) 
	{
		perror("Error opening the file");
		return 1;
	}

	ssize_t nr = write(fd, text, 26);
	if (nr == -1) 
	{
		perror("Error writing to file");
		close(fd);
		return 1;
	}

	close(fd);

	fd = open(filename, O_RDWR);
	if (fd == -1) 
	{
		perror("Error reopening the file");
		return 1;
	}

	off_t ret = lseek(fd, 0, SEEK_END);
	if (ret == -1) 
	{
		perror("Error getting size");
		close(fd);
		return 1;
	}
	printf("The current size of the file: %ld\n", ret);

	if(ftruncate(fd, 10) == -1) 
	{
		perror("Error truncating file");
		close(fd);
		return 1;
	}

	ret = lseek(fd, 0 , SEEK_END);
	if (ret == -1)
        {
                perror("Error getting size");
                close(fd);
                return 1;
        }
	printf("New file size: %ld\n", ret);

	if (lseek(fd, 0, SEEK_SET) == -1)
	{
		perror("Error Rewinding the file");
		close(fd);
		return 1;
	}

	char buf[30] = {0};
	ssize_t bytes_read = read(fd, buf, sizeof(buf) - 1);
	if (bytes_read == -1)
        {
                perror("Error Reading the file");
                close(fd);
                return 1;
        }
	
	printf("Remaining text from file: %s\n", buf);

	close(fd);
	return 0;
}
