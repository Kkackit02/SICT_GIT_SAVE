#include<iostream>

using namespace std;

int main(void)
{
    int T = 0;
    int R = 0;

    string S = "";

    string print_S = "";

    cin>>T;
    for(int i = 0; i<T; i++)
    {
        S = "";
        print_S = "";
        cin>>R;
        cin>>S;
        int string_Len = S.length();

        for(int j = 0; j < string_Len; j++)
        {
            print_S.append(R, S[j]);
            
        }

        cout<<print_S<<endl;
    }





}