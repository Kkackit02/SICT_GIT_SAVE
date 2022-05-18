// Insertion sort in C
// 삽입 정렬

#include <stdio.h>

// Function to print an array
void printArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void insertionSort(int array[], int size) {
    for (int step = 1; step < size; step++) { // step는 현재 정렬된 배열의 수(현재 정렬중인 요소 포함)
        int key = array[step]; 
        // key는 정렬되지 않은 배열에서 추출한 값.

        printf("key = %d \n", key);
        int j = step - 1;
        // 정렬된 배열에서 검사할 숫자(이미 정렬된 요소만 세기)

        // Compare key with each element on the left of it until an element smaller than
        // it is found.
        // For descending order, change key<array[j] to key>array[j].
        
        // key를 정렬 후 배열에서 비교하며 만약 key보다 array가 더 크면
        
        while (key < array[j] && j >= 0) {
            // key가 array보다 크거나 j가 0보다 작을때까지 반복
            array[j + 1] = array[j];
            // 
            printf("array[%d] : %d = array[%d] : %d \n", j + 1, array[j + 1], j, array[j]);
            --j;
            printf("--j = %d \n", j);
        }
        array[j + 1] = key; 
        // key가 현재 검사한 값보다 더 크거나, 정렬된 배열의 모든 요소와 검사하였는데도 가장 크므로
        // 정렬

        

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