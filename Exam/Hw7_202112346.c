/* 이름 : 정근녕
 * 학번 : 202112346
 * 프로그램 작성일 : 2021-04-18
 * 프로그램 설명 : 과제 7 입니다.
 */
#include<stdio.h>
#include<math.h>

void gugu(int start, int len, int matrix[len][len]);

void display(int start, int len, int matrix[len][len]);

int main(void)
{
    int start = 0;
    int len = 0;

    while(1) //범위 입력 받기
    {


	start = 0;
	len = 0;
    	printf("단수를 입력하시오: ");
    	scanf("%d %d", &start, &len);

	if(start <= len && ((start >= 1 && start <= 1000) && (len >= 1 && len <= 1000)))
	{
	    break;
	}	
	else
	{
	    printf("잘못 입력했습니다.\n");
	    continue;
	}

    }

    int matrix[len+1][(len < 10 ? 10 : len + 1)]; //배열 선언



    gugu(start, len, matrix);

}

void gugu(int start, int len, int matrix[][len < 10 ? 10 : len + 1])   // 값을 배열안에 넣는 함수
{


    for (int i = start; i < len + 1; i++) // 배열 초기화
    {
	for (int j = 1; j < (i < 10 ? 10 : i+1); j++)
	{
		matrix[i][j] = 0;

	}

    }


    for (int i = start; i < len + 1; i++) // 시작 단부터 끝단까지
    {
        for (int j = 1; j < (i < 10 ? 10 : i+1); j++) // 구구단 곱 저장, 10단 이상부터는 단수만큼 저장
	{
	    if(i < 10 &&  (j > 9)) // 현재 곱들이 단수보다 크면 그리고 단수가 9보다 크다면
	    {
	        break;
	    }

	    matrix[i][j] = i * j; // 단수 * 곱 = 단수 * 곱

	    
	}
    }


    display(start, len, matrix);
}
	
void display(int start, int len, int dis_matrix[][len < 10 ? 10 : len + 1]) //출력 함수
{
    int flag = 0;

    if(len < 10) // 최소 9까지는 곱하게 해주는 부분
    {
	flag = 10;
    }

    else
    {
	flag = len + 1;
    }
    

    for (int j = 1; j < flag; j++)  // 곱 출력
    {
	
	    
	    // 현재 단수
        for (int i = start; i < len + 1; i++) 
        {
	    int temp = log10(dis_matrix[i][i<10 ? 9 : i]) + 1; // 최종 결과 자릿수 구하기 -> 모양 이쁘게 만들기 위해서 구하는 것

	    if((i < 10 && j < 10) || (i > 9 && j < i + 1))
	    {
		
		switch(temp) // 최종 결과 자릿수에 맞추어 크기 맞추기
		{
		    case 1:
		    {
			printf("%1d *%1d =%1d|", i, j, dis_matrix[i][j]);
			break;
		    }
		    case 2:
		    {
			printf("%2d *%2d =%2d|", i, j, dis_matrix[i][j]);
			break;
		    }
		    case 3:
		    {
			printf("%3d *%3d =%3d|", i, j, dis_matrix[i][j]);
			break;
		    }
		    case 4:
		    {
			printf("%3d *%3d =%4d|", i, j, dis_matrix[i][j]);
			break;
		    }
		    case 5:
		    {
			printf("%3d *%3d =%5d|", i, j, dis_matrix[i][j]);
			break;
		    }
		    case 6:
		    {
			printf("%3d *%3d =%6d|", i, j, dis_matrix[i][j]);  
			break;
		    } 
		    case 7:
		    {
			printf("%3d *%4d =%7d|", i, j, dis_matrix[i][j]);  
			break;
		    }
		    dafault:
		    {
			printf("%3d *%3d =%8d|", i, j, dis_matrix[i][j]);
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

