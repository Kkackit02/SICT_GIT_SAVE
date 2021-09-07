#include <iostream>
#include <cstring>
#include "Exam2.h"

using namespace std;

    void Printer::SetString(const char* Data)
    {
        strcpy(CharArray, Data);
    }
    void Printer::ShowString()
    {
        cout<<CharArray<<endl;
    }