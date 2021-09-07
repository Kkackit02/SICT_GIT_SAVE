#include<iostream>
using namespace std;
void Sort(int list[], int card_num);

int main(void)
{
    int N = 0; // 3 <= N <= 100
    int M = 0; // 10 <= M <= 300,000

    int card_data[100];

    int card_num = 0;

    int result = 0;
    int mainResult = 0;
    cin>>card_num;
    cin>>M;

    for (int i = 0; i < card_num; i++)
    {
        cin>>card_data[i];
    }
    
     for (int q = 0; q < card_num; q++)
     {
        for(int w = 0; w < card_num; w++)
        {
            if(w == q)
            {
                continue;
            }

            for(int e = 0; e < card_num; e++)
            {
                if(e == w || e == q)
                {
                    continue;
                }
                //cout<<q<<" " <<w<<" "<<e<<endl;
                result = card_data[q] + card_data[w] + card_data[e];
                if(mainResult <= result && result <= M)
                {
                    mainResult = result;
                }
            }
        }
    }          

    cout<<mainResult;
}


