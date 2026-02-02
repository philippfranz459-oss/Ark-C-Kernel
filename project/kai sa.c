#include <stdio.h>

int main() {
    char text[100];
    int i = 0; // 我们的索引（坐标）

    printf("请输入原信(全小写英文): ");
    scanf("%s", text);

    // 逻辑：只要没到终点 \0
    while (text[i] != '\0') {
        
        // --- 开始加密逻辑 ---
        
        if (text[i] == 'z') {
            // 如果是 z，绕回到 a
            text[i] = 'a';
        } else {
            // 否则，普通地往后挪一位
            // 比如 97('a') 变成 98('b')
            text[i] = text[i] + 1;
        }

        // --- 加密逻辑结束 ---

        i++; // 挪向下一个柜子
    }

    printf("加密后的密文是: %s\n", text);

    return 0;
}