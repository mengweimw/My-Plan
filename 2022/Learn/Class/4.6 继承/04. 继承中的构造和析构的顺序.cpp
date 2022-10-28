#include <iostream>
using namespace std;

class Base
{
public:
    Base();
    ~Base();
};

class Son:public Base
{
public:
    Son();
    ~Son();
};

Base::Base()
{
    cout << "Base has no param creator called" << endl;
}

Base::~Base()
{
    cout << "Base's destory called" << endl;
}

Son::Son()
{
    cout << "Son has no param creator called" << endl;
}

Son::~Son()
{
    cout << "Son's destory called" << endl;
}

void test01()
{
    // Base b;
    //!< 继承中的构造和析构的顺序
    //!< 先构造父类，再构造子类，析构的顺序相反
    Son s;
}

int main()
{
    test01();

    return 0;
}