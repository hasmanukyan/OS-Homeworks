#include <stdio.h>

int swap (int *a, int *b){
	int c;
	c = *a;
	*a = *b;
	*b = c;
}


int main(){
	int a = 10,  b = 20;
	printf("before swapping: a = %d, b = %d \n", a, b);
	swap(&a, &b);
	printf("after swapping : a = %d, b = %d \n", a, b);
	
	return 0;
}
