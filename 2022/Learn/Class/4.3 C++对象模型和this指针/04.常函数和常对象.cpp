#include <iostream>
using namespace std;

class Person
{
public:
    Person()
    {
        
    }
    //!< const Person* const this   //!< 下面的成员函数加了const修饰后，修饰的是this指针，指针指向和值都不可以修改了
    void showPerson() const
    {
        //!< const 修饰后，不可修改
        //!< this 指针的本质是指针常量，指针常量的指向是不可以修改的
        // Person* const this;
        // m_A = 100;
        // this = NULL;        //!< this 指针不可以修改指针的指向
        this->m_B = 10000;            //!< 关键字 mutable 修饰后，在常函数中也可以修改
    }

    void func()
    {

    }

    int m_A;
    mutable int m_B;    //!< 特殊变量，即使在常函数中，也可以修改这个值
};

void test02()
{
    const Person p;     //!< 在对象前加 const，变为常对象
    // p.m_A = 100;        //!< 不可修改
    p.m_B = 100;        //!< 特殊变量，常对象和常函数都可以修改
    p.showPerson();     //!< 常对象只能调用常函数
    // p.func();           //!< 常对象不能调用非常函数
}

int main()
{
    test02();

    return 0;
}