#include<stdio.h>

int main(){
    char name[100];
    int count = 0;
    printf ("你的名字:");
    scanf("%s",name);
    while (name[count] != '\0'){
        count++;
    }
    printf("总长度为%d个字节\n",count);
    return 0;
}