#include<iostream>
using namespace std;

class Truck
{
private:
    int mass; // 트럭 무게
    int location; // 트럭 위치
    bool isPass = false; // 

public:

    void SetData(int input_mass, int input_location)
    {
        mass = input_mass;
        location = input_location;
    }

    int ReturnMass() const
    {
        return mass;
    }

    bool ReturnPass() const
    {
        return isPass;
    }
    // 참조자를 통해 통과 시 다리의 하중과 다리 위에 있는 트럭의 수를 감소
    void Move(int w, int & now_weight, int & in_truck) 
    {
        location++;
        if(location >= w) // 다리의 길이보다 현재 위치가 더 갔을 때
        {
            if(isPass == false) //이미 통과한 차량은 값을 수정하지 않게 하는 조건
            {
                isPass = true;
                now_weight -= mass;
                in_truck--;
            }
        }
    }
};

int main(void)
{
    int n = 0; //트럭의 수
    int w = 0; //단위 길이
    int L = 0; //최대 하중
    int temp = 0;

    int now_weight = 0;
    int in_truck = 0;

    int result = 1;
    bool isPass = false;
    
    cin>>n;
    cin>>w;
    cin>>L;
    
    Truck *p = new Truck[n];
    for(int i = 0; i<n; i++)
    {
        cin>>temp;
        p[i].SetData(temp, 0);
    }

    int truck_idx = 0;
    while(p[n-1].ReturnPass() == false) // 마지막 차량이 통과를 할때 까지
    {
        result++;
        if(L >= (now_weight + p[truck_idx].ReturnMass()) && in_truck < w) 
        // 현재 다리 위의 트럭들의 중량 + 다음 트럭의 중량이 다리의 하중보다 작고,
        // 다리의 길이보다 트럭의 수가 적으면 트럭을 새로 추가
        {
            now_weight += p[truck_idx].ReturnMass();
            in_truck++;
            truck_idx++;
            for(int i = 0; i < truck_idx; i++) //다리 위 차량들 이동
            {
                int& ref_weight = now_weight;
                int& ref_in_truck = in_truck;
                p[i].Move(w,ref_weight,ref_in_truck);
            }
        }
        else //새로운 차량을 넣을 수 없다면
        {
            for(int i = 0; i < truck_idx; i++) //다리 위 차량들 이동
            {
                int& ref_weight = now_weight;
                int& ref_in_truck = in_truck;
                p[i].Move(w,ref_weight,ref_in_truck);
            }
        }
    }
    cout<<result<<endl; //결과 출력
    delete [] p; //할당 해제
}