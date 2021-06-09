#include<stdio.h>

int main(void)
{
    int matrix_range = 0;
    
    scanf("%d", &matrix_range);

    int matrix[999999] = {0};

    for (int i = 0; i < matrix_range; i++)
    {
	scanf("%d", &matrix[i]);
    }

    int max = -1000000;
    int min = 1000000;

    for (int i = 0; i < matrix_range; i++)
    {
	if(matrix[i] > max)
	{

	    max = matrix[i];
	}

	if(matrix[i] < min)
	{
	    min = matrix[i];
	}
    }
    
    printf("%d %d\n", min, max);
}
