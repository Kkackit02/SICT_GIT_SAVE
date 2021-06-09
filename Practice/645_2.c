#include<stdio.h>
int get_sum(int array[], int size);
int main(void)
{
    int matrix[3][6]= {
        {10,10,10,10,10,10},
        {10,10,10,10,10,10},
        {10,10,10,10,10,70}};
    int result = 0; 
    result += get_sum(matrix, sizeof(matrix)/sizeof(int));

    printf("%d\n", result);
}

int get_sum(int array[], int size)
{
    int result = 0;
    int *p_array = &array[0];
    for (int i = 0; i < size; i++)
    {
        result += *p_array;
        *p_array++;
        
    }
    return result;
}