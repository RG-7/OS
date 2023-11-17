/*
	Write a program using C/C++/Java to simulate the FCFS, SJF (pre-emptive as well as non-
	preemptive approach). The scenario is: user may input n processes with respective CPU burst
	time and arrival time. System will ask the user to select the type of algorithm from the list
	mentioned above. System should display the waiting time for each process, average waiting
	time for the whole system, and final execution sequence.
*/
#include <stdio.h>
#include <stdlib.h>
struct Process {
    int pid, at, bt, wt, tat, ct, temp;
};

void fcfs (struct Process p[], int number_of_processes) {
    int min, clock = 0;
    int temp = number_of_processes;
    float atat = 0, awt = 0;

    while (temp != 0) {
        min = -1;
        for (int i = 0; i < number_of_processes; i++) {
            if (p[i].at <= clock && p[i].bt != 0) {
                if (min == -1) {
                    min = i;
                    continue;
                }
                
                if (p[i].at < p[min].at) {
                    min = i;
                    continue;
                }
                
                if (p[i].at == p[min].at) {
                    if (p[i].pid < p[min].pid)
                        min = i;
                }
            }
        }
        
        if (min != -1) {
            clock += p[min].bt;
            p[min].bt = 0;
            p[min].ct = clock;
            p[min].tat = p[min].ct - p[min].at;
            p[min].wt = p[min].tat - p[min].temp;
            atat += ((float)p[min].tat);
            awt += ((float)p[min].wt);
            temp--;
        } else {
            clock++;
        }
    }

    printf("Following is the table after the execution.\nPID\tAT\tBT\tWT\tTAT\tCT\n");
    for (int i = 0; i < number_of_processes; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", p[i].pid, p[i].at, p[i].temp, p[i].wt, p[i].tat, p[i].ct);
    }
    printf("Average waiting time is: %f\n", (awt/((float)number_of_processes)));
    printf("Average turn around time is: %f\n", (atat/((float)number_of_processes)));
}

void sjf (struct Process p[], int number_of_processes) {
    int min, clock = 0;
    int temp = number_of_processes;
    float atat = 0, awt = 0;

    while (temp != 0) {
        min = -1;
        for (int i = 0; i < number_of_processes; i++) {
            if (p[i].at <= clock && p[i].bt != 0) {
                if (min == -1) {
                    min = i;
                    continue;
                }
                if (p[i].bt < p[min].bt) {
                    min = i;
                    continue;
                }

                if (p[i].bt == p[min].bt) {
                    if (p[i].at < p[min].at) {
                        min = i;
                        continue;
                    }
                
                    if (p[i].at == p[min].at) {
                        if (p[i].pid < p[min].pid)
                            min = i;
                    }
                }
            }
        }
        
        if (min != -1) {
            clock += p[min].bt;
            p[min].bt = 0;
            p[min].ct = clock;
            p[min].tat = p[min].ct - p[min].at;
            p[min].wt = p[min].tat - p[min].temp;
            atat += ((float)p[min].tat);
            awt += ((float)p[min].wt);
            temp--;
        } else {
            clock++;
        }
    }

    printf("Following is the table after the execution.\nPID\tAT\tBT\tWT\tTAT\tCT\n");
    for (int i = 0; i < number_of_processes; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", p[i].pid, p[i].at, p[i].temp, p[i].wt, p[i].tat, p[i].ct);
    }
    printf("Average waiting time is: %f\n", (awt/((float)number_of_processes)));
    printf("Average turn around time is: %f\n", (atat/((float)number_of_processes)));
}

void srtf (struct Process p[], int number_of_processes) {
    int min, clock = 0;
    int temp = number_of_processes;
    float atat = 0, awt = 0;

    while (temp != 0) {
        min = -1;
        for (int i = 0; i < number_of_processes; i++) {
            if (p[i].at <= clock && p[i].bt != 0) {
                if (min == -1) {
                    min = i;
                    continue;
                }

                if (p[i].bt < p[min].bt) {
                    min = i;
                    continue;
                }

                if (p[i].bt == p[min].bt) {
                    if (p[i].at < p[min].at) {
                        min = i;
                        continue;
                    }
                
                    if (p[i].at == p[min].at) {
                        if (p[i].pid < p[min].pid)
                            min = i;
                    }
                }
            }
        }
        
        if (min != -1) {
            clock++;
            p[min].bt = p[min].bt-1;
            if (p[min].bt == 0) {
                temp--;
                p[min].ct = clock;
                p[min].tat = p[min].ct - p[min].at;
                p[min].wt = p[min].tat - p[min].temp;
                atat += ((float)p[min].tat);
                awt += ((float)p[min].wt);
            }
        } else {
            clock++;
        }
    }

    printf("Following is the table after the execution.\nPID\tAT\tBT\tWT\tTAT\tCT\n");
    for (int i = 0; i < number_of_processes; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", p[i].pid, p[i].at, p[i].temp, p[i].wt, p[i].tat, p[i].ct);
    }
    printf("Average waiting time is: %f\n", (awt/((float)number_of_processes)));
    printf("Average turn around time is: %f\n", (atat/((float)number_of_processes)));
}

void main() {
    int number_of_processes, choice;
    printf("Please enter the number of processes you want to enter: ");
    scanf("%d", &number_of_processes);
    struct Process P[number_of_processes];

    for (int i = 0; i < number_of_processes; i++) {
        printf("Please enter the arrival time for P[%d]: ", i);
        scanf("%d", &P[i].at);
        printf("Please enter the burst time for P[%d]: ", i);
        scanf("%d", &P[i].bt);
        P[i].pid = i;
        P[i].temp = P[i].bt;
    }

    while (1) {
        printf("\n\n\n---Menu---\nPlease select the algorithm that you want to use to schedule your processes.\n1. First Come First Serve (FCFS) - Non Preemptive\n2. Shortest Job First (SJF) - Non Preemptive\n3. Shortest Time Remaining First (SRTF) - Preemptive\n4. Exit\nPlease enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            fcfs(P, number_of_processes);
            break;
        }
        else if (choice == 2) {
            sjf(P, number_of_processes);
            break;
        }
        else if (choice == 3) {
            srtf(P, number_of_processes);
            break;
        }
        else if (choice == 4) {
            printf("\nExited!\n");
            exit(1);
        }
        else {
            printf("\nInvalid Choice!\n");
            break;
        }
    }
}