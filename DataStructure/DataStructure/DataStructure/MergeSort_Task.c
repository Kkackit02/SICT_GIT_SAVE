// Merge sort 를 C로 구현한 코드입니다.
// 스마트ICT융합공학과 202112346 정근녕 : 자료구조와 알고리즘

#include <stdio.h>
#define MAX 100
double L[MAX], M[MAX];

// 출력부
void printArray(double arr[], int size) {
    for (int i = 0; i < size; i++)
    {
        printf("%f ", arr[i]);

    }
        
    printf("\n");
}

// 하위 배열 L 과 M을 arr로 병합
void merge(double arr[], int p, int q, int r) { 

    // p = 좌측 시작 index, q = 좌측 끝 index , r = 우측 끝 index
    // ㅣ(좌측 배열) ← Array[p..q] and M(우측 배열) ← Array[q+1..r]
    // n1은 좌측 배열 개수
    // n2는 우측 배열 개수
    int n1 = q - p + 1;
    int n2 = r - q;
    
    
    printf("배열을 나눈 기준 index = %d , value = %f \n", q, arr[q]);
    printf("L의 요소 개수 = %d , M의 요소 개수 = %d \n", n1, n2);
    //int L[n1], M[n2];

    printf("하위배열 L의 요소 = ");
    for (int i = 0; i < n1; i++)
    {
        L[i] = arr[p + i];
        printf("%f, ", arr[p + i]);
    }
        

    printf("\n");
    printf("하위배열 M의 요소 = ");
    for (int j = 0; j < n2; j++)
    {
        M[j] = arr[q + 1 + j];
        printf("%f, ", arr[q + 1 + j]);
    }


    printf("\n");

    // 상위 배열과 하위 배열의 현 인덱스 유지
    int i, j, k;
    i = 0; // 좌측배열 index
    j = 0; // 우측배열 index
    k = p; // 상위 배열의 인덱스

    // L 또는 M 의 끝에 도달할때까지 더 큰것을 선택
    // L과 M을 올바른 위치에 배치
    while (i < n1 && j < n2) {
        if (L[i] <= M[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = M[j];
            j++;
        }
        k++;
    }

    while (i < n1) { //좌측 배열 값을 큰 배열에 추가
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) { //우측 배열 값을 큰 배열에 추가
        arr[k] = M[j];
        j++;
        k++;
    }
    printf("Current Data Array : ");
    printArray(arr, r + 1);
    printf("\n");
}

// 배열을 두 하위 배열로 나눠서 정렬한 뒤 병합.
void mergeSort(double arr[], int l, int r) {
    // i = 시작 idx , r = 끝 idx 
    if (l < r) {

        // m은 배열을 나누는 기준점
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);//좌측 배열

        mergeSort(arr, m + 1, r);//우측 배열

        // 정렬된 두 하위 배열을 병합.
        merge(arr, l, m, r);
    }
}



// Driver program
int main() {
    //정렬되지않은 실수 데이터 20개
    double arr[] = { 6.0, 5.2, 12.3, 10.5, 9.4, 1.3, 1.31, 1.4 , 
        5.0 , 10.2 , 32.0, 58.0, 131, -14.2, -17.2, 0, 17.2, 18.423, 19.12, 20.5152 }; 

    int size = sizeof(arr) / sizeof(arr[0]);

    mergeSort(arr, 0, size - 1);

    printf("Sorted array: \n");
    printArray(arr, size);
}