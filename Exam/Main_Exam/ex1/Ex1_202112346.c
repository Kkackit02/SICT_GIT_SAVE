/* 이름 : 정근녕
 * 학번 : 202112346
 */


#include <stdio.h>

int main(void)
{
    int korean_GP = 0;
    int english_GP = 0;
    int math_GP = 0;
    // GP = grade point = 학점
    float korean_rating = 0;
    float english_rating = 0;
    float math_rating = 0;
    // rating = 평점

    int sum_GP = 0; //학점 합계
    float sum_RGP = 0; //평점 합계
    float sum_E = 0; // 평점 평균
    
    printf("국어과목의 학점과 평점을 입력하시오: ");
    scanf("%d %f", &korean_GP, &korean_rating);
    printf("영어과목의 학점과 평점을 입력하시오: ");
    scanf("%d %f", &english_GP, &english_rating);
    printf("수학과목의 학점과 평점을 입력하시오: ");
    scanf("%d %f", &math_GP, &math_rating);


    //계산
    //(평점 평균) == 평점 합계(학점*평점들의 합) / 학점 합계(학점들의 합)
    
   sum_RGP = (((float)korean_GP * korean_rating) + ((float)english_GP * english_rating) + ((float)math_GP * math_rating)); //평점 합계 계산
   sum_GP = korean_GP + english_GP + math_GP; //학점 합계 계산
   sum_E = sum_RGP/(float)sum_GP; //평점 평균 계산
  
   printf("\n결과: %d\n", (sum_GP >= 10 && (sum_E) >= 4.0)); // 학점 합계가 10 이상, 그리고 평점 평균이 4.0 이상일때 1 출력)

   return 0;

}


