#include<iostream>
using namespace std;

int main(void)
{
    int N = 0;
    cin>>N;

    float matrix[N];
    float result = 0;
    for(int i = 0; i < N; i++)
    {
        cin>>matrix[i];
    }


    int max_Num = 0;
    for(int i = 0; i < N; i++)
    {
        if(matrix[i] >= matrix[max_Num])
        {
            max_Num = i;
        }
    }

    for(int i = 0; i < N; i ++)
    {
        if(max_Num == i)
        {
            continue;
        }
        matrix[i] = matrix[i]/matrix[max_Num] * 100;
    }
    matrix[max_Num] = matrix[max_Num]/matrix[max_Num] * 100;

    for(int i = 0; i < N; i ++)
    {
        result += matrix[i];
    }

    result /= N;

    cout<<result<<endl;
}