/*-----------------------------------------------------------------------------------------
                                    PROGRAM-(c)

Write a C program that uses stack operations to convert a given infix expression into its 
postfix equivalent, implement the stack using array

-------------------------------------------------------------------------------------------
BY: DEEPANSHU MITTAL 11912056 I.T.
-------------------------------------------------------------------------------------------*/


#include<stdio.h>
#include<ctype.h>
#include<string.h>


char stack[20];                     //declaring stack with char datatype

int top=-1;

int priority(char c)                   //function to return priorities of the operators
{

    if(c=='^')
    return 3;

    else if(c=='*' || c=='/')
    return 2;

    else if(c=='+'||c=='-')
    return 1;

}


void push(char n)                       //function to push operators into the stack
{

    top++;
    stack[top]=n;

}

char pop()                              //function to pop elements from the stack
{

    if(top>=0)
    {

        char r=stack[top];
        top--;

        return r;

    }
     
}

void main()                     
{

    char infix[20];
    char postfix[20];

    int k=0;

    printf("\nenter the infix expression: ");       //input infix expression from the user
    gets(infix);
    

    for(int i=0;infix[i]!='\0';i++)
    {

        if(infix[i]=='(')
        {

            push('(');
        }

        else if(infix[i]==')')
        {
            while(stack[top]!='(')
            {

                postfix[k++]=pop();

            }

            char r=pop();
            
        }

        else if(isdigit(infix[i]))          //check if the element is a digit
        {

            postfix[k++]=infix[i];
        }

        else if(top==-1)                //check if the stack is empty
            push(infix[i]);


        else if(priority(infix[i])>=priority(stack[top]))   //check if the priority of the new operator is higher than that on the top of stack
            push(infix[i]);


        else if(priority(infix[i])<priority(stack[top]))    //check if the priority of the new operator is lower than that on top of the stack
        {

            while(stack[top]!='(' && top>-1)
            {

                postfix[k++]=pop();
            }

            push(infix[i]);

        }

    }

    while(top>-1)           //pushing the remaining operators from the stack to the postfix expression                   
    {
        postfix[k++]=pop();
    }
    

    printf("\n the Postfix Expression is: ");           //print the postfix expression

    puts(postfix);
    


}