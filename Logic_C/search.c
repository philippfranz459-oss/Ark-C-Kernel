#include<stdio.h>

int main(){
    int a[10];
    int i;
    int zhengque;

    for(i=0; i<10; i++){
        printf("数据 %d: ", i+1);
        scanf("%d", &a[i]);
    }
    printf("请输入要查找的数据: ");
    scanf("%d", &zhengque);

    // 二分法
    int left = 0;
    int r=i-1;

    

    while (left <= r)
    {
        int mid= left + (r-left)/2;
    if (a[mid] == zhengque){
        printf("找到了，位置在 %d\n", mid+1);
        printf("那个数是 %d\n", a[mid]);
        return mid;
    }else if (a[mid]<zhengque){
        left = mid + 1;
        printf("向右查找\n");
    } else {
        r = mid - 1;
        printf("向左查找\n");
    }
}
    printf("没有找到\n");
    return -1;
    
    




}