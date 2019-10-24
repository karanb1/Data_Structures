#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data = 0;
    struct node *next = NULL;
};
struct node *start = NULL;
int count = 0;
void insertFront(int a)
{
	struct node *n = (struct node*)malloc(sizeof(struct node));
	if(n == NULL)
	{printf("Overflow!"); return;}
	n -> data = a;
	if(start == NULL)
		n -> next = start;
	else 
		n -> next = start;
	start = n;
	count++;
}
int main()
{
    int ch, a, pos;
	printf("Circular Linked List Operations: \n1.Insert at front\n2.Insert at rear\n");
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