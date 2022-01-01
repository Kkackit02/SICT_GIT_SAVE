#include<iostream>
using namespace std;

int main(void)
{
    int test_Case_Num;
    cin>>test_Case_Num;
    cin.get();
    int result_array[test_Case_Num];
    for(int i = 0; i < test_Case_Num; i++)
    {
        result_array[i] = 0;
    }

    
    for(int i = 0; i < test_Case_Num; i++)
    {
        int add_Num = 1;
        while(true)
        {
            char temp;
            temp = cin.get();
            if(temp == 'O')
            {
                result_array[i] += add_Num;
                add_Num++; 
            }
            else if(temp == 'X')
            {
                add_Num = 1;
            }
            else if(temp == '\n')
            {
                add_Num = 1;
                break;
            }
        }
    }

    for(int i = 0; i < test_Case_Num; i++)
    {
        cout<<result_array[i]<<endl;
    }
}