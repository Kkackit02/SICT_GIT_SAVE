// Merge sort �� C�� ������ �ڵ��Դϴ�.
// ����ƮICT���հ��а� 202112346 ���ٳ� : �ڷᱸ���� �˰���

#include <stdio.h>
#define MAX 100
double L[MAX], M[MAX];

// ��º�
void printArray(double arr[], int size) {
    for (int i = 0; i < size; i++)
    {
        printf("%f ", arr[i]);

    }
        
    printf("\n");
}

// ���� �迭 L �� M�� arr�� ����
void merge(double arr[], int p, int q, int r) { 

    // p = ���� ���� index, q = ���� �� index , r = ���� �� index
    // ��(���� �迭) �� Array[p..q] and M(���� �迭) �� Array[q+1..r]
    // n1�� ���� �迭 ����
    // n2�� ���� �迭 ����
    int n1 = q - p + 1;
    int n2 = r - q;
    
    
    printf("�迭�� ���� ���� index = %d , value = %f \n", q, arr[q]);
    printf("L�� ��� ���� = %d , M�� ��� ���� = %d \n", n1, n2);
    //int L[n1], M[n2];

    printf("�����迭 L�� ��� = ");
    for (int i = 0; i < n1; i++)
    {
        L[i] = arr[p + i];
        printf("%f, ", arr[p + i]);
    }
        

    printf("\n");
    printf("�����迭 M�� ��� = ");
    for (int j = 0; j < n2; j++)
    {
        M[j] = arr[q + 1 + j];
        printf("%f, ", arr[q + 1 + j]);
    }


    printf("\n");

    // ���� �迭�� ���� �迭�� �� �ε��� ����
    int i, j, k;
    i = 0; // �����迭 index
    j = 0; // �����迭 index
    k = p; // ���� �迭�� �ε���

    // L �Ǵ� M �� ���� �����Ҷ����� �� ū���� ����
    // L�� M�� �ùٸ� ��ġ�� ��ġ
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

    while (i < n1) { //���� �迭 ���� ū �迭�� �߰�
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) { //���� �迭 ���� ū �迭�� �߰�
        arr[k] = M[j];
        j++;
        k++;
    }
    printf("Current Data Array : ");
    printArray(arr, r + 1);
    printf("\n");
}

// �迭�� �� ���� �迭�� ������ ������ �� ����.
void mergeSort(double arr[], int l, int r) {
    // i = ���� idx , r = �� idx 
    if (l < r) {

        // m�� �迭�� ������ ������
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);//���� �迭

        mergeSort(arr, m + 1, r);//���� �迭

        // ���ĵ� �� ���� �迭�� ����.
        merge(arr, l, m, r);
    }
}



// Driver program
int main() {
    //���ĵ������� �Ǽ� ������ 20��
    double arr[] = { 6.0, 5.2, 12.3, 10.5, 9.4, 1.3, 1.31, 1.4 , 
        5.0 , 10.2 , 32.0, 58.0, 131, -14.2, -17.2, 0, 17.2, 18.423, 19.12, 20.5152 }; 

    int size = sizeof(arr) / sizeof(arr[0]);

    mergeSort(arr, 0, size - 1);

    printf("Sorted array: \n");
    printArray(arr, size);
}