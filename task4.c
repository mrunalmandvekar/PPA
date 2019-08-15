/*Problem statement: Implement circular queue using singly linked list*/
#include<stdio.h>
#include<stdlib.h> 
#include<limits.h>
typedef struct node
{ 
	int data; 
	struct node* link; 
}NODE; 

struct Queue 
{ 
	NODE *front, *rear; 
}; 


void enQueue(struct Queue *q, int value) 
{ 
	NODE *temp =(NODE*)malloc(sizeof(NODE)); 
	temp->data = value; 
	if (q->front == NULL) 
		q->front = temp; 
	else
		q->rear->link = temp; 

	q->rear = temp; 
	q->rear->link = q->front; 
} 


int deQueue(struct Queue *q) 
{ 
	if (q->front == NULL) 
	{ 
		printf ("Queue is empty"); 
		return INT_MIN; 
	} 

	
	int value; 
	if (q->front == q->rear) 
	{ 
		value = q->front->data; 
		free(q->front); 
		q->front = NULL; 
		q->rear = NULL; 
	} 
	else 
	{ 
		NODE *temp = q->front; 
		value = temp->data; 
		q->front = q->front->link; 
		q->rear->link= q->front; 
		free(temp); 
	} 

	return value ; 
} 

void displayQueue(struct Queue *q) 
{ 
	NODE *temp = q->front; 
	printf("\nElements in Circular Queue are: "); 
	while (temp->link != q->front) 
	{ 
		printf("%d ", temp->data); 
		temp = temp->link; 
	} 
	printf("%d", temp->data); 
} 


int main() 
{ 
	int ch,num,x;
	struct Queue *q =(struct Queue*)malloc(sizeof(struct Queue)); 
	q->front = q->rear = NULL;
	
    do{
        printf("\nQueue operation=\n1.Insert\n2.Delete\n3.Print\n4.Exit");
        printf("\nEnter your choice=");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            printf("\nEnter element to Insert=");
            scanf("%d",&num);
            enQueue(q,num);
            break;
            case 2:
            printf("\nDeleted value = %d", deQueue(q));
            break;
            case 3:
            displayQueue(q);
            break;
            case 4:
            exit(0);
            default:
            printf("\nWrong choice!");
        }

    }while(ch>0 && ch<6);
    return 0;
	return 0; 
} 
/*Output:
mrunal@mrunal:~/sem3/ppa$ gcc task4.c
mrunal@mrunal:~/sem3/ppa$ ./a.out

Queue operation=
1.Insert
2.Delete
3.Print
4.Exit
Enter your choice=1

Enter element to Insert=22

Queue operation=
1.Insert
2.Delete
3.Print
4.Exit
Enter your choice=1

Enter element to Insert=33

Queue operation=
1.Insert
2.Delete
3.Print
4.Exit
Enter your choice=1

Enter element to Insert=44

Queue operation=
1.Insert
2.Delete
3.Print
4.Exit
Enter your choice=1

Enter element to Insert=55

Queue operation=
1.Insert
2.Delete
3.Print
4.Exit
Enter your choice=3

Elements in Circular Queue are: 22 33 44 55
Queue operation=
1.Insert
2.Delete
3.Print
4.Exit
Enter your choice=2

Deleted value = 22
Queue operation=
1.Insert
2.Delete
3.Print
4.Exit
Enter your choice=3

Elements in Circular Queue are: 33 44 55
Queue operation=
1.Insert
2.Delete
3.Print
4.Exit
Enter your choice=2

Deleted value = 33
Queue operation=
1.Insert
2.Delete
3.Print
4.Exit
Enter your choice=3

Elements in Circular Queue are: 44 55
Queue operation=
1.Insert
2.Delete
3.Print
4.Exit
Enter your choice=4
mrunal@mrunal:~/sem3/ppa$ 
*/
