#include<stdio.h>

void matrix(int m, int n, int p, int A[][m], int B[][n], int C[][m]);

int main(void)
{
    int m = 0;
    int n = 0;
    int p = 0;                                                                                          
    

    printf("m, n , p를 입력하시오: ");

    scanf("%d %d %d", &m, &n, &p);
   
    int A[n][m];

    int B[p][n];

    int C[p][m];

    printf("첫 번째 %d * %d 행렬(A)를 입력하시오:\n", m, n);

    for (int y = 0; y < m; y++)
    {
        for (int x = 0; x < n; x++)
	{
            scanf("%d", &A[x][y]);
	}
    } 

    printf("두 번째 %d * %d 행렬(B)를 입력하시오:\n", n, p);

    for (int y = 0; y < n; y++)
    {			        
	for (int x = 0; x < p; x++)
	{						            
	    scanf("%d", &B[x][y]);							         
	}
    }


    matrix(m, n, p, A, B, C);
    
    printf("결과: \n");

    for (int i = 0; i < m; i++)
    {			            
	for (int j = 0; j < p ; j++)					            
	{	
	    printf("%d ", C[j][i]);
	}

	printf("\n");
    }
    
}

void matrix(int m, int n, int p, int A[][m], int B[][n], int C[][m])
{
    // A * B, A = y, B = x
    //int m = sizeof(A) / sizeof(A[0]); // A의 y, C의 y
    //int n = sizeof(A[0]) / sizeof(int);   // A의 x, B의 y 
    //int p = sizeof(B[0]) / sizeof(int);   // B의 x, C의 x    
    

    for (int z = 0; z < p; z++)
    {
	for (int y = 0; y < m; y++)
	{
	    C[z][y] = 0;
	}
    }


    for (int y = 0; y < m; y++)
    {
	for (int x = 0; x < n; x++)
	{
	    for (int z = 0; z < p; z++)
	    {
	        C[z][y] += A[x][y] * B[z][x];
	    }
	}
    }
}
