#include<stdio.h>

void rotate(int *p, int *q, int *r);
void get_avgsum(int arr[10], int len, int *avg, int *max);
int main()

{

   int arr[10] = {10,20,30,40,50,60,70,80,90,100};

   int avg, max;

   get_avgsum(arr, 10, &avg, &max);

   rotate(&arr[2], &arr[3], &arr[4]);

   printf("Array: ");

   for (int i=0; i<10; i++)

     printf("%d ", arr[i]);

   printf ("\nAvg: %d, Max: %d\n", avg, max);

}

void get_avgsum(int arr[10], int len, int *avg, int *max)
{
    int average_value = 0;
    int sum_value = 0;

    int max_value = 0;
    for(int i =0; i < len; i++)
    {
        sum_value += arr[i];
        if(arr[i] > max_value)
        {
            max_value = arr[i];
        }
    }
    average_value = sum_value / len;

    *avg = average_value;
    *max = max_value;
}

void rotate(int *p, int *q, int *r)
{
    int temp = 0;
    
    temp = *p;
    *p = *r;
    *r = *q;
    *q = temp;
}
