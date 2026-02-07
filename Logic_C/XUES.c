#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 定义Student结构体
typedef struct {
    int age;
    char *name;  // 动态分配的姓名指针
} Student;

// 创建学生并分配内存
Student* create_student(int age, const char *name) {
    Student *stu = (Student*)malloc(sizeof(Student));
    if (!stu) return NULL;

    stu->age = age;
    stu->name = (char*)malloc(strlen(name) + 1);  // +1 for '\0'
    if (!stu->name) {
        free(stu);
        return NULL;
    }
    strcpy(stu->name, name);
    return stu;
}
void update_student_status(Student **stu_ptr, const char *new_name) {
    if (!stu_ptr || !*stu_ptr) return;  // 检查空指针

    Student *stu = *stu_ptr;
    char *old_name = stu->name;  // 保存旧地址以便释放

    // 分配新内存并复制新名字
    stu->name = (char*)malloc(strlen(new_name) + 1);
    if (!stu->name) {
        stu->name = old_name;  // 分配失败则恢复旧指针
        return;
    }
    strcpy(stu->name, new_name);

    free(old_name);  // 释放旧内存
}
void free_student(Student *stu) {
    if (!stu) return;
    free(stu->name);  // 先释放成员指针
    free(stu);        // 再释放结构体
}

int main() {
    // 创建学生并初始化
    Student *stu = create_student(18, "职高生");
    if (!stu) {
        printf("内存分配失败！\n");
        return 1;
    }
    printf("修改前: 年龄=%d, 姓名=%s\n", stu->age, stu->name);

    // 动态修改姓名
    update_student_status(&stu, "Upwork开发者");
    printf("修改后: 年龄=%d, 姓名=%s\n", stu->age, stu->name);

    // 释放内存
    free_student(stu);
    return 0;
}