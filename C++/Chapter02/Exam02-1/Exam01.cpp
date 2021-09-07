#include <iostream>

void add(int &ref)
{
    ref++;
}

void reverse(int &ref)
{
    ref*=-1;
}

int main(void)
{
    int val1 = 10;
    int val2 = -20;
    int val3 = 30;

    add(val1);
    reverse(val2);
    reverse(val3);

    std::cout<<"val1 to ADD : "<<val1<<std::endl;

    std::cout<<"val2 to Reverse : "<<val2<<std::endl;
    std::cout<<"val3 to Reverse : "<<val3<<std::endl;
}