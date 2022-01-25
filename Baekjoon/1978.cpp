#include<iostream>
using namespace std;


int main(void)
{
    int N = 0;
    int result = 0;
    int count_Num = 0;
    int isPrime = true;
    cin>>N;
    
    int input_Array[N];
    for(int i = 0; i < N; i++)
    {
        cin>>input_Array[i];
    }


    int temp = 0;
    for(int i = 0; i < N; i++)
    {
        if(input_Array[i] == 1)
        {
            continue;
        }

        count_Num = 0;
        for(int j = 2; j < input_Array[i]; j++)
        {
            if(input_Array[i] % j == 0)
            {
                isPrime = false;
            }
            
        }
        if(isPrime == true)
        {
            result++;
        }
        else
        {
            isPrime = true;
        }
    }
    


    cout<<result<<endl;
}