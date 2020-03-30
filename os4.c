#include<stdio.h>

int n,i;
int Total_burst=0,j=0,k=0,l=0;  //j,k,l represents No. of processes in *EACH* queue respectively
int t1=0,t2=0,t3=0;   //t1,t2,t3 represents total burst times for *EACH* queue
int at[40],bt[40],wt[40],wt1[40],tat1[40],pr[40],arrival_time1[40],arrival_time2[40],arrival_time3[40];
int burst_time1[40],burst_time2[50],burst_time3[40],priority2[40],process2[40];
int wt2[40],tat2[40],wt3[40],tat3[40];

void roundRobin1(){
	int rem_bt[n],x;  // copy of bt[] array to store remaining burst time
	printf("\n***Queue1 executed***\n");
	for(i=0;i<j;i++)
	{
		rem_bt[i]=burst_time1[i];
	} 
	
	
	
	int t=0; // Here,t represents CURRENT TIME
	
	// Keep traversing processes in round robin manner 
    // until all of them are not done. 
    printf("\nProcess ID\tBurst Time\t Turnaround Time\t Waiting Time\n");

    while (1) 
    { 
        bool done = true; 
        
  
        // Traversing all processes one by one repeatedly 
        for (int i = 0 ;i<j; i++) 
        { 
            // If burst time of a process is greater than 0 
            // then only need to process further 
            if (rem_bt[i] > 0) 
            { 
                done = false; // There is a pending process 
  
                if (rem_bt[i] > 4) 
                { 
                    // Increase the value of t i.e. shows 
                    // how much time a process has been processed 
                    t += 4; 
  
                    // Decrease the burst_time of current process 
                    // by quantum 
                    rem_bt[i] -= 4; 
                } 
  
                // If burst time is smaller than or equal to 
                // quantum. Last cycle for this process 
                else
                { 	
                	
                    // Increase the value of t i.e. shows 
                    // how much time a process has been processed 
                    t = t + rem_bt[i]; 
                    
                    //turnaround time = Current time - Arrival time
                       tat1[i] = t-arrival_time1[i];
                    
  
                    // Waiting time is turnaround time minus time 
                    // used by this process 
                    wt1[i] = tat1[i] - burst_time1[i]; 
  
                    // As the process gets fully executed 
                    // make its remaining burst time = 0 
                    rem_bt[i] = 0; 
                    printf("\nProcess[%d]\t\t%d\t\t%d\t\t%d",i+1,burst_time1[i],tat1[i],tat1[i]-burst_time1[i]);

                    
                    
                } 
            } 
            
            	
            } 
  
        // If all processes are done 
        if (done == true){
        	int total_wt=0,total_tat=0;
        	// Calculate total waiting time and total turn 
        	// around time 
   			 for (int i=0; i<j; i++) 
   			 { 
        			total_wt = total_wt + wt1[i]; 
        			total_tat = total_tat + tat1[i];
					 
        		
             }
             
             printf("\n\nAverage waiting time = %f",(float)total_wt / (float)j);
             printf("\nAverage turn around time = %f\n\n ",(float)total_tat / (float)j);
             break;
			}
          
    } 
} 

void priority(){
	printf("***Queue2 executed***\n\n");
	int q,temp,pos;
	float awt=0,atat=0;  //Here awt is average waiting time and atat is average turnaround time
	for(i=0;i<k;i++){
		pos=i;
		for(q=i+1;q<k;q++){
			if(pr[q]<pr[pos])
			{
				pos=q; //SETTING THE POSITION OF PROCESS ACCORDING TO PRIORITY
			}
		}
		temp=priority2[i];
		priority2[i]=priority2[pos]; //Sorting the priority
		priority2[pos]=temp;
		
		temp=burst_time2[i];
		burst_time2[i]=burst_time2[pos];  //Sorting burst time
		burst_time2[pos]=temp;        
		
		}
		wt2[0]=0;
		printf("process\tBurst time\tpriority\twaiting time\tturnaround time\t\n");
		for(i=0;i<k;i++){
			wt2[i]=0;
			tat2[i]=0;
			for(q=0;q<i;q++)
			{
				wt2[i]=wt2[i] + burst_time2[q];
			}
			tat2[i]=wt2[i] + burst_time2[i];
			awt=awt+wt2[i];
			atat=atat+tat2[i];
			printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n",i+1,burst_time2[i],priority2[i],wt2[i],tat2[i]);
		}
		
		awt=awt/k;
		atat=atat/k;
		printf("Average waiting time=%f\n",awt);
		printf("Average turnaround time=%f\n",atat);
		
		 for(i=0;i<k;i++)
    {
    	while(burst_time2[i]!=0)
    	{
    		if(burst_time2[i]>10)
    		{
				printf("\nProcess[%d] of Queue2 is running for 10 units\n",i+1);
				burst_time2[i]=burst_time2[i]-10;
			}
			else if(burst_time2[i]<=10)
			{
				printf("\nProcess[%d] of Queue2 is running for %d units\n",i+1,burst_time2[i]);
				burst_time2[i]=0;
			}
		}
	}
		
		 
	
}

void fcfs()
{	printf("\n***Queue3 executed***\n");
	int r;
	float avgwt=0,avgtat=0;
	wt3[0]=0;
	printf("process\t burst time\t waiting time\t turnaround time\n");
	for(i=0;i<l;i++)
	{
		wt3[i]=0;
		tat3[i]=0;
		for(r=0;r<i;r++)
		{
			wt3[i]=wt3[i]+burst_time3[r];
		}
		tat3[i]= wt3[i] + burst_time3[i];
		avgwt=avgwt+wt3[i];
		avgtat=avgtat+tat3[i];
		printf("\n%d\t\t%d\t\t%d\t\t%d\n",i+1,burst_time3[i],wt3[i],tat3[i]);
		
	}
	
	avgwt=avgwt/l;
	avgtat=avgtat/l;
	printf("Average waiting time=%f\n",avgwt);
	printf("Average turnaround time=%f\n",avgtat);
	
	    for(i=0;i<l;i++)
    {
    	while(burst_time3[i]!=0)
    	{
    		if(burst_time3[i]>10)
    		{
				printf("\nProcess[%d] of Queue3 is running for 10 units\n",i+1);
				burst_time3[i]=burst_time3[i]-10;
			}
			else if(burst_time3[i]<=10)
			{
				printf("\nProcess[%d] of Queue3 is running for %d units\n",i+1,burst_time3[i]);
				burst_time3[i]=0;
			}
		}
	}

	
	
	
	
}

void round_robin()
{
	printf("Quantum time between 3 queues is 10\n");
	for(i=1;i<Total_burst;i=i+10)
	{
		if(t1>10)
		{
			printf("Queue1 is running for 10 units\n");
			t1=t1-10;
		}
		else if(t1<=10&&t1!=0)
		{
			printf("Queue1 is running for %d units\n",t1);
			t1=0;
		}
		if(t2>10)
		{
			printf("Queue2 is running for 10 units\n");
			t2=t2-10;
		}
		else if(t2<=10&&t2!=0)
		{
			printf("Queue2 is running for %d units\n",t2);
			t2=0;
		}
		if(t3>10)
		{
			printf("Queue3 is running for 10 units\n");
			t3=t3-10;
		}
		else if(t3<=10&&t3!=0)
		{
			printf("Queue3 is running for %d units\n",t3);
			t3=0;
		}
	}
}

	
	
	


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
		if(pr[i]>15 || pr[i]<1)
		{
			printf("\ninvalid input\n");
			exit(0);
			
		}
		Total_burst=Total_burst+bt[i];
	}
	for(i=0;i<n;i++)
	{
		if(pr[i]>=11&&pr[i]<=15)
		{
			printf("\nProcess[%d] belongs to Queue 1\n\n",i+1);
			arrival_time1[j]=at[i];
			burst_time1[j]=bt[i];
			j++;
			t1=t1+bt[i];
		}
		
		else if(pr[i]>=6&&pr[i]<=10)
		{
			printf("\nProcess[%d] belongs to Queue 2\n\n",i+1);
			arrival_time2[k]=at[i];
			burst_time2[k]=bt[i];
			priority2[k]=pr[i];
			process2[k]=k+1;
			k++;
			t2=t2+bt[i];
		}
		
		else if(pr[i]>=1&&pr[i]<=5)
		{
			printf("\nProcess[%d] belongs to Queue 3\n\n",i+1);
			arrival_time3[l]=at[i];
			burst_time3[l]=bt[i];
			l++;
			t3=t3+bt[i];
		}
	}
	
	round_robin();
	if(j!=0)
	{
	roundRobin1();
    }
    if(k!=0)
    {
	
	priority();
    }
	if(l!=0)
	{
	fcfs();
    }
	
	
}
