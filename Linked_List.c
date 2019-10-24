#include<stdio.h>
#include<stdlib.h>
int count = 0;
struct node{
	int data;
	struct node *next;
};
struct node *start = NULL;
void insertFront(int a)
{
	struct node *n = (struct node*)malloc(sizeof(struct node));
	if(n == NULL)
	{
		printf("Overflow!"); return;
	}
	n -> data = a;
	if(start == NULL)
		n -> next = NULL;
	else 
		n -> next = start;
	start = n;
	count++;
}
void insertRear(int a)
{
	struct node *n = (struct node*)malloc(sizeof(struct node));
	if(n == NULL)
	{ printf("Overflow!"); return;}
	n -> data = a;
	struct node *trv = start;
	if(start == NULL)
		start = n;
	else
	{
		while(trv -> next != NULL)
			trv = trv -> next;
		trv -> next = n;
	}
	n -> next = NULL;
	count++;
}
void insertPos(int a, int pos);
void deleteFront()
{
	if(start == NULL)
	{printf("List is Empty!\n"); return;}
	struct node *temp = start, *trv = start -> next;
	if(trv == NULL)
		start = NULL;
	else
		start = trv;
	free(temp);
	count--;
}
void deleteRear()
{
	if(start == NULL)
	{printf("List is Empty!\n"); return;}
	struct node *temp = start, *trv = start -> next;
	if(trv == NULL)
		start = NULL;
	else
	{
		while((trv -> next) -> next != NULL)
			trv = trv -> next;
		temp = trv -> next;
		trv -> next = NULL;
	}
	free(temp);
	count--;
}
void deletePos(int pos);
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
	//printf("Linked List Operations: \n1.Insert at front\n2.Insert at rear\n3.Insert at a specified location\n");
	//printf("4.Delete at front\n5.Delete at rear\n6.Delete at specified location\n7.List\n8.Exit\n");
	printf("Linked List Operations: \n1.Insert at front\n2.Insert at rear\n");
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
/*			case 3: printf("Enter element to insert and postion: ");
					scanf("%d %d", &a, &pos);
					insertPos(a, pos);
					break;*/
			case 3:	deleteFront();
					break;
			case 4:	deleteRear();
					break;
/*			case 6: printf("Enter positon of node: ");
					scanf("%d", &pos);
					deletePos(pos);
					break;*/
			case 5:	traverse();
					break;
		}
	}while(ch != 6);
	return 0;
}
