#include<stdio.h>

void pascalTriangle(int len);

void triabglePrint(int len, int pascal[][len]);

int main(void)
{
    int len = 0;

    scanf("%d", &len);

    pascalTriangle(len);
    
}


void pascalTriangle(int len)
{
    printf("파스칼 제작 시작 \n");
    int pascal[len+1][len+1];

    for (int x = 1; x < (len); x++)
    {
	printf("%d %d \n", x, len);
        for (int y = 1; y < (len); y++)
        {

	    if(x = 1)
            {
	           pascal[x][y] = 1; 
	    }
		
	    else
	    {
		   pascal[x][y] = pascal[x-1][y-1] + pascal[x][y-1];
	    }
	    //printf("%d\n", pascal[x][y]);
	} 
    }
    triabglePrint(len, pascal);
    printf("함수 출력 시작\n");
}

void triabglePrint(int len, int pascal[][len])
{
    for (int y = 1; y < (len); y++)
    {
	    for (int x = 1; x < (len); x++)
	    {
		if(x <= y)
		{
		    printf("%d ", pascal[x][y]);
		}
		else
		{
		    printf("공백");
		}
	    }
	    printf("\n");
    }
    printf("함수 출력 완료\n");
}
