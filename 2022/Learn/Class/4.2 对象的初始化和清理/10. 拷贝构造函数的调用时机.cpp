#include <iostream>
using namespace std;

//!< 拷贝构造函数的调用时机

class Person
{
public:
    Person()
    {
        cout << "No param creator" << endl;
    }

    Person(int age)
    {
        m_age = age;
        cout << "Has param creator" << endl;
    }

    Person(const Person& p)
    {
        m_age = p.m_age;
        cout << "Copy creator" << endl;
    }

    ~Person()
    {
        cout << "Destory" << endl;
    }

    int m_age;
};

//!< 使用一个已经创建完毕的对象初始化一个新的对象
void test01()
{
    Person p1;
    p1.m_age = 100;

    Person p2(p1);
    cout << "p1 age " << p1.m_age << " p2 age " << p2.m_age << endl;

    p2.m_age = 99;
    cout << "p1 age " << p1.m_age << " p2 age " << p2.m_age << endl;

    return;
}

void doWork(Person p)
{
    p.m_age = 1000;
    cout << "doWork p.m_age " << p.m_age << endl;
}

//!< 值传递的方式给函数参数传值
void test02()
{
    Person p(100000);
    doWork(p);
    cout << "test02 p.m_age " << p.m_age << endl;
}

Person doWork2()
{
    Person p1(1000);
    cout << "int* " << &p1 << endl;
    return p1;
}

//!< 以值方式返回局部对象
void test03()
{
    Person p = doWork2();
    cout << "test 03 p.m_age " << p.m_age << endl;
    cout << "test 03 p.m_age " << p.m_age << endl;
    cout << "int* " << &p << endl;
}


int main()
{
    // test01();
    test02();
    test03();

    return 0;
}