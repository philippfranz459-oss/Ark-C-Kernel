#include <stdio.h>

int main() {
    int sum = 0;
    int scores[5];
    float pingjun;

    // 修改点 1：i < 5，确保循环 5 次
    for (int i = 0; i < 5; i++) {
        printf("这是第(%d)个人的成绩 他的成绩是: ", i + 1);
        
        // 修改点 2：末尾必须加分号
        scanf("%d", &scores[i]);
        
        sum = scores[i] + sum;
    }

    pingjun = (float)sum / 5;

    // 修改点 3：打印 float 必须用 %f
    printf("这几个人的平均数为：%.2f\n", pingjun);
    printf("这几个人的总分为：%d\n", sum);

    return 0;
}