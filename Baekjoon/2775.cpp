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
        //cout<<i<<endl;
        k[i]++;
    }

    int matrix[15][15];

    for(int q = 0; q < 15; q++)
    {
        for (int w = 0; w < 15; w++)
        {
            matrix[q][w] = 1;
        }   
    }

    for(int j = 0; j < 15; j++)
    {
        matrix[0][j] = j+1;
    }

    for(int j = 1; j<15; j++) //1층부터 k[i] 까지
    {
        for(int q = 1; q<15; q++) // 0호부터 n[i] 까지
        {
            matrix[j][q] = matrix[j][q-1] + matrix[j-1][q];
        }
    }

    

    for(int i = 0; i < T; i++)
    {
        /*
        for(int q = 0; q < k[i]; q++)
        {
            for (int w = 0; w < n[i]; w++)
            {
                cout<<"|"<<matrix[q][w]<<"|";
            }   
            cout<<endl;
        }   
        */
        cout<<matrix[k[i]-1][n[i]-1]<<endl;
    }

}
