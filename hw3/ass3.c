#include <stdio.h>
#include <stdlib.h>

void cleanup1();
void cleanup2();

int main()
{
	printf("The start of the program.\n");

	if (atexit(cleanup1) != 0)
	{
		perror("Cleanup1 did not work.\n");
		return 1;
	}
	if (atexit(cleanup2) != 0)
	{
		perror("Cleanup2 did not work.\n");
		return 1;
	}

	exit(0);
	printf("The program will end normally...\n");
	return 0;
}

void cleanup1() 
{
	printf("Cleanup function N1.\n");
}

void cleanup2() 
{
	printf("Cleanup function N2.\n");
}
