#include <stdio.h>
#define SEC_PER_MIN 60
#define SEC_PER_HOUR 3600
int main(void)
{
    double dist, speed;
    int FTSecond, Fhour, Fmin, Fsecond;
    int TSecond, hour, min, second;
    printf("주행거리(km):");
    scanf("%lf",&dist);
    printf("평균주행속도(km/h):");
    scanf("%lf",&speed);
    
    FTSecond = (dist/speed)*SEC_PER_HOUR ; // 총 주행 시간 (초)
    Fhour = FTSecond / SEC_PER_HOUR;
    Fmin = (FTSecond % SEC_PER_HOUR) / SEC_PER_MIN; 
    Fsecond = FTSecond % SEC_PER_MIN;
    

    TSecond =   dist / speed * SEC_PER_HOUR; // 총 주행 시간 (초)
    
    hour = TSecond/SEC_PER_HOUR;
    min = (TSecond % SEC_PER_HOUR) / SEC_PER_MIN; 
    second = (TSecond - (SEC_PER_HOUR * hour)) - (SEC_PER_MIN * min);
    printf("답안 총 주행 시간: %d시간 %d분 %d초\n", Fhour, Fmin, Fsecond);
    printf("제출 총 주행 시간: %d시간 %d분 %d초\n",hour, min, second);
    return 0;
}
