#include <stdio.h>
#include <limits.h>

struct Process
{
	int pid;
	int arrival_time;
	int burst_time;
	int turnaround_time;
	int waiting_time;
	int response_time;
};

void FCFS (struct Process p[], int n) 
{
	for (int i = 0; i < n -1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (p[i].arrival_time > p[j].arrival_time) {
				struct Process temp = p[i];
				p[i] = p[j];
				p[j] = temp;
			}
		}
	}
	int current_time = 0;
	double total_wait = 0, total_turn = 0, total_resp = 0;

	printf("\nFirst Come First Served (FCFS)\n");
	printf("Gantt chart: |");
	
	for (int i = 0; i < n; i++) {
		if (current_time < p[i].arrival_time) {
			current_time = p[i].arrival_time;
		}
		
		printf(" P%d |", p[i].pid);

		p[i].waiting_time = current_time - p[i].arrival_time;
		p[i].response_time = p[i].waiting_time;
		current_time += p[i].burst_time;
		p[i].turnaround_time = current_time - p[i].arrival_time; 
		
		total_wait += p[i].waiting_time;
		total_turn += p[i].turnaround_time;
		total_resp += p[i].response_time;
	}
	printf("\nPID\tAT\tBT\tWT\tTAT\tRT\n");
	for (int i = 0; i < n; i++) {
		printf("%d\t%d\t%d\t%d\t%d\t%d\n", p[i].pid, p[i].arrival_time, p[i].burst_time,  p[i].waiting_time, p[i].turnaround_time, p[i].response_time);
	}

	printf("\nAverage Waiting Time: %.2f", total_wait / n);
	printf("\nAverage Turnaround Time: %.2f", total_turn / n);
	printf("\nAverage Response Time: %.2f\n", total_resp / n);
}


void SJF (struct Process p[], int n) 
{
	int completed[n];
	for (int i = 0; i < n; i++)
		completed[i] = 0;

	int completed_count = 0, time = 0;
	double total_wait = 0, total_resp = 0, total_turn = 0;
	
	int minArrival = INT_MAX;
	for (int i = 0; i < n; i++) {
		if (p[i].arrival_time < minArrival) {
			minArrival = p[i].arrival_time;
		}
	}
	time = minArrival;
		
	printf("\nShortest Job First (SJF)\n");
        printf("Gantt chart: |");

	while(completed_count < n) {
		int index = -1, minBT = INT_MAX;
		for (int i = 0; i < n; i++) {
			if (!completed[i] && p[i].arrival_time <= time) {
				if (p[i].burst_time < minBT) {
					minBT = p[i].burst_time;
					index = i;
				} 
				else if (p[i].burst_time == minBT) {
					if(p[i].arrival_time < p[index].arrival_time)
						index = i;
				}
			}
		}

		if(index == -1) {
			time++;
			continue;	
		}
		
		printf(" P%d |", p[index].pid);
		
		p[index].waiting_time = time - p[index].arrival_time;
		p[index].response_time =  p[index].waiting_time;
		time += p[index].burst_time;
		p[index].turnaround_time = time - p[index].arrival_time;

		completed[index] = 1;
		completed_count++;

		total_wait += p[index].waiting_time;
		total_resp += p[index].response_time;
		total_turn += p[index].turnaround_time;
	}

	printf("\nPID\tAT\tBT\tWT\tTAT\tRT\n");
	
	for (int i = 0; i < n; i++) {
		printf("%d\t%d\t%d\t%d\t%d\t%d\n", p[i].pid, p[i].arrival_time, p[i].burst_time, p[i].waiting_time, p[i].turnaround_time, p[i].response_time);
	 }

	printf("\nAverage Waiting Time: %.2f", total_wait / n);
	printf("\nAverage Turnaround Time: %.2f", total_turn / n);
	printf("\nAverage Response Time: %.2f\n", total_resp / n);
	
}

int main() 
{
	int n;
	printf("Enter the number of processes: ");
	scanf("%d", &n);
	
	struct Process p[n];

	for (int i = 0; i < n; i++ ) {
		printf("Enter the arrival time and burst time for process %d: ", i+1);
		scanf("%d %d", &p[i].arrival_time, &p[i].burst_time);
		p[i].pid = i + 1;
	}
	struct Process fcfs_p[n], sjf_p[n];

	for (int i = 0; i < n; i++) {
		fcfs_p[i] = p[i];
		sjf_p[i] = p[i];
	}
	FCFS(fcfs_p, n);
	SJF(sjf_p, n);

	return 0;
}	

