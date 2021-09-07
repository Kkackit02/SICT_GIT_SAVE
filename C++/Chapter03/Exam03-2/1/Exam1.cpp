#include <iostream>
#include "Exam1.h"

using namespace std;

void Calculator::Init()
{
    addNum = 0;
    minusNum = 0;
    multiplyNum = 0;
    divideNum = 0;
}
    double Calculator::Add(double a , double b)
    {
        addNum++;
        return a+b;
    }
    double Calculator::Div(double a , double b)
    {
        divideNum++;
        return a/b;
    }
    double Calculator::Min(double a, double b)
    {
        minusNum++;
        return a-b;
    }
    double Calculator::Mul(double a , double b)
    {
        multiplyNum++;
        return a*b;
    }
    void Calculator::ShowOpCount()
    {
        cout<<"덧셈: "<<addNum<<" 뺄셈: "<<minusNum<<" 곱셈: "<<multiplyNum<<" 나누기: "<<divideNum<<endl;
    }