#include<iostream>
using namespace std;

void Cover(int *matrix, int H, int W);


int result = 0;

int main(void)
{
    int C = 0;
    cin>>C;

    

    int matrix[C];

    for (int i = 0; i<C; i++)
    {

        int H = 0; // 1 <= H <= 20
        int W = 0; // 1 <= W <= 20

        cin>>H;
        cin>>W;

        int input_Matrix[W][H];
        cin.get();
        for(int i = 0; i < H; i++)
        {
            for(int j = 0; j < W; j++)
            {
                char temp = cin.get();
                if(temp == '#')
                {
                    input_Matrix[j][i] = -1;
                }
                else if(temp == '.')
                {
                    input_Matrix[j][i] = 0;
                }
            }
            cin.get();
        }
        
        
        for(int i = 0; i < H; i++)
        {
            for(int j = 0; j < W; j++)
            {
                cout<<input_Matrix[j][i]<<" ";   
            }
            cout<<endl;
        }
        

        Cover((int*)input_Matrix, H,W);
    }

    cout<<result<<endl;
}

void Cover(int *matrix, int H, int W)
{
    int count = 0;
    int check = 0;
    int temp_Matrix[W][H];

    cout<<endl;
    for(int i = 0; i < H; i++)
    {
        for(int j = 0; j < W; j++)
        {
            temp_Matrix[j][i] = *(matrix + i * H + j);  
            cout<<temp_Matrix[j][i]+1<<" ";   
            if(temp_Matrix[j][i] == 0)
            {
                count++;
            }
        }
        cout<<endl;
    }

    if(count == 0)
    {
        result++;
        return;
    }

    else
    {

        for(int i = 0; i < H; i++)
        {
            for(int j = 0; j < W; j++)
            {
                if(temp_Matrix[j][i] == 0)
                {
                    temp_Matrix[j][i] = 1;
                    if(i+1 != H)
                    {
                        if(temp_Matrix[j][i+1] == 0 && temp_Matrix[j-1][i+1] == 0)//아래 왼
                        {
                            if(j != 0)
                            {
                                temp_Matrix[j][i+1] = 1;
                                temp_Matrix[j-1][i+1] = 1;
                                Cover((int*)temp_Matrix, H, W);
                                temp_Matrix[j][i+1] = 0;
                                temp_Matrix[j-1][i+1] = 0;
                                check++;
                            }
                           
                        }
                        if(temp_Matrix[j][i+1] == 0 && temp_Matrix[j+1][i+1] == 0)//아래 왼
                        {
                            if(j != W-1)
                            {
                                temp_Matrix[j][i+1] = 1;
                                temp_Matrix[j+1][i+1] = 1;
                                Cover((int*)temp_Matrix, H, W);
                                temp_Matrix[j][i+1] = 0;
                                temp_Matrix[j+1][i+1] = 0;
                                check++;
                            }
                            
                        }
                        if(temp_Matrix[j][i+1] == 0 && temp_Matrix[j-1][i] == 0)//좌 아래
                        {
                            if(j != 0)
                            {
                                temp_Matrix[j][i+1] = 1;
                                temp_Matrix[j-1][i] = 1;
                                Cover((int*)temp_Matrix, H, W);
                                temp_Matrix[j][i+1] = 0;
                                temp_Matrix[j-1][i] = 0;
                                check++;
                            }
                        }

                        if(temp_Matrix[j][i+1] == 0 && temp_Matrix[j+1][i] == 0)//우 아래
                        {
                            if(j != W-1)
                            {
                                temp_Matrix[j][i+1] = 1;
                                temp_Matrix[j+1][i] = 1;
                                Cover((int*)temp_Matrix, H, W);
                                temp_Matrix[j][i+1] = 0;
                                temp_Matrix[j+1][i] = 0;
                                check++;
                            }
                        }
                    }

                    if(check == 0)
                    {
                        return;
                    }
                }  
            }
        }

        
    }


    
}