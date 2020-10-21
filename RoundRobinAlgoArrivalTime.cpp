/* Name : Annie Bhalla
   Roll No. : 19HCS4009
   Course : BSC (H) Computer Science
   Semester : 3
   Subject : Operating System
   Title : Round Robin Scheudling ( always Preemptive) with Arrival Time
*/


#include<iostream>
#include<vector>
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
	bool arrived=0;
};

// (1) to enter the details of all processes 

void input(int len, RRobin obj[])
 {
 		for(int i=0;i<len;i++)
	{
		cout<<"\n Enter Arrival Time and Burst Time "<<i+1<<" : "<<endl;	
		cin>>obj[i].arrivalTime>>obj[i].burstTime;
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
 
class Node
{
    public:
    struct RRobin process;
    Node *next;
};
class Queue
{
    Node *head,*tail;
    public:
    Queue(){head = tail = NULL;}
    void addback(RRobin p)
    {
        Node *add = new Node();
        add->process = p;
        add->next = NULL;
        if(head==NULL){head = tail = add;}
        else {tail->next = add; tail = add;}
    }
    int removefront()
    {
        if(head == NULL)
            return -1;
        Node *del = head;
        head = del->next;
        int n = del->process.id;
        return n;
    }
    void display()
    {
        if(head == NULL)
            cout<<"\nEmpty List\n";
        else
        {
            Node *pt = head;
            while(pt!=NULL)
            {
                cout<<pt->process.id<<"  ";
                pt=pt->next;
            }
            cout<<"\n";
        }
    }
    void addNewProcesses(RRobin process[],int nop,int timer)
    {
        for(int i = 0;i<nop;i++)
        {
            if(process[i].arrived == 0 && process[i].arrivalTime<=timer)
            {
                addback(process[i]);
                process[i].arrived = 1;
            }
        }
    }
};

// Scheduling algo

void schedule(int nop,RRobin process[])
{
    Queue readyqueue;
    int completed = 0,timer = 0;
    readyqueue.addNewProcesses(process,nop,timer);
    while(completed!=nop)
    {
        int p = readyqueue.removefront();
        if(p == -1)
		{
		timer++;
		continue;
		}
        if(process[p].remaining_bt<=time_quantum)
        {
            timer += process[p].remaining_bt;
            process[p].remaining_bt = 0;
            process[p].finishTime = timer;
            process[p].turnaroundTime = process[p].finishTime - process[p].arrivalTime;
            process[p].waitingTime = process[p].turnaroundTime - process[p].burstTime;
            completed++;
            readyqueue.addNewProcesses(process,nop,timer);
        }
        else
        {
            timer += time_quantum;
            process[p].remaining_bt -= time_quantum;
            readyqueue.addNewProcesses(process,nop,timer);
            readyqueue.addback(process[p]);
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
 
 
