#include <stdio.h>
#include<stdlib.h>
struct Student
{
    int num;
    struct Student *next;
};
struct Student *create()
{
    struct Student *head = NULL;
    struct Student *p;
    struct Student *q;
    while (1)
    {
        p = (struct Student *)malloc(sizeof (struct Student));
        scanf("%d", &p->num);
        p->next = NULL;
        if (p->num == 0)
        {
            free(p);
            return head;
        }
        if (head == NULL)
        {
            head = p;
            q = p;
        }
        else
        {
            q->next = p;
            q = p;
           
        }
        
    }
}
// struct Student* reverse(struct Student*head)
// {
//     struct Student *cur=head;
//     struct Student *pre=NULL;
//     struct Student *next;
//     while(cur!=NULL)
//     {
//         next=cur->next;
//         cur->next = pre;
//         pre=cur;
//         cur = next;
//     }
//     head = pre;
//     return head;
// }这个是利用迭代，进行链表的反转

// void Print(struct Student*head)
// {
//     if(head==NULL)
//         return;
//     else{
//         Print(head->next);
//         printf("%d\n", head->num);
//     }
// }这个是利用递归来进行反转打印

struct Student *reverse(struct Student * head)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }
    //先找到最后一个 
        struct Student *newHead = reverse(head->next);
        (head->next)->next = head;
        head->next = NULL;

        return newHead;
    } // 这里比较难理解，所以我画了一张图来助你理解.指路：C:\Users\黄子轩\Desktop\mycode\pictures\递归反转链表.png

int main()
{
    struct Student *head;
    head = create();
    head=reverse(head);
    while(head!=NULL)
    {
        printf("%d\n", head->num);
        head = head->next;
    }
    return 0;
}