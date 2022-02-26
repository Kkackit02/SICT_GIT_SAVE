#include <vector>
#include <iostream>
#include<algorithm>
#include<cmath>
using namespace std;

int solution(vector<int> nums) {
    int answer = 0;
    int nums_size = nums.size(); 
    int maxNum = 0; // 계산량을 줄이기 위해서 넣은 변수
    for(int i = 0; i < nums_size; i++)
    {
        maxNum += nums[i]; 
    // 3개를 더했을때 가장 큰 수가 되는 경우의 수를 maxNum으로 해놓으면 가장 좋겠지만 
    // 우선 그냥 입력받은 수의 값을 다 더해서 maxNum을 구함
    }
    
    int Temp_Array[maxNum]; //에라토스테네스의 체 알고리즘을 쓰기 위한 임시 배열
    int PrimeNum_Array[maxNum]; //임시 배열로 구한 소수들을 저장할 배열
    int prime_Count = 0; // PrimeNum_Array 배열의 index
    for(int i = 0; i < maxNum+1; i++)
    {
        Temp_Array[i] = i; // 초기화
    }
    
    
    //에라토스테네스의 체 알고리즘 // https://donggoolosori.github.io/2020/10/16/eratos/
    for(int i = 2; i < sqrt(maxNum+1); i++)  // 어차피 제곱인 수들은 소수가 아니므로 제곱근으로 계산
    {
        if(Temp_Array[i] == 0) //이미 삭제된 수들은 continue
            continue;
        for(int j = i * i; j<= maxNum+1; j+= i) 
        {   
            Temp_Array[j] = 0;
        }
    }
    
    //임시 배열에서 구한 소수들을 저장
    for(int i = 0; i < maxNum+1; i++)
    {
        if(Temp_Array[i] != 0)
        {
            PrimeNum_Array[prime_Count] = Temp_Array[i];
            prime_Count++;
       
    }
    
    
    
    int temp = 0;
    for(int i = 0; i < nums_size; i++) //조합 구하기
    {
        for(int j = 0; j < i; j++)
        {
            for(int k = 0; k < j; k++)
            {
                temp = nums[i] + nums[j] + nums[k]; 
                for(int i = 0; i < prime_Count; i++) //나온 조합의 수들을 다 더한 수가 소수인지 검사
                {
                    if(temp == PrimeNum_Array[i]) //만약 소수라면
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


// 1. 에라토스테네스의 체 알고리즘으로 입력받은 수에서 나올 수 있는 범위의 소수를 다 구하기.
// 2. num C(조합) 3 의 경우의 수를 구하기.
// 3. 구한 경우의 수의 수들을 다 더한 뒤 1에서 구한 배열에 비교해보면서 소수인지 판별.
// 4. 소수라면 answer에 1을 더하고 반복이 끝나면 결과 출력
