/*
 *이름 : 정근녕
 *학번 : 202112346
 *프로그램 작성일 : 2021-06-16
 *프로그램 설명 : 기말고사 문제 2입니다.
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

typedef struct inventory // 구조체 선언
{
    char* name; //이름
    int quantity; // 수량
    double price; // 가격
    struct inventory *next_inventory; // 다음 재고
}invent;

invent *makeInventory();
void printData(invent* one);
void input_Char();

int main(void)
{
    invent* one;
    invent* two;
    invent* three;
    invent* temp_invent;
    one = malloc (sizeof(invent));
    two = malloc (sizeof(invent));
    three = malloc (sizeof(invent));

    one->next_inventory = two;
    two->next_inventory = three;

    temp_invent = one;
    
    for (int i = 0; i < 3; i++)
    {
        switch (i)
        {
        case 0:
            printf("첫 번째 재고의 정보를 입력하시오.\n");
            break;
        case 1:
            printf("두 번째 재고의 정보를 입력하시오.\n");
            break;
        case 2:
            printf("세 번째 재고의 정보를 입력하시오.\n");
            break;      
        default:
            break;
        }

        printf("이름: ");
        input_Char(temp_invent);
        printf("수량: ");
        scanf("%d", &temp_invent->quantity);
        printf("가격: ");
        scanf("%lf", &temp_invent->price);
        if(i != 2)
        {
            printf("----------\n");
        }
        temp_invent = temp_invent->next_inventory;
        while(getchar() != '\n')
        {
            
        }
    }
    
    printData(one);
}



void printData(invent* one)
{
    invent* temp;
    temp = one;
    invent* forFree;
    printf("\n현재 재고는 다음과 같습니다\n");
    printf("%s %d %d\n", temp->name, temp->quantity, (int)temp->price);
    while (1)
    {
        if(temp->next_inventory != NULL)
        {
            forFree = temp;
            temp = temp->next_inventory;
            free(forFree);
            printf("%s %d %d\n", temp->name, temp->quantity, (int)temp->price);
        }
        else
        {
            break;
        }
    }
}

void input_Char(invent* temp_invent)
{
    char *temp_char_p = NULL;
    char temp_char;
    int count = 0;

    while((temp_char = getchar()) != '\n')
    {
        temp_invent->name = (char*) realloc(temp_invent->name, sizeof(char)*(count+1) );
        temp_invent->name[count] = temp_char;
        count++;
    }

    temp_invent->name = (char*) realloc(temp_invent->name, sizeof(char)*(count+1) );
    temp_invent->name[count] = '\0';
}