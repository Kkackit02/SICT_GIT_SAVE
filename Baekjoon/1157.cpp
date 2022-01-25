#include<iostream>
using namespace std;


int main(void)
{
    string input_String;
    
    cin>>input_String;

    int Alpha_Array[26];
    
    int most_often_Num = 0;

    bool isMost = true;
    for(int i = 0; i < 26; i++)
    {
        Alpha_Array[i] = 0;
    }

     
    for(int i = 0; i < input_String.size(); i++)
    {
        input_String[i] = tolower(input_String[i]);

        Alpha_Array[int(input_String[i]) - 97]++;
    }

    
    for(int i =1; i< 26; i++)
    {
        if(Alpha_Array[i] > Alpha_Array[most_often_Num])
        {
            most_often_Num = i;
            isMost= true;
        }
        else if(Alpha_Array[i] == Alpha_Array[most_often_Num])
        {
            isMost = false;
        }

    }

    if(isMost == false)
    {
        cout<<"?"<<endl;
    }
    else
    {
        cout<<char(most_often_Num + 65)<<endl;
    }


}