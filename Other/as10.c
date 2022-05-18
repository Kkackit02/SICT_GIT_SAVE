#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct NODE
{
	int data;
	struct NODE* link;
}NODE;

int MAX(NODE*link); //제일 큰 수 계산 하는거 
void deleteMax(NODE*link, int max_n);
int main() 
{
	NODE* head = NULL;
	int num, max_n, sign = 0;
	int num1 = 0, num2 = 0;
	NODE *p;
	char c;

	//입력 꼬인다 ! 개꼬인다! 일단 atoi 에다가 문자열이 아니라 문자 넣으니까 이상하다 
	//segmentation오류 뜬다 
	while((c = getchar()) != ']') // ']'가 들어오면 입력 받는 반복문 안들어가고 종료 
	{
		c = getchar(); // 문자 입력받음 

		if(c == '-')
		{
			sign = 1;
			break;
		}

		if(isdigit(c) != 0) //숫자면 if 문 안에 들어감 
		{
			int num1 = atoi(c); //현재 char형 숫자를 int 형으로 바꿔줌 
			 
			if(num2 == 0) //처음 들어온 숫자면 그대로 저장 
			{
				num2 = num1;
			}
			else // ex) 두자리 수 등을 연이어 저장하기 위함 
			{
				num2 = num2*10 + num1; // 기존에 저장된거 자릿수 올려주고 새로 받은거 더함 
			}


			if(sign == 1)//음수일 때 num에 저장하기 
			{
				num = -num2;
				sign = 0;
			}
			else //양수일 때 저장하기 
			{
				num = num2; 
			}
		}
		else //숫자가 아니라면 새로운 원소 받기 위해 num2 초기화해줌 
		{	
			num2 = 0;
			break;
		}

		p = (NODE*)malloc(sizeof(NODE));
		p->data = num; 
		p->link = NULL;

		if(head == NULL)
		{
			head = p;
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
	
	max_n = MAX(head);
	
	int i = 1;
	NODE *tmp = head;
	p = head;

	for(tmp; tmp!= NULL; tmp = tmp->link)
	{
		printf("step %d. 가장 큰 값: %d 리스트:head", i, max_n);
		p = head;

		deleteMax(head, max_n);
		while(p != NULL)
		{
			printf("->%d ", p->data);
			p = p->link;
		}
		printf("\n");
		i++;
		max_n = MAX(head);
	}	

}

int MAX(NODE*head)
{
	NODE* tmp = head;
	int max_n = tmp -> data;
	for(tmp; tmp != NULL; tmp = tmp->link)
	{
		if(max_n < tmp->data)
		{
			max_n = tmp->data;
		}
	}

	return max_n;
}

void deleteMax(NODE*head, int max_n)
{
	NODE* list = head;
	struct NODE *removeNode = head->link;

	//지금 지우는게 문제,, 
	if(head == NULL) //비어있을 때 
	{
		return;
	}
	else if (head->data == max_n) //최댓값이 첫번째 노드에 해당될 때 
	{
		head = head->link;
		return;
	}
	else
	{
		while (list->link != NULL)
		{
			if(list->link->data == max_n)
			{
				list->link = list->link->link;
				return;
			}
			list = list->link;
		}
	}
}
