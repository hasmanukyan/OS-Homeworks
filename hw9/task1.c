#include <stdio.h>
#include <pthread.h>

void* thread_function(void* arg) 
{
	int thread_num = *(int*)arg;
	printf("Thread %d is running (Thread ID: %lu)\n", thread_num, pthread_self());
	return NULL;
}

int main() 
{
	pthread_t threads[3];
	int thread_nums[3];

	for (int i = 0; i < 3; i++) 
	{
		thread_nums[i] = i + 1; 
		if (pthread_create(&threads[i], NULL, thread_function, &thread_nums[i]) != 0) 
		{
			perror("Failed to create thread");
			return 1;
		}
	}

	for (int i = 0; i < 3; i++) 
	{
		pthread_join(threads[i], NULL);
	}

	printf("All threads have completed. Exiting main thread.\n");
	return 0;
}

