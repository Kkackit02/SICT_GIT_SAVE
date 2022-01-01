#include<iostream>
using namespace std;

int main(void)
{
    int N = 0;
    cin>>N;

    int result = 0;
    cin.get();
    for(int i =0; i < N; i++)
    {
        int temp = 0;
        temp = cin.get() - '0';
        result+=temp;
        
    }

    cout<<result;

}