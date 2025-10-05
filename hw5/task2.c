#include <stdio.h>
#include <stdlib.h>

int main() {
	int n;
	printf("Enter the number of elements: ");
	scanf("%d", &n);
	
	int *arr = (int *)calloc(n, sizeof(int));
	if (!arr) {
		perror("calloc");
		return 1;
	}

	printf("Array after calloc: ");
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}

	printf("\nEnter %d integers: ", n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	double sum = 0;
	for (int i = 0; i < n; i++) {
		sum += arr[i];
	}
	double avg = sum / n;

	printf("Updated array: ");
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}

	printf("\nAverage of the array: %.1f\n", avg);

	free(arr);
	return 0;
}
