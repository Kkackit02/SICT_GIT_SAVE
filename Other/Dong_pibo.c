#include <stdio.h>
#include <stdlib.h>

int count = 0;

int fibo(int n)
{
    count = count + 1;
    //printf("%d 값으로 함수가 실행되었습니다.\n", n);

    if (n == 0){
        return 0;;
    }
    
    if(n == 1)
    {
        return 1;
    }
    
    else{
        int temp = fibo(n-1) + fibo(n - 2);
        return (temp);
    }
}

int main(){
    int input = 0;
    
    int i = 0;
    
    printf("출력할 피보나치 수열의 항 : ");
    scanf("%d", &input);
    
    for (i = 1; i <= input; i++){
        count = 0;
        int temp = fibo(i);
        printf("fibo(%d) = %d       count = %d\n", i, temp, count);
    }
}