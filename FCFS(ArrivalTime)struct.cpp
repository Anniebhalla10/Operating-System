/* Name : Annie Bhalla
   Roll No. : 19HCS4009
   Course : BSC (H) Computer Science
   Semester : 3
   Subject : Operating System
   Title : FCFS with Arrival Time using structures
*/

#include<iostream>
using namespace std;

struct FCFS
{
	int index;
	int arrivalTime;
	int burstTime;
	int finishTime=0;
	int turnaroundTime=0;
	int waitingTime=0;
	
};

int main()
{
	int nop;
	FCFS *process;
	FCFS temp;
	cout<<"\n ENter the number of Processes : ";
	cin>>nop;
	process = new FCFS[nop];
	
	// input of details of each process in ready queue
	for(int i=0;i<nop;i++)
	{
		cout<<"\n Enter Arrival Time and Burst Time of Process P "<<i+1<<" : "<<endl;
		cin>>process[i].arrivalTime>>process[i].burstTime;
		process[i].index=i;
	}
	
	// Displaying ready queue
	
		cout<<" Process No. "<<'\t'<<"Arrival Time"<<'\t'<<"Burst Time"<<endl;
	for(int i=0;i<nop;i++)
	{
		cout<<process[i].index<<'\t'<<'\t'<<process[i].arrivalTime<<'\t'<<'\t'<<process[i].burstTime<<endl;
	}
	
	// sorting the processes w.r.t arrival time
	
	for(int i=0;i<nop-1;i++)
	{
		for(int j=0;j<nop-1-i;j++)
		{
			if(process[j].arrivalTime>process[j+1].arrivalTime)
			{
				temp= process[j];
				process[j]=process[j+1];
				process[j+1]=temp;
			}
		}
	}
	cout<<endl<<endl<<endl;
	// Displaying details after sorting 
	
		cout<<" Process No. "<<'\t'<<"Arrival Time"<<'\t'<<"Burst Time"<<endl;
	for(int i=0;i<nop;i++)
	{
		cout<<process[i].index<<'\t'<<'\t'<<process[i].arrivalTime<<'\t'<<'\t'<<process[i].burstTime<<endl;
	}
	
	// calculating finishing time
	
	process[0].finishTime=process[0].burstTime;
	for(int i=1;i<nop;i++)
	{
		process[i].finishTime= process[i].burstTime + process[i-1].finishTime;
		
	}
	
	// calculating  turn around time [TA=FT-AT] , waiting time [WT=TA-BT] , avg waiting time
	
	float avg_waiting_time=0;
	for(int i=0;i<nop;i++)
	{
		process[i].turnaroundTime= process[i].finishTime - process[i].arrivalTime;
		process[i].waitingTime= process[i].turnaroundTime - process[i].burstTime;
		avg_waiting_time += process[i].waitingTime;
	}

	avg_waiting_time= avg_waiting_time / nop;

cout<<endl<<endl<<endl;
// Displaying process no, arrival time , burst time , finishing time , TA , WT

    	cout<<" Process No. "<<'\t'<<"Arrival Time"<<'\t'<<"Burst Time"<<'\t'<<" Finishing Time"<<'\t'<<" Turn Around Time"<<'\t'<<"Waiting Time"<<endl;
    	
    	
			for(int i=0;i<nop;i++)
{

		cout<<process[i].index<<'\t'<<'\t'<<process[i].arrivalTime<<'\t'<<'\t'<<'\t'<<process[i].burstTime<<'\t'<<'\t'<<process[i].finishTime<<'\t'<<'\t'<<process[i].turnaroundTime<<'\t'<<'\t'<<process[i].waitingTime<<endl;
		
	}
	
	cout<<endl<<endl;
	
	cout<<"\n Average waiting Time is : "<<avg_waiting_time;
	return 0;

	
}
