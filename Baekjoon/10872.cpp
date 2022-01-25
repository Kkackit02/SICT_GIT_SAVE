#include<iostream>

using namespace std;

int main(void)
{
    int N = 0;
    cin>>N;
    int result = 1;

    for(int i = 1; i <= N; i++)
    {
        result = result * i;
    }

    cout<<result<<endl;
}