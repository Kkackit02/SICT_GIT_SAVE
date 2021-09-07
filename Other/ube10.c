#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct NODE // 리스트 노드를 위한 구조체 선언
{
	int data;
	struct NODE* link;
}NODE;


int MAX(NODE*link); //제일 큰 수 계산 하는 함수 
void deleteMax(NODE*link, int max_n); // 노드를 지우는 함수
void Generation_Node(int num, NODE* head);
void cal(NODE* head);
int main() 
{
	NODE* head = (NODE*)malloc(sizeof(NODE)); // 헤드 포인터 선언
	int num, max_n, sign = 0, test = 0; //num = 가공된 원소 하나 , max_n = 리스트의 최대값, sign = 음수 체크 , test = 원소 하나 마무리
	int num1 = 0, num2 = 0; // num 1은 임시로 받은 숫자 넣는 곳 // num2 는 아마 최종값으로 가기 위해 num1 을 가공한 뒤 넣는 변수
	NODE *p; //
	char c; // 임시 입력값

	//입력 꼬인다 ! 개꼬인다! 일단 atoi 에다가 문자열이 아니라 문자 넣으니까 이상하다 
	//segmentation오류 뜬다 
	while(1) // ']'가 들어오면 입력 받는 반복문 안들어가고 종료 
	{
		c = getchar(); // 문자 하나 입력 받음
		if(c == '-')
		{
			sign = 1;
			continue;
		}

		if(isdigit(c) != 0) //숫자면 if 문 안에 들어감 
		{
            test = 1;
			int num1 = c - '0'; //현재 char형 숫자를 int 형으로 바꿔줌 (형변환)
			 
			if(num2 == 0) //처음 들어온 숫자면 그대로 저장 
			{
				num2 = num1;
			}
			else // ex) 두자리 수 등을 연이어 저장하기 위함 
			{
				num2 = num2 * 10 + num1; // 기존에 저장된거 자릿수 올려주고 새로 받은거 더함 
			}

		}
		else //숫자가 아니라면 새로운 원소 받기 위해 num2 초기화해줌 
		{	
            if(sign == 1)//음수일 때 num에 저장하기 
			{
				num = -num2;
				sign = 0;
			}
			else //양수일 때 저장하기 
			{
				num = num2;
			}

            if(test == 1)
            {
                printf("%d\n", num);
                Generation_Node(num, head);
            }
            
            test = 0;
			num2 = 0;
		}

        if(c == ']')
        {
            break;
        }
    }
    // 여기까지 입력과 연결 리스트 생성

    cal(head);


}

void Generation_Node(int num, NODE* head)
{
	NODE* p = (NODE*)malloc(sizeof(NODE)); //생성한 노드의 틀
	p->data = num; 
	p->link = NULL;

	if(head->link == NULL) // 맨 처음
	{
		head->link = p;
	}
	else
	{
		NODE *tmp = head;
		while(tmp->link != NULL)
		{
			tmp = tmp -> link;
		}
		tmp->link = p;
	}
}


void cal(NODE* head)
{
	int max_n = MAX(head);
	int i = 1; // step idx
	NODE *tmp = head; // 가리키는 포인터
	NODE *p = head; //

	while(head->link != NULL)
	{
		printf("step %d. 가장 큰 값: %d 리스트:", i, max_n);
		deleteMax(head, max_n);
        //printf("여기까진 되어요\n");
        
        if(head->link != NULL)
        {
            p = head->link;
            printf(" head -> %d ", p->data);
        }
        else
        {
            printf(" 비어있습니다.\n");
            break;
        }
        

        //printf("\n 최대값은 %d \n", max_n);
        while(1)
		{
            if(p->link != NULL)
            {
                p = p->link;
                printf("-> %d ", p->data);
            }
            else
            {
                break;
            }
		}

		printf("\n");
		i++;
        
        max_n = MAX(head);
    }
	
}




int MAX(NODE*head)
{
	NODE* tmp = head->link;
	int max_n = tmp -> data; // 첫번째 껄 넣고
    
    while(1)
    {
        
        if(max_n < tmp->data) //최대값보다 큰 값이 나오면
		{
			max_n = tmp->data; //
		}
        
        if(tmp->link != NULL)
        {
            tmp = tmp->link;
        }
        else
        {
            
            if(max_n < tmp->data) //최대값보다 큰 값이 나오면
		    {
			    max_n = tmp->data; //
		    }
            
            break;
        }
    }
    return max_n;
    /*
	for(tmp; tmp->link != NULL; tmp = tmp->link) // 전체를 순회하면서
	{
		
	}
    
    */ 
   //[5,4,        87, -6, 12         , 0,  -21 , 47]
	
}

void deleteMax(NODE*head, int max_n)
{
	NODE* before_node = head; //연결리스트
    NODE* now_node = before_node->link;

	//지금 지우는게 문제,, 
	if(head->link == NULL) //비어있을 때 
	{
		return; // 끝 아무 것도 안함
	}

	while(1) // 끝까지 순회
	{
		if(now_node->data == max_n)
		{
            if(now_node->link == NULL)
            {
                before_node->link = NULL;
                //printf(" \n 현재 : %d 다음 : %d \n", before_node->data, now_node->data);
                free(now_node);
                break;
            }
            else
            {
                
                before_node->link = now_node->link;
                //printf(" \n 현재 : %d 다음 : %d \n", before_node->data, now_node->data);
                free(now_node);
			    break;
            }
		}

        if(now_node->link == NULL)
        {
            break;
        }
		before_node = before_node->link;
        now_node = before_node->link;


	}
}
