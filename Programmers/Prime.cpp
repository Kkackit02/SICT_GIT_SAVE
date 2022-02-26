#include <vector>
#include <iostream>
#include<algorithm>
#include<cmath>
using namespace std;

int solution(vector<int> nums) {
    int answer = 0;
    int nums_size = nums.size();
    int maxNum = 0;
    for(int i = 0; i < nums_size; i++)
    {
        maxNum += nums[i];
    }
    
    int Temp_Array[maxNum]; 
    int PrimeNum_Array[maxNum];
    int prime_Count = 0;
    for(int i = 0; i < maxNum+1; i++)
    {
        Temp_Array[i] = i;
    }
    
    
    
    for(int i = 2; i < sqrt(maxNum+1); i++)
    {
        if(Temp_Array[i] == 0)
            continue;
        for(int j = i * i; j<= maxNum+1; j+= i)
        {   
            Temp_Array[j] = 0;
        }
    }
    for(int i = 0; i < maxNum+1; i++)
    {
        if(Temp_Array[i] != 0)
        {
            PrimeNum_Array[prime_Count] = Temp_Array[i];
            prime_Count++;
        }
    }
    
    int temp = 0;
    for(int i = 0; i < nums_size; i++)
    {
        for(int j = 0; j < i; j++)
        {
            for(int k = 0; k < j; k++)
            {
                temp = nums[i] + nums[j] + nums[k];
                for(int i = 0; i < prime_Count; i++)
                {
                    if(temp == PrimeNum_Array[i])
                    {
                        cout<<temp<<endl;
                        answer++;
                    }
                }
            }
        }
    }
        
    return answer;
}
