#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int compare(const void *a, const void *b)
{
    return strcmp((const char *)a, (const char *)b);
}

int main()
{
    int n;
    scanf("%d", &n);    
    getchar();
    char str[n][20];
    int i;
    for (i = 0;i<n;i++)
    {
        scanf("%s", str[i]);
    }
    qsort(str, n, sizeof(str[0]), compare);
    for (i = 0; i < n;i++)
    {
        puts(str[i]);
    }
    return 0;
}