#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	
	char **arr = (char **)malloc(3 * sizeof(char *));
	if (!arr) {
		perror("malloc");
		return 1;
	}
	
	printf("Enter 3 strings: ");
	for (int i = 0; i < 3; i++) {
		arr[i] = (char *)malloc(50 * sizeof(char));
		if (!arr[i]) {
			perror("malloc");
			for (int j = 0; j < i; j++) {
				free(arr[j]);
			}
			free(arr);
			return 1;
		}
		scanf("%49s", arr[i]);
	}
	printf("Current string: ");
	for (int i = 0; i < 3; i++) {
		printf("%s ", arr[i]);
	}

	char **new_arr = (char **)realloc(arr, 5 * sizeof(char *));
	if (!new_arr) {
                perror("realloc");
                for (int i = 0; i < 3; i++) {
                	free(arr[i]);
                }
                free(arr);
		return 1;
        }

	arr = new_arr;
	printf("\nEnter 2 more strings: ");
        for (int i = 3; i < 5; i++) {
                arr[i] = (char *)malloc(50 * sizeof(char));
                if (!arr[i]) {
                        perror("malloc");
                        for (int j = 0; j < i; j++) {
                                free(arr[j]);
                        }
                        free(arr);
                        return 1;
                }
                scanf("%49s", arr[i]);
        }
	
	printf("All strings: ");
        for (int i = 0; i < 5; i++) {
                printf("%s ", arr[i]);
        }
	printf("\n");

	for (int i = 0; i < 5; i++) {
		free(arr[i]);
	}
	free(arr);
	return 0;
}
