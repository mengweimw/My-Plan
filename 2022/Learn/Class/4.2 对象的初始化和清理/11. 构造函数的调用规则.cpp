#include <iostream>
using namespace std;

//!< 构造函数的调用规则
//!< 创建一个类，C++会默认添加三个函数
//!< 默认构造函数（空实现）
//!< 默认析构函数（空实现）
//!< 拷贝构造函数（值拷贝）

//!< 如果我们写了有参构造函数，编译器就不会提供默认构造，但是会提供拷贝构造
//!< 如果我们写了拷贝构造函数，编译器就不会提供其他的普通构造函数（无参和有参）

class Person
{
public:
    Person()
    {
        cout << "Default creator called" << endl;
    }

    Person(int age)
    {
        cout << "Has param creator called" << endl;
    }

    //!< 编译器会实现默认拷贝构造函数，不用我们自己来实现
    // Person(const Person& p)
    // {
    //     m_age = p.m_age;
    //     cout << "Copy creator called" << endl;
    // }

    ~Person()
    {
        cout << "Default destory called" << endl;
    }

    int m_age;
};

void test01()
{
    Person p;
    p.m_age = 19;

    Person p2(p);
    cout << "p2 age " << p2.m_age << endl;
}

int main()
{
    test01();

    return 0;
}