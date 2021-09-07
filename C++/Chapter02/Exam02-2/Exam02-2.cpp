#include<iostream>




int main(void)
{

    const int num =12;

    const int *ptr = &num;

    const int *(&Ref_ptr) = ptr;
    
    std::cout<<*ptr<<std::endl;
    std::cout<<*Ref_ptr<<std::endl;
    return 0;

}