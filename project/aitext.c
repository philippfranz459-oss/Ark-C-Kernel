#include <stdio.h>

int main(void) 
{
    // C语言最佳实践：即使只有一行，也会给 for 循环加上大括号
    for (int j = 1; j <= 100; j++) 
    {
        // 第一优先级：最苛刻的条件（3和5的最小公倍数 15）
        if (j % 3 == 0 && j % 5 == 0) 
        {
            printf("这个数不仅是三还是五的倍数 (FizzBuzz)\n");
        } 
        // 第二优先级：满足 3 的
        else if (j % 3 == 0) 
        {
            printf("这是一个三的倍数 (Fizz)\n");
        } 
        // 第三优先级：满足 5 的
        else if (j % 5 == 0) 
        {
            printf("这是一个五的倍数 (Buzz)\n");
        } 
        // 最终兜底：原样输出数字
        else 
        {
            printf("%d\n", j);
        }
    }
    return 0;
}