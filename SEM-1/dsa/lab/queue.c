#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int queue[MAX];
int front = -1;
int rear = -1;

int isEmpty()
{
  if(front == -1 || front > rear)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

int isFull()
{
  if(rear == MAX-1)
  {
    return 1;
  }
  else{
    return 0;
  }
}

void display()
{
  int i;
  if(isEmpty()){
    printf("Queue is Empty!\n");
    return;
  }
  
  printf("Queue is: \t");
  for(i = front; i <= rear; i++){
    printf("%d\t", queue[i]);
  }
  printf("\n");
}

void enqueue(int item)
{
  if(isFull())
  {
    printf("Queue Overflow!\n");
    return;
  }
  if(front == -1)
  {
    front = 0;
  }
  rear = rear + 1;
  queue[rear] = item;
}

int dequeue()
{
  int item;

  if(isEmpty())
  {
    printf("Queue is Empty");
    exit(1);
  }
  item = queue[front];
  front = front + 1;
  return item;
}

int main()
{
  int choice, item;

  while(1)
    {
      printf("1.Insert\n");
      printf("2.Delete\n");
      printf("3.Display\n");
      printf("4.Exit\n");

      printf("Enter the Choice: ");
      scanf("%d", &choice);

      switch(choice)
        {
          case 1:
            printf("Give the input to insert into the queue: ");
            scanf("%d", &item);
            enqueue(item);
            break;
          case 2:
            item = dequeue();
            printf("The Removed element from the queue is: %d\n", item);
            break;
          case 3:
            display();
            break;
          case 4:
            exit(1);
          default:
            printf("Enter a Valid choice\n");
        }
    }
  return 0;
}