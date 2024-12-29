#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int arr[1001][1001];
bool jiancha(int arr[1001][1001],int i,int j)
{
    int m,n;
    int count = 0;
    for (m = i - 1; m <= i + 1;m++)
    {
        for (n = j - 1;n<=j+1;n++)
        {
            if(m==i&&n==j)
            {
                continue;
            }
            else
            {
                if(arr[i][j]>arr[m][n])
                {
                    count++;
                }    
            }
        }
    }
    if(count==1)
    {
        return true;
    }
    else{
        return false;
    }
}
int main()
{
    int count = 0;
    int i,j;
    int a,b;
    cin >> a >> b;
    for(i=1;i<=a;i++)
    {
        for(j=1;j<=b;j++)
        {
            cin >> arr[i][j];
        }
    }

    for (i = 2; i <= a-1;i++)
    {
        for (j = 2; j <= b-1;j++)
        {
            if(jiancha(arr,i,j))
            {
                count++;
            }
        }
    }
    cout << count;
    return 0;
}