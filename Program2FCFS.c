#include<stdio.h>

int a[10], b[10], no[10], wt[10], tat[10];

void main()
{
	float sumwt=0, sumtat=0, avgwt=0, avgtat=0
	int i, j, n, sb=0, temp;
	
	printf("Enter the number of processes: \n");
	scanf("%d", &n);
	
	for(i=0; i<n; i++)
	{
		no[i] = i;
		printf("Enter the Arrival Time & Burst Time for process %d: ", i);
		scanf("%d %d", &a[i], &b[i]);
	}
	
	for(i=0; i<n-1; i++)
	{
		for(j=0; j<n-1-i; j++)
		{
			temp = a[j];
			a[j] = a[j+1];
			a[j+1] = temp;
			
			temp = b[j];
			b[j] = b[j+1];
			b[j+1] = temp;
			
			temp = no[j];
			no[j] = no[j+1];
			no[j+1] = temp;
		}
	}
	
	for(i=0; i<n; i++)
	{
		if(sb == 0)
			sb = a[i];
			
		else
			sb += b[i-1];
			
		wt[i] = sb - a[i];
		tat[i] = wt[i] + b[i];
	}
	
	for(i=0; i<n; i++)
	{
		sumwt += wt[i];
		sumtat += tat[i];
	}
	
	avgwt = sumwt/n;
	avgtat = sumtat/n;
	
	printf("\tProcess\t\tAT\t\tBT\t\tWT\t\tTAT\n");
	for(i=0; i<n; i++)
		printf("\tP%d\t\t%d\t\t%d\t\t%d\t\t%d\n", no[i], a[i], b[i], wt[i], tat[i]);
		
	printf("\nAverage WT is %f\n", avgwt);
	printf("\nAverage TAT is %f\n", avgtat);
}
