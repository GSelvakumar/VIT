#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int value;
    struct Node *link;
};
struct Node *last;

void Insert(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->value = value;
    
    if(last == NULL)
    {
        last = newNode;
        last->link = last;
    }
    else
    {
        struct Node *head = last->link;

        if(head->value < value)
        {
            newNode->link = head;
            last->link = newNode;
        }
        else if(last->value > value)
        {
            newNode->link = head;
            last->link = newNode;
            last = newNode;
        }
        else
        {
            struct Node *currentNode = head;   
            struct Node *prevNode = last;
            
            do
            {
                if(value > currentNode->value && value < prevNode->value)
                {
                    prevNode->link = newNode;
                    newNode->link = currentNode;
                    break;
                }
                
                prevNode = currentNode;
                currentNode = currentNode->link;
            }while(currentNode != head);
        }
    }
}

void Delete(int vacancy)
{
    struct Node *node = last->link;
    int count = 1;
    
while(count < vacancy)
{
	node = node->link;
	count++;
}
node->link = last->link;
last = node;    
}
