/*
이름 : 정근녕
학번 : 202112346
프로그램 작성일 : 2021-06-12
프로그램 설명 : Hw10_202112346 과제 10 입니다.
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

typedef struct _node // 구조체 선언
{
    int data; // 노드 데이터
    struct _node *pointer; // 다음 노드의 주소
}Node;

void DisplayNode(int step, int value, Node* head);
int Input(Node* head);
Node* MakeNode(int value, Node* head, Node* backnode);
void SeekNode(int step, Node* head);
void DeleteNode(int index, Node* head);


int main(void)
{
    Node* head; // 헤드 선언
    head = (Node*)malloc(sizeof(Node)); // 헤드에 메모리 할당(동적)

    int amount = 0; //총 리스트의 개수

    printf("정수 값들을 입력하시오. : ");
    amount = Input(head); //입력값 받기 return 리스트 개수

    printf("\n");
    for (int i=0; i< amount; i++) // 리스트 개수만큼 반복
    {
        SeekNode(i+1, head); // 리스트에서 큰 수를 찾아서 출력하고 삭제(내부에 함수가 존재)
    }
    printf("\n");
}

int Input(Node* head) // 입력 값 받기
{

    char data; // 입력 받은 문자
    int combo = 0; // 입력에서 숫자가 얼마나 연속되는지 저장하는 변수 (1의 자리는 1, 10의 자리는 2, 100의 자리는 3 .....)
    int temp = 0; //정수로 변환한 문자를 저장하는 변수
    int amount = 0; //연결 리스트의 길이
    int minus_check = 0; // 음수를 구하기 위한 검사 변수
    Node* backNode; 

    while(1) // 텍스트 파일의 끝까지 반복(사실상 무한 루프)
    {
        data = getchar(); // 한 문자 입력받기
        if(isdigit(data) || (data == '-' && minus_check == 0)) // 입력받은 문자가 숫자라면 or ('-'가 처음 나왔을 때)
        {
            if(data == '-') // 입력받은 문자가 '-'라면
            {
                minus_check = 1; //나중에 temp(정수로 바꾼 문자의 임시 변수)를 음수로 바꿔주기 위한 검사 변수
            }
            else
            {
                if(combo > 0) // 입력받은 문자열이 또 숫자라면
                {
                    temp = temp * 10; //현재 temp의 자릿수 올리기
                }
                temp += data - '0'; //숫자면 정수로 변환해서 넣기
                // 123을 받는 과정 (1) -> (1 * 10 + 2 = 12) -> (12 * 10 + 3 = 123)
                combo++; 
                data = 0;
            }
        }
        else
        {
            if(combo > 0) // 숫자가 앞에 나왔었다면
            {
                //printf("%d \n", temp);
                if(minus_check == 1) // 만약 숫자가 나오기 바로 전에 -가 있었다면
                {
                    temp*= -1; // 수를 음수로 변환
                }
                backNode = MakeNode(temp, head, backNode); //구한 수로 노드 생성
                amount++; // 리스트 개수 ++
            }
            combo = 0;
            temp = 0;
            minus_check = 0;
            //숫자가 아닌 부분이 나왔으므로 변수들 초기화
        }
        if(data == 10)  // 만약 줄바꿈 문자가 나온다면 입력 종료
        {
            break;
        }
        
    }
    return amount; // 리스트의 길이를 반환
}

Node* MakeNode(int value, Node* head, Node* backnode)
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
        backnode->pointer = Now_Node; //전에 생성했던 노드의 다음을 지금 생성한 노드로 채우기
    }
    
    return Now_Node; //지금 생성했던 노드를 다음 노드 생성에 전달(전에 생성했던 노드로 사용)하기 위해 반환
}

void SeekNode(int step, Node* head) //리스트의 가장 큰 수를 찾고 출력 함수로 보내는 함수
{
    int index = 1; //가장 큰 수의 위치를 저장하는 변수
    int count = 1; //현재 노드 위치를 저장하는 변수
    int Larger_N; //가장 큰 수를 저장하는 변수

    if(head->pointer != NULL) // 헤드의 다음 노드 주소가 저장되어있다면
    {
        Node* Now_Node = head->pointer; //현재 검사할 노드는 헤드의 다음 노드 주소
        Larger_N = Now_Node->data; //가장 큰 수에 지금 노드 값을 저장하고 시작
    
        while(Now_Node->pointer != NULL) // 노드의 주소가 비워져있을때까지 == 리스트의 끝에 도달할때까지
        {
            if(Larger_N < Now_Node->data) //지금 검사하는 노드에 저장된 수가 전 노드에서 저장했던 수보다 크면
            {
                Larger_N = Now_Node->data; // 지금 노드에 저장된 수를 저장
                index = count; // 지금 노드 위치를 저장
            }
            Now_Node = Now_Node->pointer; // 다음 노드로 이동
            count++; // 노드 위치 이동
        }

        if(Larger_N < Now_Node->data) // 끝에 도달했을때를 위한 예외 검사
            {
                Larger_N = Now_Node->data;
                index = count;
            }

    }
    
    //printf("\n %d: 번째의 데이터 값은 %d \n", index, Larger_N);
    DeleteNode(index, head); // 가장 큰 수를 가진 노드를 지우기
    DisplayNode(step, Larger_N, head); // SeekNode 함수에서 구한 가장 큰 값과 전체 연결 리스트의 남은 값을 출력하는 함수 실행
}

void DeleteNode(int index, Node* head) // SeekNode 함수에서 구한 가장 큰 값과 전체 연결 리스트의 남은 값을 출력하는 함수
{

    Node* remove_Node = NULL; // 지울 노드
    Node* back_Node = NULL; // 지울 노드의 전 노드

    if(head -> pointer != NULL) // 헤드의 다음 노드 주소가 비워져있지 않다면
    {
        back_Node = head; // 전 노드는 헤드
        remove_Node = head -> pointer; // 지울 노드는 헤드의 다음 노드 주소
        int count = 1; 

        while(1)
        {
            if(remove_Node->pointer == NULL) // 헤드가 가르키는 노드의 다음 노드가 비워져 있다면(노드가 한개 있는 상황 : head -> Node1 -> NULL)
            {
                    back_Node->pointer = NULL; // 전 노드가 가르킬 대상이 없으므로 비우기
                    free(remove_Node); //할당 해제 == 노드 삭제
                    break;
            }
            else
            {
                if(count == index) // 가장 큰 수가 가르키는 곳과 지금 노드의 위치가 동일하다면
                {
                    if(remove_Node->pointer == NULL) //지울 노드의 다음 노드가 없다면(맨 끝을 지워야하는 상황)
                    {
                        back_Node->pointer = NULL; // 지울 노드의 전 노드의 다음 주소를 비움
                    }
                    else
                    {
                        back_Node->pointer = remove_Node->pointer; // 전 노드에 다음 노드를 연결시키기
                    }
                    free(remove_Node); //할당 해제 == 노드 삭제
                    break;
                }
            }
            back_Node = remove_Node; // 지금 노드를 전 노드로 지정
            remove_Node = remove_Node->pointer; // 노드 한칸 이동
            count++;
        }    
    }
    else
    {
        //노드가 비어있는 상황
    }
}
void DisplayNode(int step, int value, Node* head) //값을 출력하는 함수
{
    
    Node* Now_Node = head->pointer; //출력을 위한 노드 생성
    printf("step %d. 가장 큰 값: %d 리스트:", step, value);
    if(head->pointer == NULL)
    {
        printf(" 비어있습니다.");
    }
    else
    {
        printf(" head");
    }
    while (Now_Node != NULL) // 포인터가 NULL가 될때까지 반복(리스트의 끝까지 가기)
    {
        printf(" -> %d", Now_Node->data);    
        Now_Node = Now_Node->pointer;  
    }
    printf("\n");
}