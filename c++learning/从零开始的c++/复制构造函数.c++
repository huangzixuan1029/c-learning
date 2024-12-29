#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Clock{
    public:
    Clock()//可以用初始化列表进行初始化
    {   
        hour=0;
        minute=0;
        second = 0;
    }
    //这是初始化列表的操作Clock(int h, int m, int s) : hour(h), minute(m), second(s) {}
    Clock(int a,int b,int c);
    
    void  showtime();
    Clock(Clock &p);//复制构造函数声明的写法

private:
    int hour, minute, second;
};

int main()
{
    Clock c1;
    c1.showtime();
    Clock c2(1, 2, 3);
    c2.showtime();
    c1=c2;
    c1.showtime();
    return 0;
}


void Clock::showtime()
{
    cout << hour << ":" << minute << ":" << second << endl;                     
}
Clock::Clock(Clock &p)//复制构造函数定义的写法
{
    hour=p.hour;
    minute=p.minute;
    second = p.second;
}
Clock::Clock(int a,int b,int c)//这是构造函数的写法
{
    hour = a;
    minute = b;
    second = c;
}
// 笔记总结

// 构造函数与赋值的区别
//赋值：赋值是对已经存在的对象进行修改。
//构造函数：构造函数是在对象创建时进行初始化

// 构造函数的名称必须与类名完全相同，且没有返回值类型。

// Clock::Clock指的是Clock类里面的Clock构造函数,看参数来判断是复制构造函数还是普通的构造函数，比如复制构造函数是(Clock &p)指的是Clock类对象的引用，所以是&(只能传引用) 本质上构造函数名字都是一样的 只是参数的区别

//还有就是 复制构造函数默认会自动生成 一般不用显式的写出来 但是普通的构造函数写的情况还是很多的
//一般在处理动态分配内存的话 要显式的写出来