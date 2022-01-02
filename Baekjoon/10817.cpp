#include<iostream>

using namespace std;

int main(void)
{
    int A = 0;
    int B = 0;
    int C = 0;

    int input_Array[3];
    int sequence_Array[3];
    cin>>input_Array[0];
    cin>>input_Array[1];
    cin>>input_Array[2];

    int most_Num = 0;
    int most_idx = 0;

    for(int j = 0; j < 3; j++)
    {
        most_Num = 0;
        most_idx = 0;
        for(int i = 0; i < 3; i++)
        {
            if(input_Array[i] >= most_Num)
            {
                most_Num = input_Array[i];
                most_idx = i;
            }
        }
        input_Array[most_idx] = 0;
        sequence_Array[j] = most_Num;
    }
    
    cout<<sequence_Array[1]<<endl;
    
}