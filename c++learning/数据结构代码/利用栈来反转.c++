#include<iostream>
#include<stack>
#include<cstring>
using namespace std;
void reverse(char*c,int n)
{
    stack<char> S;
    for (int i = 0; i < n;i++)
    {
        S.push(c[i]);
    }
    for(int i=0;i<n;i++)
    {
        c[i]=S.top();
        S.pop();
    }
}
int main()
{
    char c[51];
    cout<<"enter a string"<<endl;
    gets(c);
    reverse(c, strlen(c));
    puts(c);
}