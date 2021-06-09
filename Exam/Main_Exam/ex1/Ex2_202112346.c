/* 이름 : 정근녕
 * 학번 : 202112346
 */

#include<stdio.h>

int main(void)
{
    int input_origin_num = 0; // 사용자 입력 값
    int input_express_num = 0; // 화면에 나타내고자 하는 숫자
    
    int four_number = 0; // 천의자리
    int three_number = 0; // 백의자리
    int two_number = 0;
    int first_number = 0;


    //입력 받기
    printf("4자리 숫자를 입력하시오: "); 
    scanf("%d", &input_origin_num);
    printf("화면에 나타내고자 하는 숫자를 입력하시오: ");
    scanf("%d", &input_express_num);

    //각 자릿수 분리
    four_number = input_origin_num / 1000;
    three_number = ((input_origin_num % 1000)/100);
    two_number = ((input_origin_num % 100)/10);
    first_number = (input_origin_num % 10); 

    // 검사 및 출력
    (four_number == input_express_num) ? (printf("%d ", four_number * 0)) : printf("%c ", (char)('-')); 
    (three_number == input_express_num) ? (printf("%d ", three_number * 1)) : printf("%c ", (char)('-'));
    (two_number == input_express_num) ? (printf("%d ", two_number * 2)) : printf("%c ", (char)('-'));
    (first_number == input_express_num) ? (printf("%d \n", first_number * 3)) : printf("%c \n", (char)('-'));

   
    return 0;
    
    


}
