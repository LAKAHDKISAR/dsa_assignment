#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Creating new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Inserting after a particular value
void insertAfter(struct Node* head, int key, int value) {
    struct Node* temp = head;

    while (temp != NULL && temp->data != key)
        temp = temp->next;

    if (temp == NULL) {
        printf("Node with value %d not found\n", key);
        return;
    }

    struct Node* newNode = createNode(value);

    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL)
        temp->next->prev = newNode;

    temp->next = newNode;
}

// Deleting node by value
void deleteNode(struct Node** head, int key) {
    struct Node* temp = *head;

    while (temp != NULL && temp->data != key)
        temp = temp->next;

    if (temp == NULL) {
        printf("Node with value %d not found\n", key);
        return;
    }

    if (temp->prev == NULL)
        *head = temp->next;
    else
        temp->prev->next = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    free(temp);
}

int main() {
    struct Node* head = createNode(5);
    struct Node* second = createNode(6);
    struct Node* third = createNode(8);
    struct Node* fourth = createNode(10);

    // Linking nodes
    head->next = second;
    second->prev = head;
    second->next = third;
    third->prev = second;
    third->next = fourth;
    fourth->prev = third;

    printf("Initial list: ");
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    // Inserting another
    insertAfter(head, 8, 9);

    printf("\nAfter inserting: ");
    temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    // Deleting node 8
    deleteNode(&head, 8);

    printf("\nAfter deleting: ");
    temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");

    return 0;
}
