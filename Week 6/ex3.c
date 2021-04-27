#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>


int main()
{
	int n; //number of processes
	int* at;
	int* bt;
	int* id;
	int* ct;
	int* wt;
	int* tat;
	int q;
	printf("----   Welcome to the Round Robin algorithm ----\n");
	printf("Enter the number of processes:\n");
	scanf("%d",&n);
	at = (int*)malloc(sizeof(int)*n);
	bt = (int*)malloc(sizeof(int)*n);
	id = (int*)malloc(sizeof(int)*n);
	ct = (int*)malloc(sizeof(int)*n);
	wt = (int*)malloc(sizeof(int)*n);
	tat = (int*)malloc(sizeof(int)*n);
	for(int i=0;i<n;i++)  //input
	{
		printf("Enter the arrival time of process number %d\n",i);
		scanf("%d",&at[i]);
		printf("Enter the burst time of process number %d\n",i);
		scanf("%d",&bt[i]);
		id[i] = i;
	}

	printf("Enter the value of the quantum:\n");
	scanf("%d",&q);
	//sort according to arrival time
	for(int i=0;i<n;i++)
	{
		for(int j=1;j<n;j++)
		{
			if(at[j]<at[j-1])
			{
				int tmp = at[j];
				at[j] = at[j-1];
				at[j-1] = tmp;
				tmp = bt[j];
				bt[j] = bt[j-1];
				bt[j-1] = tmp;
				tmp = id[j];
				id[j] = id[j-1];
				id[j-1] = tmp;
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		wt[i] = 0;
		tat[i] = 0;
	}

	int time = 0;
	bool done  = false;
	while(!done)  //run the processes 
	{
		for(int i=0;i<n;i++)
		{
			if(bt[i]==0) continue;
			if(time<at[i]) time = at[i];
			int rt = (bt[i]>q?q:bt[i]);
			bt[i] -= rt;
			wt[id[i]] += time - at[i];
			time+=rt;
			ct[id[i]] = time;
			tat[id[i]] += time - at[i];
			at[i] = time;
		}
		done = true;
		for(int i=0;i<n;i++)
		{
			if(bt[i]!=0)
			{
				done = false;
				break;
			}
		}
	}
	float totalwt = 0;   
	float totaltat = 0;
	for(int i=0;i<n;i++)
	{
		printf("For process number %d: WT = %d, CT = %d, TAT = %d\n", i,wt[i],ct[i],tat[i]);
		totaltat += tat[i];
		totalwt+=wt[i];
	}
	printf("Average TAT = %f\n", totaltat/n);
	printf("Average WT = %f\n", totalwt);
}
