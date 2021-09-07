#include<iostream>
#include<cstdlib>
using namespace std;

int Cal_Dist(int r1, int c1, int r2, int c2);
int Cal_Chicken_Dist(int shop_Num, int home_Num, struct Space* shop, struct Space *home, int jump);
int recoll(int break_Num, int count, int shop_Num, int home_Num, int shop, int home);
void combination(int depth, int next, int n, int r, int* cArr);
void printArray(int* cArr);



struct Space // 공간
{
    int type;// 0 = 빈칸, 1 = 집, 2 = 치킨집
    int x;
    int y;
    int check;
};



int main(void)
{
    int N;
    cin>>N;

    int M;
    cin>>M;
    Space space[N][N];
    
    int home_Num = 0;
    int shop_Num = 0;


    int min_dist = 1000;
    int remain_Num = 0;
    int total = 0;



    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j< N; j++)
        {
            cin>>space[j][i].type;    
            if(space[j][i].type == 2)
            {
                shop_Num ++;
                remain_Num++;
            }       
            else if(space[j][i].type == 1)
            {
                home_Num ++;
            }
        }
    }
    
    Space home[home_Num];
    Space shop[shop_Num];
    
    int homeIdx = 0;
    int shopIdx = 0;
    cout<<home_Num<<endl;
    cout<<shop_Num<<endl;
    
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {  
            if(space[j][i].type == 1)
            {
                home[homeIdx].type = 1;
                home[homeIdx].x = j;
                home[homeIdx].y = i;
                homeIdx++;
            }
            else if(space[j][i].type == 2)
            {
                shop[shopIdx].type = 2;
                shop[shopIdx].x = j;
                shop[shopIdx].y = i;
                shopIdx++;
            }
        }
    }
    
    total = Cal_Chicken_Dist(shop_Num, home_Num, shop, home, -1);

    int n = remain_Num;
    int r = remain_Num - M;
    //cout<<" 도시의 치킨거리는 "<<total<<endl;
    int cArr[n] = { 0, };
    combination(0, 1, n , r, cArr);
    //total = recoll(Time);
    

    cout<<total<<endl;

}



//1. 모든 집들의 '치킨 거리'를 계산한다. 계산할 때마다 result에 합해 '도시의 치킨 거리를 구한다'
//2. 만약 이 '치킨 집이 사라진다면' 함수를 실행한다.
//3. 함수에서는 치킨집들을 순회하며 가장 치킨거리가 가장 크게 작아지는 치킨집을 찾는다.
//4. 검사가 끝나면 가장 크게 작아지는 치킨집의 type을 0으로 바꿔준다.
//5. 그와 함께 '도시의 치킨 거리'를 구한다.
//5. '치킨 집이 사라진다면' 함수를 remain_Num이 M과 같아질때까지 반복한다.
//6. 현재 '도시의 치킨 거리'를 출력한다.

int Cal_Dist(int r1, int c1, int r2, int c2)
{
    return ((abs((r1+1)-(r2+1))) + (abs((c1+1)-(c2+1))));
}

int Cal_Chicken_Dist(int shop_Num, int home_Num, struct Space *shop, struct Space *home, int jump)
{
    //cout<<"치킨거리를 계산합니다!"<<endl;
    int temp = 0;
    int min_temp = 1000;
    int total = 0;
    bool isjump = false;

    for(int i = 0; i < home_Num; i++)
    {
        min_temp = 1000;
        for (int j = 0; j < shop_Num; j++)
        {
            if(shop[j].type != 0 && jump)
            {
                temp = Cal_Dist(home[i].x, home[i].y, shop[j].x, shop[j].y);
                //cout<<home[i].x<<shop[j].x<<home[i].y<<shop[j].y<<endl;
                //cout<<j<<"번째로 현재 계산된 치킨거리 "<<temp<<endl;
                if(min_temp >= temp)
                {
                    min_temp = temp;
                }
            }
        }
        total+=min_temp;
        
        //cout<<" 가장 짧은 치킨집의 거리는 "<<min_temp<<endl;
        //cout<<" 도시의 치킨거리는 "<<total<<endl;
    }
    return total;
}

/*
int recoll(int break_Num, int count, int shop_Num, int home_Num, int shop, int home)
{
    int del_shop = -1;
    int temp = 0;
    int temp_total= 0;
    for (int i = 0; i< shop_Num; i++)
    {

        temp = Cal_Chicken_Dist(shop_Num, home_Num, shop, home, i);
        cout<<temp<<endl;

        if(temp_total <= temp)
        {
            del_shop = i;
            temp_total = temp;
        }
    }    
        
    cout<<del_shop<<"번째 상점이 폐업했습니다"<<endl;
    shop[del_shop].type = 0;
    remain_Num --;
    //cout<<"남은 치킨 집의 수는: "<<remain_Num<<endl;
    total = Cal_Chicken_Dist(shop_Num, home_Num, shop, home, -1);

    if(break_Num != count)
    {
        recoll();
    }
    else if(braek_Num == count)
    {
        return total;
    }
    
}
*/


void combination(int depth, int next, int n, int r, int* cArr){
    if(depth == r){
        printArray(cArr);
        return;
    }

    for(int i = next; i <= n; i++){
        cArr[depth] = i;
        
        combination(depth + 1, i + 1, n, r, cArr);
    }
}

void printArray(int* cArr)
{
    for(int i =0; i < sizeof(cArr)/ sizeof(cArr[0]); i++)
    {
        cout<<cArr[i];
    }
    cout<<endl;
}
