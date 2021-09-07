#include <iostream>
using namespace std;

#define ID_LEN 20
#define MAX_SPD 200
#define FUEL_STEP 2
#define ACC_STEP 10
#define BRK_STEP 10

struct Point
{
    int xpos;
    int ypos;

    void MovePos(int x, int y)
    {
        xpos = x;
        ypos = y;
    }
    void AddPoint(const Point &pos)
    {
        xpos += pos.xpos;
        ypos += pos.ypos;
    }
    void ShowPosition()
    {
        cout<<"X = "<<xpos<<endl;
        cout<<"Y = "<<ypos<<endl;
    }
};

int main(void){
    
    Point pos1 = {12, 4};
    Point pos2 = {20, 30};

    pos1.MovePos(-7, 10);
    pos1.ShowPosition();
    pos1.AddPoint(pos2);
    pos1.ShowPosition();
    return 0;
}