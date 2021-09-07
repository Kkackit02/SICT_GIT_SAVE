#include <iostream>
using namespace std;

class Simpleclass
{
    private:
    int num1;
    int num2;

    public:
    Simpleclass()
    {
        num1 = 0;
        num2 = 0;
    }
    Simpleclass(int n)
    {
        num1 = n;
        num2 = 0;
    }
    Simpleclass(int n1, int n2)
    {
        num1 = n1;
        num2 = n2;
    }

    /*
    SimpleClass(int n1 = 0, int n2 = 0)
    {
        num1 = n1;
        num2 = n2;
    }
    */

   void ShowData() const
   {
       cout<<num1<<' '<<num2<<endl;
   }
};

int main(void)
{
    Simpleclass sc1;
    sc1.ShowData();

    Simpleclass sc2(100);
    sc2.ShowData();

    Simpleclass sc3(100, 200);
    sc3.ShowData();
    return 0;
}