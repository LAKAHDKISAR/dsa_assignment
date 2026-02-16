# Building Min Heap and Max Heap from an Unsorted Array

## Explanation of Data Structures Defined

The program uses an array-based representation of a binary heap.

A heap is a complete binary tree that satisfies either:

- **Max Heap Property:** Parent node ≥ child nodes
- **Min Heap Property:** Parent node ≤ child nodes

Instead of using a tree structure with pointers, the heap is implemented using an array.

For any index `i` in the array:

- Left child → `2*i + 1`
- Right child → `2*i + 2`
- Parent → `(i - 1) / 2`

Two arrays are used:

- `arr1[]` → to build the Max Heap
- `arr2[]` → to build the Min Heap

This ensures both heaps are built independently from the same unsorted data.

## Description of Functions Implemented

### 1. swap(int *a, int *b)

**Purpose:** Swaps two integer values.

**Usage:** Used during heapify operations when parent-child exchange is required.

### 2. maxHeapify(int arr[], int n, int i)

**Purpose:** Maintains the Max Heap property for a subtree rooted at index `i`.

**Working:**

- Compares parent with left and right children.
- Identifies the largest value.
- Swaps if necessary.
- Recursively applies heapify on affected subtree.

### 3. minHeapify(int arr[], int n, int i)

**Purpose:** Maintains the Min Heap property for a subtree rooted at index `i`.

**Working:**

- Compares parent with left and right children.
- Identifies the smallest value.
- Swaps if necessary.
- Recursively applies heapify on affected subtree.

### 4. buildMaxHeap(int arr[], int n)

**Purpose:** Builds a Max Heap from an unsorted array.

**Working:**

- Starts from the last non-leaf node `(n/2 - 1)`
- Calls `maxHeapify()` for each node up to the root
- Ensures complete heap structure

**Time Complexity:** O(n)

### 5. buildMinHeap(int arr[], int n)

**Purpose:** Builds a Min Heap from an unsorted array.

**Working:**

- Starts from last non-leaf node
- Calls `minHeapify()` up to the root
- Ensures complete heap structure

**Time Complexity:** O(n)

### 6. printArray(int arr[], int n)

**Purpose:** Prints elements of the array.

Used to display:

- Original array
- Max Heap
- Min Heap

## main() Function

The `main()` function performs the following steps:

1. Defines two arrays with the same unsorted data:

```c
{25, 12, 40, 7, 18, 33}
```

2. Prints the original array.

3. Calls:
   - `buildMaxHeap()` on `arr1`
   - Prints Max Heap

4. Calls:
   - `buildMinHeap()` on `arr2`
   - Prints Min Heap

This demonstrates both heap constructions clearly.

## Output

![](assets/Program_6_output.png)
