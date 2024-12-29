#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void add(int (&brr)[3])
{
    int i;
    for(i=0;i<3;i++)
    {
        brr[i] += 3;
        
    }
    return;
}
int main()
{
    int i;
    int arr[3] = {1, 2, 3};
    add(arr);
    for (i = 0; i < 3; i++)
    {
        printf("%d\n", arr[i]);
    }
    return 0;
}