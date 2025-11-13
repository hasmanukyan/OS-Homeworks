#include <stdio.h>
#include <pthread.h>

void* calculate_square(void* arg) 
{
	int num = *(int*)arg;
	int square = num * num;
	printf("Square of %d is %d: Thread ID: %lu\n", num, square, pthread_self());
	return NULL;
}

int main() 
{
	int numbers[] = {1, 2, 3, 4, 5};
	int size = sizeof(numbers) / sizeof(numbers[0]);
	pthread_t threads[size];

	for (int i = 0; i < size; i++) 
	{
		pthread_create(&threads[i], NULL, calculate_square, &numbers[i]);
	}

	for (int i = 0; i < size; i++) 
	{
        	pthread_join(threads[i], NULL);
	}

	printf("All threads finished.\n");
	return 0;
}

