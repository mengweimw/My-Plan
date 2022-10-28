#include <iostream>
using namespace std;

class Base
{
public:
    int m_A;
    Base()
    {
        m_A = 100;
    }
    void func()
    {
        cout << "Base test" << endl;
    }
    void func(int a)
    {
        cout << "Base test int a" << endl;
    }
protected:
    int m_B;
private:
    int m_C;
};

class Son:public Base
{
public:
    int m_A;
    Son()
    {
        m_A = 200;
    }
    void func()
    {
        cout << "Son test" << endl;
    }
};

void test01()
{
    Son s;
    cout << "s.m_A: " << s.m_A << endl;
    //!< 如果通过子类对象，访问父类中的同名成员，需要加上作用域
    cout << "s.Base::m_A " << s.Base::m_A << endl;
}

void test02()
{
    Son s;
    s.func();
    s.Base::func();
    //!< 如果子类中出现和父类同名的成员函数，子类的同名成员会隐藏掉父类中所有同名成员函数
    //!< 如果子类想访问父类中被隐藏掉的同名成员函数，需要加作用域
    s.Base::func(100);
}

int main()
{
    test01();
    test02();

    return 0;
}