// Selection sort in C

#include <stdio.h>

// function to swap the the position of two elements
//void void swap(int* a, int* b) {
void swap(double* a, double* b) {
    double temp = *a;
    //int temp = *a;
    *a = *b;
    *b = temp;
}
//void selectionSort(int array[], int size) {
void selectionSort(double array[], int size) {
    for (int step = 0; step < size - 1; step++) {
        int min_idx = step;
        for (int i = step + 1; i < size; i++) {

            // To sort in descending order, change > to < in this line.
            // Select the minimum element in each loop.
            if (array[i] < array[min_idx])
                min_idx = i;
        }

        // put min at the correct position
        swap(&array[min_idx], &array[step]);
    }
}

// function to print an array
//void printArray(int array[], int size) {
void printArray(double array[], int size) {
    for (int i = 0; i < size; ++i) {
        //printf("%d  ", array[i]);
        printf("%f  ", array[i]);
    }
    printf("\n");
}

// driver code
int main() {
    //int data[] = { 20, 12, 10, 15, 2 ,78, 56 , 3 , 21 };
    double data[] = { 20.3, 12.2, 10.5, 15.5, 2.3 ,78.8, 56.4 , 3.4 , 21.2, 20.4, 20.5 };
    int size = sizeof(data) / sizeof(data[0]);
    selectionSort(data, size);
    printf("Sorted array in Acsending Order:\n");
    printArray(data, size);
}