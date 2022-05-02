#include<stdio.h>

// C프로그래밍 0444-06 Homework 3-3 풀이
// 정근녕
int main(void)
{
    double width = 0;
    double hight = 0;
    
    double area = 0;
    double circumference = 0;

    
    printf("아래 값들을 입력해주세요.\n");
    printf("사각형의 길이: ");
    scanf("%lf", &width);

    printf("사각형의 높이: ");
    scanf("%lf", &hight);

    
    area = width*hight;
    circumference = (width+hight)*2;

    printf("넓이는 %lf 입니다.\n", area);
    printf("둘레는 %lf 입니다.\n", circumference);
}