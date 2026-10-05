#include <stdio.h>
#define MAX 5

int stack[MAX];
int top = -1;

void push() {
    int value;

    if (top == MAX - 1) {
        printf("Stack is full.\n");
        return;
    }

    printf("Enter a value: ");
    scanf("%d", &value);
    stack[++top] = value;
    printf("Value pushed.\n");
}

void pop() {
    if (top == -1) {
        printf("Stack is empty.\n");
        return;
    }

    printf("Popped: %d\n", stack[top--]);
}

void display() {
    if (top == -1) {
        printf("Stack is empty.\n");
        return;
    }

    printf("Stack (top to bottom): ");
    for (int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main() {
    while(true)
    {
        printf("\n---MENU---\n");
        printf("1.Push\n");
        printf("2.Pop\n");
        printf("3.Display\n");
        printf("4.Exit\n");
        int choice;
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:push();
                   break;
                
             case 2:pop();
                    break;

            case 3:display();
                   break;

            case 4:printf("Exiting.\n");
                   break;

            default:printf("Invalid choice.\n");
        }
    }
    return 0;
}