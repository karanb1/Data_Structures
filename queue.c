#include<stdio.h>
#include<stdlib.h>
#define MAX 100
int queue[MAX];
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
		queue[rear] = a;
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

void display()
{
  int i;
  for(i = front; i <= rear; i++)
    printf("%d ", queue[i]);
  printf("\n");
  return;
}

int main()
{
    int ch, e;
    printf("Queue Operations\n1.EnQueue\n2.DeQueue\n3.Traverse\n");
    printf("4.Exit\n");
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
      case 3: display();
              break;
    }
    } while(ch != 4);
    return 0;    
}