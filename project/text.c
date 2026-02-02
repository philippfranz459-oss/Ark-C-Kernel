#include<stdio.h>

int main (void){
    for (int j = 1;j <= 100; j++)
    if (j % 3 == 0 && j % 5 == 0){
        printf("%d:这个数不仅是三还是五的倍数\n",j);
    }
    else if (j % 3 == 0)
    {
        printf("%d:这是一个三的倍数\n",j);
    }else if (j % 5 == 0){
        printf("%d:这是一个五的倍数\n",j);
    }
    else {
        printf ("%d:这啥都不是\n",j);
    }

}   