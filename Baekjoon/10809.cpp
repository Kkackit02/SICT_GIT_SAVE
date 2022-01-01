#include<iostream>

using namespace std;

int main(void)
{
    int alphabet_Array[26];

    for (int i = 0; i<26; i++)
    {
        alphabet_Array[i] = -1;
    }
    string input_Sentence;

    cin>>input_Sentence;


    int len_Sentence = input_Sentence.length();
    
    for(int i = 0; i < len_Sentence; i++)
    {
        int spell = input_Sentence[i]; //문자를 아스키 코드로 변환

        spell = spell - 97; //a가 0부터 시작하게 바꿈

        if(alphabet_Array[spell] == (-1))
        {
            alphabet_Array[spell] = i;
        }

    }

    for(int i = 0; i < 26; i++)
    {
        cout<<alphabet_Array[i]<<" ";
    }
}