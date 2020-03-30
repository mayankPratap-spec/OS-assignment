main(){
	printf("Enter the no. of process you want to process\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter details of process[%d]\n",i+1);
		printf("Arrival Time:");
		scanf("%d",&at[i]);
		printf("Burst Time:");
		scanf("%d",&bt[i]);
		printf("Priority(1 to 15):");
		scanf("%d",&pr[i]);
		Total_burst=Total_burst+bt[i];
	}
	for(i=0;i<n;i++)
	{
		if(pr[i]>=11&&pr[i]<=15)
		{
			printf("\n\nProcess[%d] belongs to Queue 1\n",i+1);
			arrival_time1[j]=at[i];
			burst_time1[j]=bt[i];
			j++;
			t1=t1+bt[i];
		}
		
		else if(pr[i]>=6&&pr[i]<=10)
		{
			printf("Process[%d] belongs to Queue 2\n",i+1);
			arrival_time2[k]=at[i];
			burst_time2[k]=bt[i];
			priority2[k]=pr[i];
			process2[k]=k+1;
			k++;
			t2=t2+bt[i];
		}
		
		else if(pr[i]>=1&&pr[i]<=5)
		{
			printf("Process[%d] belongs to Queue 3\n\n\n\n",i+1);
			arrival_time3[l]=at[i];
			burst_time3[l]=bt[i];
			l++;
			t3=t3+bt[i];
		}
	}
	
	roundRobin1();
	round_robin();
	fcfs();
	priority();
	
	
}
