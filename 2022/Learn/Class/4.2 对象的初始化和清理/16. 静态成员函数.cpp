#include <iostream>
using namespace std;


class Person
{
public:
    static int m_a;
    int m_b;

    //!< 所有对象共享同一个函数
    //!< 静态成员函数只能访问静态成员变量
    static int func()
    {
        cout << "static int func called" << endl;
        m_a = 99;
        cout << "m_a " << m_a << endl;
        // m_b = 100;  //!< 静态成员函数不能访问非静态的成员变量，无法区分哪个对象的m_b属性
        return 0;
    }

private:
    //!< 静态成员函数也是有访问权限的
    static void func2()
    {
        cout << "static int func2 called" << endl;
        return;
    }
};

int Person::m_a = 10000;

void test01()
{
    //!< 通过对象访问
    Person p;
    p.func();
    //!< 通过类名访问
    Person::func();

    // Person::func2(); //!< 类外不能访问私有属性的静态成员函数
}

int main()
{
    test01();

    return 0;
}