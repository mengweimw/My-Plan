#include <iostream>
using namespace std;

//!< 成员变量和成员函数是分开存储的
class Person
{
public:
    int m_a;    //!< 非静态成员变量，属于类的对象上的数据

    static int m_b; //!< 静态成员变量，不属于类的对象上的数据
    void func()     //!< 非静态成员函数，不属于类的对象上的数据
    {
        cout << "func" << endl;
    }

    static void func2() //!< 静态成员函数，不属于类的对象上的数据
    {
        cout << "static func" << endl;
    }

};

int Person::m_b = 100;

void test01()
{
    Person p;
    //!< 空对象，占用内存空间为 1B
    //!< C++ 编译器会给每个空对象也分配一个字节的空间，是为了区分空对象占用内存的位置
    //!< 每个空对象也应该有一个独一无二的内存地址
    cout << "sizeof Person " << sizeof(p) << endl;
}

int main()
{
    test01();
    return 0;
}