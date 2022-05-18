#include<stdio.h>
#include<string.h>
#define _CRT_SECURE_NO_WARNINGS    // fopen 보안 경고로 인한 컴파일 에러 방지

int main(void)
{
    char word[20][50];
    int counter[20];

    for (int i = 0; i < 20; i++)
    {
        counter[i] = 0;
    }

    int word_Count = 0;
    FILE *pFile = fopen("list.txt", "r");
    int temp = 0;
    int flag = 0;
    while(!feof(pFile))
    {
        flag = 0;
        char data[100];
        fgets(data, sizeof(data), pFile);
        data[strlen(data)-1] = ' ';

        for (int i = 0; i < word_Count; i++)
        {
            if(strcmp(word[i], data) == 0)
            {
                counter[i]++;
                flag = 1;
            }
        }
        if(flag != 1)
        {
             strcpy(word[word_Count], data);
             counter[word_Count]++;
             word_Count++;        
        }
    }       
    printf("\n");
    
    for(int i = 0; i < word_Count; i++)
    {
        printf("%s: %d\n", word[i],counter[i]);
    }
    fclose(pFile);
}