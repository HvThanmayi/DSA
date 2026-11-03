#include<stdio.h>
#include<stdlib.h>
struct Node{
   int data;
   struct Node *next;
};
void deletefirst(struct Node **head)
{
  if(*head==NULL)
  {
    printf("List is empty\n");
    return;
  }
  struct Node *temp=*head;
  printf("Deleted element: %d",temp->data);
  *head=temp->next;
  free(temp);
}
void deleteend(struct Node **head)
{
  if(*head==NULL)
  {
    printf("List is empty\n");
    return;
  }
  struct Node *temp=*head;
  if(temp->next==NULL)
  {
    printf("Deleted element: %d",temp->data);
    free(temp);
    *head=NULL;
  }
  while(temp->next->next!=NULL)
    temp=temp->next;
  printf("Deleted element: %d",temp->next->data);
  free(temp->next);
  temp->next=NULL;
}
void deleteSpecificEle(struct Node **head,int value)
{
  if(*head==NULL)
  {
    printf("List is empty\n");
    return;
  }
  if((*head)->data==value)
  {
    deletefirst(head);
    return;
  }
  struct Node *temp=*head;
  while(temp->next!=NULL && temp->next->data!=value)
     temp=temp->next;
  if(temp->next==NULL)
  {
    printf("Element not fount\n");
    return;
  }
  struct Node *nodetodelete=temp->next;
  printf("Deleted element: %d",nodetodelete->data);
  temp->next=nodetodelete->next;
  free(nodetodelete);
}
void insertEnd(struct Node **head, int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    struct Node *temp;

    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    newNode->data = value;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}
void createList(struct Node **head) {
    int count, value, i;

    printf("Enter the number of nodes: ");
    if (scanf("%d", &count) != 1 || count < 0) {
        printf("Invalid number of nodes!\n");
        return;
    }

    for (i = 1; i <= count; i++) {
        printf("Enter value for node %d: ", i);
        if (scanf("%d", &value) != 1) {
            printf("Invalid input!\n");
            return;
        }
        insertEnd(head, value);
    }
}
void display(struct Node *head) {
    struct Node *temp = head;

    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Linked list: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
int main(void) {
    struct Node *head = NULL;
    int choice, value;

    createList(&head);

    while(1)
    {
        printf("\n1.Delete at First\n");
        printf("2.Delete from End\n");
        printf("3.Delete specific element\n");
        printf("4.Display list\n");
        printf("5.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:deletefirst(&head);
                  break;
            case 2:deleteend(&head);
                  break;

            case 3:printf("Enter value to be deleted: ");
                   scanf("%d",&value);
                   deleteSpecificEle(&head,value);
                   break;
            case 4:
                display(head);
                break;
            case 5:printf("Exiting the program");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
