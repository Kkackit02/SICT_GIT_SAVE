// Quick sort�� C�� ������ �ڵ��Դϴ�.
// ����ƮICT���հ��а� 202112346 ���ٳ� : �ڷᱸ�� �� �˰���
#include <stdio.h>



// �ٲٱ� �Լ�
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


//pivot�� pivot ��ġ�� ã�� �Լ�
int partition(double array[], int low, int high) {

    // ���� �����ʿ� �ִ� ��Ҹ� pivot���� ����
    double pivot = array[high];
    printf("pivot = %f", pivot);
    printf(" �� �������� ���� ��Ҵ� ����, ū ��Ҵ� ���������� ���� \n");

    // ���� ���� ����� idx
    int i = (low - 1);


    // pivot�� ��
    for (int j = low; j < high; j++) {
        if (array[j] <= pivot) {

            // �ǹ����� ������ i�� ����Ű�� ���� ��ü
            i++;
            swap(&array[i], &array[j]);
        }
    }

    // pivot ��Ҹ� i���� �� ū ������ ����
    swap(&array[i + 1], &array[high]);

    return (i + 1);
}

void quickSort(double array[], int low, int high) {
    if (low < high) {

        // pivot���� ������ pivot���� ��������
        // pivot���� ũ�� pivot���� ����������

        int pi = partition(array, low, high);
        printf("pivot : %f �� pi :  ��ġ %d �� �����Ǿ��� \n", array[pi], pi);
        printf("���� �� : \n");
        printArray(array, 20);
        printf("\n");

        //pivot ���� ��� ȣ��
        quickSort(array, low, pi - 1);

        //pivot ������ ��� ȣ��
        quickSort(array, pi + 1, high);
    }
}



// main function
int main() {
    double data[] = { 8.0, 7.4, 2.2, 1.1, 0.0, 9.4, 6.4 , 5.6 , 6.9, 10.5 , -32.2 , 
        -15.4 , 132.4 , 123.24242, 1.24, 6.156, -51.6, 16.5 , 1 , 20 };

    int n = sizeof(data) / sizeof(data[0]);

    printf("���� �� �迭 : \n");
    printArray(data, n);
    printf("\n");


    quickSort(data, 0, n - 1);

    printf("��� ��Ұ� ���ĵ� �迭 : \n");
    printArray(data, n);
}