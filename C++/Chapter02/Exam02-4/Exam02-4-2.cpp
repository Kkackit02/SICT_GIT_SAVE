#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
int main(void)
{
    srand(time(NULL));
    for(int i = 0; i< 5; i++)
    {
        std::cout<<rand()%101<<std::endl;
    }

}


