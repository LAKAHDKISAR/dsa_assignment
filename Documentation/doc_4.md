# Implementation of Doubly Linked List Using Structure

## Objective

To implement a Doubly Linked List in C and perform the following operations:

- Insert a node after a given node
- Delete a node
- Demonstrate the operations in `main()`

## Structure Definition

```c
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};
```

Each node contains:

- `data` → stores the value
- `prev` → pointer to previous node
- `next` → pointer to next node

## Functions Used

### 1. createNode()

Creates a new node dynamically using `malloc()` and initializes:

- data
- prev = NULL
- next = NULL

### 2. insertAfter()

Inserts a new node after a specified value.

**Steps:**

1. Traverse the list to find the given value.
2. If found:
   - Create new node.
   - Adjust next and prev pointers properly.
3. If not found:
   - Print error message.

### 3. deleteNode()

Deletes a node with a given value.

**Steps:**

1. Traverse the list to find the value.
2. Adjust previous and next node pointers.
3. Free the memory of deleted node.
4. If node is head, update head pointer.

## Demonstration

### Initial List:

```
5 → 6 → 8 → 10
```

### After inserting 9 after 8:

```
5 → 6 → 8 → 9 → 10
```

### After deleting 8:

```
5 → 6 → 9 → 10
```

## Output

![](assets/Program_4_output.png)
