#include<stdio.h>
#include<conio.h>
int count;
count = 0;
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
	return;
}
void insertRear(int a)
{
	struct node *n = (struct node*)malloc(sizeof(struct node));
	if(n == NULL)
	{
		printf("Overflow!"); return;
	}
	count++;
	struct node *trv = start;
	while(trv != NULL)
		trv = trv -> next;
	n -> data = a;
	trv = n;
	n -> next = NULL;
	return;
}
void insertPos(int a, int pos);
void deleteFront();
void deleteRear();
void deletePos(int pos);
void traverse()
{
	struct node *trv = start;
	while(trv != NULL)
	{
		printf("%d ->", trv -> data);
		trv = trv -> next;
	}
	printf("end\n");
}
int main()
{
	int ch, a, pos;
	printf("Linked List Operations: \n1.Insert at front\n2.Insert at rear\n3.Insert at a specified location\n");
	printf("4.Delete at front\n5.Delete at rear\n6.Delete at specified location\n7.List\n8.Exit");
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
			case 3: printf("Enter element to insert and postion: ");
					scanf("%d %d", &a, &pos);
					insertPos(a, pos);
					break;	
			case 4:	deleteFront();
					break;
			case 5:	deleteRear();
					break;
			case 6: printf("Enter positon of node: ");
					scanf("%d", &pos);
					deletePos(pos);
					break;
			case 7:	traverse();
					break;
			case 8:	break;
		}
	}while(ch != 8);
	return 0;
}
