#include <iostream>
using namespace std;

class Point //콧물 처치용 캡슐
{
private:
    int xpos, ypos, radius;
public:
    void Init(int x, int y, int r)
    {
        xpos = x;
        ypos = y;
        radius = r;
    }
    void ShowPointInfo() const
    {
        cout<<"radius: "<< radius <<endl;
        cout<<"["<<xpos<<", "<<ypos<<"]"<<endl;
    }
};

class Ring
{
private:
    Point innerCircle;
    Point outterCircle;
public:
    void Init(int inner_x, int inner_y, int inner_radius, int outter_x, int outter_y, int outter_radius)
    {
        innerCircle.Init(inner_x, inner_y, inner_radius);
        outterCircle.Init(outter_x, outter_y, outter_radius);
    }
    void ShowRingInfo() const
    {
        cout<<"Inner Circle Info..."<<endl;
        innerCircle.ShowPointInfo();
        cout<<"Outter Circle Info..."<<endl;
        outterCircle.ShowPointInfo();
    }
};

int main(void)
{
    Ring ring;
    ring.Init(1, 1, 4, 2, 2, 9);
    ring.ShowRingInfo();
    return 0;
}