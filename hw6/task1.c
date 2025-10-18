#include <stdio.h>

int main()
{
	int varInt = 10;
	char varChar = 'C';
	double varDouble = 10.5;
	short varShort = 1;

	printf("Size of Int: %zu\n", sizeof(varInt));
	printf("Size of Char: %zu\n", sizeof(varChar));
	printf("Size of Double: %zu\n", sizeof(varDouble));
	printf("Size of Short: %zu\n", sizeof(varShort));

	printf("Address of Int: %p\n", &varInt);
	printf("Address of Char: %p\n", &varChar);
	printf("Address of Double: %p\n", &varDouble);
	printf("Address of Short: %p\n", &varShort);

	return 0;
}
