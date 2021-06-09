#include <stdio.h>


int main(void)
{
	int A, B = 0;
	double result = 0;


	scanf("%d %d", &A, &B);
	result = ((double)A/(double)B);

	printf("%0.9lf", result);
	
	return 0;
}

