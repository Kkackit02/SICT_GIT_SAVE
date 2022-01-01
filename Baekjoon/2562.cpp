#include<iostream>
using namespace std;

int main(void)
{
    int matrix[9];
    for(int i = 0; i<9; i++)
    {
        cin>>matrix[i];
    }

    int max_Num = 0;
    int result = matrix[max_Num];
    for(int i = 0; i<9; i++)
    {
        if(matrix[i] > matrix[max_Num]) //주어지는 입력 값들이 모두 다른 수 이므로 =는 생략
        {
            max_Num = i;
            result = matrix[max_Num];
        }
    }

    cout<<result<<endl;
    cout<<max_Num+1<<endl;
}