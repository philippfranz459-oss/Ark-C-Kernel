#include<stdio.h>

int main(void)
{
    int i = 2147483647;
    printf("signed int result:%d\n",i + 1);
    unsigned int j = 2147483647;
    printf("unsignde int result:%d\n",j + 1);

    return 0;
}