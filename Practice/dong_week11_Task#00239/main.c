#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include"calc.h"

#define BUFLEN 100
void printpkt (char* p)
{
    short pkt_len = *(short*)p;
    short hdr_len = *((short*)p+1);

    for(int i =hdr_len; i <pkt_len ; i++)
    {
        printf("%c", *(p + i));
    }
    printf("\n");
}

/*
int main(void)
{
    FILE *fp;
    char buf[BUFLEN];
    char *p = buf;
    fp = fopen("input.dat", "rb");
    fread(buf, 1, BUFLEN, fp);
    fclose(fp);
    printpkt (p);
}
*/


int main(void)
{
    int a = 2, b = 3;
    printf("A + B : %d\n", add(a, b));
    printf("A * B : %d\n", mul(a, b));
    printf("A^2 : %d\n", square(a));
}
