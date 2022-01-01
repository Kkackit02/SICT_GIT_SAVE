#include<stdio.h>

void Display_Board(int matrix[6][8], int turnData, int gameFlag);
int Check_End(int matrix[6][8]);
void Input_Num(int* turn_Pointer, int matrix[6][8], int matrix_Floor[8]);
int Check_Draw(int matrix[6][8]);
void Input_Block(int matrix[6][8], int matrix_Floor[8]);


int main(void)
{
    int gameFlag = 0; // 0 = 진행중, 1 = P1 승리, 2 = P2 승리, 3 = 무승부
    int data_Matrix[6][8];

    for (int i = 0; i < 6; i++) // 배열 초기화
    {
        for(int j = 0; j < 8; j++)
        {
            data_Matrix[i][j] = 0;
        }
    }

    int matrix_Floor[8]; //칸에 얼마나 들어있는지 저장

    for (int i = 0; i < 8; i++) // 초기화
    {
        matrix_Floor[i] = 0;
    }

    int turn_Data = 0; // 0 -> player 1 , 1 -> player 2 / 누구의 턴인지 저장
    int* turn_Pointer = &turn_Data;

    Input_Block(data_Matrix, matrix_Floor);
    Display_Board(data_Matrix, turn_Data, gameFlag);
    while (1)
    {
        Input_Num(turn_Pointer, data_Matrix, matrix_Floor);
        
        if(Check_Draw(data_Matrix) == 0)
        {
            if(Check_End(data_Matrix) == 1)
            {
                if(turn_Data == 0) // 1P턴이 왔을때 게임이 끝났으므로 2P 승리
                {
                    gameFlag = 2;
                }
                else if(turn_Data == 1) //2P턴이 왔을때 게임이 끝났으므로 1P 승리
                {
                    gameFlag = 1;
                }
                Display_Board(data_Matrix, turn_Data, gameFlag);
                break;
            }
            else
            {
                //게임을 계속해서 진행
            }
        }
        else if(Check_Draw(data_Matrix) == 1)
        {
            {
                gameFlag = 3;
                Display_Board(data_Matrix, turn_Data, gameFlag);
                break;
            }
        }
        Display_Board(data_Matrix, turn_Data, gameFlag);
    }
    
}

void Display_Board(int matrix[6][8], int turn_Data, int gameFlag) // 화면 출력
{
    printf("  1   2   3   4   5   6   7   8  \n");
    for (int i = 5; i >= 0; i--)
    {
        printf("|");
        for(int j = 0; j < 8; j++)
        {
            if(matrix[i][j] == 0)
            {
                printf("___|");
            }
            else if(matrix[i][j] == 1)
            {
                printf("_O_|");
            }
            else if(matrix[i][j] == 2)
            {
                printf("_@_|");
            }
            else if(matrix[i][j] == 3)
            {
                printf("_X_|");
            }
        }
        printf("\n");
    }
    
    if(gameFlag == 0)
    {
        printf("P1's marker is O, P2's marker is @\n");
        printf("P%d's turn, Enter the column number: ", turn_Data+1);
    }
    else if(gameFlag == 1)
    {
        printf("P1 wins!\n");
    }
    else if(gameFlag == 2)
    {
        printf("P2 wins!\n");
    }
    else if(gameFlag == 3)
    {
        printf("Game ended in a draw.\n");
    }
}


int Check_End(int matrix[6][8])
{
    int combo = 0; //1이면 끝
    int player_Tag= 0;

    int isEnd = 0;


    //가로 검사
    for (int i = 0; i < 6; i++)
    {
        combo = 0;
        for(int j = 0; j < 8; j++)
        {
            if(matrix[i][j] == 1) // P1 마커 검사
            {
                if(player_Tag == 1)
                {
                    player_Tag = 1;
                    combo++;
                    if(combo == 4) //4연속으로 나올 시
                    {
                        isEnd = 1;
                        return isEnd;
                    }
                }
                else if(player_Tag == 2) // 다른 마커가 나오면.
                {
                    player_Tag = 1;
                    combo = 1;
                }
                else // 태그가 없을 때(0) 지정
                {
                    player_Tag = 1;
                    combo = 1;
                }
            }
            else if(matrix[i][j] == 2) // P2 마커 검사
            {
                if(player_Tag == 2)
                {
                    player_Tag = 2;
                    combo++;
                    if(combo == 4) //4연속으로 나올 시
                    {
                        isEnd = 1;
                        return isEnd;
                    }
                }
                else if(player_Tag == 1) // 다른 마커가 나오면.
                {
                    player_Tag = 2;
                    combo = 1;
                }
                else //태그가 없을 때(0) 지정
                {
                    player_Tag = 2;
                    combo = 1;
                }
            }
            else
            {
                combo = 0;
            }
        }
    }

    
    combo = 0;
    //세로 검사 (가로 검사와 같은 검사 구조)
    for (int j = 0; j < 8; j++)
    {
        combo = 0;
        for(int i = 0; i < 6; i++)
        {
            if(matrix[i][j] == 1) // P1 마커 검사
            {
                if(player_Tag == 1)
                {
                    player_Tag = 1;
                    combo++;
                    if(combo == 4) //4연속으로 나올 시
                    {
                        isEnd = 1;
                        return isEnd;
                    }
                }
                else if(player_Tag == 2) //다른 마커가 나오면
                {
                    player_Tag = 1;
                    combo = 1;
                }
                else
                {
                    player_Tag = 1;
                    combo = 1;
                }
            }
            else if(matrix[i][j] == 2) // P2 마커 검사
            {
                if(player_Tag == 2)
                {
                    player_Tag = 2;
                    combo++;
                    if(combo == 4) //4연속으로 나올 시
                    {
                        isEnd = 1;
                        return isEnd;
                    }
                }
                else if(player_Tag == 1) //다른 마커가 나오면
                {
                    player_Tag = 2;
                    combo = 1;
                }
                else //태그가 없을 때(0)
                {
                    player_Tag = 2;
                    combo = 1;
                }
            }
            else
            {
                combo = 0;
            }
        }
    }

    
    //우하향대각선 검사 (검사는 위와 같은 구조)
    combo = 0;
    int now_X = 5;
    int now_Y = 0;

    int temp_X = now_X;
    int temp_Y = now_Y;

    int matrix_Helper = 0; //대각선 알고리즘을 위한 변수

    while(1) //줄 변경
    {
        int temp_X = now_X;
        int temp_Y = now_Y;

        while(1) //검사
        {
            if(matrix[temp_X][temp_Y] == 1)
            {
                if(player_Tag == 1)
                {
                    player_Tag = 1;
                    combo++;
                    if(combo == 4)
                    {
                        isEnd = 1;
                        return isEnd;
                    }
                }
                else if(player_Tag == 2)
                {
                    player_Tag = 1;
                    combo = 1;
                }
                else
                {
                    player_Tag = 1;
                    combo = 1;
                }
            }
            else if(matrix[temp_X][temp_Y] == 2)
            {
                if(player_Tag == 2)
                {
                    player_Tag = 2;
                    combo++;
                    if(combo == 4)
                    {
                        isEnd = 1;
                        return isEnd;
                    }
                }
                else if(player_Tag == 1)
                {
                    player_Tag = 2;
                    combo = 1;
                }
                else
                {
                    player_Tag = 2;
                    combo = 1;
                }
            }
            else
            {
                combo = 0;
            }

            if(temp_X == 5 || temp_Y == 7)
            {
                break;
            }  
            else
            {
                temp_X++;
                temp_Y++;
            }  
        }
        if(now_X != 0 & matrix_Helper == 0)
        {
            now_X--;
            now_Y = 0;
        }
        else
        {
            matrix_Helper = 1;
            now_X = 0;
            now_Y++;

            if(now_X == 0 && now_Y == 7)
            {
                break;
            }  
        }
    }

    
    //우상향대각선 검사(검사는 위와 같은 구조)
    combo = 0;
    now_X = 0;
    now_Y = 0;

    temp_X = now_X;
    temp_Y = now_Y;

    matrix_Helper = 0; //대각선 알고리즘을 위한 변수

    while(1) //줄 변경
    {
        int temp_X = now_X;
        int temp_Y = now_Y;

        while(1) //줄 검사
        {
            if(matrix[temp_X][temp_Y] == 1)
            {
                if(player_Tag == 1)
                {
                    player_Tag = 1;
                    combo++;
                    if(combo == 4)
                    {
                        isEnd = 1;
                        return isEnd;
                    }
                }
                else if(player_Tag == 2)
                {
                    player_Tag = 1;
                    combo = 1;
                }
                else
                {
                    player_Tag = 1;
                    combo = 1;
                }
            }
            else if(matrix[temp_X][temp_Y] == 2)
            {
                if(player_Tag == 2)
                {
                    player_Tag = 2;
                    combo++;
                    if(combo == 4)
                    {
                        isEnd = 1;
                        return isEnd;
                    }
                }
                else if(player_Tag == 1)
                {
                    player_Tag = 2;
                    combo = 1;
                }
                else
                {
                    player_Tag = 2;
                    combo = 1;
                }
            }
            else
            {
                combo = 0;
            }

            if(temp_X == 0 || temp_Y == 5)
            {
                break;
            }  
            else
            {
                temp_X--;
                temp_Y++;
            }  
        }
        if(now_X != 5 & matrix_Helper == 0)
        {
            now_X++;
            now_Y =0;
        }
        else
        {
            matrix_Helper = 1;
            now_Y++;
            now_X = 5;
            if(now_X == 5 && now_Y == 7)
            {
                break;
            }  
        }

        
    }
    
    return 0;
    
    }

int Check_Draw(int matrix[6][8])
{
    int player_1_matrix[6][8];
    int player_2_matrix[6][8];

    for (int i = 0; i < 6; i++) // 배열 복사
    {
        for(int j = 0; j < 8; j++)
        {
            player_1_matrix[i][j] = matrix[i][j];
            player_2_matrix[i][j] = matrix[i][j];
        }
    }

    for (int i = 0; i < 6; i++) // 빈 칸을 모두 각 플레이어 마커로 채우기.
    {
        for(int j = 0; j < 8; j++)
        {
            if(player_1_matrix[i][j] == 0) // 빈칸을 모두 O로
            {
                player_1_matrix[i][j] = 1;
            }

            if(player_2_matrix[i][j] == 0) // 빈칸을 모두 @로
            {
                player_2_matrix[i][j] = 2;
            }
        }
    }
    if(Check_End(player_1_matrix) == 1 || Check_End(player_2_matrix) == 1) // 둘 중 하나라도 성공하면
    {
        printf("\n");
        return 0; // 계속 게임 진행
    }
    else // 둘 다 성공이 불가능하면
    {
        printf("\n");
        return 1; // 무승부
    }
    
    
}

void Input_Num(int* turn_Pointer, int matrix[6][8], int matrix_Floor[8])
{
    int temp = 0;
    scanf("%d", &temp);
    temp--;
    matrix[matrix_Floor[temp]][temp] = *turn_Pointer == 0 ? 1 : 2; // P1의 차례인지 아닌지로 1(P1), 2(P2) 저장
    matrix_Floor[temp]++;

    //*turn_Pointer -> turn_Data (0 = P1, 1 = P2)
    if(*turn_Pointer == 0)
    {
        *turn_Pointer = 1; // P1의 턴이었다면 P2의 턴으로
    }
    else
    {
        *turn_Pointer = 0; // P2의 턴이었다면 P1의 턴으로
    }

}

void Input_Block(int matrix[6][8], int matrix_Floor[8])
{
    
    while(1)
    {
        printf("For initialization, add block: ");
        int temp = 0;
        scanf("%d", &temp);
        
        if(temp == 0)
        {
            printf("Game started\n\n");
            break;
        }

        temp--;
        matrix[matrix_Floor[temp]][temp] = 3; // 0 = 빈칸, 1 = P1, 2 = P2, 3 = Block
        matrix_Floor[temp]++;
    }
}