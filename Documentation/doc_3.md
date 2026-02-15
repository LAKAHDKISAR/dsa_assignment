# Reverse Traversal of a Singly Linked List

## Program Overview

This program implements a singly linked list and demonstrates:

- Creating nodes dynamically
- Inserting nodes at the end of the list
- Traversing the list in normal order
- Traversing the list in reverse order using recursion

The reverse traversal does not modify the linked list. It only prints the elements in reverse order.

## Data Structure Definition

The linked list is implemented using a structure:

```c
struct Node {
    int data;
    struct Node* next;
};
```

### Explanation:

- `data` → stores the integer value of the node.
- `next` → stores the address of the next node.
- The last node points to `NULL`.

Memory for each node is allocated dynamically using `malloc()`.

## Functions Implemented

### 1. `createNode(int value)`

- Allocates memory for a new node.
- Initializes the `data` field with the given value.
- Sets `next` to `NULL`.
- Returns pointer to the newly created node.

### 2. `insertEnd(struct Node** head, int value)`

**Purpose:**

- Inserts a new node at the end of the linked list.

**Logic:**

- If the list is empty (`head == NULL`), the new node becomes the head.
- Otherwise, traverse to the last node.
- Update its `next` pointer to the new node.

### 3. `display(struct Node* head)`

**Purpose:**

- Traverses the linked list from beginning to end.
- Prints each node's data.

**Logic:**

- Start from head.
- Move to next node until `NULL` is reached.

### 4. `reverseTraversal(struct Node* head)`

**Purpose:**

- Prints the linked list in reverse order.
- Uses recursion.

**Logic:**

- If head is `NULL`, return.
- Recursively call `reverseTraversal(head->next)`.
- Print the node's data while returning from recursion.

## Why Recursion Works

Recursion first moves to the last node. Printing happens while the recursive calls return.

### Example:

Linked list:

```
10 → 20 → 30 → 40 → NULL
```

Recursive calls go forward:

```
10 → 20 → 30 → 40 → NULL
```

Printing happens backward:

```
40 30 20 10
```

## Organization of `main()`

The `main()` function:

1. Initializes the head pointer to `NULL`.
2. Inserts four nodes into the list.
3. Displays the list in normal order.
4. Calls the reverse traversal function.
5. Prints both outputs clearly.

## Sample Output

![](assets/Program_3_output.png)
