#include<iostream>
#include<string>
#include <algorithm>
using namespace std;
string translate(int value, string a)
{
    int temp;

    temp = value % 2;
    value /= 2;

    a.append(to_string(temp));
    if(value == 0)
    {
        return a;
    }
    else
    {
        return translate(value, a);
    }
}

int main(void)
{
    int n = 0;
    string N;
    cin>>n;
    N = translate(n, N);
    reverse(N.begin(), N.end());
    cout<<N<<endl;

}


