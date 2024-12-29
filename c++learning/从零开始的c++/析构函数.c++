#include <iostream>

class MyClass
{
public:

    MyClass()
    {
        std::cout << "Constructor called" << std::endl;
    }

    ~MyClass()
    {
        std::cout << "Destructor called" << std::endl;
    }
    
};

int main()
{
    MyClass obj; // 创建对象时调用构造函数
    // 对象生命周期结束时调用析构函数
    return 0;
}
//总的来说析构函数和构造函数 在动态分配内存的情况下 有点用途