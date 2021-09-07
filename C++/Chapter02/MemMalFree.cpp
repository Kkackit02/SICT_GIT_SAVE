#include <iostream>
#include <string.h>
#include <stdlib.h>


char * MakeSterAdr(int len)
{
    char * str = (char*)malloc(sizeof(char)*len);
    return str;
}


int main(void)
{
    char * str = MakeSterAdr(20);
    strcpy(str, "I am so happy~");
    std::cout<<str<<std::endl;

    free(str);
    return 0;
}