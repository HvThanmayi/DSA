#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void insertBeginning(struct Node **head, int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    newNode->data = value;
    newNode->next = *head;
    *head = newNode;
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

void insertAtPosition(struct Node **head, int value, int position) {
    struct Node *newNode;
    struct Node *temp;
    int i;

    if (position < 1) {
        printf("Invalid position!\n");
        return;
    }

    if (position == 1) {
        insertBeginning(head, value);
        return;
    }

    temp = *head;
    for (i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Invalid position!\n");
        return;
    }

    newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    newNode->data = value;
    newNode->next = temp->next;
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

void freeList(struct Node *head) {
    struct Node *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main(void) {
    struct Node *head = NULL;
    int choice, value, position;

    createList(&head);

    do {
        printf("\n1. Insert at beginning\n");
        printf("2. Insert at a position\n");
        printf("3. Insert at end\n");
        printf("4. Display list\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input!\n");
            freeList(head);
            return 1;
        }

        switch (choice) {
            case 1:
                printf("Enter value: ");
                if (scanf("%d", &value) != 1) break;
                insertBeginning(&head, value);
                break;
            case 2:
                printf("Enter value and position: ");
                if (scanf("%d %d", &value, &position) != 2) break;
                insertAtPosition(&head, value, position);
                break;
            case 3:
                printf("Enter value: ");
                if (scanf("%d", &value) != 1) break;
                insertEnd(&head, value);
                break;
            case 4:
                display(head);
                break;
            case 0:
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 0);

    freeList(head);
    return 0;
}
