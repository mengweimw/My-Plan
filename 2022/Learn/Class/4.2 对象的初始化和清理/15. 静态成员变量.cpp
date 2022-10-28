#include <iostream>
using namespace std;

class Person
{
public:
    //!< 1. 所有对象共享同一份数据
    //!< 2. 编译阶段就分配了内存
    //!< 3. 类内声明，类外初始化
    static int m_age;
private:
    //!< 静态成员变量也是有访问权限的
    static int m_B;

};

//!< 类外初始化
int Person::m_age = 100;
// int Person::m_B = 200;  //!< 类外无法访问私有静态成员变量

void test01()
{
    Person p;
    cout  << p.m_age << endl;

    Person p2;
    p2.m_age = 200;
    cout  << p.m_age << endl;
}

void test02()
{
    //!<  静态成员变量不属于某个对象上，所有对象共享同一份数据
    //!<  因此静态成员变量有两种访问方式：
    //!< 1. 通过对象访问
    Person p;
    cout << p.m_age << endl;
    //!< 2. 通过类名访问
    cout << Person::m_age << endl;
}

int main()
{
    test01();
    test02();

    return 0;
}