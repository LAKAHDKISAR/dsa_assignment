#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// creating new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Inserting node at end
void insertEnd(struct Node** head, int value) {
    struct Node* newNode = createNode(value);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

// Normal traversal
void display(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Reverse traversal
void reverseTraversal(struct Node* head) {
    if (head == NULL)
        return;

    reverseTraversal(head->next);
    printf("%d ", head->data);
}

int main() {
    struct Node* head = NULL;

    // Creating linked list
    insertEnd(&head, 10);
    insertEnd(&head, 20);
    insertEnd(&head, 30);
    insertEnd(&head, 40);

    printf("Normal traversal: ");
    display(head);

    printf("Reverse traversal: ");
    reverseTraversal(head);
    printf("\n");

    return 0;
}
