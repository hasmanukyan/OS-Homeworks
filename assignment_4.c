#include <stdio.h>

int main(){
	int var = 10;
	int *p = &var;
	int **ptp = &p;
	
	printf("Value of integer using variable: %d\n", var);
	printf("Value of integer using pointer: %d\n", *p);
	printf("Value of integer using double pointer: %d\n", **ptp);

	return 0;	
}
