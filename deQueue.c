//To implement operations of deQueue : Doubly ended queue. 
//Elements can be inserted at both front and rear. 
//Elements can also be inserted at both front and rear. 
#include<stdio.h>
#include<stdlib.h>
#define MAX 100
int dequeue[MAX];

int front = -1, rear = -1;

int getElement()
{
  int a;
  printf("Enter Element: ");
  scanf("%d", &a);
  return a;
}

void enQueue(int a)
{
	if(rear + 1 == MAX)
      printf("Overflow!\n");
	else
	{
		if(front == -1) front = 0;
		rear = (rear + 1) % MAX;
		dequeue[rear] = a;
		printf("Element is added\n");
	} 
}

void deQueue()
{
  if(front == -1)
    printf("Queue Empty!\n");
  else if(front == MAX - 1)
    front = -1, rear = -1;
  else front++;
  return;  
}

void insertFront(int a)
{
  if(rear - front + 1 == MAX)
    printf("Overflow!\n");
  else if(front > 0)
  {
    front--;
    dequeue[front] = a;
  }
  else
  {
    int i;
    for(i = rear; i >= 0; i--)
      dequeue[i + 1] = dequeue[i];
    dequeue[0] = a;
    rear++;
  }
  return;
}

void deleteRear()
{
  if(front == -1)
    printf("Empty Queue!\n");
  else if(front == rear)
    front = -1, rear = -1;
  else rear--;
  return;
}

void display()
{
  int i;
  for(i = front; i <= rear; i++)
    printf("%d ", dequeue[i]);
  printf("\n");
  return;
}

int main()
{
  int ch, e;
  printf("Operations on Doubly Ended Queue:\n1.Enque\n2.Deque\n");
  printf("3.Insert at front\n4.Delete at rear\n5.Traverse\n6.Exit\n");
  do
  {
    printf("Enter your choice: ");
    scanf("%d", &ch);
    switch(ch)
    {
      case 1: e = getElement();
              enQueue(e);
              display();
              break;
      case 2: deQueue();
              display();
              break;
      case 3: e = getElement();
              insertFront(e);
              display();
              break;
      case 4: deleteRear();
              display();
              break;
      case 5: display();
              break;
    }
  }while(ch != 6);
  return 0;
}