// Insertion sort in C

#include <stdio.h>

// Function to print an array
void printArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void insertionSort(int array[], int size) {
    for (int step = 1; step < size; step++) {
        int key = array[step];
        printf("key = %d \n", key);
        int j = step - 1;

        // Compare key with each element on the left of it until an element smaller than
        // it is found.
        // For descending order, change key<array[j] to key>array[j].
        while (key < array[j] && j >= 0) {
            array[j + 1] = array[j];
            printf("array[%d] : %d = array[%d] : %d \n",
                j + 1, array[j + 1], j, array[j]);
            --j;
            printf("--j = %d \n", j);
        }
        array[j + 1] = key;
        printf("array[%d] = %d \n", j + 1, key);
    }
}

// Driver code
int main() {
    int data[] = { 9, 5, 1, 4, 3 };
    int size = sizeof(data) / sizeof(data[0]);
    insertionSort(data, size);
    printf("Sorted array in ascending order:\n");
    printArray(data, size);
}