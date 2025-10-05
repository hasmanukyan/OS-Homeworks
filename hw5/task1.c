#include <stdio.h>
#include <stdlib.h>

int main() {
	int n;
	int *arr;

	printf("Enter the number of elements: ");
	scanf("%d", &n);

	arr = (int *)malloc( n * sizeof(int));
	if(!arr) {
		perror("malloc");
		return 1;
	}
	
	int sum = 0;
	printf("Enter %d integers: ", n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		sum += arr[i];
	}

	printf("Sum of the array: %d\n", sum);

	free(arr);
	return 0;
}
