/*
 *이름 : 정근녕
 *학번 : 202112346
 *프로그램 작성일 : 2021-06-16
 *프로그램 설명 : 기말고사 문제 1입니다.
 */


#include<stdio.h>
#include<stdlib.h>

typedef struct _node // 구조체 선언
{
    int data; // 노드 데이터
    struct _node *pointer; // 다음 노드의 주소
}Node;

Node* MakeNode(int value, Node* head, Node* backnode);
void DisplayNode(Node* head, int input_express_num);
int main(void)
{
    Node* head; // 헤드 선언
    Node* backNode; //생성에 사용할 노드 선언 
    head = (Node*)malloc(sizeof(Node)); // 헤드 동적할당

    int input_origin_num = 0; // 사용자 입력 값
    int input_express_num = 0; // 화면에 나타내고자 하는 숫자
    
    int four_number = 0; // 천의자리
    int three_number = 0; // 백의자리
    int two_number = 0;
    int first_number = 0;


    //입력 받기
    printf("4자리 숫자를 입력하시오: "); 
    scanf("%d", &input_origin_num);

    if(input_origin_num < 10000 && input_origin_num > 0)
    {
        printf("화면에 나타내고자 하는 숫자를 입력하시오: ");
        scanf("%d", &input_express_num); // 화면에 나타내고자 하는 숫자 입력 받기

        four_number = input_origin_num / 1000; //천의 자리 수 추출
        three_number = ((input_origin_num % 1000)/100); //백의 자리 수 추출
        two_number = ((input_origin_num % 100)/10); // 십의 자리 수 추출
        first_number = (input_origin_num % 10);  // 일의 자리 수 추출

        backNode = MakeNode(four_number, head, head); // 첫 번째 노드 생성(천의 자리)
        backNode = MakeNode(three_number, head, backNode); // 두 번째 노드 생성(백의 자리)
        backNode = MakeNode(two_number, head, backNode); //세 번째 노드 생성(십의 자리)
        backNode = MakeNode(first_number, head, backNode); //네 번째 노드 생성(일의 자리)

        printf("결과: ");
        DisplayNode(head, input_express_num); // 계산 및 출력
        
    }
    else
    {
        printf("잘못 입력하셨습니다.\n"); 
    }
   
    return 0;
}

Node* MakeNode(int value, Node* head, Node* backnode) // 노드 생성 및 데이터 저장 함수
{
    Node* Now_Node;
    Now_Node = (Node*)malloc(sizeof(Node)); // 노드 메모리 동적 할당
    Now_Node -> data = value; //노드에 값 저장
    Now_Node->pointer = NULL; //다음 노드의 주소를 비워두기

    if(head->pointer == NULL) //헤드의 다음 노드 주소가 비워져있다면
    {
        head->pointer = Now_Node; //헤드의 다음 노드 주소를 지금 생성한 노드로 채우기
    }
    else
    {
        backnode->pointer = Now_Node; //이전 노드의 다음을 지금 생성한 노드로 채우기
    }

    return Now_Node; //함수에서 생성한 노드를 다음 노드 생성에 전달하기 위해서 반환
}

void DisplayNode(Node* head, int input_express_num) // 계산 및 값을 출력하는 함수
{
    
    Node* Now_Node = head->pointer; //출력을 위한 노드 생성
    int count = 0; //몇 번째인지 출력하기 위한 노드
    while (Now_Node != NULL) // 포인터가 NULL가 될때까지 반복(리스트의 끝까지 가기)
    {
        if(Now_Node->data == input_express_num) // 만약 현재 노드(X의 자리)가 표현하려는 수와 일치하는지 검사
        {
            printf("%d ", count);
        }
        else
        {
            printf("- ");
        }
        Now_Node = Now_Node->pointer; //출력이 끝났으니 다음 노드로 이동
        count++; 
    }
    printf("\n");
}