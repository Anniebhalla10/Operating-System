/* Name : Annie Bhalla
   Roll No. : 19HCS4009
   Course : BSC (H) Computer Science
   Semester : 3
   Subject : Operating System
   Title : Shortest Job First - Preemptive
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
	double waitingTime;
	int remaining_bt;
	
	
};




// (1) to enter the details of all processes 

void input(int len, SJF obj[])
 {
 		for(int i=0;i<len;i++)
	{
		cout<<"\n Enter Arrival Time and  Burst Time "<<i+1<<" : "<<endl;	
		cin>>obj[i].arrivalTime>>obj[i].burstTime;
		obj[i].id=i+1;
		obj[i].remaining_bt = obj[i].burstTime;
	}
 }
 
 // (2) Displaying process no, arrival time , burst time , finishing time , TA , WT
 
 void display(int n, SJF process[])
 {
    	cout<<" Process No. "<<'\t'<<"Arrival Time"<<'\t'<<"Burst Time"<<'\t'<<" Finishing Time"<<'\t'<<" Turn Around Time"<<'\t'<<"Waiting Time"<<endl;
			
    	for(int i=0;i<n;i++)
		{

		cout<<process[i].id<<'\t'<<'\t'<<process[i].arrivalTime<<'\t'<<'\t'<<'\t'<<process[i].burstTime<<'\t'<<'\t'<<process[i].finishTime<<'\t'<<'\t'<<process[i].turnaroundTime<<'\t'<<'\t'<<process[i].waitingTime<<endl;
				
		}
 }
 
 
 // scheduling algo
 
void schedule(int n, SJF proc[])
{
    int completed = 0, timer = 0;
    while(completed!=n)
    {
        int min_bt = 100;
        int index = -1;
        for(int i=0;i<n;i++)
        {
            if(proc[i].remaining_bt!=0 && proc[i].arrivalTime <= timer)
            {
                if(proc[i].remaining_bt<min_bt)
                {
                    min_bt = proc[i].remaining_bt;
                    index = i;
                }
                if(proc[i].remaining_bt == min_bt)
                    if(proc[i].arrivalTime < proc[index].arrivalTime)
                        index = i;
            }
        }
        if(index != -1)
        {
            proc[index].remaining_bt--;
            timer++;
            if(proc[index].remaining_bt == 0)
            {
                completed++;
                proc[index].finishTime = timer;
				proc[index].turnaroundTime = proc[index].finishTime - proc[index].arrivalTime;
				proc[index].waitingTime = proc[index].turnaroundTime - proc[index].burstTime;
            }
        }
        else
            timer++;
    }
    double wt_avg = 0,tat_avg = 0;
	display(n,proc);
	for(int i=0;i<n;i++)
	{
		wt_avg += proc[i].waitingTime;
		tat_avg += proc[i].turnaroundTime;
	}
	cout<<"Average Waiting Time : "<<(wt_avg/n)<<endl;
	cout<<"Average Turnaround Time : "<<(tat_avg/n)<<endl;
}
	 
	  
 // driver code
 int main()
 {
 		
	
	int nop;                               // nop= number of processes
	SJF *process;
	cout<<"\n Enter the number of Processes : ";
	cin>>nop;
	process = new SJF[nop];
	
	input(nop,process);                      // calling input function to enter AT and BT and priority
	
	// Displaying AT and BT of processes
	
   	cout<<" Process No. "<<'\t'<<"Arrival Time"<<'\t'<<"Burst Time"<<endl;
	for(int i=0;i<nop;i++)
	{
		cout<<process[i].id<<'\t'<<'\t'<<process[i].arrivalTime<<'\t'<<'\t'<<process[i].burstTime<<endl;
	}

	schedule(nop, process);     				// calling schedule function
	
	delete [] process;

	return 0;
 }


