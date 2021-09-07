#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

int main(void)
{
    int N = 0;
    cin>>N;
    int K = 0;
    cin>>K;
    int stop_Num = 0;
    int result = 0;
    int temp = 2;

    int comp_data;

    int num_Array[N+1];
    list<int> num_list;
    
    
    for (int i = 1; i < N+1; i++)
    {
        //num_Array[i] = i;
        num_list.push_back(i);
    }

    while (temp <= N)
    {
        for(int i = 1; i*temp < N+1 ; i++)
        {
            list<int>::iterator it;

            it = find(num_list.begin(), num_list.end(), i*temp);
            if(it != num_list.end())
            {
                replace(num_list.begin(), num_list.end(), i*temp, 0);
                result = temp * i;
                //cout<<result<<endl;
                stop_Num++;
            }

            if(K == stop_Num)
            {
                break;
            }
        }

        if(K == stop_Num)
            {
                break;
            }
        temp ++;
    }
    
    cout<<result<<endl;
}