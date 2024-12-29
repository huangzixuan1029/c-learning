#include<iostream>
#include<string>
using namespace std;
class Student
{
private:
    int a;
    int b;
    /* data */
public:
    Student (int x,int y):a(x),b(y){}
    void showtime()
    {
        cout << a<<'|'<<b<< endl;
    }
};
//关于隐式转换:在 C++ 中，隐式转换确实需要构造函数的定义。构造函数是用于创建对象并初始化其成员变量的函数。如果没有定义构造函数，编译器会提供一个默认的构造函数，但这个默认构造函数不会进行任何隐式转换。

int main()
{
    Student c={10,20};//这是转换两个的写法
    c.showtime();
    c = {20, 20};
    c.showtime();
    return 0;
}