#include <stdio.h>
void swap(double* a, double* b) {
    double temp = *a;
    *a = *b;
    *b = temp;
}

void printNodeArray(double arr[], int n) {
    int node_Floor = 1;
    int indices = 1;
    for (int i = 0; i < n; ++i)
    {
        printf("[%d] : %f ",i , arr[i]);
        if (i == node_Floor || i == 0)
        {
            printf("\n");
            node_Floor = node_Floor + indices;
            indices = indices * 2;
        }
    }
    printf("\n");
}

void printArray(double arr[], int n) {
    for (int i = 0; i < n; ++i)
    {
        printf("%f ", arr[i]);
    }
    printf("\n");
}

void heapify(double arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(double arr[], int n) {
    // max heap 으로 구현 됨.
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    printNodeArray(arr, n);
    printf("\n");
    // Heap sort
    for (int i = n - 1; i >= 0; i--) {
        printf("Swap %f to %f | nowSortIdx = %d \n", arr[0], arr[i], i);
        swap(&arr[0], &arr[i]);
        printNodeArray(arr, n);
        heapify(arr, i, 0); //요소를 힙화해서, 루트에서 가장 큰 요소를 다시 가져오기.
        printf("\n");
        printf("Heapify!\n");
        printNodeArray(arr, n);
        printf("\n");
        
    }
}



int main() {
    double arr[] = { 1.0, 12.0, 9.4, 5.5, 6.21, 10.13 , 15.4 , 2323.1 , 151.69, -132.32, 
        232.65, 569.23, 4.5, -1.2 , 1412.23, 15.123, -12.2 ,23.213 ,-5.241 ,0 };
    

    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Before Sorted array is \n");
    printArray(arr, n);
    printf("\n");

    heapSort(arr, n);

    printf("After Sorted array is \n");
    printArray(arr, n);
}