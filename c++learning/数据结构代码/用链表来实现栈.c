#include <stdio.h>
#include <stdlib.h>
struct Student
{
    int data;
    struct Student *next;
};
struct Student *create()
{
    struct Student *head = NULL;
    struct Student *p = NULL;
    while (1)
    {
        p = (struct Student *)malloc(sizeof(struct Student));
        p->next = NULL;
        scanf("%d", &p->data);
        if (p->data == 0)
        {
            free(p);
            return head;
        }

        if (head == NULL)
        {
            head = p;
        }
        else // 一定注意这里 不能写if(head!=NULL)，因为上面紧接着就是head=p;
        {
            p->next = head;
            head = p;
        }
    }
    return head;
}

void delPop(struct Student **head)
{
    if (*head != NULL)
    {
        struct Student *temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

int main()
{
    struct Student *head = NULL;
    head = create();
    delPop(&head);
    while (head != NULL)
    {
        printf("%d\n", head->data);
        head = head->next;
    }
    return 0;
}