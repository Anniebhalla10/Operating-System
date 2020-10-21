/* Name : Annie Bhalla
   Roll No. : 19HCS4009
   Course : BSC (H) Computer Science
   Semester : 3
   Subject : Operating System
   Title : First Come First Serve Scheduling
*/

#include<iostream>
using namespace std;

int main()
{
	int nop ;                              // nop= number of processes
	int *burst;                            // array to store burst time of each process
	float avg_wait_time=0;                //  used to calcuate avg waiting time
	cout<<"\n Enter the number of processes : ";
	cin>>nop;
	burst= new int[nop];
	cout<<"\n Enter the burst time of each process"<<endl;
	for(int i=0;i<nop;i++)
	{
		cin>>burst[i];
	}
	int arrival_time=0; // all processes arrive at t=0 in the ready queue
	int *TA_time;          //TA = turn around
	TA_time= new int[nop+1];
	TA_time[0]=0;
	for(int i=1;i<=nop+1;i++)
	{
		TA_time[i]= burst[i-1]+ TA_time[i-1];
	}
	
	// here the TA= FT - AT and since the AT is same for all processes ie 0, FT=TA
	//Printing Turn around time 
	cout<<"\n *** Turn Around Time ***";
	for(int i=1;i<nop+1;i++)
	{
		cout<<"\n Proess P "<<i+1<<"  :  "<<TA_time[i]<<endl;
	}
	cout<<endl;
	// displaying waiting time for all processes and also finding out the avg waiting time
	cout<<"\n *** Waiting Time ***";
		for(int i=0,k=1;i<nop;i++,k++)
	{
		int x = TA_time[k]-burst[i];
		avg_wait_time += x;
		cout<<"\n Proess P "<<k<<"  :  "<<x<<endl;
	}
	
	avg_wait_time = avg_wait_time/nop;
	cout<<endl<<endl<<" Average Waiting Time is :"<< avg_wait_time;
	delete [] burst;
	delete [] TA_time;
	return 0;
}
