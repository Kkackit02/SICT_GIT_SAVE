#include<iostream>

int main(void)
{
    int input = 0;

    std::cout<<"숫자를 입력해주십시오: ";
    std::cin>>input;

    for(int i = 1; i < 10; i++)
    {
        std::cout<<input<<" * "<<i<<" = "<<input*i<<" 입니다."<<std::endl;
    }
}