#include <stdio.h>


int main(void)
{

	int year = 0;
	int result = 0;
	scanf("%d", &year);

	printf("%d", (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)));

	return 0;

}
