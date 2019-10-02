// Circular queue operations using arrays.

#include<stdio.h>
#include<stdlib.h>

#define MAX 100

int front = -1, rear = -1;

int cqueue[MAX];

// Function to add a number in a circular queue.
void add(int no)
{
	if((rear + 1) % MAX == front)
	{
		printf("Overflow!\n");
    }
	else
	{
		if(front == -1) front = 0;
		rear = (rear + 1) % MAX;
		cqueue[rear] = no;
		printf("Element is added\n");
	} 
}

// Function to remove an element in a circular queue.
void deletion()
{
	if(front==rear) printf("Underflow!\n");
	else front=(front+1) % MAX;
}

// Function to display a circular queue.
void display()
{
	int i = front;
	for(; i <= rear; i = (++i) % MAX) printf("%d ", cqueue[i]);
	printf("\n");
}

void main()
{
	int ch,no;
	printf("Circular Queue Operations Menu: \n");
	printf("1. EnQueue \n2. DeQueue \n3. Traverse \n4. Exit\n");
	do
	{
		printf("Enter your choice: ");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1:printf("Enter the number to be inserted: ");
			       scanf("%d", &no);
			       add(no);
			       display();
			       break;
			case 2:deletion();    
			       display();
				   break;
		    case 3:display();
			       break;
		}
	}while(ch!=4);
}
