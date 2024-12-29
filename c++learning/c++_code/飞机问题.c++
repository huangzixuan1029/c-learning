// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// struct AirP
// {
//     char name[20];
//     char time[20];
// };

// void input(int opnum, struct AirP arr[], int n)
// {
//     char str1[20];
//     char str2[20];
//     char str3[20];
//     int i, j;
//     for (i = 0; i < opnum; i++)
//     {
//         scanf("%s", str1);
//         if (strcmp(str1, "CANCEL") == 0)
//         {
//             scanf("%s", str2);
//             for (j = 0; j < n; j++)
//             {
//                 if (strcmp(str2, arr[j].name) == 0)
//                 {
//                     strcpy(arr[j].time, "ERROR");
//                 }
//             }
//         }
//         else
//         {
//             scanf("%s%s", str2, str3);
//             for (j = 0; j < n; j++)
//             {
//                 if (strcmp(str2, arr[j].name) == 0)
//                 {
//                     strcpy(arr[j].time, str3);
//                 }
//             }
//         }
//     }
// }

// void sort(struct AirP arr[], int n)
// {
//     for (int i = 0; i < n - 1; i++)
//     {
//         for (int j = 0; j < n - i - 1; j++)
//         {
//             if (strcmp(arr[j].time, "ERROR") == 0)
//             {
//                 struct AirP temp = arr[j];
//                 arr[j] = arr[j + 1];
//                 arr[j + 1] = temp;
//             }
//             // 如果下一个航班是 "ERROR"，则跳过比较
//             else if (strcmp(arr[j + 1].time, "ERROR") == 0)
//             {
//                 continue;
//             }
//             // 比较两个有效时间
//             else if (strcmp(arr[j].time, arr[j + 1].time) > 0)
//             {
//                 struct AirP temp = arr[j];
//                 arr[j] = arr[j + 1];
//                 arr[j + 1] = temp;
//             }
//         }
//     }
// }

// void output(struct AirP arr[], int n)
// {
//     sort(arr, n); // 先排序
//     for (int i = 0; i < n; i++)
//     {
//         // 跳过时间被设置为 "ERROR" 的航班
//         if (strcmp(arr[i].time, "ERROR") != 0)
//         {
//             printf("%s %s\n", arr[i].name, arr[i].time);
//         }
//     }
// }

// int main()
// {
//     int n;
//     scanf("%d", &n);
//     struct AirP *arr = (struct AirP *)malloc(n * sizeof(struct AirP));
//     int i, j;
//     for (i = 0; i < n; i++)
//     {
//         scanf("%s%s", arr[i].name, arr[i].time);
//     }
//     int opnum;
//     scanf("%d", &opnum);
//     // 一个计划的输入函数&&然后改变存入的数据
//     // 然后写一个函数进行排序输出
//     input(opnum, arr, n);
//     output(arr, n);

//     return 0;
// }

//了解qsort函数

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct AirP
{
    char name[20];
    char time[20];
};

void input(int opnum, struct AirP arr[], int n)
{
    char str1[20];
    char str2[20];
    char str3[20];
    int i, j;
    for (i = 0; i < opnum; i++)
    {
        scanf("%s", str1);
        if (strcmp(str1, "CANCEL") == 0)
        {
            scanf("%s", str2);
            for (j = 0; j < n; j++)
            {
                if (strcmp(str2, arr[j].name) == 0)
                {
                    strcpy(arr[j].time, "ERROR"); // 修改 arr[j].time
                }
            }
        }
        else
        {
            scanf("%s%s", str2, str3);
            for (j = 0; j < n; j++)
            { // 修正循环变量
                if (strcmp(str2, arr[j].name) == 0)
                {
                    strcpy(arr[j].time, str3);
                }
            }
        }
    }
}

void sort(struct AirP arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            // 如果当前航班是 "ERROR"，则跳过比较
            if (strcmp(arr[j].time, "ERROR") == 0)
            {
                continue;
            }
            // 如果下一个航班是 "ERROR"，则交换
            if (strcmp(arr[j + 1].time, "ERROR") == 0)
            {
                struct AirP temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
            // 比较两个有效时间
            else if (strcmp(arr[j].time, arr[j + 1].time) > 0)
            {
                struct AirP temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void output(struct AirP arr[], int n)
{
    sort(arr, n); // 先排序
    for (int i = 0; i < n; i++)
    {
        // 跳过时间被设置为 "ERROR" 的航班
        if (strcmp(arr[i].time, "ERROR") != 0)
        {
            printf("%s %s\n", arr[i].name, arr[i].time);
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    struct AirP *arr = (struct AirP *)malloc(n * sizeof(struct AirP));
    int i;
    for (i = 0; i < n; i++)
    {
        scanf("%s%s", arr[i].name, arr[i].time);
    }
    int opnum;
    scanf("%d", &opnum);

    input(opnum, arr, n);
    output(arr, n);

    free(arr);
    return 0;
}