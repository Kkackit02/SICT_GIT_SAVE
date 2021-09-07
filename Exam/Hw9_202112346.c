/*
이름 : 정근녕
학번 : 202112346
프로그램 작성일 : 2021-06-12
프로그램 설명 : Hw9_202112346 과제 9 입니다.
*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void gugu(int start, int len, int** matrix);
int getInput(int*start_p, int*len_p);
void display(int start, int len, int** matrix);

int main(void)
{
    int len = 0;
	int* len_p = &len;

	int start = 0;
	int* start_p = &start;

	getInput(start_p, len_p);
	int **matrix;

	int j = 0;
	//할당
	matrix = (int**)malloc(sizeof(int*)*(len-start+1)); // 단수 배열 할당

	int range = len - start + 1; //8 10 => 10 - 8 +1 = 3-> 출력해야할 단의 개수

	for(int j = 0; j < range; j++) // 곱 배열 할당
	{
		matrix[j] = (int*)malloc(sizeof(int) * ((start + j) <= 9 ? 9 : start + j)); // 9단까지는 9 곱까지, 9단 초과부터는 단수만큼
	}	
	
    gugu(start, len, matrix);

	for(int j = 0; j < range; j++) // 곱 할당 해제
	{
		free(matrix[j]);
	}	
	free(matrix); // 단 할당 해제


	return 0;
}


int getInput(int*start_p, int*len_p)
{
	int start = 0;
    int len = 0;

	while(1) //범위 입력 받기
    {
		start = 0;
		len = 0;
		
    	printf("단수를 입력하시오: ");
    	scanf("%d %d", &start, &len);

		if(start <= len && ((start >= 1 && start <= 1000) && (len >= 1 && len <= 1000))) // 범위대로 입력받기
		{
			*start_p = start;
			*len_p = len;
			break;
		}	
		else
		{
			printf("잘못 입력했습니다.\n");
			continue;
		}

    }
}


void gugu(int start, int len, int** matrix)   // 값을 계산하고 배열안에 넣는 함수
{
	
	for (int i = 0; i < len - start + 1; i++) // 배열 초기화
    {
		for (int j = 0; j < (i+start-1 < 9 ? 9 : start+i); j++)
		{
			matrix[i][j] = 0;
		}
    }


    for (int i = 0; i < len - start + 1; i++) // 시작 단부터 끝단까지
    {
        for (int j = 0; j < (i+start-1 < 9 ? 9 : start+i); j++)  // 구구단 곱 저장, 10단 이상부터는 단수만큼 저장
		{
			matrix[i][j] = (start + i) * (j + 1); // 단수 * 곱 = 단수 * 곱
			//printf("%d * %d = %d %d : %d\n ",start + i, j + 1 , i, j,  matrix[i][j]);
		}
    }

    display(start, len, matrix);
}
	
void display(int start, int len, int** dis_matrix) //출력 함수
{
	int range = len <= 9 ? 9 : len;
	
    for (int j = 0; j < range; j++) // 곱 출력 $ * x(이부분)
    {	    
	    // 현재 단수
        for (int i= 0; i < len - start + 1; i++)  //단수 출력 x(이부분) * &
        {
			int x = j + 1; // 현재 곱 
			int y = i + start; // 현재 단
	    	int temp = log10(dis_matrix[i][y <= 9 ? 8 : start + i - 1]) + 1; // 최종 결과 자릿수 구하기 -> 모양 이쁘게 만들기 위해서 구하는 것

			if((y < 10 && x < 10) || (y > 9 && x < y + 1)) // 현재 단수가 9단 안이면 9단까지 곱 출력 || 현재 단수가 9단 초과면 그 단수만큼 곱 출력
			{
				switch(temp) // 최종 결과 자릿수에 맞추어 크기 맞추기
				{
					case 1: // 단의 제일 높은 곱의 자릿수가 1
					{
					printf("%1d *%1d =%1d|", i + start, j + 1, dis_matrix[i][j]);
					break;
					}
					case 2:
					{
					printf("%2d *%2d =%2d|", i + start, j + 1, dis_matrix[i][j]);
					break;
					}
					case 3:
					{
					printf("%3d *%3d =%3d|", i + start, j + 1, dis_matrix[i][j]);
					break;
					}
					case 4:
					{
					printf("%3d *%3d =%4d|", i + start, j + 1, dis_matrix[i][j]);
					break;
					}
					case 5:
					{
					printf("%3d *%3d =%5d|", i + start, j + 1, dis_matrix[i][j]);
					break;
					}
					case 6:
					{
					printf("%3d *%3d =%6d|", i + start, j + 1, dis_matrix[i][j]);  
					break;
					} 
					case 7:
					{
					printf("%3d *%4d =%7d|", i + start, j + 1, dis_matrix[i][j]);  
					break;
					}
					dafault:
					{
					printf("%3d *%3d =%8d|", i + start, j + 1, dis_matrix[i][j]);
					break;
					}
				}
	    	}

			else
			{
				switch(temp) // 끝 단을 이쁘게 출력하기 위한 처리
				{
					case 1:
					{
					printf("       |");
					break;
					}
					case 2:
					{
					printf("          |");
					break;
					}
					case 3:
					{
					printf("             |");
					break;
					}
					case 4:
					{
					printf("              |");
					break;
					}
					case 5:
					{
					printf("               |");
					break;
					}
					case 6:
					{
					printf("                |");
					break;
					}
					case 7:
					{
					printf("                 |");
					break;
					}
					default:
					{
					printf("                  |");
					break;
					}
				}
			}
        }
	printf("\n");
    }
}

