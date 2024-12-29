#include<stdio.h>
#include<string.h>
struct Air{
    char *name;
    char *time;
};
int main()
{
    int num;
    scanf("%d",&num);
    getchar();
    int i;
    struct Air jichang[num];
    for (i = 0; i < num;i++)
    {
        scanf("%s%s", &jichang[i].name, &jichang->time);
    }
    getchar();
    int opnum;
    scanf("%d", &opnum);
    
    return 0;
}