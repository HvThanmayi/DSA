#include<stdio.h>
#define MAX 5
int queue[MAX];
int front=-1,rear=-1;
void enqueue()
{
  int num;
  if(rear==MAX-1)
  {
    printf("Queue overflow");
  }
  else
  {
    printf("Enter a number: ");
    scanf("%d",&num);
    if(front==-1)
       front=0;
    rear++;
    queue[rear]=num;
  }
}
void dequeue()
{
  int value;
  if((front==-1)||(front>rear))
  {
    printf("Queue underflow");
  }
  else
  {
    value=queue[front];
    front++;
    printf("%d deleted from queue",value);
    if(front>rear)
        front=rear=-1;
  }
}
void display()
{
  if(front==-1)
     printf("Queue is empty");
  else
  {
    printf("Elements in queue are:\n");
    for(int i=front;i<=rear;i++)
       printf("%d ",queue[i]);
  }
}
int main()
{
  int choice;
  while(1)
  {
    printf("\n---MENU---\n");
    printf("1)Enqueue\n");
    printf("2)Dequeue\n");
    printf("3)Display\n");
    printf("4)Exit\n");
    printf("Enter your choice: ");
    scanf("%d",&choice);
    switch(choice)
    {
      case 1:enqueue();
             printf("Element added successfully");
             break;

      case 2:dequeue();
             break;

      case 3:display();
             break;

      case 4:printf("Exiting the program");
             return 0;

      default:printf("Invalid choice");
    }
  }
  return 0;
}
