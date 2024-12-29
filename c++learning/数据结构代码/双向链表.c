#include<stdio.h>
#include<stdlib.h>

typedef struct Nodes
{
    int data;
    struct Nodes*next;
    struct Nodes *prev;
}Node;
/*这些成员总共占用了 4 + 8 + 8 = 20 字节。但是，编译器会根据特定的对齐规则来分配内存，以确保结构体的成员访问是高效的。这意味着编译器可能会在结构体的末尾添加填充字节（padding），以确保整个结构体的大小是某个特定值的倍数（通常是最大的成员大小或者处理器字长）。这是步长为32的原因*/

Node* createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if(newNode==NULL)
    {
        printf("fail to allocate neicun\n");
        return NULL;  
    }
    newNode->data=data;
    newNode->prev=NULL;
    newNode->next=NULL;
    return newNode;
}

void insertend(Node**head,int data)//这是尾插法双向链表的写法，与之前的写法不同的是，这个是手动每次只能添加一个元素的写法
{
    Node*newnode=createNode(data);
    newnode->next = NULL;
    newnode->prev = NULL;
    if(*head==NULL)
    {
        *head = newnode;
    }
    else{
        Node *record = *head;
        while(record->next!=NULL)
        {
            record = record->next;
        }
        record->next = newnode;
        newnode->prev = record;
    }
}

void insertHead(Node**head,int data)
{
    Node*newNode=createNode(data);

    if(*head==NULL)
    {
        *head = newNode;
    }
    
    else{
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
    }

}

void traverseForward(Node*head)
{
    while(head!=NULL)
    {
        printf("%d %d\n",head->data,head);
        head = head->next;
    }

}

void traverseBackward(Node*head)
{
    Node*p=head;
    while(p->next!=NULL)
    {
        p = p->next;
    }
    while (p!=NULL)
    {
        printf("%d %d\n", p->data,p);
        p = p->prev;
    }
} /*
 在双向链表中，NULL 通常用来表示链表的结束。当我们从链表的末尾开始向前遍历时，我们需要在到达链表的开始之前停止循环。在双向链表的前端，head 节点的 prev 指针应该是 NULL，因为 head 节点没有前驱节点。因此，当我们遍历到 head 节点时，p->prev 将是 NULL，这时循环条件 while (p != NULL) 将评估为 false，循环将结束。
 */
// 也就是说，如果head没有前驱节点，则会默认为head->pre=NULL;(?)

void del(Node*del)//处理不了head头节点变化的情况，由于head也是一个指针，所以想修改head指针，还得用指向指针的指针
{ 
    if(del->prev!=NULL)
    {
        del->prev->next = del->next;
    }
    if(del->next!=NULL)
    {
        del->next->prev = del->prev;
    }
    free(del);//注意free函数的参数是空类型的指针,释放指针的副本，由于指针的副本和指针指向同一块内存，所以可以这样用
    del = NULL;
}
//这是删除一个节点的method
int main()
{
    Node*head=NULL;
    insertend(&head, 1);
    insertend(&head, 2);
    insertend(&head, 3);
    insertend(&head, 4);
    insertHead(&head, 0);
    insertHead(&head, -1);
    del(head->next);
    printf("Forward:\n");
    traverseForward(head);
    printf("Backward:\n");
    traverseBackward(head);
    
    return 0;
}