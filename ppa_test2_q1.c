/*Problem statement:
Implement a Queue using linked list.
Functions to be implemented :-
1.) enqueue // to insert into the queue.
2.) dequeue // to delete from the queue.
3.) peek // to display the current element in the queue.*/

#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
int data;
struct node *next;
}NODE;
NODE *front=NULL;
NODE *rear=NULL;


void enqueue(int x)
{
NODE *temp=(NODE*)malloc(sizeof(NODE));
temp->data=x;
temp->next=NULL;
if(rear==NULL)
{
front=rear=temp;
return;
}
rear->next=temp;
rear=temp;
}

void dequeue()
{
NODE *temp=front;
if(front==NULL)
	{
	return;
	}
if(front==rear)
	{
	front=rear=NULL;
	}
else
	{
	front=front->next;
	}
free(temp);
}

int peek()
{
return front->data;
}


void print()
{
NODE *temp=front;
while(temp!=NULL)
{
printf("%d\t",temp->data);
temp=temp->next;
}
}

int main()
{
int ch,num,x;
    do{
        printf("\nQueue operation=\n1.Insert\n2.Delete\n3.Print\n4.Peek\n5.Exit");
        printf("\nEnter your choice=");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            printf("\nEnter element to Insert=");
            scanf("%d",&num);
            enqueue(num);
            break;
            case 2:
            dequeue();
            break;
            case 3:
            print();
            break;
            case 4:
            x=peek();
            printf("\npeeked element is=%d",x);
            break;
            case 5:
            exit(0);
            default:
            printf("\nWrong choice!");
        }

    }while(ch>0 && ch<6);
    return 0;
}
/*mrunal@mrunal:~/placement$ gcc queuell.c 
mrunal@mrunal:~/placement$ ./a.out

Queue operation=
1.Insert
2.Delete
3.Print
4.Peek
5.Exit
Enter your choice=1

Enter element to Insert=11

Queue operation=
1.Insert
2.Delete
3.Print
4.Peek
5.Exit
Enter your choice=1

Enter element to Insert=22

Queue operation=
1.Insert
2.Delete
3.Print
4.Peek
5.Exit
Enter your choice=1

Enter element to Insert=33

Queue operation=
1.Insert
2.Delete
3.Print
4.Peek
5.Exit
Enter your choice=1

Enter element to Insert=44

Queue operation=
1.Insert
2.Delete
3.Print
4.Peek
5.Exit
Enter your choice=1

Enter element to Insert=55

Queue operation=
1.Insert
2.Delete
3.Print
4.Peek
5.Exit
Enter your choice=3
11	22	33	44	55	
Queue operation=
1.Insert
2.Delete
3.Print
4.Peek
5.Exit
Enter your choice=4

peeked element is=11
Queue operation=
1.Insert
2.Delete
3.Print
4.Peek
5.Exit
Enter your choice=2

Queue operation=
1.Insert
2.Delete
3.Print
4.Peek
5.Exit
Enter your choice=3
22	33	44	55	
Queue operation=
1.Insert
2.Delete
3.Print
4.Peek
5.Exit
Enter your choice=5
mrunal@mrunal:~/placement$ 
 */