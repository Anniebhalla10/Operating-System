/* Name : Annie Bhalla
   Roll No. : 19HCS4009
   Course : BSC (H) Computer Science
   Semester : 3
   Title : Priority Scheudling Non Preemptive
*/

#include<iostream>
using namespace std;

struct PRIOR
{
	int id;
	int arrivalTime;
	int burstTime;
	int priority;
	int turnaroundTime;
	int finishTime;
	int waitingTime;
	bool status;
};

// to enter the details of all processes 

void input(int len,PRIOR obj[])
 {
 		for(int i=0;i<len;i++)
	{
		cout<<"\n Enter Arrival Time and Burst Time and Priority of Process P "<<i+1<<" : "<<endl;
		cin>>obj[i].arrivalTime>>obj[i].burstTime>>obj[i].priority;
		obj[i].id=i;
	}
	
 }
 
// scheduling the processes according to priority
void schedule(int nop , PRIOR p[])
{
	 int timer=0 , completed =0;
	 while ( completed != nop)
	 {
	 	int max_pr =0 ;
	 	int index = -1;
	 	for(int i=0;i<nop;i++)
	 	{
	 		if(p[i].arrivalTime <= timer && p[i].status ==0)
				{
					if( p[i].priority > max_pr)
					{
						max_pr = p[i].priority;
						index= i;
					}
					if(p[i].priority == max_pr)
					  if( p[i].arrivalTime < p[index].arrivalTime)
					    index= i;
				}
		 }
		 
		 if( index!=-1)
		 {
		 	timer += p[index].burstTime;
		 	completed++;
		 	p[index].status =1;
		 	p[index].finishTime = timer;
		 	p[index].turnaroundTime = p[index].finishTime-p[index].arrivalTime;
		 	p[index].waitingTime= p[index].turnaroundTime-p[index].burstTime;
		 }
	 }
}

 
 
 // Displaying process no, arrival time , burst time , finishing time , TA , WT
 
 void display(int n, PRIOR process[])
 {
    	cout<<" Process No. "<<'\t'<<"Arrival Time"<<'\t'<<"Burst Time"<<'\t'<<"Priority"<<'\t'<<" Finishing Time"<<'\t'<<" Turn Around Time"<<'\t'<<"Waiting Time"<<endl;
			
    	for(int i=0;i<n;i++)
		{

		cout<<process[i].id<<'\t'<<'\t'<<process[i].arrivalTime<<'\t'<<'\t'<<'\t'<<process[i].burstTime<<'\t'<<'\t'<<process[i].priority<<'\t'<<'\t'<<process[i].finishTime<<'\t'<<'\t'<<process[i].turnaroundTime<<'\t'<<'\t'<<process[i].waitingTime<<endl;
				
		}
 }
 
 
// driver code
 int main()
{
	int nop;                               // nop= number of processes
	PRIOR *process;
	cout<<"\n Enter the number of Processes : ";
	cin>>nop;
	process = new PRIOR[nop];
	
	input(nop,process);                      // calling input function to enter AT and BT and priority
	
	// Displaying AT and BT of processes
	
   	cout<<" Process No. "<<'\t'<<"Arrival Time"<<'\t'<<"Burst Time"<<'\t'<<"Priority"<<endl;
	for(int i=0;i<nop;i++)
	{
		cout<<process[i].id<<'\t'<<'\t'<<process[i].arrivalTime<<'\t'<<'\t'<<process[i].burstTime<<'\t'<<'\t'<<process[i].priority<<endl;
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



