#include<iostream>
using namespace std;


int main(void)
{
    int T = 0;
    cin>>T;

    //-10000 <= x1,y1,x2,y2 <= 10000
    // r1,r2 <= 10000
    int x1 = 0;
    int y1 = 0;
    int r1 = 0;

    int x2 = 0;
    int y2 = 0;
    int r2 = 0;

    int result[T];


    for(int i = 0; i < T; i++)
    {
        int count = 0;        
        cin>>x1;
        cin>>y1;
        cin>>r1;
        cin>>x2;
        cin>>y2;
        cin>>r2;

        if(r1 > r2)
        {
            int temp = r1;
            r1 = r2;
            r2 = temp;
        }
        int center_Distance = (x1-x2)*(x1-x2) + (y1-y2) * (y1-y2);
        if(((r2 - r1)*(r2 - r1) < center_Distance) && (center_Distance < (r1 + r2)*(r1 + r2)))
        {
            result[i] = 2;
        }
        else if(center_Distance == (r1 + r2)*(r1 + r2))
        {
            result[i] = 1;
        }
        else if((center_Distance == (r2 - r1)*(r2 - r1)) && (center_Distance != 0))
        {
            result[i] = 1;
        }
        else if(center_Distance < (r2 - r1)*(r2 - r1))
        {
            result[i] = 0;
        }
        else if(center_Distance > (r1 + r2)*(r1 + r2))
        {
            result[i] = 0;
        }
        else if((center_Distance == 0) && (r1 == r2))
        {
            result[i] = -1;
        }
    }

    for(int i = 0; i < T; i++)
    {
        cout<<result[i]<<endl;
    }
}