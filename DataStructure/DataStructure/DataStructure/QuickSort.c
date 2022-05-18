// Quick sort를 C로 구현한 코드입니다.
// 스마트ICT융합공학과 202112346 정근녕 : 자료구조 및 알고리즘
#include <stdio.h>



// 바꾸기 함수
void swap(double* a, double* b) {
    double t = *a;
    *a = *b;
    *b = t;
}



void printArray(double array[], int size) {
    for (int i = 0; i < size; ++i) {
        printf("%f  ", array[i]);
    }
    printf("\n");
}


//pivot와 pivot 위치를 찾는 함수
int partition(double array[], int low, int high) {

    // 가장 오른쪽에 있는 요소를 pivot으로 지정
    double pivot = array[high];
    printf("pivot = %f", pivot);
    printf(" 을 기준으로 작은 요소는 왼쪽, 큰 요소는 오른쪽으로 정렬 \n");

    // 가장 왼쪽 요소의 idx
    int i = (low - 1);


    // pivot와 비교
    for (int j = low; j < high; j++) {
        if (array[j] <= pivot) {

            // 피벗보다 작으면 i가 가리키는 값과 교체
            i++;
            swap(&array[i], &array[j]);
        }
    }

    // pivot 요소를 i에서 더 큰 값으로 변경
    swap(&array[i + 1], &array[high]);

    return (i + 1);
}

void quickSort(double array[], int low, int high) {
    if (low < high) {

        // pivot보다 작으면 pivot보다 왼쪽으로
        // pivot보다 크면 pivot보다 오른쪽으로

        int pi = partition(array, low, high);
        printf("pivot : %f 가 pi :  위치 %d 에 지정되었음 \n", array[pi], pi);
        printf("정렬 후 : \n");
        printArray(array, 20);
        printf("\n");

        //pivot 왼쪽 재귀 호출
        quickSort(array, low, pi - 1);

        //pivot 오른쪽 재귀 호출
        quickSort(array, pi + 1, high);
    }
}



// main function
int main() {
    double data[] = { 8.0, 7.4, 2.2, 1.1, 0.0, 9.4, 6.4 , 5.6 , 6.9, 10.5 , -32.2 , 
        -15.4 , 132.4 , 123.24242, 1.24, 6.156, -51.6, 16.5 , 1 , 20 };

    int n = sizeof(data) / sizeof(data[0]);

    printf("정렬 전 배열 : \n");
    printArray(data, n);
    printf("\n");


    quickSort(data, 0, n - 1);

    printf("모든 요소가 정렬된 배열 : \n");
    printArray(data, n);
}