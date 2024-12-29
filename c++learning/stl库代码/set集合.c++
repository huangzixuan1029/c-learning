#include<iostream>
#include<set>
using namespace std;
int main()
{
    set<int>s;
    s.insert(9);
    s.insert(4);
    s.insert(1);
    s.erase(10);//不带有返回值
    for (auto p = s.begin(); p != s.end();p++)
    {
        cout << *p << endl;
    }
    cout << (s.find(4) != s.end()) << endl;
    cout << sizeof(s) << endl;//set类对应的内存是48

    return 0;
}