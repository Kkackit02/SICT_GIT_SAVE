#include<stdio.h>

void Turn(int matrix[][4]);
void Print_data(int matrix[][4]);

int main()
{
    int matrix[4][4] = {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
        {13,14,15,16}
    };

    Print_data(matrix);
    Turn(matrix);
    Turn(matrix);
    Turn(matrix);
    
    return 0;
}


void Turn(int matrix[][4])
{
    int tempMatrix[4][4];
     for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            tempMatrix[i][j]=matrix[3-j][i];
        }
    }
    Print_data(tempMatrix);


     for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            matrix[i][j]=tempMatrix[i][j];
        }
    }
    
}

void Print_data(int matrix[][4])
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    printf("-------------------------\n");
}