#include <iostream>
using namespace std;

//!< 左移运算符重载
class Person
{
    friend ostream& operator<<(ostream& out, Person& p);
public:
    Person();
    Person(int a, int b);
    ~Person();

    //!< 使用成员函数重载，左移运算符，p.operator<<(cout)， 简化版本，p << cout
    //!< 一般不会用成员函数重载左移运算符，因为无法实现 cout 在左边
    // void operator<<()
    // {
        
        
    // }

private:
    int m_A;
    int m_B;
};

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

//!< 全局只有一个cout，所以此处要采用 & 的方式返回
ostream& operator<<(ostream& out, Person& p)
{
    out << "m_A: " << p.m_A << " m_B: " << p.m_B;
    return out;
}

void test01()
{
    Person p(100, 1000);
    //!< 链式变成思想，cout << p 返回为cout 即可以再次输出 << 
    cout << p << endl;
}

int main()
{
    test01();
    return 0;
}