#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define SIZE 100

char stack[SIZE];
int top = -1;

/*PUSH OPERATION*/

void push(char item)
{
    if(top >= SIZE-1)
    {
        printf("\nStack Overflow.");
    }
    else{
        top = top + 1;
        stack[top] = item;
    }
}

/*POP OPERATION*/

char pop()
{
    char item;

    if(top < 0)
    {
        printf("\nstack underflow");
        getchar();
        exit(1);
    }
    else{
        item = stack[top];
        top = top-1;
        return(item);
    }
}

/*CHECK SYMBOL IS OPERATOR OR NOT*/

int isOperator(char symbol)
{
    if(symbol=='^' || symbol=='*' || symbol=='/' || symbol=='+' || symbol=='-')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

/*CHECKING PRECEDENCE*/

int precedence(char symbol)
{
    if(symbol=='^')
    {
        return(3);
    }
    else if(symbol=='*' || symbol=='/')
    {
        return(2);
    }
    else if(symbol=='+' || symbol=='-')
    {
        return(1);
    }
    else
    {
        return(0);
    }
}