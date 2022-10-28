#include <iostream>
using namespace std;

class Base
{
public:
    static int m_A;
    static void func();
};

int Base::m_A = 100;
void Base::func()
{
    cout << "Base static func" << endl;
}

class Son:public Base
{
public:
    static int m_A;
    static void func();
};

int Son::m_A = 200;
void Son::func()
{
    cout << "Son static func" << endl;
}

void test01()
{
    //!< 通过对象的方式访问静态成员
    Son s;
    cout << "Son m_A: " << s.m_A << endl;
    cout << "Base m_A: " << s.Base::m_A << endl;

    s.func();
    s.Base::func();

    //!< 通过类名的方式访问静态成员
    cout << "Son m_A: " << Son::m_A << endl;
    //<! 第一个 :: 代表通过类名的方式访问，第二个 :: 代表访问父类作用域下的成员
    cout << "Base m_A: " << Son::Base::m_A << endl;
    Son::func();
    Son::Base::func();
}

int main()
{
    test01();

    return 0;
}