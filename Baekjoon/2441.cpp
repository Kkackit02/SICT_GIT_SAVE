#include<iostream>

using namespace std;

int main(void)
{
    int N = 0;

    cin>>N;

    for(int i = N; i > 0; i--)
    {
        for(int k = 0; k < N-i; k++)
        {
            cout<<" ";
        }
        for(int j = 0; j < i; j++)
        {
            
            cout<<"*";
        }
        cout<<endl;
    }



}