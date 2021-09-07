#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
int main(void)
{
    char str1[30] = "result";
    char str2[30] = "";

    std::cout<<"str1 : "<<str1<<std::endl;  
    std::cout<<"str1의 길이 : "<<strlen(str1)<<std::endl;
    std::cout<<"str1에 123 추가 " << strcat(str1, "123")<<std::endl;
    std::cout<<"str1의 길이 : "<<strlen(str1)<<std::endl;
    std::strcpy(str2,str1);
    std::cout<<"str1 : "<<str1<<std::endl; 
    std::cout<<"str2 : "<<str2<<std::endl;
    std::cout<<"str2에 str1 복사" <<std::endl;

    if(strcmp(str1,str2) == 0)
    {
        std::cout<<"str1은 str2와 같다"<<std::endl;
    }
    else
    {
        std::cout<<"str1은 str2와 다르다"<<std::endl;
    }
    std::cout<<"str1의 길이 : "<<strlen(str1)<<std::endl;
    std::cout<<"str2의 길이 : "<<strlen(str2)<<std::endl;
    return 0;
}