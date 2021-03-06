/*-----------------------------------------------------------------------------------------
                                    PROGRAM-(g)

Write a C program to calculate 

    a. no. of leaf and non-leaf nodes in a binary tree
    
-------------------------------------------------------------------------------------------
BY: DEEPANSHU MITTAL 11912056 I.T.
-------------------------------------------------------------------------------------------*/

#include<stdio.h>
#include<stdlib.h>


typedef struct node{  
                      //defining structure of the tree node
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


int no_of_leaf_nodes(struct node* t)     //function to count the no. of leaf nodes in the givenn binary tree
{

    if(t==NULL)
        return 0;
    else if(t->left==NULL && t->right==NULL)
        return 1;
    else
        return(no_of_leaf_nodes(t->left) + no_of_leaf_nodes(t->right));


}

int no_of_non_leaf_nodes(struct node* t)     //function to count the no. of non-leaf nodes in the givenn binary tree
{

    if(t==NULL)
        return 0;
    else if(t->left==NULL && t->right==NULL)
        return 0;
    else
        return(1 + no_of_non_leaf_nodes(t->left) + no_of_non_leaf_nodes(t->right));


}


void main()                                         
{

    tnode* root=create();

    printf("\n The number of leaf-nodes in the above binary tree are = %d",no_of_leaf_nodes(root));

    printf("\n The number of non-leaf-nodes in the above binary tree are = %d",no_of_non_leaf_nodes(root));


}
