#include <stdio.h>

struct Variables
{
	char a;
	int b;
	double c;
};
/*
struct Variables 
{
	double c;
	int b;
	char a;
};
*/

int main() 
{
	struct Variables example;

	printf("Size of struct: %zu\n", sizeof(example));
	
	printf("Address of Char in struct: %p\n", &example.a);
	printf("Address of Int in struct: %p\n", &example.b);
	printf("Address of Double in struct %p\n", &example.c);
	return 0;
}
