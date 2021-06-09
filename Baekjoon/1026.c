#include<stdio.h>
void bubble(int arr[50], int len);
void bubble_index(int arr[50], int arr_index[50], int len);
int main(void)
{
    int len = 50;
    int A[50] = {0};
    int B[50] = {0};

    int maxA[50] = {0};
    int maxB[50] = {0};
    int TempB[50] = {0};
    int S[50] = {0};
    
    int result = 0;

    scanf("%d", &len);

    for (int i = 0; i < len; i++)
    {
        scanf("%d", &A[i]);
        maxA[i] = A[i];

    }
    for (int i = 0; i < len; i++)
    {
        scanf("%d", &B[i]);
        TempB[i] = B[i];
        maxB[i] = i;
    }

    
    bubble_index(TempB, maxB, len);
    bubble(maxA, len);
    // 최솟값을 위한 값을 구하기 위해 정렬

    for (int i = 0; i < len; i++)
    {
        A[maxB[i]] = maxA[len-i-1]; // 정렬로 얻은 값을 이용해 A 재정렬
    }

    for (int i = 0; i < len; i++)
    {
        S[i] = A[i]*B[i];
        
        result += S[i];
        
    }
    printf("%d\n", result);
}



void bubble(int arr[50], int len)
{
    int temp;

    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len - 1; j++)   
        {
            if (arr[j] > arr[j + 1])          
            {                                 
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;            
            }
        }
    }
}

void bubble_index(int arr[50], int arr_index[50], int len)
{
    int temp1;
    int temp2;

    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len - 1; j++)   
        {
            if (arr[j] > arr[j + 1])          
            {                     
                temp1 = arr[j];
                temp2 = arr_index[j];

                arr[j] = arr[j + 1];
                arr_index[j] = arr_index[j + 1];

                arr[j + 1] = temp1;             
                arr_index[j + 1] = temp2;            
            }
        }
    }
}