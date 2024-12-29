#include<stdio.h>
#include<stdlib.h>
int compare(const void*a,const void*b)
{
    return (*(int*)a) - (*(int*)b);
}
int main()
{
    int arr[10];
    int i;
    for(i=0;i<10;i++)
    {
        scanf("%d", &arr[i]);
    }
    qsort(arr, 10, sizeof(int), compare);
    for(i=0;i<10;i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}