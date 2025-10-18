#include <stdio.h>

struct Variables
{
	char a;
	int b;
	double c;
};

#pragma pack(1) 
//#pragma pack(2)
//#pragma pack(4)
struct PackedStruct 
{
	char a;
	int b;
	double c;
};

int main() 
{
	struct Variables ex1;

	printf("Size of the struct: %zu\n", sizeof(ex1));
	printf("\nAddress of Char in struct: %p\n", &ex1.a);
	printf("Address of Int in struct: %p\n", &ex1.b);
	printf("Address of Double in struct: %p\n", &ex1.c);

        struct PackedStruct ex2;

        printf("\nSize of the packed struct: %zu\n", sizeof(ex2));
        printf("\nAddress of Char in struct: %p\n", &ex2.a);
        printf("Address of Int in struct: %p\n", &ex2.b);
        printf("Address of Double in struct: %p\n", &ex2.c);

	return 0;
}
