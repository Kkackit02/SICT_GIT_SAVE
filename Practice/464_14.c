#include<stdio.h>
#include<stdlib.h>
#include <time.h>

int randomWalk(void);
int move(int value, int *x, int *y);

int main(void)
{
    srand(time(NULL));
    int n = 0;
    int m = 0;

    scanf("%d %d", &n, &m);

    int x = n/2; // 중앙으로 이동
    int y = m/2; // 중앙으로 이동

    int *x_p = &x;
    int *y_p = &y;

    int location[n][m];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            location[i][j] = 0;   
        }
    }

    location[x][y] = 1;
    for (int k = 0; k < 40; k++)
    {
        move(randomWalk(), x_p, y_p);
        //printf("X : %d \nY : %d \n", x, y);
        location[x][y] = 1;
        //printf("%d", location[x][y]);
    }

    for (int i = 0; i < n; i++)
    {
        printf("\n");
        for (int j = 0; j < m; j++)
        {
            if(location[i][j] == 0)
            {
                printf("'");
                //printf("%d", location[n][m]);
            }
            else if(location[i][j] == 1)
            {
                printf("*");
                //printf("%d", location[n][m]);
            }
        }
    }

    
}

int randomWalk(void)
{
    int random = 0;
    random = rand() % 8; // 난수 생성
    //printf("%d \n", random);
	return random;
}

int move(int value, int *x, int *y)
{
    switch (value)
    {
        case 0:
            (*y)++;
            break;
        case 1:
            (*x)++;
            (*y)++;
            break;
        case 2:
            (*x)++;
            break;
        case 3:
            (*x)++;
            (*y)--;
            break;
        case 4:
            (*y)--;
            break;
        case 5:
            (*x)--;
            (*y)--;
            break;
        case 6:
            (*x)--;
            break;
        case 7:
            (*x)--;
            (*y)++;
            break;
        default:
            //printf("예외");
            break;
    }
}