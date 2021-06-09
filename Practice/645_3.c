#include<stdio.h>

int get_average(int list[], int size);

int main(void)
{
    int scores[3][3]= {
        {40,50,100},
        {70,80,30},
        {60,100,20}
        };

    int result = 0; 
    
    result += get_average(scores, sizeof(scores)/sizeof(int));
    printf("%d\n", result);

 
    
}

int get_average(int list[], int size)
{
    int result = 0;
    int *p_list = &list[0];
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        result += *p_list;
        //*p_array++;
        
    }
    return result;

}