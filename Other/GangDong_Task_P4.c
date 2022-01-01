#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void Display_Board(int turn_Flag, int board[9][9]);
void Display_Block(int turn_Flag, int block[3][3]);
void Make_Block(int turnFlag, int block[3][3]);
void Ratate_Block(int block[3][3]);

int Check_isLay(int block[3][3], int board[9][9]);
int Check_canLay(int block[3][3], int board[9][9], int r, int c);
void Put_Block(int block[3][3], int board[9][9], int r, int c);

int main(void)
{
    srand((unsigned int)time(NULL));

    int data_Matrix[9][9];
    int block[3][3];
    int turn_Flag = 2; // 1 = P1, 2 = P2

    int isLay = 0; // false
    int canLay = 0; // false
    int r = -1; 
    int c = -1;

    for (int i = 0; i < 9; i++) //초기화
    {
        for(int j = 0; j < 9; j++)
        {
            data_Matrix[i][j] = 0;
        }
    }

    while(1) // 게임 프로세스 반복
    {
        if(turn_Flag == 1) // 턴 바꾸기
        {
            turn_Flag = 2;
        }
        else if(turn_Flag == 2)
        {
            turn_Flag = 1;
        }
        Make_Block(turn_Flag, block); // 플레이어에 맞는 블록 생성
        
        for(int i = 0; i < 3; i++) // 4번 회전하며 수행 가능여부 검사
        {
            isLay = Check_isLay(block, data_Matrix);

            if(isLay == 1) //만약 가능하면 검사 종료
            {
                break;
            }
            else
            {
                Ratate_Block(block); // 불가능하면 회전한 뒤 다시 검사
            }
        }

        if(isLay == 0) // 끝까지 불가능하면 더 이상 삽입 할 공간이 없으므로 게임 프로세스 종료
        {
            break; //게임 종료
        }
        

        char temp; // 입력용 변수
        int check_Rotate_Input = 0; // 0 = false;

        Display_Board(turn_Flag, data_Matrix);
        while(1) // 플레이어 턴 프로세스
        {
            check_Rotate_Input = 0;
            r = -1;
            c = -1;
            
            printf("\n");
            Display_Block(turn_Flag, block);
            printf("Put your block (r c) or Rotate (0): ");
            while(1) // 입력을 위한 반복
            {
                temp = getchar();
                if(temp == '0')
                {
                    Ratate_Block(block);
                    check_Rotate_Input = 1;
                }
                else if(temp != ' ' && temp != '\n')
                {
                    if(r == -1)
                    {
                        r = temp - '0';
                    }
                    else
                    {
                        c = temp - '0';
                    }
                }
                else if(temp == '\n')
                {
                    break;
                }
            }
            
            // 입력이 끝난 후 받은 값으로 시스템 진행
            if(check_Rotate_Input != 1) //회전이 아닌 다른 명령일때
            {
                canLay = Check_canLay(block, data_Matrix, c-1, r-1);

                if(canLay == 0) // 입력이 불가능하다면
                {
                    printf("P%d is not able to put the block into (%d,%d).\n", turn_Flag,r,c);
                    continue; // 다시 입력받기
                }
                else if(canLay == 1) // 입력이 가능하면
                {
                    Put_Block(block, data_Matrix, c-1, r-1);
                    break; // 입력 종료
                }
            }
            else if(check_Rotate_Input == 1) // 회전했으니 다시 입력받기
            {
                continue;
            }
        }
    }
    
    //게임 종료 후

    Display_Board(turn_Flag, data_Matrix);
    printf("\n");
    Display_Block(turn_Flag, block);
    printf("\n");
    if(turn_Flag == 1)
    {
        printf("P%d fails to put the block. P%d wins!\n", 1, 2);
    }
    else
    {
        printf("P%d fails to put the block. P%d wins!\n", 2, 1);
    }
    

}

void Display_Board(int turn_Flag, int board[9][9])
{
    printf("\n");
    printf("   1 2 3 4 5 6 7 8 9\n");
    printf("   _ _ _ _ _ _ _ _ _\n");
    for (int i = 0; i < 9; i++)
    {
        printf("%d ", i+1);
        for(int j = 0; j < 9; j++)
        {
            printf("|");
            switch (board[i][j])
            {
                case 0:
                    printf("_");
                    break;
                case 1:
                    printf("O");
                    break;
                case 2:
                    printf("@");
                    break;
            }
        }
        printf("|");
        printf("\n");
    }

    
}

void Display_Block(int turn_Flag, int block[3][3])
{
    printf("P%d's block:\n", turn_Flag);

    printf(" _ _ _ \n");
    for(int i = 0; i < 3; i++)
    {
        
        for(int j = 0; j < 3; j++)
        {
            printf("|");
            switch (block[i][j])
            {
                case 0:
                    printf("_");
                    break;
                case 1:
                    printf("O");
                    break;
                case 2:
                    printf("@");
                    break;
            }
            
        }
        printf("|\n");
    }
}



void Make_Block(int turnFlag, int block[3][3])
{

    int block_Id = 0;

    int block_Type = 1; // 1 = 1P, 2 = 2P

    for (int i = 0; i<3; i++)
    {
        for (int j =0; j<3; j++)
        {
            block[i][j] = 0;
        }
    }



    if(turnFlag == 1)
    {
        block_Type = 1;
    }
    else if(turnFlag == 2)
    {
        block_Type = 2;
    }

    block_Id = rand() % 13 + 1;

    switch (block_Id)
    {
    case 1:
        
        block[0][0] = block_Type;
        block[0][1] = block_Type;
        block[0][2] = block_Type;
        break;
    case 2:
        block[0][0] = block_Type;
        block[0][1] = block_Type;
        block[0][2] = block_Type;
        block[1][0] = block_Type;
        break;
    case 3:
        block[0][0] = block_Type;
        block[0][1] = block_Type;
        block[0][2] = block_Type;
        block[1][2] = block_Type;
        break;
    case 4:
        block[0][0] = block_Type;
        block[0][1] = block_Type;
        block[0][2] = block_Type;
        block[1][1] = block_Type;
        break;
    case 5:
        block[0][1] = block_Type;
        block[0][2] = block_Type;
        block[1][0] = block_Type;
        block[1][1] = block_Type;
        break;
    case 6:
        
        block[0][0] = block_Type;
        block[0][1] = block_Type;
        block[1][1] = block_Type;
        block[1][2] = block_Type;
        break;
    case 7:
        block[0][0] = block_Type;
        block[0][1] = block_Type;
        block[1][0] = block_Type;
        block[1][1] = block_Type;
        break;
    case 8:
        block[0][0] = block_Type;
        block[1][0] = block_Type;
        block[1][1] = block_Type;
        block[2][0] = block_Type;
        block[2][1] = block_Type;
        break;
    case 9:
        block[0][1] = block_Type;
        block[0][2] = block_Type;
        block[1][0] = block_Type;
        block[1][1] = block_Type;
        block[2][0] = block_Type;
        break;
    case 10:
        block[0][0] = block_Type;
        block[0][1] = block_Type;
        block[1][1] = block_Type;
        block[1][2] = block_Type;
        block[2][1] = block_Type;
        break;
    case 11:
        block[0][1] = block_Type;
        block[0][2] = block_Type;
        block[1][0] = block_Type;
        block[1][1] = block_Type;
        block[2][1] = block_Type;
        break;
    case 12:
        block[0][2] = block_Type;
        block[1][0] = block_Type;
        block[1][1] = block_Type;
        block[1][2] = block_Type;
        block[2][0] = block_Type;
        break;
    case 13:
        block[0][0] = block_Type;
        block[1][0] = block_Type;
        block[1][1] = block_Type;
        block[1][2] = block_Type;
        block[2][2] = block_Type;
        break;
    case 14:
        block[0][1] = block_Type;
        block[1][0] = block_Type;
        block[1][1] = block_Type;
        block[1][2] = block_Type;
        block[2][1] = block_Type;
        break;
    default:
        printf("블록 생성에 실패했습니다.\n");
        break;
    }
}


void Ratate_Block(int block[3][3])
{
    int temp_block[3][3];

    // 반시계 회전한 배열 만들기
    for(int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            temp_block[3-j-1][i] = block[i][j]; 
        }
    }
    // 원래 배열을 회전한 배열로 교체
    for(int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            block[i][j] = temp_block[i][j]; 
        }
    }

}

void Put_Block(int block[3][3], int board[9][9], int r, int c)
{
    for(int i = 0; i < 3; i++)
    {
        for(int j =0; j < 3; j++)
        {
            if(board[i+r][j+c] == 0) // 이미 값이 존해하는 다른 칸에 현재 플레이어 블록의 빈칸을 삽입하지 않기위한 조건 
            {
                board[i+r][j+c] = block[i][j];
            }
            
        }
    }
}

int Check_isLay(int block[3][3], int board[9][9]) // 공간이 있는지
{
    int isPossible = 1; // true
    int isLay = 0; // false

    for(int i = 0; i < 7; i++)
    {
        for(int j = 0; j < 7; j++)
        {
            isPossible = 1;

            for(int y = 0; y < 3; y++)
            {
                for(int x = 0; x < 3; x++)
                {
                    if(block[y][x] != 0 && board[i+y][j+x] != 0)
                    {
                        isPossible = 0;
                        break;
                    }
                }
                if(isPossible == 0)
                {
                    break;
                }
            }

            if(isPossible == 1)
            {
                isLay = 1;
                return isLay;
            }
            else
            {
                continue; //의미없지만 가독성을 올리기 위해서 넣음
            }
        }
    }
        
    return isLay;
}

int Check_canLay(int block[3][3], int board[9][9], int y, int x)
{
    int canLay = 1; // 0 = false, 1 = true
    for(int i = 0; i < 3; i++)
    {
        for(int j =0; j < 3; j++)
        {
            if(block[i][j] != 0 && board[i+y][j+x] != 0)
            {
                canLay = 0;
                return canLay;
            }
        }
    }

    return canLay;
}

