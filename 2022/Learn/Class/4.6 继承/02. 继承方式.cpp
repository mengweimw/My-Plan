#include <iostream>
using namespace std;

class Base1
{
public:
    int m_A;
protected:
    int m_B;
private:
    int m_C;
};

class Son1: public Base1
{
public:
    void func();
};

void Son1::func()
{
    //!< 父类中公共权限属性，在子类中仍然为公共权限
    m_A = 10;
    //!< 父类中保护权限属性，在子类中仍然为保护权限
    m_B = 100;
    //!< 父类中私有权限属性，子类不可访问
    // m_C = 200;

    cout << "m_A: " << m_A << " m_B: " << m_B << endl;
}

void test01()
{
    Son1 s1;
    s1.func();
    s1.m_A = 1000;
    //!< 保护权限类外不能访问，类内可以访问
    // s1.m_B = 1000;
}

class Base2
{
public:
    int m_A;
protected:
    int m_B;
private:
    int m_C;
};

class Son2:protected Base2
{
public:
    void func();
};

void Son2::func()
{
    //!< 父类中公共权限的属性，保护继承后在子类中变为保护权限
    m_A = 1000;
    //!< 父类中保护权限的属性，保护集成后在子类仍然为保护权限
    m_B = 10000;
    //!< 父类中的私有权限属性，子类中不能访问
    // m_C = 1000;
}

void test02()
{
    Son2 s2;
    // //!< 保护权限属性，类外不能访问
    // s2.m_A = 1000;
    // //!< 保护权限属性，类外不能访问
    // s2.m_B = 200;
    // //!< 私有权限属性，不能访问
    // s2.m_C = 2000;
}

class Base3
{
public:
    int m_A;
protected:
    int m_B;
private:
    int m_C;
};

class Son3:private Base3
{
public:
    void func();
};

class GrandSon:public Son3
{
public:
    void func();
};

void Son3::func()
{
    //!< 私有继承后，权限变为私有，只有类内能访问
    m_A = 1000;
    //!< 私有继承后，权限变为私有，只有类内能访问
    m_B = 1000;
    // m_C = 1000;
}

void test03()
{
    Son3 s3;
    s3.func();
}

void GrandSon::func()
{
    //!< 私有属性被公有继承后，在类内是无法访问的
    // m_A = 1000;
    // m_B = 1000;
}

int main()
{
    test01();
    return 0;
}