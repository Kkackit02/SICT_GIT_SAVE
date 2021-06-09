#include<stdio.h>

int main(void)
{
    int A, B, C;
    scanf("%d %d %d", &A, &B, &C);

    int temp = A*B*C;

    int result[10] = {0};
    
    while(temp>0)
    {
        switch (temp%10)
        {
        case 0:
            result[0] += 1;
            temp/=10;
            break;
        case 1:
            result[1] += 1;
            temp/=10;
            break;
        case 2:
            result[2] += 1;
            temp/=10;
            break;
        case 3:
            result[3] += 1;
            temp/=10;
            break;
        case 4:
            result[4] += 1;
            temp/=10;
            break;
        case 5:
            result[5] += 1;
            temp/=10;
            break;
        case 6:
            result[6] += 1;
            temp/=10;
            break;
        case 7:
            result[7] += 1;
            temp/=10;
            break;
        case 8:
            result[8] += 1;
            temp/=10;
            break;  
        case 9:
            result[9] += 1;
            temp/=10;
            break;   
    
        default:
            temp/=10;
            break;
        }
    }

    for (int i = 0; i < 10; i++)
    {
        printf("%d\n", result[i]);
    }
    
    //d
    
}