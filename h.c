/*-----------------------------------------------------------------------------------------
                                    PROGRAM-(h)

Write a C program that uses functions to perform the following:

    a. Create the binary search tree of integers
    b. Traverse the above binary search treee non recursively in order
    c. Calculate its height
    
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



tnode* stack[20];       //stack is used for non-recursive traversal

int top=-1;             //top is declared with insialised with -1

void push(tnode* x)         //function to push a node to the stack
{
    top++;
    stack[top]=x;
}

tnode* pop()                   //function to pop a node from the stack
{
    tnode* temp=(tnode*)malloc(sizeof(tnode));
    temp=stack[top];
    top--;
    return temp;
}

void traversal(tnode* t)            //function for preorder traversal non-recursively(iteratively)
{

    tnode* temp=(tnode*)malloc(sizeof(tnode));
    temp=t;

    while(1){

    while(temp)
    {
        printf("%d ",temp->data);
        push(temp);
        temp=temp->left;
    }

    if(!temp && top==-1)
    return;

    else{
        temp=pop();
        temp=temp->right;
    }


    }



}


int height(struct node* t)     //function to find the height of the given binary tree
{

    if(t==NULL)
        return 0;

    else if(t->left==NULL && t->right==NULL)
        return 0;

    else
        return(1 + (height(t->left) > height(t->right) ? height(t->left) : height(t->right)));
                    //1 + max(height(t->left),height(t->right))


}

void main()
{

    tnode* root=create();

    printf("\n Binary search tree created.\n");

    printf("\n Preorder traversal non-recursively results in : ");

    traversal(root);

    printf("\n\n Height of the given tree is: %d",height(root));


}