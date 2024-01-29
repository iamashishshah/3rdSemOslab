#include<stdio.h>

int main()
{
	int time, bt[10], at[10], smallest, n, i;
	float sumtat = 0, sumwt = 0, sumbt = 0;
	
	printf("Enter the number of processes: ");
	scanf("%d", &n);
	
	for(i=0; i<n; i++)
	{
		printf("The Arrival Time and Burst Time for process P%d: ", i+1);
 		scanf("%d %d", &at[i], &bt[i]);
 		
 		sumbt += bt[i];
 	}
 	
 	bt[9] = 9999;
 	
 	for(time=0; time < sumbt; )
	{
		smallest = 9;
		for(i=0; i<n; i++)
		{
			if(at[i]<=time && bt[i]>0 && bt[i]<bt[smallest])
				smallest = i;
		}
		
		printf("P[%d]\t|\t%d\t|\t%d\n", smallest+1, time+bt[smallest]-at[smallest], time-at[smallest]);
		
		sumtat += time+bt[smallest]-at[smallest];
		sumwt += time-at[smallest];
		time += bt[smallest];
		bt[smallest] = 0;
	}
	
	printf("\n\nAverage waiting time = %f", sumwt/n);
	printf("\n\nAverage turnaround time = %f\n", sumtat/n);
	
	return 0;
}
