#include <iostream>
using namespace std;

class SoSimple
{
    private:
    int num;
    public:
    SoSimple(int n) : num(n)
    {    }
    SoSimple(const SoSimple& copy) : num(copy.num)
    {
        cout<<"Called SoSimple(const SoSimple& copy_"<<endl;
    }
    void ShowData()
    {
        cout<<"num: "<<num<<endl;
    }

};

void SimpleFincObj(SoSimple ob)
{
    ob.ShowData();
}

int main(void)
{
    SoSimple obj(7);
    cout<<"함수호출 전"<<endl;
    SimpleFincObj(obj);
    cout<<"함수호출 후"<<endl;
    return 0;
}