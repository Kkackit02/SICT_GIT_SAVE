#include <iostream>

using namespace std;

//어떤 양의 정수 X의 각 자리가 등차수열을 이룬다면 그 수를 한수라고 한다.

///Ex 1234 , 4321 , 1357

int main(void)
{
    int N = 0; // 1 <= N <= 1000;
    cin>>N;

    int zero_Num; //1의 자리
    int first_Num; //10의 자리
    int second_Num; // 100의 자리

    int result = 0;
    int temp = 0;

    for(int i = 1; i < N+1; i++)
    {
        zero_Num = i%10; // 1의 자리
        first_Num = (i/10)%10; //10의 자리
        second_Num = (i/100)%10; // 100의 자리

        if(i < 100)
        {
            result ++;
        }

        else if(i >= 100 && i <= 999)
        {
            temp = second_Num - first_Num;
            if(first_Num == zero_Num + temp && second_Num == zero_Num + temp * 2)
            {
                result++;   
            }      
        }

        
    }  

    

    cout<<result<<endl;

}