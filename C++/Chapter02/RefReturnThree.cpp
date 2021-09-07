#include <iostream>



/*
참조형
- 기본 자료형
지금 참조하고 있던 값을
저기다 보내주는거고
참조형에 보내는건
얘도 지금 참조하고있는걸 참조하게
만드는거
맞지??
int 에다가는
return ref를 보냈을때
ref의 값만 딱 보내는거고
int& 에다가는
ref가 참조하는걸
int&도 참조하게
만든다
*/

int RefRetFuncTwo(int &ref)
{
    ref++;
    return ref;
}

int main(void)
{
    int num1 = 1;
    //int &num2 = RefRetFuncOne(num1);
    int num2 = RefRetFuncTwo(num1);
    num1+=1;
    num2+=100;
    std::cout<<"num1: "<<num1<<std::endl;
    std::cout<<"num2: "<<num2<<std::endl;

    return 0;
}