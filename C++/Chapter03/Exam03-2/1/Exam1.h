#ifndef __EXAM1_H__
#define __EXAM1_H__

class Calculator
{
private:
    int addNum;
    int minusNum;
    int multiplyNum;
    int divideNum;

public:
    void Init();
    double Add(double a , double b);
    double Div(double a , double b);
    double Min(double a, double b);
    double Mul(double a , double b);
    void ShowOpCount();
};
#endif