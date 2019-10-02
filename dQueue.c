// To implement dequeue operations using an array.

#include<stdio.h>
#include<stdlib.h>

#define MAX 100

int front = -1, rear = -1, dqueue[MAX];

// Function to insert at right of the queue.
void insert_right()
{
    int item;
    if((front == 0 && rear== MAX - 1) || (front == rear + 1))
      printf("Overflow error\n");
    if(front == -1)
    {       
	    front=0;
      rear=0;
	  }
    else
      if(rear==max-1)
	  rear = 0;
    else
    rear=rear+1;
    printf("Input the element for adding in queue : ");
    scanf("%d", &item);
    dqueue[rear]=item;
    Sleep(1000);
}

// Function to insert at left of the queue.
void insert_left()
{       
    int item;
    if((front==0 && rear==max-1) || (front==rear+1))
    {       
	  printf("Overflow error\n");
      Sleep(2000);
	}
    if (front==-1)
    {       
	 front=0;
     rear=0;       
    }
    else
     if(front==0)
      front=max-1;
    else
     front=front-1;
    printf("Input the element for adding in queue : ");
    scanf("%d", &item);
    dqueue[front]=item;   
	Sleep(1000);   
}

// Function to delete at the left of the queue.
void delete_left()
{       
    if (front==-1)
    {      
	  printf("Underflow error\n");
      Sleep(2000); 
    }
    printf("Element deleted from queue is : %d\n",dqueue[front]);
    if(front==rear)
	{       
	  front=-1;
      rear=-1;        
    }
    else
     if(front==max-1)
      front=0;
    else
    {
     front=front+1;
     Sleep(2000);
    }
}

// Function to delete at the right of the queue.
void delete_right()
{
  if (front==-1)
  {
    printf("Underflow error\n");
    Sleep(2000);        
  }
    printf("Element deleted from queue is : %d\n",dqueue[rear]);
    if(front==rear)
    {       
	 front=-1;
     rear=-1;        
    }
    else
     if(rear==0)
      rear=max-1;
    else
    {
     rear=rear-1;   
	 Sleep(2000);  
    } 
}

// Function to display the queue.
void display_queue()
{       
  int front_pos=front,rear_pos=rear;
    if(front==-1)
    {       
	  printf("Queue is empty\n");
      Sleep(2000); 
	}
    printf("Queue elements :\n");
    if(front_pos<=rear_pos)
    {       
	 while(front_pos<=rear_pos)
     {       
	   printf("%d ",dqueue[front_pos]);
       front_pos++;    
	 }       
	 Sleep(2000);
	}
    else
    {       
	 while(front_pos<=max-1)
     {       
	   printf("%d ",dqueue[front_pos]);
       front_pos++;    
	 }
     front_pos=0;
     while(front_pos<=rear_pos)
     {      
	  printf("%d ",dqueue[front_pos]);
      front_pos++;
     }
     Sleep(2000);
    }
    printf("\n");
}

// Menu for input queue.
void input_que()
{       
  int choice;
  do
  {  
   system("cls");     
   printf("1.Insert at right\n");
   printf("2.Delete from left\n");
   printf("3.Delete from right\n");
   printf("4.Display\n");
   printf("5.Quit\n");
   printf("Enter your choice : ");
   scanf("%d",&choice);
   switch(choice)
   { 
    case 1:insert_right();
           display_queue();
           break;
    case 2:delete_left();
           display_queue();
           break;
    case 3:delete_right();
           display_queue();
            break;
    case 4:display_queue();
           break;
    case 5:exit;
    default:printf("Wrong choice\n");
   }
  }while(choice!=5);
}

// Menu for output queue.
void output_que()
{ 
    int choice;
    do
    {
      system("cls");
	  printf("1.Insert at right\n");
      printf("2.Insert at left\n");
      printf("3.Delete from left\n");
      printf("4.Display\n");
      printf("5.Quit\n");
      printf("Enter your choice : ");
      scanf("%d",&choice);
      switch(choice)
      {
        case 1:insert_right();
               display_queue();
               break;
        case 2:insert_left();
               display_queue();
               break;
        case 3:delete_left();
               display_queue();
               break;
        case 4:display_queue();
               break;
        case 5:exit;
        default:printf("Wrong choice\n");
       }
      }while(choice!=5);
}

int main()
{       
  int choice;
  do
  {
  	system("cls");
    printf("1.Input restricted dequeue\n");
    printf("2.Output restricted dequeue\n");
    printf("3.Quit \n");
    printf("Enter your choice : \n");
    scanf("%d",&choice);
    switch(choice)
    {
     case 1 :input_que();
             break;
     case 2:output_que();
            break;
     case 3:exit(0);
  }
 }while(choice!=3);
 return 0;
}
