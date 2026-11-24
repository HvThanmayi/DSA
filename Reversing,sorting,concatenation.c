#include<stdio.h>
#include<stdlib.h>
struct Node{
  int data;
  struct Node *next;
};

struct Node *insert(struct Node *head,int value)
{
  struct Node *newNode=malloc(sizeof(struct Node));
  if(newNode==NULL)
  {
    printf("Memory allocation failed!");
    return head;
  }
  newNode->data=value;
  newNode->next=NULL;
  if(head==NULL)
  {
    head=newNode;
    return head;
  }
  struct Node *temp=head;
  while(temp->next!=NULL)
    temp=temp->next;
  temp->next=newNode;
  return head;
}

struct Node *reverseList(struct Node *head)
{
  struct Node *prev=NULL;
  struct Node *current=head;
  struct Node *n=NULL;
  while(current!=NULL)
  {
    n=current->next;
    current->next=prev;
    prev=current;
    current=n;
  }
  return prev;
}

void sort(struct Node *head)
{
  struct Node *temp,*current;
  int swap;
  for(temp=head;temp->next!=NULL;temp=temp->next)
  {
    for(current=temp->next;current!=NULL;current=current->next)
    {
      if(temp->data>current->data)
      {
        swap=temp->data;
        temp->data=current->data;
        current->data=swap;
      }
    }
  }
}

struct Node *concatenate(struct Node *head1,struct Node *head2)
{
  if(head1==NULL)
    return head2;
  if(head2==NULL)
    return head1;
  struct Node *temp=head1;
  while(temp->next!=NULL)
    temp=temp->next;
  temp->next=head2;
  return head1;
}

void display(struct Node *head)
{
  if(head==NULL)
  {
    printf("List is empty:");
    return;
  }
  struct Node *temp=head;
  while(temp!=NULL)
  {
    printf("%d->",temp->data);
    temp=temp->next;
  }
  printf("NULL");
}

int main()
{
  struct Node *head1=NULL;
  struct Node *head2=NULL;
  int n,m,value;
  printf("\nEnter number of nodes for List1: ");
  scanf("%d",&n);
  for(int i=1;i<=n;i++)
  {
     printf("Enter the value for node %d: ",i);
     scanf("%d",&value);
     head1=insert(head1,value);
  }
  printf("\nEnter number of nodes for List2: ");
  scanf("%d",&m);
  for(int i=1;i<=m;i++)
  {
     printf("Enter the value for node %d: ",i);
     scanf("%d",&value);
     head2=insert(head2,value);
  }
  while(1){
  printf("\n\n---MENU---\n");
  printf("1)Reversing\n");
  printf("2)Sorting\n");
  printf("3)Concatenation\n");
  printf("4)Exit\n");
  int choice;
  printf("Enter your choice: ");
  scanf("%d",&choice);
  switch(choice)
  {
    case 1:printf("\nReversing List1: ");
           head1=reverseList(head1);
           display(head1);
           printf("\nReversing List2: ");
           head2=reverseList(head2);
           display(head2);
           break;

    case 2:printf("\nSorting List1: ");
           sort(head1);
           display(head1);
           printf("\nSorting List2: ");
           sort(head2);
           display(head2);
           break;

    case 3:printf("\nConcatenating both lists: \n");
           head1=concatenate(head1,head2);
           display(head1);
           break;

    case 4:printf("Exiting the program");
           return 0;

    default:printf("\nInvalid choice!\n");
    }
    }
    return 0;
  }
