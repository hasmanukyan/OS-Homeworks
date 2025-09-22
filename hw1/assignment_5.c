#include <stdio.h>

int main(){
	
	char str[] = "Hello";
	char *p = str;

	for(char *i = p; *i; i++){
		printf("%c", *i);
	}
	printf("\n");
	
	int count = 0;
	while(*(p + count)){
		count++;
	}
	printf("Number of characters: %d\n", count);


	return 0;

}
