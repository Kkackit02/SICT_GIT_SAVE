#include<stdio.h>

int main(void)
{
    int n, m;
    int array_1[10];
    int array_2[10];
    int array_3[20];
    int idx = 0;
    scanf("%d", &n);
    scanf("%d", &m);

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &array_1[i]);
    }
    for(int i = 0; i < m; i++)
    {
        scanf("%d", &array_2[i]);
    }


    for(int i = 0; i < (n >= m ? n : m); i++)
    {
        if(i<n)
        {
            array_3[idx] = array_1[i];
            idx++;
        }   
        if(i<m)
        {
            array_3[idx] = array_2[i];
            idx++;
        }
    }

    for(int i = 0; i < n+m; i++)
    {
        printf("%d\n", array_3[i]);
    }
}