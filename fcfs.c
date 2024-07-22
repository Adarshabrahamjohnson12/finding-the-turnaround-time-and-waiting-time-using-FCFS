#include<stdio.h>
#include<stdlib.h>
struct fcfs
{
	int pid;
	int bt;
	int tat;
	int wt;
}p[10000];
int main()
{
	int n,i;
	int total_wt = 0, total_tat = 0; 
	printf("enter the number of processes");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
	p[i].pid=i+1;
	printf("enter the burst time of the process %d: ", p[i]. pid);
	scanf("%d",&p[i].bt);
	}
	//calculate tat and wt for each process
	p[0].wt=0; //wt for the first process is zero
	
	for(i=1;i<n;i++)
	{
	p[i].wt=p[i-1].wt+p[i-1].bt;
	}
	    for(i = 0; i < n; i++)
    {
        p[i].tat = p[i].wt + p[i].bt;
        total_wt += p[i].wt; //waiting time
        total_tat += p[i].tat; //Accumulate turnaround time
    }
	for(i=0;i<n;i++)
	{
		p[i].tat=p[i].wt+p[i].bt;
	}
	
	//display the process details
	printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");

	for(i=0;i<n;i++)
	{
	printf("%d\t%d\t\t%d\t\t%d\n", p[i].pid, p[i].bt, p[i].wt, p[i].tat);
    }
	    // Displaying total waiting time and total turnaround time
    printf("\nTotal Waiting Time: %d\n", total_wt);
    printf("Total Turnaround Time: %d\n", total_tat);
return 0;
}