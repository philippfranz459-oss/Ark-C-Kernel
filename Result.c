#include <stdio.h>

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int *p = arr;

    // 逻辑点 1：步长 (Scale)
    p = p + 2; 
    printf("Result 1: %d\n", *p);

    // 逻辑点 2：写入 (Write-back)
    *p = 999;
    printf("Result 2: %d\n", arr[2]);

    // 逻辑点 3：地址的本质 (The Hex Truth)
    printf("Address of p: %p\n", (void *)p);
    printf("Address of p+1: %p\n", (void *)(p + 1));

    return 0;
}