/*-----------------------------------------------------------------------------------------
                                    PROGRAM-(b)
                                
Write a C program that uses functions to perform the following:

    a. Create the doubly linked list of integers
    b. Delete a given integer from the above doubly linked list
    c. Display the contents of the above doubly linked list after deletion

-------------------------------------------------------------------------------------------
BY: DEEPANSHU MITTAL 11912056 I.T.
-------------------------------------------------------------------------------------------*/

#include<stdio.h>
#include<stdlib.h>


struct node{                        //defining doubly linked list structure
    int data;
    struct node* next;
    struct node* prev;
}* head;


void create(int n)              //function to create the structure of the doubly linked list
{

    int data;

    struct node* temp=(struct node*)malloc(sizeof(struct node));
    head=(struct node*)malloc(sizeof(struct node));

    printf("\n enter the 1'th element of the list ");

    scanf("%d",&data);

    temp=head;
    head->data=data;
    head->prev=NULL;
    head->next=NULL;

    for(int i=2;i<=n;i++)
    {

        printf("\n enter the %d'th element of the list ",i);
        scanf("%d",&data);

        struct node* new=(struct node*)malloc(sizeof(struct node));
        new->data=data;
        new->next=NULL;
        new->prev=temp;
        temp->next=new;
        temp=temp->next;

    }
    

    printf("\n Linked List created.");


}


void deleten(int x)                 //function to delete the given number
{

    if(head->data==x)       //if the node to be deleted is present at the beginning of the linked list
    {

        struct node* temp=(struct node*)malloc(sizeof(struct node));
        temp=head;
        head=head->next;
        head->prev=NULL;

        free(temp);

        return;

    }

    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp=head;


    while(temp->next->data!=x)
    {
        temp=temp->next;
    }

    struct node* temp1=(struct node*)malloc(sizeof(struct node));
    temp1=temp->next;
    temp->next=temp->next->next;

    if(temp->next!=NULL)
        temp->next->prev=temp;

    free(temp1);

}


void printn()                   //function to print the doubly linked list
{

    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp=head;

    printf("\n Linked List is: ");

    while(temp)
    {
        printf("%d ",temp->data);

        temp=temp->next;

    }

}


void main()                     
{

    int n;

    printf("\nenter the number of nodes ");
    scanf("%d",&n);

    create(n);         

    printn();
    
    int x;

    printf("\n enter the number to delete ");
    scanf("%d",&x);

    deleten(x);
    
    printn();


}