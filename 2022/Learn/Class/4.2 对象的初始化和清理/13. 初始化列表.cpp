#include <iostream>
using namespace std;

class Person
{
public:
    Person():m_a(1000), m_b(2000), m_c(3000)
    {
        cout << "No param creator called" << endl;
    }

    //!< 有参构造的初始化列表
    Person(int a, int b, int c):m_a(a), m_b(b), m_c(c)
    {
        cout << "Has param creator called" << endl;
    }
    
    ~Person()
    {
        cout << "Destory called" << endl;
    }

    int m_a;
    int m_b;
    int m_c;
};

void test01()
{
    Person p(1, 2, 3);
    cout << "m_a: " << p.m_a << " m_b " << p.m_b << " m_c " << p.m_c << endl; 

    Person p1(p);
    cout << "m_a: " << p1.m_a << " m_b " << p1.m_b << " m_c " << p1.m_c << endl; 

    Person p2;
    cout << "m_a: " << p2.m_a << " m_b " << p2.m_b << " m_c " << p2.m_c << endl; 

    Person p3(p2);
    cout << "m_a: " << p3.m_a << " m_b " << p3.m_b << " m_c " << p3.m_c << endl; 
}

int main()
{
    test01();

    return 0;
}