#include <iostream>
using namespace std;

class FruitSeller
{
private:
    int APPLE_PRICE;
    int numofApples;
    int myMoney;

public:
    bool initMembers(int price, int num, int money)
    {
        if(price>0 && num >= 0 &&  money>= 0)
        {
            APPLE_PRICE = price;
            numofApples = num;
            myMoney = money;
            return true;
        }
        else
        {
            cout<<"잘못된 값을 입력했습니다."<<endl;
            return false;
        }
    }

    bool SaleApples(int money)
    {
        int num = money/APPLE_PRICE;
        numofApples -= num;
        myMoney+=money;
        return num;
    }
    void ShowSalesResult() const
    {
        cout<<"남은 사과: "<<numofApples<<endl;
        cout<<"판매 수익: "<<myMoney<<endl<<endl;
    }  
};

class FruitBuyer
{
    int myMoney;
    int numOfApples;

    public:
    bool InitMembers(int money)
    {
        if(money>0)
        {
            myMoney = money;
            numOfApples = 0;
            return true;
        }
        else
        {
            cout<<"잘못된 값을 입력했습니다."<<endl;
            return false;
        }

        
    }
    void BuyApples(FruitSeller &seller, int money)
    {
        if(money > 0 && myMoney >= money)
        {
            numOfApples+=seller.SaleApples(money);
            myMoney-=money;
        }
        else
        {
            cout<<"돈이 부족합니다."<<endl;
        }
        
    }
    void ShowBuyResult() const
    {
        cout<<"현재 잔액: "<<myMoney<<endl;
        cout<<"사과 개수: "<<numOfApples<<endl<<endl;
    }
};

int main(void)
{
    FruitSeller seller;
    int temp_a;
    int temp_b;
    int temp_c;
    cout<<"상인의 정보를 입력해주십시오."<<endl;
    while(true)
    {
        cin>>temp_a;
        cin>>temp_b;
        cin>>temp_c;
        
        if(seller.initMembers(temp_a, temp_b, temp_c))
        {
            break;
        }
        else
        {
            cout<<"다시 입력해주십시오."<<endl;
        }
    }
    
    FruitBuyer buyer;
    cout<<"구매자의 정보를 입력해주십시오."<<endl;
    while(true)
    {
        cin>>temp_a;
        if(buyer.InitMembers(temp_a))
        {
            break;
        }
        else
        {
            cout<<"다시 입력해주십시오."<<endl;
        }
    }
    int i = 0;
    while(i < 5)
    {
        cin>>temp_a;
        buyer.BuyApples(seller, temp_a);
        cout<<"과일 판매자의 현황"<<endl;
        seller.ShowSalesResult();
        cout<<"과일 구매자의 현황"<<endl;
        buyer.ShowBuyResult();
        i++;
    }
    return 0;
}