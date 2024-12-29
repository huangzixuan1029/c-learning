#include<iostream>
#include<map>
using namespace std;
int main()
{
    map<string, int> m;
    m["i love baoding"]=1;
    m["i am in handan"]=2;
    m["hzx"] = 1029;
    for (auto p = m.begin();p!=m.end();p++)
    {
        cout << "key is " << p->first<<" " << "num is " << p->second << endl;
    }
    cout << "you can see my find\n";
    cout <<"hzx: "<< m["hzx"] << endl;
    cout << sizeof(m) << endl; // 相同的map对应的内存大小也是48个字节
    return 0;
}//键值对的排列顺序是按照字母的顺序进行排列的 在我写的哪个循环里，反映出实际上是通过map这个容器是通过结构体指针进行访问的