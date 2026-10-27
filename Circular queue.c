#include<stdio.h>
#define MAX 3
int q[MAX];
int front=-1,rear=-1;
void enqueue()
{
  int num;
  if((rear+1)%MAX==front)
  {
    printf("Queue overflow");
    return;
  }
  printf("Enter the number to be inserted: ");
  scanf("%d",&num);
  if(front==-1 && rear==-1)
     front=0;
  if(rear==MAX-1)
     rear=0;
  else
     rear++;
  q[rear]=num;
}
void dequeue()
{
  if(front==-1)
  {
    printf("Queue underflow");
    return;
  }
  int value=q[front];
  printf("%d deleted from queue",value);
  if(front==rear)
    front=rear=-1;
  else if(front==MAX-1)
    front=0;
  else
    front++;
}
void display()
{
  int i;
  if(front==-1)
  {
    printf("Queue is empty");
    return;
  }
  i=front;
  printf("Queue elements: ");
  while(1)
  {
    printf("%d ",q[i]);
    if(i==rear)
      break;
    i=(i+1)%MAX;
  }
}
int main()
{
  int choice;
  while(1)
  {
    printf("\n--MENU--\n");
    printf("1)Enqueue\n");
    printf("2)Dequeue\n");
    printf("3)Display\n");
    printf("4)Exit\n");
    printf("Enter your choice: ");
    scanf("%d",&choice);
    switch(choice)
    {
      case 1:enqueue();
             break;

      case 2:dequeue();
             break;

      case 3:display();
             break;

      case 4:printf("\nExiting the program\n");
             return 0;

      default:printf("Invlaid choice");
    }
  }
  return 0;
}
