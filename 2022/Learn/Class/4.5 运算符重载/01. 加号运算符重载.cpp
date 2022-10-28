#include <iostream>
using namespace std;

//!< 对于内置的数据类型，编译器知道如何运算
//!< 注：成员函数重载和全局函数重载只能保留一个，要不会发生冲突
class Person
{
public:
    int m_A;
    int m_B;
    
    Person();
    Person(int a, int b);
    ~Person();

    //!< 通过自己写一个成员函数，实现两个对象相加属性后返回新的对象
    Person operator+(Person& p);
};

Person Person::operator+(Person& p)
{
    Person temp;
    temp.m_A = this->m_A + p.m_A;
    temp.m_B = this->m_B + p.m_B;
    
    return temp;
}

Person::Person()
{
    cout << "Has no param Person creator called" << endl;
}

Person::Person(int a, int b)
{
    m_A = a;
    m_B = b;
    cout << "Has param Person creator called" << endl;
}

Person::~Person()
{
    cout << "Person destory called" << endl; 
}

//!< 使用成员函数，重载+号运算符
// Person operator+(Person& p1, Person& p2)
// {
//     Person temp;

//     temp.m_A = p1.m_A + p2.m_A;
//     temp.m_B = p1.m_B + p2.m_B;

//     return temp;
// }

//!< 对运算符重载，可以再次重载
Person operator+(Person& p1, int a)
{
    Person temp;

    temp.m_A = p1.m_A + a;
    temp.m_B = p1.m_B + a;

    return temp;
}


void test01()
{
    Person p1(15, 20);
    Person p2(20, 15);

    // Person p3 = p1.operator+(p2);
    //!< 上面的调用方式可以简化为
    Person p3 = p1 + p2;
    cout << "p3.m_A " << p3.m_A << " p3.m_B " << p3.m_B << endl;

    // Person p4 = operator+(p1, p2);
    //!< 上面的调用方式可以简化为：
    Person p4 = p1 + p2;
    cout << "p4.m_A " << p4.m_A << " p4.m_B " << p4.m_B << endl;

    //!< 运算符重载可以发生函数重载
    Person p5 = p1 + 10;
    cout << "p5.m_A " << p5.m_A << " p5.m_B " << p5.m_B << endl;

}



int main()
{
    test01();

    return 0;
}