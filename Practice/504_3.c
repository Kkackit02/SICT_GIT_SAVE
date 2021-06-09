#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void array_fill(int *A, int size);


int main(void)
{
    srand(time(NULL));
    
    int size = 0;

    printf("크기를 입력하시오.\n");
    scanf("%d", &size);

    int Num[size];
 
    array_fill(Num, size);


    for(int i = 0; i < size; i++)
    {
        printf("%d \n", Num[i]);
  
    }
    
}

void array_fill(int *A, int size)
{
    for(int i = 0; i < size; i++)
    {
        *A = rand();
        *A++;
    }
}