#include<iostream>
using namespace std;

int main(void)
{
    int M = 0;
    int N = 0;

    int size = 100;

    cin>>M;
    cin>>N;

    int min_squared = 100;
    int max_squared = 0;
    
    int sum_result = 0;
    int min_result = 0;

    bool isResult = false;
    for (int i = 1; i <= size; i++) // if size <- 100, 100*100 = 10000까지 비교
    {
        if(i*i >= M && i*i <= N)
        {
            if(min_squared*min_squared >= i*i)
            {
                min_squared = i;
            }

            if(max_squared * max_squared <= i*i)
            {
                max_squared = i;
                
            }
            isResult = true;
        }
    }

    for(int i = min_squared; i <= max_squared; i++)
    {
        sum_result+=(i*i);
    }
    min_result = (min_squared*min_squared);

    if(isResult == true)
    {
        cout<<sum_result<<endl;
        cout<<min_result<<endl;
    }
    else
    {
        cout<<-1<<endl;
    }
    

    
}