#include<stdio.h>
#include<stdlib.h>
int count = 0;
struct node{
	int data;
	struct node *next = NULL;
    struct node *prev = NULL;
};
struct node *start = NULL;
void insertFront(int a)
{
	struct node *n = (struct node*)malloc(sizeof(struct node));
	if(n == NULL)
	{printf("Overflow!"); return;}
	n -> data = a;
	if(start == NULL)
		n -> next = NULL;
	else 
		n -> next = start;
	n -> prev = NULL;
	start = n;
	count++;
}
void insertRear(int a)
{
	struct node *n = (struct node*)malloc(sizeof(struct node));
	if(n == NULL)
	{printf("Overflow!\n"); return;}
	n -> data = a;
	struct node *trv = start;
	if(start == NULL)
	{
		n -> prev = NULL;
		start = n;
	}
	else
	{
		while(trv -> next != NULL)
			trv = trv -> next;
		trv -> next = n;
		n -> prev = trv;
	}
	n -> next = NULL;
	count++;
}
void deleteFront()
{
	if(start == NULL)
	{printf("Empty List!\n"); return;}
	struct node *temp = start;
	start = temp -> next;
	start -> prev = NULL;
	free(temp);
	count--;
}
void deleteRear()
{
	if(start == NULL)
	{printf("List Empty!\n"); return;}
	struct node *trv = start, *temp = NULL;
	if(start -> next == NULL)
	{	
		temp = start;
		start = NULL;
	}
	else
	{	
		while((trv -> next) -> next != NULL)
			trv = trv -> next;
		temp = trv -> next;
		trv -> next = NULL;
	}
	free(temp);
}
void traverse()
{
	printf("start -> ");
	struct node *trv = start;
	while(trv != NULL)
	{
		printf("%d -> ", trv -> data);
		trv = trv -> next;
	}
	printf("end\n");
}
int main()
{
	int ch, a, pos;
	printf("Doubly Linked List Operations: \n1.Insert at front\n2.Insert at rear\n");
	printf("3.Delete at front\n4.Delete at rear\n5.List\n6.Exit\n");
	do{
		printf("Enter your choice: ");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1:	printf("Enter element to insert: ");
					scanf("%d", &a);
					insertFront(a);
					break;
			case 2:	printf("Enter element to insert: ");
					scanf("%d", &a);
					insertRear(a);
					break;
			case 3:	deleteFront();
					break;
			case 4:	deleteRear();
					break;
			case 5:	traverse();
					break;
		}
	}while(ch != 6);
	return 0;
}
