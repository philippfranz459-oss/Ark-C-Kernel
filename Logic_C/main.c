#include<stdio.h>

// 这是一个定义好的“交换机器”
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int x = 5;
    int y = 10;
    printf("Original: x = %d, y = %d\n", x, y);

    // 真正的逻辑交火点：调用函数
    // 注意：我们传的是地址（房产证），不是数字
    swap(&x, &y); 

    printf("After swap function: x = %d, y = %d\n", x, y);
    return 0;
}