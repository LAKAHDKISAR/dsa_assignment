# Sorting Random Integers Using User-Selected Algorithm

## Data Structures

### 1. Array to Store Random Integers

```c
#define MAX 1000
int arr[MAX];
```

- `arr` is a one-dimensional integer array.
- It stores `N` randomly generated integers.
- `N` is provided by the user at runtime.
- `MAX` limits the maximum allowed size to prevent overflow.

The values are generated in the range:

```
[1, 1000]
```

### 2. Performance Counters

```c
long long comparisons;
long long swaps;
```

- `comparisons` counts the total number of element comparisons performed.
- `swaps` counts the total number of swaps (or shifts in insertion sort).
- For Merge Sort, swaps are not applicable since it does not swap elements directly.

`long long` is used to safely store large counts when `N` is large.

## Functions Implemented

### 1. generateRandom(int arr[], int n)

**Purpose:** Generates `n` random integers in the range `[1, 1000]` and stores them in the array.

**How it works:**

- Uses `rand() % 1000 + 1`
- Seeded using `srand(time(NULL))`

### 2. printArray(int arr[], int n)

**Purpose:** Prints all elements of the array.

**Used:**

- Before sorting
- After sorting

### 3. bubbleSort(int arr[], int n)

**Purpose:** Sorts the array using Bubble Sort.

**Logic:**

- Compares adjacent elements.
- Swaps if they are out of order.
- Repeats for `n-1` passes.

**Counts:**

- Comparisons
- Swaps

**Time Complexity:** O(n²)

### 4. selectionSort(int arr[], int n)

**Purpose:** Sorts the array using Selection Sort.

**Logic:**

- Finds the minimum element in the unsorted portion.
- Swaps it with the first unsorted element.

**Counts:**

- Comparisons
- Swaps (only when required)

**Time Complexity:** O(n²)

### 5. insertionSort(int arr[], int n)

**Purpose:** Sorts the array using Insertion Sort.

**Logic:**

- Takes one element at a time.
- Inserts it into the correct position in the sorted portion.

**Counts:**

- Comparisons
- Shifts (counted as swaps)

**Time Complexity:**

- Best Case: O(n)
- Worst Case: O(n²)

### 6. mergeSort(int arr[], int left, int right)

**Purpose:** Sorts the array using Merge Sort (Divide and Conquer).

**Logic:**

1. Divide the array into two halves.
2. Recursively sort each half.
3. Merge the sorted halves.

**Counts:**

- Comparisons only
- Swaps are not applicable

**Time Complexity:** O(n log n)

### 7. merge()

**Purpose:** Helper function used by Merge Sort to merge two sorted subarrays.

## main() Function

The main() function is structured as follows:

1. Prompts the user to enter the number of elements `N`.
2. Validates the input (`N > 0` and `N ≤ MAX`).
3. Calls generateRandom() to fill the array.
4. Prints the generated numbers.
5. Displays a menu for selecting sorting algorithm:
   - 1 → Bubble Sort
   - 2 → Selection Sort
   - 3 → Insertion Sort
   - 4 → Merge Sort
6. Calls the selected sorting function.
7. Prints the sorted array.
8. Displays:
   - Total comparisons
   - Total swaps (if applicable)

This modular structure improves clarity and maintainability.

## Output

### Bubble Sort

![](assets/Program_8_output_1.png)

### Selection Sort

![](assets/Program_8_output_2.png)

### Insertion Sort

![](assets/Program_8_output_3.png)

### Merge Sort

![](assets/Program_8_output_4.png)
