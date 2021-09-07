#include<iostream>
#include<string.h>

typedef struct __point
{
    int xpos;
    int ypos;
} Point;


Point& PntAdder(const Point &p1, const Point &p2);

Point& PntAdder(const Point &p1, const Point &p2)
{
    Point* returnData = new Point;
    returnData->xpos = (p1.xpos + p2.xpos);
    returnData->ypos = (p1.ypos + p2.ypos);
    return *returnData;
}

int main(void)
{
    Point* val1 = new Point;
    val1->xpos = 3;
    val1->ypos = 2;
    
    Point* val2 = new Point;
    val2->xpos = 3;
    val2->ypos = 4;

    Point& result = PntAdder(*val1, *val2);

    std::cout<<"X = "<<val1->xpos << ", Y = "<<val1->ypos<<std::endl;
    std::cout<<"X = "<<val2->xpos << ", Y = "<<val2->ypos<<std::endl;
    std::cout<<"X = "<<result.xpos << ", Y = "<< result.ypos<<std::endl;
    delete(val1);
    delete(val2);
    delete &result;
}