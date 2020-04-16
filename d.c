/*-----------------------------------------------------------------------------------------
                                    PROGRAM-(d)

Write a C program to implement a double ended queue ADT using 
    a. array and
    b. Doubly linked list respectively

-------------------------------------------------------------------------------------------
BY: DEEPANSHU MITTAL 11912056 I.T.
-------------------------------------------------------------------------------------------*/

#include<stdio.h>
#include<stdlib.h>

#define size 100        //define max size of the circular queue (say 100)

int a[size];            //double ended queue can be implemented using circular array queue
int r=-1;                   //let r denote last element of the array , a is the array, f denote first element of the array
int f=-1;


void ainsfrn()          //function to insert an element in the front of the array
{
    if((f==0 && r==size-1)|| f==r+1)
        {
            printf("\n Overflow");          //check if the array is full 
            return;
        }
    else if(f==-1)
        {
            f=0;                            //check if the array is empty
            r=0;
        }
    else if(f==0)                       //check if f=0
        f=size-1;
    else 
        f--;

    printf("\n enter the element to be inserted in front ");
    int x;
    scanf("%d",&x);         //input element to be inserted

    a[f]=x;

}

void ainslst()              //function to insert an element at rear of the array
{
    if((f==0 && r==size-1)|| f==r+1)
        {
            printf("\n Overflow");          //check if the array is full
            return;
        }
    else if(f==-1)                      //check if the array is empty
        {
            f=0;
            r=0;
        }
    else if(r==size-1)                  //check if the r is size-1
        r=0;
    else 
        r++;

    printf("\n enter the element to be inserted at last ");
    int x;
    scanf("%d",&x);         //input element to be inserted
    
    a[r] = x;

} 

void adelfrn()              //function to delete the front most element from the array
{
    if(f==-1)
    {                   //check if the array is empty
        printf("\n Underflow");
        return;
    }
    else if(f==r)
    {
        f=-1;               //check if only one element in the array 
        r=-1;
    }
    else if(f==size-1)
        f=0;                    
    else
    {
        f++;
    }
    
}

void adellst()                  //function to delete the last element of the array
{
    if(f==-1)
    {               //check if the array is empty
        printf("\n Underflow");
        return;
    }
    else if(f==r)
    {                       //check if only one element in the array
        f=-1;
        r=-1;
    }
    else if(r==0)
        r=size-1;
    else
    {
        r--;
    }
}

void aprint()               //function to print the array
{
    if (f == -1) 
    { 
        printf("\nQueue is Empty"); 
        return; 
    } 
    printf("\nElements in array are: "); 
    if (r >= f) 
    { 
        for (int i = f; i <= r; i++) 
            printf("%d ",a[i]); 
    } 
    else
    { 
        for (int i = f; i < size; i++) 
            printf("%d ", a[i]); 
        for (int i = 0; i <= r; i++) 
            printf("%d ", a[i]); 
    } 

}



struct node{
    
    int data;                   //define structure of the doubly linked list for the 
    struct node* prev;              //implementation of doubly ended queue
    struct node* next;
}* head;


void linsfrn()              //function to insert an element at the front of the list
{
    struct node* temp=(struct node*)malloc(sizeof(struct node));

    printf("\n enter the node to be inserted in the front ");
    int x;
    scanf("%d",&x);

    if(head->prev==NULL)
    {
        temp->data=x;               //if head is defined already
        temp->next=head;
        head->prev=temp;
        temp->prev=NULL;
        head=temp;

    }

    else                    //if list is empty
    {
        head->data=x;
        head->next=NULL;
        head->prev=NULL;
    }

}

void linslst()              //function to insert an element at the last of list
{
    struct node* temp=(struct node*)malloc(sizeof(struct node));

    printf("\n enter the node to be inserted in the front ");
    int x;
    
    scanf("%d",&x);
    
    temp=head;
    
    while(temp->next!=NULL)             //moving to last of the list
    {
        temp=temp->next;
    }
    
    struct node* new=(struct node*)malloc(sizeof(struct node));
    
    new->data=x;
    new->next=NULL;
    temp->next=new;
    new->prev=temp;

}

void ldelfrn()              //function to delete the front element of the list
{
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    
    temp=head;
    
    head=head->next;
    
    free(temp);

    head->prev=NULL;

}

void ldellst()          //function to delete the last element of the list
{
    struct node* temp=(struct node*)malloc(sizeof(struct node));
   
    temp=head;
   
    while(temp->next->next!=NULL)
    {
        temp=temp->next;                    //moving to the last of the list
    }
    
    free(temp->next);       
    
    temp->next=NULL;

}

void lprint()                   //function to print the list
{
    struct node* temp=(struct node*)malloc(sizeof(struct node));
   
    printf("\n Linked list is: ");
   
    temp=head;
   
    while(temp)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    
    }

}

void main()
{

    printf("\n To implement a double ended queue ADT using , press \n 1 - array \n 2 - doubly linked list\n -1 - Exit ");
    
    int wish;           //input choice from the user
    
    scanf("%d",&wish);

    if(wish!=-1)
    {

        switch(wish)
        {
            case 1: {
                            //implement using an array
                int w;
                printf("\n enter\n 1 - insert at front\n 2 - insert at last\n 3 - delete from front\n 4 - delete from last\n 5 - print the array\n -1 - Exit ");
                scanf("%d",&w);
                
                while(w!=-1)
                {
                    if(w==1)
                        ainsfrn();

                    else if(w==2)
                        ainslst();

                    else if(w==3)
                        adelfrn();

                    else if(w==4)
                        adellst();

                    else if(w==5)
                        aprint();

                    printf("\n enter\n 1 - insert at front\n 2 - insert at last\n 3 - delete from front\n 4 - delete from last\n 5 - print the array\n -1 - Exit ");
                    scanf("%d",&w);

                }
                break;
            }

            case 2: {
                            //implement using doubly linked list

                head=(struct node*)malloc(sizeof(struct node));
                int w;

                printf("\n enter\n 1 - insert at front\n 2 - insert at last\n 3 - delete from front\n 4 - delete from last\n 5 - print the list\n -1 - Exit ");
                scanf("%d",&w);

                while(w!=-1)
                {
                    if(w==1)
                        linsfrn();

                    else if(w==2)
                        linslst();
                    
                    else if(w==3)
                        ldelfrn();
                    
                    else if(w==4)
                        ldellst();
                    
                    else if(w==5)
                        lprint();
                    
                    printf("\n enter\n 1 - insert at front\n 2 - insert at last\n 3 - delete from front\n 4 - delete from last\n 5 - print the list\n -1 - Exit ");
                    scanf("%d",&w);
                
                }
                break;
            }

            default: printf("\n Invalid Choice");


        }

    }

    return;

}