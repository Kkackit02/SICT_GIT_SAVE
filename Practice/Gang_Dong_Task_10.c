#include<stdio.h>
#include<string.h>

#define Max_Word_Length 50

int main(void)
{
    const char *planets[] = {"Mercury", "Venus", "Earth", "Mars", "Jupiter", "Saturn", "Uranos", "Neptune", "Pluto"};

    printf("Enter names: ");

    char spelling;
    char word[Max_Word_Length];
    int key = 0;
    while(1)
    {
        spelling = getchar();

        if(spelling == ' ' || spelling == '\n')
        {
            // 비교
            word[key] = 0;
            key++;
            for(int i = 0; i < 9; i++)
            {
                //printf("%s : %s \n", word, planets[i]);
                if(strncmp(word, planets[i], Max_Word_Length) == 0)
                {
                    printf("%s is a planet.\n", word);
                    key = 0;
                    word[0] = 0;
                    break;
                }
                else
                {
                    if(i == 8)
                    {
                        printf("%s is NOT a planet.\n", word);
                        word[0] = 0;
                        key = 0;
                    }
                }
            }

            if(spelling == '\n')
            {
                break;
            }
        }
        else
        {
            word[key] = spelling;
            key++;
        }
    }
}
