#include <stdio.h>
#include <pthread.h>

typedef struct 
{
	int *array;
	int start;
	int end;
	int thread_id;
} ThreadData;

void* sum_part(void* arg) 
{
	ThreadData* data = (ThreadData*)arg;
	int sum = 0;

	for (int i = data->start; i < data->end; i++) 
	{
        	sum += data->array[i];
	}

	printf("Thread %d: Sum of elements [%d..%d) = %d\n",
		data->thread_id, data->start, data->end, sum);

	return NULL;
}

int main() 
{

	int arr[] = {2, 4, 6, 8, 10, 12, 14, 16};
	int size = sizeof(arr)/sizeof(arr[0]);

	pthread_t threads[2];
	ThreadData thread_data[2];

	int mid = size/2;

	thread_data[0].array = arr;
	thread_data[0].start = 0;
	thread_data[0].end = mid;
	thread_data[0].thread_id = 1;

	thread_data[1].array = arr;
	thread_data[1].start = mid;
	thread_data[1].end = size;
	thread_data[1].thread_id = 2;

	pthread_create(&threads[0], NULL, sum_part, &thread_data[0]);
	pthread_create(&threads[1], NULL, sum_part, &thread_data[1]);

	pthread_join(threads[0], NULL);
	pthread_join(threads[1], NULL);

	printf("Main thread: Both partial sums have been calculated.\n");
	return 0;
}

