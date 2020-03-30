#include<stdio.h>
int n,i;
int Total_burst=0,j=0,k=0,l=0;  //j,k,l represents No. of processes in *EACH* queue respectively
int t1=0,t2=0,t3=0;   //t1,t2,t3 represents total burst times for *EACH* queue
int at[40],bt[40],wt[40],tat[40],pr[40],arrival_time1[40],arrival_time2[40],arrival_time3[40];
int burst_time1[40],burst_time2[50],burst_time3[40],priority2[40],process2[40];

void roundRobin1(){
	int rem_bt[n],x;  // copy of bt[] array to store remaining burst time
	printf("\nQuantum time for queue 1 is 4\n");
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
                       tat[i] = t-at[i];
                    
  
                    // Waiting time is turnaround time minus time 
                    // used by this process 
                    wt[i] = tat[i] - bt[i]; 
  
                    // As the process gets fully executed 
                    // make its remaining burst time = 0 
                    rem_bt[i] = 0; 
                    printf("\nProcess[%d]\t\t%d\t\t%d\t\t%d",i+1,burst_time1[i],tat[i],tat[i]-burst_time1[i]);

                    
                    
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
        			total_wt = total_wt + wt[i]; 
        			total_tat = total_tat + tat[i];
					 
        		
             }
             
             printf("\n\nAverage waiting time = %f",(float)total_wt / (float)j);
             printf("\nAverage turn around time = %f ",(float)total_tat / (float)j);
             break;
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
	//round_robin();
	//fcfs();
	//priority();
	
	
}
