# Process Scheduling Simulation (FCFS & SJF)

## Overview

This C program simulates CPU process scheduling using two non-preemptive algorithms:

1. **First Come First Served (FCFS)**
2. **Shortest Job First (SJF)**

For each process, the program calculates:

* Waiting Time (WT)
* Turnaround Time (TAT)
* Response Time (RT)

It also prints a **Gantt chart** showing the order of execution and computes average times for each algorithm.

-------------------------------------------

## Files

* `schedulers.c` — contains the full code of implementing FCFS and SJF scheduling algorithms.

-----------------------------------------------

## How to Compile

Open a terminal, navigate to the project folder, and run:

`gcc schedulers.c -o scheduler`

This will create an executable process called `scheduler`.

## How to Run

Run the program in terminal writing:

`./scheduler`

The program will prompt for:

1. Number of processes
2. Arrival time and burst time for each process

**Example Input:**

Enter the number of processes: 4
Enter the arrival time and burst time for process 1: 0 8
Enter the arrival time and burst time for process 2: 1 4
Enter the arrival time and burst time for process 3: 2 9
Enter the arrival time and burst time for process 4: 3 5

---------------------------------------

## Output

The program shows:

* **FCFS Results**: Gantt chart, process table, and average times
* **SJF Results**: Gantt chart, process table, and average times

**Example Output (SJF):**

Shortest Job First (SJF)
Gantt Chart: | P2 | P4 | P1 | P3 |
PID	AT	BT	WT	TAT	RT
1	0	8	0	8	0
2	1	4	7	11	7
4	3	5	9	14	9
3	2	9	15	24	15

Average Waiting Time: 7.75
Average Turnaround Time: 14.25
Average Response Time: 7.75
