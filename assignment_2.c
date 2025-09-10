#include <stdio.h>

int main(){

	int arr[5] = {2,4,6,8,10};
	int *p = arr;
	printf("The Original array: ");
	for(int i = 0; i < 5; i++){
		printf("%d ", *(p + i));
	}
	
	for(int i = 0; i < 5; i++){
		*(p + i) = *(p+i) +10;
	}
	
	printf("\n Modified array using the pointer: \n");
	for (int i = 0; i<5; i++){
		printf("%d ", *(p+i));
	}

	printf("\n Modified array using array name: \n");
	for (int i = 0; i<5; i++){
		printf("%d ", arr[i]);
	}
	
	return 0;

}
