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

    SoSimple& AddNum(int n)
    {
        num+=n;
        return *this;
    }

    void ShowData()
    {
        cout<<"num: "<<num<<endl;
    }

};

SoSimple SimpleFincObj(SoSimple ob)
{
    cout<<"return 이전 "<<endl;
    //ob.ShowData();
    return ob;
}

int main(void)
{
    SoSimple obj(7);
    SimpleFincObj(obj).AddNum(30).ShowData();
    obj.ShowData();
    return 0;
}