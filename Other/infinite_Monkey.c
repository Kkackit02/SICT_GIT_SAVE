#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(void)
{
    int monkey = 100000;
    int key = 4;
    int sentence = 4;
    srand(time(NULL));

    int Success_Key_Array[monkey];
    int Most_Key_Array[sentence+1];

    for (int i = 0; i < monkey; i++)
    {
        Success_Key_Array[i] = 0;
    }   

    for (int i = 0; i < sentence+1; i++)
    {
        Most_Key_Array[i] = 0;
    }   
    
    for (int i = 0; i < monkey; i++)
    {
        int mostKeyCount = 0;
        for (int j = 0; j < sentence; j++)
        {
            int random = rand() % key;
            if(random == 0)
            {
                Success_Key_Array[i]++;
                mostKeyCount++;
            }
        }
        
        Most_Key_Array[mostKeyCount]++;
    }

    for (int i = 0; i < sentence+1; i++)
    {
        printf("%d - %d : \n", i, Most_Key_Array[i]);
    }
}