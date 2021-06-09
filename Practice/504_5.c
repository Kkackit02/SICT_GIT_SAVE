#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void convert(double *grades, double *scores, int size);


int main(void)
{
    double grades[10] = {00.00, 00.50, 01.00, 01.50, 02.00, 02.50, 03.00, 03.50, 04.00, 04.30};
    
    double score[10] = { 0, };

    
    convert(grades, score, 10);

    
}

void convert(double *grades, double *scores, int size)
{
    for(int i = 0; i < size + 1; i++)
    {
        //score[i] = grade
    }
}