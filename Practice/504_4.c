#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void array_print(int *A, int size);


int main(void)
{
    srand(time(NULL));
    
    int size = 0;

    printf("크기를 입력하시오.\n");
    scanf("%d", &size);

    int Num[size];
    for(int i = 0; i < size+1; i++)
    {
        Num[i] = i;
    }
    array_print(Num, size);

    
}

void array_print(int *A, int size)
{
    printf("A[] = { ");
    for(int i = 0; i < size + 1; i++)
    {
        printf("%d ", *A);
        A++;
    }
    printf("}\n");
}