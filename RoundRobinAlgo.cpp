/* Name : Annie Bhalla
   Roll No. : 19HCS4009
   Course : BSC (H) Computer Science
   Semester : 3
   Subject : Operating System
   Title : Round Robin Scheudling ( always Preemptive)
*/

#include<iostream>
using namespace std;

int time_quantum;

struct RRobin
{
	int id;
	int arrivalTime=0;
	int burstTime;
	int turnaroundTime;
	int finishTime;
	int waitingTime;
	bool status =0;
	int remaining_bt;
};

// (1) to enter the details of all processes 

void input(int len, RRobin obj[])
 {
 		for(int i=0;i<len;i++)
	{
		cout<<"\n Enter Burst Time "<<i+1<<" : "<<endl;	
		cin>>obj[i].burstTime;
		obj[i].id=i+1;
		obj[i].remaining_bt = obj[i].burstTime;
	}
 }
 
 // (2) Displaying process no, arrival time , burst time , finishing time , TA , WT
 
 void display(int n, RRobin process[])
 {
    	cout<<" Process No. "<<'\t'<<"Arrival Time"<<'\t'<<"Burst Time"<<'\t'<<" Finishing Time"<<'\t'<<" Turn Around Time"<<'\t'<<"Waiting Time"<<endl;
			
    	for(int i=0;i<n;i++)
		{

		cout<<process[i].id<<'\t'<<'\t'<<process[i].arrivalTime<<'\t'<<'\t'<<'\t'<<process[i].burstTime<<'\t'<<'\t'<<process[i].finishTime<<'\t'<<'\t'<<process[i].turnaroundTime<<'\t'<<'\t'<<process[i].waitingTime<<endl;
				
		}
 }
 
 // scheduling algo
 
 void schedule(int nop , RRobin p[])
 {
 	int completed=0, timer=0;
 	while( completed!= nop)
 	{
 		for( int i=0;i<nop;i++)
 		{
 			if(p[i].status==0)
 			{
 				
			 
 			if( p[i].remaining_bt <= time_quantum )
 			{
 				timer += p[i].remaining_bt;
 				p[i].remaining_bt =0;
 				p[i].status= 1;
 				completed++;
 				p[i].finishTime = timer;
 				p[i].turnaroundTime= p[i].finishTime;
 				p[i].waitingTime = p[i].turnaroundTime - p[i].burstTime;
 				
			 }
			 else
			  if( p[i].remaining_bt> time_quantum)
			  {
			  	  timer += time_quantum;
			  	  p[i].remaining_bt -= time_quantum;
			  }
		}
		 }
		 
	 }
 }
 
  
 
 // driver code
 int main()
{
	
	cout<<"\n Enter the time quantum : ";
	cin>>time_quantum;
	
	int nop;                               // nop= number of processes
	RRobin *process;
	cout<<"\n Enter the number of Processes : ";
	cin>>nop;
	process = new RRobin[nop];
	
	input(nop,process);                      // calling input function to enter AT and BT and priority
	
	// Displaying AT and BT of processes
	
   	cout<<" Process No. "<<'\t'<<"Arrival Time"<<'\t'<<"Burst Time"<<endl;
	for(int i=0;i<nop;i++)
	{
		cout<<process[i].id<<'\t'<<'\t'<<process[i].arrivalTime<<'\t'<<'\t'<<process[i].burstTime<<endl;
	}

	schedule(nop, process);     				// calling schedule function
	
	cout<<endl<<endl<<endl;
	float avg_waiting_time=0;
	
	for(int i=0;i<nop;i++)
	avg_waiting_time += process[i].waitingTime;
	
	avg_waiting_time= avg_waiting_time / nop;

	cout<<endl<<endl<<endl;
	cout<<" *******              Result                 ********"<<endl<<endl;
 	display(nop,process);
 
    cout<<endl<<endl;	
	cout<<"\n Average waiting Time is : "<<avg_waiting_time<<" ms ";
	
	delete [] process;

	
	return 0;
}
 
 
