/*-----------------------------------------------------------------------------------------
                                    PROGRAM-(e)

Write a C program that uses functions to perform the following:

    a. create a binary search tree of characters
    b. travesre the above binary search tree recursively in postorder, inorder and preorder

-------------------------------------------------------------------------------------------
BY: DEEPANSHU MITTAL 11912056 I.T.
-------------------------------------------------------------------------------------------*/

#include<stdio.h>
#include<stdlib.h>


typedef struct node{                    //defining structure of the tree node
    char data;                            //I will use tnode instead of struct node in the further program now       
    struct node* left;
    struct node* right;

} tnode;


tnode* create()                         //function to create the binary tree
{

    tnode* new=(tnode*)malloc(sizeof(tnode));

    int x;

    printf("\n enter the node data (-1 for no node) ");

    scanf("%d",&x);

    if(x==-1)
    {
        return NULL;
    }

    new->data=x;

    printf("\n enter the left node of node %d",new->data);
    new->left=create();

    printf("\n enter the right node of node %d",new->data);
    new->right=create();
    
    return new;

}

void postorder(struct node* t)      //function to traverse in postorder
{   
    if(t==NULL)
    return;

    postorder(t->left);

    postorder(t->right);

    printf("%c ",t->data);

} 

void inorder(struct node* t)            //function to traverse in inorder
{   

    if(t==NULL)
    return;

    inorder(t->left);
 
    printf("%c ",t->data);
 
    inorder(t->right);

}      

void preorder(struct node* t)           //function to traverse in preorder
{   
    if(t==NULL)
    return;
 
    printf("%c ",t->data);
 
    preorder(t->left);
 
    preorder(t->right);

}    


void main()                                         
{
    tnode* root= create();

    printf("\n Postorder traversal: ");
    postorder(root);

    printf("\n Inorder traversal: ");
    inorder(root);

    printf("\n Preorder traversal: ");
    preorder(root);

}
