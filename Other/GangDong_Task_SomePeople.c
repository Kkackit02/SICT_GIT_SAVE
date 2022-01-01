#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int getxy(char map[10][10], int xy[2]);
void printmap(char map[10][10]);
void movemonster(char map[10][10]);

int main(void) {
    char map[10][10] = {
        '.','.','.','.','.','.','.','.','.','.'
        ,'.','#','.','.','.','.','.','.','.','.'
        ,'.','.','.','.','.','.','.','.','.','.'
        ,'.','.','.','.','.','.','.','.','.','.'
        ,'.','.','.','.','.','.','.','.','.','.'
        ,'.','.','.','.','.','M','.','.','.','.'
        ,'.','.','.','.','.','.','.','M','.','.'
        ,'.','.','.','.','.','.','.','.','.','.'
        ,'.','.','.','.','.','.','.','.','.','.'
        ,'.','.','.','.','.','.','.','.','.','G'
    };

    srand(time(NULL));
    char c;
    int xy[2]; //xy[0] x, xy[1] y
    int movedFlag = 1;
    while (1)
    {
        

        if(movedFlag == 0)
        {
            movedFlag = 1;
            movemonster(map);
        }


        system("clear");
        printmap(map);
        getxy(map, xy);
        c = getchar();
        getchar(); //엔터 버퍼에서 빼기


        if (c == 'a')
        {
            if (map[xy[1]][xy[0] - 1] == 'G')
            {
                map[xy[1]][xy[0] - 1] == '#';
                break; // 게임 종료
            }

            else if (map[xy[1]][xy[0] - 1] != 'M')
            {
                movedFlag = 0;
                map[xy[1]][xy[0] - 1] = '#';
                map[xy[1]][xy[0]] = '.';
            }
            
        }
        else if (c == 'w')
        {
            if (map[xy[1] - 1][xy[0]] == 'G')
            {
                map[xy[1] - 1][xy[0]] = '#';
                break; // 게임 종료
            }

            else if (map[xy[1] - 1][xy[0]] != 'M')
            {
                movedFlag = 0;
                map[xy[1] - 1][xy[0]] = '#';
                map[xy[1]][xy[0]] = '.';
            }
            
        }
        else if (c == 's')
        {
            if (map[xy[1] + 1][xy[0]] == 'G')
            {
                map[xy[1] + 1][xy[0]] == '#';
                break; // 게임 종료
            }

            else if (map[xy[1] + 1][xy[0]] != 'M')
            {
                movedFlag = 0;
                map[xy[1] + 1][xy[0]] = '#';
                map[xy[1]][xy[0]] = '.';
            }
            
        }
        else if (c == 'd')
        {
            if (map[xy[1]][xy[0] + 1] == 'G')
            {
                map[xy[1]][xy[0] + 1] == '#';
                break; // 게임 종료
            }

            else if (map[xy[1]][xy[0] + 1] != 'M')
            {
                movedFlag = 0;
                map[xy[1]][xy[0] + 1] = '#';
                map[xy[1]][xy[0]] = '.';
            }
            
        }
        else if (c == 'b')
        {
            break;
        }
            
        
        
    }
    
    printmap(map);
    printf("게임이 종료 되었습니다.");
}
int getxy(char map[10][10], int xy[2])
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (map[i][j] == '#')
            {
                xy[0] = j;
                xy[1] = i;
            }
        }
    }
    return 0;
}

void printmap(char map[10][10]) {
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
            printf("%c", map[i][j]);
        printf("\n");
    }
    printf("\n");
}

void movemonster(char map[10][10])
{
    int dir;
    int M1xy[2];
    int M2xy[2];
    int count = 0;

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if(map[i][j] == 'M')
            {
                if(count == 0)
                {
                    M1xy[1] = i;
                    M1xy[0] = j;
                    count++;
                }
                else if(count == 1)
                {
                    M2xy[1] = i;
                    M2xy[0] = j;
                }
            }
        }
    }

    
    while(1) //M1 이동
    {
        dir = rand() % 4; // 0 - up, 1 - down, 2 - left, 3 - right

        if(dir == 0)
        {
            if(M1xy[1]-1 < 10 && M1xy[1]-1 >= 0)
            {
                if(map[M1xy[1]-1][M1xy[0]] == '.')
                {
                    map[M1xy[1]-1][M1xy[0]] = 'M'; 
                    map[M1xy[1]][M1xy[0]] = '.';
                    break;
                }
                else
                {
                    continue;
                }
            }
            else
            {
                continue;
            }     
        }      
        else if(dir == 1)
        {
            if(M1xy[1]+1 < 10 && M1xy[1]+1 >= 0)
            {
                if(map[M1xy[1]+1][M1xy[0]] == '.')
                {
                    map[M1xy[1] + 1][M1xy[0]] = 'M'; 
                    map[M1xy[1]][M1xy[0]] = '.';
                    break;
                }
                else
                {
                    continue;
                }
            }
            else
            {
                continue;
            }    
        }    
        else if(dir == 2)
        {
            if(M1xy[0]-1 < 10 && M1xy[0]-1 >= 0)
            {
                if(map[M1xy[1]][M1xy[0]-1] == '.')
                {
                    map[M1xy[1]][M1xy[0]-1] = 'M'; 
                    map[M1xy[1]][M1xy[0]] = '.';
                    break;
                }
                else
                {
                    continue;
                }
            }
            else
            {
                continue;
            }         
        }        
        else if(dir == 3)
        {
            if(M1xy[0]+1 < 10 && M1xy[0]+1 >= 0)
            {
                if(map[M1xy[1]][M1xy[0]+1] == '.')
                {
                    map[M1xy[1]][M1xy[0]+1] = 'M'; 
                    map[M1xy[1]][M1xy[0]] = '.';
                    break;
                }
                else
                {
                    continue;
                }
            }
            else
            {
                continue;
            }         
        }        
    }      

    int debug= 0;

    while(1) //M2 이동
    {
        dir = rand() % 4;

        debug++;
        if(debug >= 10)
        {
            break;
        }

        if(dir == 0)
        {
            if(M2xy[1]-1 < 10 && M2xy[1]-1 >= 0)
            {
                if(map[M2xy[1]-1][M2xy[0]] == '.')
                {
                    map[M2xy[1]-1][M2xy[0]] = 'M'; 
                    map[M2xy[1]][M2xy[0]] = '.';
                    break;
                }
                else
                {
                    continue;
                }
            }
            else
            {
                continue;
            }     
        }      
        else if(dir == 1)
        {
            if(M2xy[1]+1 < 10 && M2xy[1]+1 >= 0)
            {
                if(map[M2xy[1]+1][M2xy[0]] == '.')
                {
                    map[M2xy[1] + 1][M2xy[0]] = 'M'; 
                    map[M2xy[1]][M2xy[0]] = '.';
                    break;
                }
                else
                {
                    continue;
                }
            }
            else
            {
                continue;
            }    
        }    
        else if(dir == 2)
        {
            if(M2xy[0]-1 < 10 && M2xy[0]-1 >= 0)
            {
                if(map[M2xy[1]][M2xy[0]-1] == '.')
                {
                    map[M2xy[1]][M2xy[0]-1] = 'M'; 
                    map[M2xy[1]][M2xy[0]] = '.';
                    break;
                }
                else
                {
                    continue;
                }
            }
            else
            {
                continue;
            }         
        }        
        else if(dir == 3)
        {
            if(M2xy[0]+1 < 10 && M2xy[0]+1 >= 0)
            {
                if(map[M2xy[1]][M2xy[0]+1] == '.')
                {
                    map[M2xy[1]][M2xy[0]+1] = 'M'; 
                    map[M2xy[1]][M2xy[0]] = '.';
                    break;
                }
                else
                {
                    continue;
                }
            }
            else
            {
                continue;
            }         
        }        
        
    }       
    
    
    
}