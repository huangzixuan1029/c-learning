#include<iostream>
#include<bits/stdc++.h>
using namespace std;
bool function1 (char a,char b)
{
    int num1 = (a - 'E' + 26) % 26;
    int num2 = (b - 'Z' + 26) % 26;
    if(num1==num2)
    {
        return true;
    }
    else{
        return false;
    }
}
int main()
{
    int n;
    cin >> n;
    getchar();
    string str;
    getline(cin, str);
    int i;
    int count = 0;
    for(i=0;i<str.length()-1;i++)
    {
        if(function1(str[i],str[i+1]))
        {
            count++;
        }
    }
    cout << count << endl;
    if(2*count>n)
    {
        cout << "(#-_-)";
    }
    else
    {
        cout << "(O_o)(o_O)";
    }
    return 0;
}