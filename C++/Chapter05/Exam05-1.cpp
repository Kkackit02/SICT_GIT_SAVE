#include <iostream>
#include <cstring>
using namespace std;

namespace COMP_POS
{
    enum {CLERK , SENIOR, ASSIST, MANAGER};
};

class NameCard
{
    private:
    char * name;
    char * companyName;
    char * callNum;
    int rank;

    public:
    NameCard(const char * inputName, const char * inputCompanyName, const char * inputCallNum, int inputRank)
    {
        name = new char[strlen(inputName) + 1];
        strcpy(name, inputName);
        companyName = new char[strlen(inputCompanyName) + 1];
        strcpy(companyName, inputCompanyName);
        callNum = new char[strlen(inputCallNum) + 1];
        strcpy(callNum, inputCallNum);
        rank = inputRank;
    }
    NameCard(const NameCard& copy) : rank(copy.rank)
    {
        name=new char[strlen(copy.name)+1];
        strcpy(name, copy.name);

        companyName=new char[strlen(copy.companyName)+1];
        strcpy(companyName, copy.companyName);

        callNum=new char[strlen(copy.callNum)+1];
        strcpy(callNum, copy.callNum);
    }

    void ShowNameCardInfo() const
    {
        cout<<"이름: "<<name<<endl;
        cout<<"회사: "<<companyName<<endl;
        cout<<"전화번호: "<<callNum<<endl;
        switch(rank)
        {
            case COMP_POS::CLERK:
                cout<<"직급: 사원"<<endl;
                break;
            case COMP_POS::SENIOR:
                cout<<"직급: 주임"<<endl;
                break;
            case COMP_POS::ASSIST:
                cout<<"직급: 대리"<<endl;
                break;
            case COMP_POS::MANAGER:
                cout<<"직급: 과장"<<endl;
                break;            
        }
    }

    ~NameCard()
    {
        delete []name;
        delete []companyName;
        delete []callNum;
    }

};

int main(void)
{
    NameCard manClerk("Lee", "ABCEng", "010-1111-2222", COMP_POS::CLERK);
    NameCard copy1 = manClerk;
    NameCard manSENIOR("HONG", "OrangeEng", "010-3333-4444", COMP_POS::SENIOR);
    NameCard copy2 = manSENIOR;
    NameCard manAssist("Kim", "SoGoodComp", "010-5555-6666", COMP_POS::ASSIST);

    copy1.ShowNameCardInfo();
    copy2.ShowNameCardInfo();
    return 0;
}
