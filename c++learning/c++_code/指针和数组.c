#include <stdio.h>
int main()
{
    int aa[3][4] = {{1, 2, 3, 12}, {7, 4, 5, 15}, {6, 11, 17, 19}};

    int *pa;
    pa = aa;
    int a;
    a = *(pa + 2) + 3;
   
    printf("%d", a);
    return 0;
}