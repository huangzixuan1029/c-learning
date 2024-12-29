#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// bool shengxu(int n)
// {
//     int cur,pre;
//     cur = n % 10;
//     n = n / 10;
//     while(n>0)
//     {
//         pre = cur;
//         cur=n%10;
//         n = n / 10;
//         if(cur>=pre)
//         {
//             return false;
//         }
        
//     }
//     return true;
// }

bool shengxu(int n)
{
    string str = to_string(n);
    int i;
    for (i = 1; i < str.length();i++)
    {
        if(str[i]-str[i-1]<=0)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    int n;
    cin>>n;
    int i;
    i = n + 1;
    while(!shengxu(i))
    {
        i++;
    }
    cout << i << endl;
    return 0;
}