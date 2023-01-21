// Write a program to implement the Stack operation to reverse the String in c.

#include <stdio.h>
#include <string.h>
#define MAX 100

char stack[MAX];
int top = -1;

void push(char);
char pop();
int isFull();
int isEmpty();

int main()
{
    char str[MAX];
    int i, len;

    printf("Enter a string: ");
    gets(str);

    len = strlen(str);

    for (i = 0; i < len; i++)
    {
        push(str[i]);
    }

    for (i = 0; i < len; i++)
    {
        str[i] = pop();
    }

    printf("Reverse string is: %s", str);

    return 0;
}


void push(char ch)
{
    if (isFull())
    {
        printf("Stack is full. Overflow condition! \n");
    }
    else
    {
        top++;
        stack[top] = ch;
    }
}

char pop()
{
    char ch;

    if (isEmpty())
    {
        printf("Stack is empty. Underflow condition! \n");
        return 0;
    }
    else
    {
        ch = stack[top];
        top--;
        return ch;
    }
}

int isFull()
{
    if (top == MAX - 1)
        return 1;
    else
        return 0;
}

int isEmpty()
{
    if (top == -1)
        return 1;
    else
        return 0;
}

// Output:

// Enter a string: Hello
// Reverse string is: olleH
