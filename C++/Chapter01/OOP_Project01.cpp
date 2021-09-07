#include <iostream>
#include <cstring>



typedef struct
{
    int UserMoney;
    int UserAccount;
    char UserName[30];
}Account;

void MakeAccount(Account account[], int initNum);
void Deposit(Account account[], int initNum);
void Withdraw(Account account[], int initNum);
void ReadData(Account account[], int initNum);

int main(void)
{
    bool outFlag = false;
    
    
    Account account[10];
    int initNum = 0;

    int UserSwitch;
    while(true)
    {
        std::cout<<"-----Menu-----"<<std::endl;
        std::cout<<"1. 계좌개설"<<std::endl;
        std::cout<<"2. 입 금"<<std::endl;
        std::cout<<"3. 출 금"<<std::endl;
        std::cout<<"4. 계좌정보 전체 출력"<<std::endl;
        std::cout<<"5. 프로그램 종료"<<std::endl;

        std::cout<<"선택 : ";
        std::cin>>UserSwitch;

        switch (UserSwitch)
        {
        case 1:
            
            MakeAccount(account, initNum);
            initNum++;
            break;
            
        case 2:
        {
            Deposit(account, initNum);
            break;
        }

        case 3:
        {
            Withdraw(account, initNum);
            break;
        }   
        case 4:
        {
            ReadData(account, initNum);
            break;
        }
        case 5:
            outFlag = true;
            break;

        default:
            break;    
        }

        if(outFlag == true)
        {
            break;
        }
    }
}


void MakeAccount(Account account[], int initNum)
{
    std::cout<<"계좌ID: ";
    std::cin>>account[initNum].UserAccount;
    std::cout<<"이 름: ";
    std::cin>>account[initNum].UserName;
    std::cout<<"잔 액: ";
    std::cin>>account[initNum].UserMoney;
}

void Deposit(Account account[], int initNum)
{
    int tempID = 0;
    int temp = 0;
    std::cout<<"[입     금]"<<std::endl;
    std::cout<<"계좌 ID: ";
    std::cin>>tempID;
    for (int i = 0; i < initNum; i++)
    {
        if(account[i].UserAccount == tempID)
        {
            tempID = i;
        }
    }
    std::cout<<"입금액: ";
    std::cin>>temp;
    account[tempID].UserMoney+=temp;
    std::cout<<"입금 완료";
}
void Withdraw(Account account[], int initNum)
{
    int tempID = 0;
    int temp = 0;
    std::cout<<"[출     금]"<<std::endl;
    std::cout<<"계좌 ID: ";
    std::cin>>tempID;

    for (int i = 0; i < initNum; i++)
    {
        if(account[i].UserAccount == tempID)
        {
            tempID = i;
        }
    }

    std::cout<<"출금액: ";
    std::cin>>temp;
    account[tempID].UserMoney+=temp;
    std::cout<<"출금 완료";
}

void ReadData(Account account[], int initNum)
{
    int tempID = 0;
    std::cout<<"계좌 ID: ";
    std::cin>>tempID;
    for (int i = 0; i < initNum; i++)
    {
        if(account[i].UserAccount == tempID)
        {
            tempID = i;
        }
    }
    std::cout<<"이 름: ";
    std::cout<<account[tempID].UserName<<std::endl;
    std::cout<<"잔 액: ";
    std::cout<<account[tempID].UserMoney<<std::endl;
}