/* Name : Annie Bhalla
   Roll No. : 19HCS4009
   Course : BSC (H) Computer Science
   Semester : 3
   Subject : Operating System
   Title : SJF Implementation - Shortest Job First (Non Preemptive)

*/
#include<iostream>
using namespace std;

struct SJF
{
	int id;
	int arrivalTime;
	int burstTime;
	int finishTime;
	int turnaroundTime;
	int waitingTime;
	
};



void input(int len,SJF obj[]);
void display(int n,SJF process[]);
void sort(int num, SJF object[]);
void swap(SJF *a, SJF *b);


int main()
{
	 
	int nop;                               // nop= number of processes
	SJF *process;
	cout<<"\n Enter the number of Processes : ";
	cin>>nop;
	process = new SJF[nop];
	
	input(nop,process);                      // calling input function to enter AT and BT
   	
   	
    // Displaying AT and BT of processes
   
	cout<<" Process No. "<<'\t'<<"Arrival Time"<<'\t'<<"Burst Time"<<endl;
	for(int i=0;i<nop;i++)
	{
		cout<<process[i].id<<'\t'<<'\t'<<process[i].arrivalTime<<'\t'<<'\t'<<process[i].burstTime<<endl;
	}

	sort(nop, process);     				// calling sort function for sorting the processes according to SJF scheduling
	
	cout<<endl<<endl<<endl;
	
	// Displaying AT and BT Details after sorting 
	cout<<"\n *******         Displaying After Sorting        ******** "<<endl<<endl;
	
	cout<<" Process No. "<<'\t'<<"Arrival Time"<<'\t'<<"Burst Time"<<endl;
	for(int i=0;i<nop;i++)
	{
		cout<<process[i].id<<'\t'<<'\t'<<process[i].arrivalTime<<'\t'<<'\t'<<process[i].burstTime<<endl;
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
cout<<" *******              Result                 ********"<<endl<<endl;
 display(nop,process);
 
 cout<<endl<<endl;	
	cout<<"\n Average waiting Time is : "<<avg_waiting_time;
	
	delete [] process;

	return 0;
	
}


 void input(int len,SJF obj[])
 {
 		for(int i=0;i<len;i++)
	{
		cout<<"\n Enter Arrival Time and Burst Time of Process P "<<i+1<<" : "<<endl;
		cin>>obj[i].arrivalTime>>obj[i].burstTime;
		obj[i].id=i;
	}
	
 }
 
 // Displaying process no, arrival time , burst time , finishing time , TA , WT
 
 void display(int n, SJF process[])
 {
    	cout<<" Process No. "<<'\t'<<"Arrival Time"<<'\t'<<"Burst Time"<<'\t'<<" Finishing Time"<<'\t'<<" Turn Around Time"<<'\t'<<"Waiting Time"<<endl;
			
    	for(int i=0;i<n;i++)
		{

		cout<<process[i].id<<'\t'<<'\t'<<process[i].arrivalTime<<'\t'<<'\t'<<'\t'<<process[i].burstTime<<'\t'<<'\t'<<process[i].finishTime<<'\t'<<'\t'<<process[i].turnaroundTime<<'\t'<<'\t'<<process[i].waitingTime<<endl;
				
		}
 }


void sort(int num, SJF object[])
{
	//first sorting according to arrival time using bubble sort
	 
	for(int i=0;i<num-1;i++)
	{
		for(int j=0;j<num-1-i;j++)
		{
			if(object[j].arrivalTime>object[j+1].arrivalTime)
				{
						SJF temp= object[j];
				object[j]=object[j+1];
				object[j+1]=temp;
					}	
		}
	}

	// now sorting according to sjf scheduling
	int k=object[0].burstTime;
	
	for(int i=1;i<num;i++)
	{
		int min=i;
		int flag=0;
		
		for(int j=i;j<num;j++)
		{   
			if( object[j].arrivalTime<k)     
			{
				if(object[j].burstTime<object[min].burstTime)
				   {
				   	min=j;
				   	flag=1;
				   }
			}
		
		}
		    if(flag==1)
		    {
			
				SJF temp= object[i];
				object[i]=object[min];
			   object[min]=temp;
			k=k+object[i].burstTime;
		  }
	}
		
}




