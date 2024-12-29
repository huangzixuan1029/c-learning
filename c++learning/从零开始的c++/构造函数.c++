#include <iostream>
using namespace std;

class Clock//关于函数定义中::的使用 如果只是在类中进行声明函数 函数的定义写在了类的外面 用:: 否则不用 就像下面的showtime展示的
{
public:
    // 参数化构造函数
    Clock(int nh, int nm, int ns)
    {
        hour = nh;
        minute = nm;
        second = ns;
    }

    // 默认构造函数
    Clock()
    {
        hour = 0;
        minute = 0;
        second = 0;
    }

    // 设置时间
    void settime(int nh, int nm, int ns)
    {
        hour = nh;
        minute = nm;
        second = ns;
    }

    // 显示时间
    void showtime();

private:
    int hour;
    int minute;
    int second;
};

int main()
{
    Clock c1(0, 0, 0);      // 使用参数化构造函数
    Clock c2;               // 使用默认构造函数
    Clock c3;               // 使用默认构造函数
    c3.settime(12, 13, 14); // 设置 c3 的时间

    c1.showtime(); // 显示 c1 的时间
    c2.showtime(); // 显示 c2 的时间
    c3.showtime(); // 显示 c3 的时间

    return 0;
}
void Clock::showtime()
    {
        cout << hour << ":" << minute << ":" << second << endl;
    }