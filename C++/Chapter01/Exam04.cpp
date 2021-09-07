#include<iostream>

int main(void)
{
    
    while(true)
    {
        int temp = 0;
        std::cout<<"판매 금액을 만원 단위로 입력(-1 to end): ";
        std::cin>>temp;

        

        if(temp == -1)
        {
            break;
        }
        else
        {
            std::cout<<"이번 달 급여: " << 50 + temp*0.12<<"만원"<<std::endl;
        }
    }
    std::cout<<"프로그램을 종료합니다."<<std::endl;
    
}