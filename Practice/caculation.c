#include <stdio.h>

int main()
{
    char op;
    int x, y, result = 0;

    printf("수식 입력\n(예: 2+5)\n");
    scanf("%d %c %d", &x, &op, &y);

    switch(op)
    {
	    case '+':
		        result = x+y;
		        printf("%d %c %d = %d\n", x,op,y,result);
			break;

	    case '-':
			result = x-y;
		        printf("%d %c %d = %d\n", x,op,y,result);
			break;

	    case '&':
			result = x&&y;
			printf("%8X %c %02X = %03X\n", x, op, y, result);
			break;

			
   }
}
