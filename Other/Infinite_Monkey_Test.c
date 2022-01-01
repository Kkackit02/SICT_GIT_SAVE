#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(void)
{
    int random = 0;
    srand(time(NULL));

    int zero = 0;
    int four = 0;
    int three = 0;
    int two = 0;
    int one = 0;

    int try_N = 500000;
    double average = 0;
    for(int i = 0; i < try_N; i++)
    {
        random = rand()%1001;

        if(random >= 997)
        {
            four++;
            average+=4;
        }
        else if(997 > random && random >= 879)
        {
            three++;
            average+=3;
        }
        else if(879 > random && random >= 562.5)
        {
            two++;
            average+=2;
        }
        else if(562.5 > random && random >= 250)
        {
            one++;
            average+=1;
        }
        else
        {
            zero++;
        }
    }

    average= average / try_N;
    printf("zero = %d , one = %d , two = %d , three = %d , four = %d , average = %f \n", zero, one, two, three, four, average);
    


    
    int monkey = 1;
    int key = 2;
    int word = 4;
        
    four = 0;
    three = 0;
    two = 0;
    one = 0;
    zero = 0;
    int success = 0;
    average = 0;

    for (int k = 0; k < monkey; k++)
    {
        for(int j = 0; j < try_N; j++)
        {
            for (int i = 0; i < word; i++)
            {
                random = rand()%101;
                if(random >= (100/key))
                {
                    success++;
                }
            }
            
            switch (success)
            {
                case 4:
                    four++;
                    average +=4;
                    break;
                case 3:
                    three++;
                    average +=3;
                    break;
                case 2:
                    two++;
                    average +=2;
                    break;
                case 1:
                    one++;
                    average +=1;
                    break;
                case 0:
                    zero++;
                    break;
                default:
                    break;
            }
            success = 0;

        }
    }
    
    average= average / (try_N * monkey);
    printf("zero = %d , one = %d , two = %d , three = %d , four = %d , average = %f \n", zero, one, two, three, four, average);

    double zero_P = (float)zero / (try_N * monkey);
    double one_P = (float)one / (try_N * monkey);
    double two_P = (float)two / (try_N * monkey);
    double three_P = (float)three / (try_N * monkey);
    double four_P = (float)four / (try_N * monkey);

    printf("P : zeroP = %f , one = %f , two = %f , three = %f , four = %f , average = %f \n", zero_P, one_P, two_P, three_P, four_P, average);
    printf("%f \n", zero_P + one_P + two_P + three_P + four_P);
}

