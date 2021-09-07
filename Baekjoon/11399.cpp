#include<iostream>

using namespace std;


struct People
{
    int time;
};

int main(void)
{
    int result = 0;
    int people_Num = 0;
    cin>>people_Num;
    
    
    People people_Array[people_Num];
    
    
    for (int i = 0; i < people_Num; i++)
    {
        cin>>people_Array[i].time;
    }

    int min = 0;
    int temp = 0;
    
    for(int i = 0; i< people_Num-1; i++)
    {
        min = i;

        for(int j = i+1; j<people_Num; j++)
        {
            if(people_Array[j].time < people_Array[min].time)
            {
                min = j;
            }
        }

        if(i != min)
        {
            temp = people_Array[i].time;
            people_Array[i].time = people_Array[min].time;
            people_Array[min].time = temp;
        }
    }


    for (int i = 0; i < people_Num; i++)
    {
        for(int j =0; j < i+1; j++)
        {
            result += people_Array[j].time;
        }
    }
    


    cout<<result<<endl;    
}

