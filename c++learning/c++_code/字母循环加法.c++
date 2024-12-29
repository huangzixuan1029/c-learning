#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{   
    int n;
    cin>>n;
    char fe;
    cin>>fe;
    int po = (fe - 'a' + n) % 26;
    char result='a'+po;
    cout << result << endl;
    return 0;
}