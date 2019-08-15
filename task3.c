/*Implement FCFS */

#include<stdio.h>
#include<stdlib.h>
int count=0;
typedef struct node
{
    int process;
    int bt,at,ct,tat,wt;
    struct node *next;
}QUEUE;
QUEUE *front=NULL;
QUEUE *rear=NULL;


void enqueue(int process,int at,int bt)
{
QUEUE *temp=(QUEUE*)malloc(sizeof(QUEUE));
temp->process=process;
temp->bt=bt;
temp->at=at;
temp->ct=0;
temp->wt=0;
temp->tat=0;
temp->next=NULL;
if(rear==NULL)
{
    front=rear=temp;
    return;
}
else
{
    rear->next=temp;
    rear=temp;
}

}
void cal()
{
    QUEUE *temp=front;
    int CT[count],WT[count],TAT[count];
    for(int i=0;i<count;i++)
        {
            if(i==0)
            {
                CT[i]=temp->bt;
                TAT[i]=CT[i]-temp->at;
                WT[i]=TAT[i]-temp->bt;
                temp->ct=CT[i];
                temp->tat=TAT[i];
                temp->wt=WT[i];
                temp=temp->next;
            }
            else
            {
             
            CT[i]=CT[i-1]+temp->bt;
            TAT[i]=CT[i]-temp->at;
            WT[i]=TAT[i]-temp->bt;
            temp->ct=CT[i];
            temp->tat=TAT[i];
            temp->wt=WT[i];
            temp=temp->next;
        }
        }
        
}

void sort()
{
    QUEUE *p=front,*q,*tmp;
    tmp=(QUEUE*)malloc(sizeof(QUEUE));
    while(p&&q)
    {
               
        q=p;
        p=p->next;
        if(p->bt<q->bt)
        {
            tmp=p;
            q->next=p->next;
            p->next=q;
            
        }
    }
    front=p;
    free(tmp);
}


void printQueue()
{
QUEUE *temp=front;
printf("\nProcess:\nProcessId\tArrival Time\tBurst Time\n");
while(temp!=NULL)
{
    printf("%d\t\t%d\t\t%d\n",temp->process,temp->at,temp->bt);
    temp=temp->next;
}
}


void print()
{
QUEUE *temp=front;
int avgwt=0,i,avgtat=0;
printf("\nProcess:\nProcessId\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");
while(temp!=NULL)
{
    printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",temp->process,temp->at,temp->bt,temp->ct,temp->tat,temp->wt);
    avgwt=avgwt+temp->wt;
    avgtat=avgtat+temp->tat;
    temp=temp->next;
}
printf("\nAverage turn around time is %f",(float)avgtat/(float)count);
printf("\nAverage waiting time is %f",(float)avgwt/(float)count);
}

    
void inputProcess()
{
    int i,n,at,bt;
    printf("\nEnter no of process:");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        
        printf("\nEnter arrival time:");
        scanf("%d",&at);
        printf("\nEnter burst time:");
        scanf("%d",&bt);
        enqueue(i,at,bt);
        count++;

    }
}


int main()
{
    inputProcess();
    cal();
    //printQueue();
    sort();
    printQueue();
    print();   
    return 0;
}
/*Output:
mrunal@mrunal:~/placement$ gcc fcfs.c
mrunal@mrunal:~/placement$ ./a.out 

Enter no of process:3

Enter arrival time:0

Enter burst time:2

Enter arrival time:1

Enter burst time:4

Enter arrival time:2

Enter burst time:5

Process:
ProcessId	Arrival Time	Burst Time
0		0		2
1		1		4
2		2		5

Process:
ProcessId	Arrival Time	Burst Time	Completion Time	Turnaround Time	Waiting Time
0		0		2		2		2		0
1		1		4		6		5		1
2		2		5		11		9		4

Average turn around time is 5.333333
Average waiting time is 1.666667
mrunal@mrunal:~/placement$ 
*/
