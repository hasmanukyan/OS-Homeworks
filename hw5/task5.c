#include <stdio.h>
#include <stdlib.h>

int main() {
	int n;
	printf("Enter the number of students: ");
	scanf("%d", &n);

	int *arr = (int *)malloc(n * sizeof(int));
	if (!arr) {
		perror("malloc");
		return 1;
	}

	printf("Enter the grades: ");
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	int lowest = arr[0];
	int highest = arr[0];
	for (int i = 1; i < n; i++) {
		if (arr[i] < lowest) {
			lowest = arr[i];
		}
		if (arr[i] > highest) {
			highest = arr[i];
		}
	}
	printf("Highest grade: %d", highest);
	printf("\nLowest grade: %d\n", lowest);

	free(arr);
	return 0;
}
