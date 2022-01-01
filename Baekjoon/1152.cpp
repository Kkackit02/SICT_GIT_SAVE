#include <iostream>

using namespace std;


int main(void)
{
    string input_Sentence;
    int counter = 0;
    int result = 0;
    
    bool check_flag = false;

    getline(cin, input_Sentence); // 공백 포함으로 문자열 받기

    int len_Sentence = input_Sentence.length();
        
    for (int i = 0; i < len_Sentence; i++)
    {
        if(input_Sentence[i] != ' ')
        {
            check_flag = true;
        }

        if(check_flag == true)
        {
            if (input_Sentence[i] == ' ')
            {
                result++;
                check_flag == false;
            }
        }
    }

    if(input_Sentence[len_Sentence] != ' ' && input_Sentence[len_Sentence - 1] != ' ')
    {
        result++;
    }
    
    cout<<result<<endl;

}