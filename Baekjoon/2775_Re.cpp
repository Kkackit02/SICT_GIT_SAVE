#include<iostream>
using namespace std;

int Cal_value(int* matrix, int k, int n);

int main(void)
{
    int T = 0;
    cin>>T;

    int k[T]; //층의
    int n[T]; //n호
    int result[T];

    //값 입력
    for(int i = 0; i < T; i++)
    {
        cin>>k[i];
        cin>>n[i];
         //호는 1부터 시작이므로 1 더 늘려줌
        //cout<<i<<endl;
    }

    
    for(int i = 0; i < T; i++)
    {
        int matrix[k[i]][n[i]];

        for(int i = 0; i < k[i]; i++)
        {
            matrix[i][0] = 1;
        }
        for(int i = 0; i < n[i]; i++)
        {
            matrix[0][i] = 1;
        }
     
        for(int q = 0; q < k[i]; q++)
        {
            for (int w = 0; w < n[i]; w++)
            {
                cout<<"|"<<matrix[q][w]<<"|";
            }   
            cout<<endl;
        }
    }
}

    
