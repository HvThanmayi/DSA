#include<stdio.h>
#include<stdlib.h>
struct Node {
    int data;
    struct Node *next;
};
struct Node *top = NULL;
struct Node *front = NULL;
struct Node *rear = NULL;

void push(int value)
{
    struct Node *newNode = malloc(sizeof(struct Node));
    if(newNode==NULL)
    {
      printf("Memory allocation failed!");
      return;
    }
    newNode->data = value;
    newNode->next = top;
    top = newNode;
    printf("%d is added to Stack\n",value);
}

void pop(void)
{
    if (top == NULL) {
        printf("Stack Underflow\n");
        return;
    }
    struct Node *temp = top;
    top = top->next;
    printf("%d is deleted from Stack\n", temp->data);
    free(temp);
}

void displayStack() {
    struct Node *temp = top;
    if (top == NULL) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements: ");
    while (temp!=NULL) {
        printf("%d->",temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void enqueue(int value)
{
    struct Node *newNode = malloc(sizeof(struct Node));
    if(newNode==NULL)
    {
      printf("Memory allocation failed!");
      return;
    }
    newNode->data = value;
    newNode->next = NULL;
    if (front == NULL)
      front = rear = newNode;
    else
    {
      rear->next = newNode;
      rear = newNode;
    }
    printf("%d added to Queue\n", value);
}

void dequeue(void)
{
    if (front == NULL) {
        printf("Queue Underflow\n");
        return;
    }
    struct Node *temp = front;
    printf("%d deleted from Queue\n", temp->data);
    front = front->next;
    if (front == NULL)
        rear = NULL;
    free(temp);
}

void displayQueue() {
    struct Node *temp = front;
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue: ");
    while(temp!=NULL) {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{
    int choice, value;
    while (1) {
        printf("\n1. Push");
        printf("\n2. Pop");
        printf("\n3. Display Stack");
        printf("\n4. Enqueue");
        printf("\n5. Dequeue");
        printf("\n6. Display Queue");
        printf("\n7. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                push(value);
                break;

            case 2:
                pop();
                break;

            case 3:
                displayStack();
                break;

            case 4:
                printf("Enter value: ");
                scanf("%d", &value);
                enqueue(value);
                break;

            case 5:
                dequeue();
                break;

            case 6:
                displayQueue();
                break;

            case 7:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
