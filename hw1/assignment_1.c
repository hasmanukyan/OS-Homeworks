#include <stdio.h>

int main(){
	int num = 10;
	printf("%d\n",num);
	int *p = &num;
	printf("%p\n", &num);
	printf("%p\n", p);

	*p = 15;
	printf("%d\n", num);

	return 0;

}

