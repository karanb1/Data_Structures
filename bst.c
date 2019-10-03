#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct node
{
	int data;
	struct node *left;
	struct node *right;
}
struct node* search(int data){
   struct node *current = root;
   printf("Visiting elements: ");
	
   while(current->data != data){
	
      if(current != NULL) {
         printf("%d ",current->data);
			
         //go to left tree
         if(current->data > data){
            current = current->leftChild;
         }  //else go to right tree
         else {                
            current = current->rightChild;
         }
			
         //not found
         if(current == NULL){
            return NULL;
         }
      }			
   }
   
   return current;
}
void insert(int data) {
   struct node *tempNode = (struct node*) malloc(sizeof(struct node));
   struct node *current;
   struct node *parent;

   tempNode->data = data;
   tempNode->leftChild = NULL;
   tempNode->rightChild = NULL;

   //if tree is empty
   if(root == NULL) {
      root = tempNode;
   } else {
      current = root;
      parent = NULL;

      while(1) {                
         parent = current;
			
         //go to left of the tree
         if(data < parent->data) {
            current = current->leftChild;                
            //insert to the left
				
            if(current == NULL) {
               parent->leftChild = tempNode;
               return;
            }
         }  //go to right of the tree
         else {
            current = current->rightChild;
            
            //insert to the right
            if(current == NULL) {
               parent->rightChild = tempNode;
               return;
            }
         }
      }            
   }
}        
int main()
{
	int choice, element;
	printf("Binary Search Tree Operations\n1.Insertion\n2.Searching\n3.In-order Traversal\n4.Pre-Order traversal\n5.Post-order traversal\n");
	do{
		printf("Enter your choice: ");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1: printf("Enter element to search: ");
					scanf("%d", &element);
					search(element);
					break;
			case 2: printf("Enter element to insert: ");
					scanf("%d", &element);
					insert(element);
					break;
			case 3: 
		}
	}
}
