#include<iostream>
using namespace std;

int main(void)
{
    int input_Array[10];
    int result = 0;

    int check_Array[10];


    for(int i = 0; i < 10; i++)
    {
        cin>>input_Array[i];
        input_Array[i] %= 42;

        check_Array[i] = -1; // 초기화
    }

    int idx = 0;
    bool isCheck = false;
    for(int i = 0; i < 10; i++) //나머지는 결국 1~41
    {
        for(int j = 0; j < idx+1; j++)
        {
            if(input_Array[i] == check_Array[j])
            {
                isCheck = true;
                break;
            }
        }

        if(isCheck == true)
        {
            isCheck = false;            
        }
        else
        {
            
            check_Array[idx] = input_Array[i];
            idx++;
            result++;
        }
        
    }

    cout<<result<<endl;
}