#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void merge(int *A, int *B, int *C, int size);


int main(void)
{
    int A[4] = {2,5,7,8};
    int B[4] = {1,3,4,6};
    int C[15];

    merge(A,B,C,8);

    printf("C[] = ");
    for (int k = 0; k < 8; k++)
    {
        printf("%d ", C[k]);
    }
}

void merge(int *A, int *B, int *C, int size)
{
    int count_a = 4;
    int count_b = 4;
    printf("%d %d\n", count_a, count_b);
    for(int i = 0; i <= size; i++)
    {
        printf("%d %d\n", *A, *B);
        if(*A < *B)
        {
            *C = *A;
            *A++;
            *C++;
            count_a--;
        }
        else if(*A > *B)
        {
            *C = *B;
            *B++;
            *C++;
            count_b--;
        }
        
        if(count_a == 0 || count_b == 0)
        {
            break;
        }
    }
    
    if(count_a > count_b)
    {
        for(int i; i <= size; i++)
        {
             *C = *A;
            *A++;
            *C++;
        }
    }
    else if(count_a < count_b)
    {
        for(int i; i <= size; i++)
        {
             *C = *B;
            *B++;
            *C++;
        }
    }

}