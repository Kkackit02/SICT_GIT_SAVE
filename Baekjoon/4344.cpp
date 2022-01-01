#include<iostream>
using namespace std;

int main(void)
{
    int test_Case_Num = 0;
    cin>>test_Case_Num;

    float result_array[test_Case_Num];
    for(int i = 0; i < test_Case_Num; i ++)
    {
        result_array[i] = 0;
    }

    for(int i = 0; i < test_Case_Num; i++)
    {
        int student = 0;
        cin>>student;
        int score_array[student];

        float average = 0;

        for(int j = 0; j < student; j++)
        {
            cin>>score_array[j];
            average += score_array[j];
        }

        average = average/student;

        for(int j = 0; j < student; j++)
        {
            if(score_array[j] > average)
            {
                result_array[i]+=1;
            }
        }

        result_array[i] = result_array[i]/student*100;
    }

    for(int i = 0; i < test_Case_Num; i++)
    {
        cout << fixed;
        cout.precision(3);
        cout<<result_array[i]<<"%"<<endl;
    }
}