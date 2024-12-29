#include<iostream>
#include<bits/stdc++.h>
using namespace std;
inline void swap(int&a,int&b)//注意内联函数是直接把这个函数的代码插入到main函数中 减少函数间切换的时间 一般编译器会自动完成这个任务
{
    int i;
    i=a;
    a=b;
    b = i;
}
int add(int a,int b)
{
    int result = a + b;
    return result;
}
float add(float a, float b)
{
    float result = a + b;
    return result;
}
int main()
{
    int a;
    int b;
    cin >> a >> b;
    int&r=a;//相当于对a起一个别名 可以直接拿来用 不用像C语言那样解引用啥的
    float c = 4326.34890;
    cout<<fixed <<setprecision(3) << c<<endl;//这是保留三位小数的写法 
    cout << scientific << setprecision(3) << c << endl;//setprecision包含在iosmanip 输入输出操纵器manipulators
    cout << setprecision(3) << c << endl;
    float x,y;
    x=1.2;
    y=4.6;
    cout <<fixed<<setprecision(3) <<add(x, y) << endl;
    cout << add(a, b) << endl;
    return 0;
}