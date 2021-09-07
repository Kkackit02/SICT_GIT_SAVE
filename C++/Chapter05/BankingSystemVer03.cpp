#include <iostream>
#include <cstring>
using namespace std;




class Account
{
    private:
        int id;
        int money;
        char * name;

    public:
        Account(int input_id, int input_money, char * input_name)
        : id(input_id), money(input_money)
        {
            name = new char[strlen(input_name) + 1];
            strcpy(name, input_name);
        }

        Account(const Account & ref)
        : id(ref.id), money(ref.money)
        {
            name = new char[strlen(ref.name)+1];
            strcpy(name, ref.name);
        }

        int GetId()
        {
            return id;
        }

        void Deposit(int value)
        {
            money += value;
        }

        void Withdraw(int value)
        {
            money -= value;
        }

        void ReadData()
        {
            cout<<"이 름: ";
            cout<<name<<endl;
            cout<<"잔 액: ";
            cout<<money<<endl;
        }


        ~Account()
        {
            delete []name;
        }
};

void MakeAccount_Menu(Account * account[], int initNum);
void Deposit_Menu(Account * account[], int initNum);
void Withdraw_Menu(Account * account[], int initNum);
void ReadData_Menu(Account * account[], int initNum);

int main(void)
{
    bool outFlag = false;
    
    
    Account * account[100];
    int initNum = 0;

    int UserSwitch;
    while(true)
    {
        cout<<"-----Menu-----"<<endl;
        cout<<"1. 계좌개설"<<endl;
        cout<<"2. 입 금"<<endl;
        cout<<"3. 출 금"<<endl;
        cout<<"4. 계좌정보 전체 출력"<<endl;
        cout<<"5. 프로그램 종료"<<endl;

        cout<<"선택 : ";
        cin>>UserSwitch;

        switch (UserSwitch)
        {
        case 1:
            
            MakeAccount_Menu(account, initNum);
            initNum++;
            break;
            
        case 2:
        {
            Deposit_Menu(account, initNum);
            
            break;
        }

        case 3:
        {
            Withdraw_Menu(account, initNum);
            break;
        }   
        case 4:
        {
            ReadData_Menu(account, initNum);
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


void MakeAccount_Menu(Account * account[], int initNum)
{
    int tempId = 0;
    int tempMoney = 0;
    char tempName[100];

    cout<<"계좌ID: ";
    cin>>tempId;
    cout<<"이 름: ";
    cin>>tempName;
    cout<<"잔 액: ";
    cin>>tempMoney;

    account[initNum] = new Account(tempId, tempMoney, tempName);
}

void Deposit_Menu(Account * account[], int initNum)
{
    int tempID = 0;
    int temp = 0;

    cout<<"[입     금]"<<endl;
    cout<<"계좌 ID: ";
    cin>>tempID;

    for (int i = 0; i < initNum; i++)
    {
        if(account[i]->GetId() == tempID)
        {
            tempID = i;
        }
    }

    cout<<"입금액: ";
    cin>>temp;
    account[tempID]->Deposit(temp);
    cout<<"입금 완료";
}
void Withdraw_Menu(Account * account[], int initNum)
{
    int tempID = 0;
    int temp = 0;
    cout<<"[출     금]"<<endl;
    cout<<"계좌 ID: ";
    cin>>tempID;

    for (int i = 0; i < initNum; i++)
    {
        if(account[i]->GetId() == tempID)
        {
            tempID = i;
        }
    }

    cout<<"출금액: ";
    cin>>temp;
    account[tempID]->Withdraw(temp);
    cout<<"출금 완료";
}

void ReadData_Menu(Account * account[], int initNum)
{
    int tempID = 0;
    cout<<"계좌 ID: ";
    cin>>tempID;
    for (int i = 0; i < initNum; i++)
    {
        if(account[i]->GetId() == tempID)
        {
            tempID = i;
        }
    }

    account[tempID]->ReadData();

}