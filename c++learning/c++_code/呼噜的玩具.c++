#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Student
{
    char name[10];
    int count;
    int distance;
    int isban;
};

// 函数声明
void swap(struct Student *a, struct Student *b);

int main()
{
    int n;
    scanf("%d", &n);

    // 动态分配一个数组存储学生信息
    struct Student *students = (struct Student *)malloc(n * sizeof(struct Student));

    // 输入学生信息
    for (int i = 0; i < n; i++)
    {
        scanf("%s %d %d %d", students[i].name, &students[i].count, &students[i].distance, &students[i].isban);
    }

    // 排序逻辑
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (students[i].count < students[j].count ||
                (students[i].count == students[j].count && students[i].distance > students[j].distance) ||
                (students[i].count == students[j].count && students[i].distance == students[j].distance &&
                 strcmp(students[i].name, students[j].name) > 0))
            {
                swap(&students[i], &students[j]);
            }
        }
    }

    // 输出未被禁用的学生信息
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (students[i].isban == 0)
        {
            count++;
            printf("No.%d %s %d %d\n", count, students[i].name, students[i].count, students[i].distance);
        }
    }

    // 释放动态分配的内存
    free(students);

    return 0;
}

// 交换两个学生的信息
void swap(struct Student *a, struct Student *b)
{
    struct Student temp = *a;
    *a = *b;
    *b = temp;
}
