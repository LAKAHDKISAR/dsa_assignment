#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 1000

long long comparisons = 0;
long long swaps = 0;

// Random num 1000 
void generateRandom(int arr[], int n) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000 + 1;   // Range [1,1000]
    }
}

// Printing array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Bubble Sort
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            comparisons++;
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swaps++;
            }
        }
    }
}

/* Selection Sort */
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            comparisons++;
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
            swaps++;
        }
    }
}

// Insertion Sort
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0) {
            comparisons++;
            if (arr[j] > key) {
                arr[j + 1] = arr[j];
                swaps++;   // counting shifts as swaps
                j--;
            } else {
                break;
            }
        }
        arr[j + 1] = key;
    }
}

// Merge functons 
void merge(int arr[], int left, int mid, int right) {
    int i = left, j = mid + 1, k = 0;
    int temp[MAX];

    while (i <= mid && j <= right) {
        comparisons++;
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }

    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    while (j <= right) {
        temp[k++] = arr[j++];
    }

    for (i = left, k = 0; i <= right; i++, k++) {
        arr[i] = temp[k];
    }
}

// Merge sort
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    int n, choice;
    int arr[MAX];

    printf("Enter number of elements: ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX) {
        printf("Invalid size!\n");
        return 1;
    }

    generateRandom(arr, n);

    printf("\nGenerated Numbers:\n");
    printArray(arr, n);

    printf("\nChoose Sorting Algorithm:\n");
    printf("1. Bubble Sort\n");
    printf("2. Selection Sort\n");
    printf("3. Insertion Sort\n");
    printf("4. Merge Sort\n");

    printf("Enter choice: ");
    scanf("%d", &choice);

    comparisons = 0;
    swaps = 0;

    switch (choice) {
        case 1:
            bubbleSort(arr, n);
            break;
        case 2:
            selectionSort(arr, n);
            break;
        case 3:
            insertionSort(arr, n);
            break;
        case 4:
            mergeSort(arr, 0, n - 1);
            break;
        default:
            printf("Invalid choice!\n");
            return 1;
    }

    printf("\nSorted Numbers:\n");
    printArray(arr, n);

    printf("\nTotal Comparisons: %lld\n", comparisons);

    if (choice != 4)
        printf("Total Swaps: %lld\n", swaps);
    else
        printf("Error Merge Sort\n");

    return 0;
}
