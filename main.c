//
//  main.c
//  binary tree
//
//  Created by karan balodi on 19/11/19.
//  Copyright © 2019 kar. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

struct tree {
    int info;
    struct tree* left;
    struct tree* right;
};


  struct tree *insert(struct tree *root, int x) {
      if(root == NULL) {
          root=(struct tree*)malloc(sizeof(struct tree));
          root->info = x;
          root->left = NULL;
          root->right = NULL;
          return(root);
      }
      if(root->info > x)
           root->left = insert(root->left,x);
      else {
          if(root->info < x)
              root->right = insert(root->right,x);
      }
      return(root);
  }
  void inorder(struct tree *root) {
      if(root != NULL) {
          inorder(root->left);
          printf(" %d",root->info);
          inorder(root->right);
      }
      return;
  }
   
void post(struct tree *root) {
    if(root != NULL) {
        post(root->left);
        post(root->right);
        printf(" %d",root->info);
    }
    return;
}

void pre(struct tree *root) {
    if(root != NULL) {
        printf(" %d",root->info);
        pre(root->left);
        pre(root->right);
        
    }
    return;
}

struct tree* delete(struct tree* root, int x){
    struct tree *p1,*p2;
    if(root == NULL){
        printf("\n Node Not Found");
        return(root);
    }
    else{
        if(root->info > x){
            root->left = delete(root->left,x);
            return root;
        }
        else if(root->info < x){
            root->right = delete(root->right,x);
            return root;
    }
        else
            if(root->info == x){
                if(root->left == root->right){
                    free(root);
                    return(NULL);
                }
                else if(root->left == NULL){
                    p1 = root->right;
                    free(root);
                    return p1;
                }
                else if(root->right == NULL){
                    p1 = root->left;
                    free(root);
                    return p1;
                }
                else{
                    p1=root->right;
                    p2=root->right;
                    while(p1->left != NULL){
                        p1 = p1->left;
                        p1->left = root->left;
                        free(root);
                        return p2;
                    }
                }
            }
        return(root);
    }
}


int main() {
    int choice,item;
    struct tree* root=NULL;
    do{
        printf("Enter 1 to insert, 2 for postorder, 3 for preorder,4 to delete");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("\n Enter element to be inserted");
                scanf("%d",&item);
                root = insert(root,item);
                printf("\n root is %d",root->info);
                printf("\n Inorder traversal of binary tree is : ");
                inorder(root);
                break;
                case 2:
                post(root);
                break;
                case 3:
                pre(root);
                break;
                case 4:
                printf("Enter item to be deleted");
                scanf("%d",&item);
                root = delete(root,item);
                break;
                
        }
    }
    while(choice == 1|| choice == 2||choice == 3|| choice == 4);
}
