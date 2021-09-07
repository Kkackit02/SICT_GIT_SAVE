#include <iostream>
using namespace std;

int main(void)
{
    int N = 0;
    cin>>N;
    int K = 0;
    cin>>K;
    int stop_Num = 0;
    int result = 0;
    int temp = 2;
    int del_Num;

    int num_Array[N+1];

    
    for (int i = 2; i < N+1; i++)
    {
        num_Array[i] = i;
    }

    while (temp <= N)
    {
        for(int i = 1; i*temp < N+1 ; i++)
        {
            if(num_Array[temp * i] != 0)
            {
                result = num_Array[temp * i];
                //cout<<result<<endl;
                num_Array[temp * i] = 0;
                stop_Num++;
            }

            if(K == stop_Num)
            {
                break;
            }
        }

        if(K == stop_Num)
            {
                break;
            }
        temp ++;
    }
    
    cout<<result<<endl;
}