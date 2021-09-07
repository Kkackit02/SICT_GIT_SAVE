#include <iostream>
using namespace std;

class Simpleclass
{
    private:
    int num1;
    int num2;

    public:
    Simpleclass(int n1 = 0, int n2 = 0)
    {
        num1 = n1;
        num2 = n2;
    }

   void ShowData() const
   {
       cout<<num1<<' '<<num2<<endl;
   }
};

int main(void)
{
    Simpleclass sc1();//함수의 원형 선언
    Simpleclass mysc = sc1();
    mysc.ShowData();
    return 0;
}

Simpleclass sc1()
{
    Simpleclass sc(20, 30);
    return sc;
}