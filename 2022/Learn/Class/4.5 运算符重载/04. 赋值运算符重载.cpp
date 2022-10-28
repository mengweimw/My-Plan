#include <iostream>
using namespace std;

class Person
{
public:
    Person()
    {

    }
    Person(int age)
    {
        m_age = new int(age);
    }

    ~Person()
    {
        if (NULL != m_age)
        {
            delete m_age;
            m_age = NULL;
        }
    }

    //!< 编译器实现的是浅拷贝函数，如果在析构时释放内存，会出现double free的问题

    //!< 我们自己的实现，在堆区开辟内存，用堆区深拷贝数据
    Person& operator=(Person& p)
    {
        //!< 应该先判断是否有属性在堆区，如果有限释放，再深拷贝
        if (NULL != m_age)
        {
            delete m_age;
            m_age = NULL;
        }

        m_age = new int(*p.m_age);

        return *this;
    }

    int* m_age;
};

void test01()
{
    Person p1(18);
    Person p2(20);
    Person p3(30);

    p3 = p2 = p1;
    
    cout << "p1 age: " << *p1.m_age << endl;
    cout << "p2 age: " << *p2.m_age << endl;
    cout << "p3 age: " << *p3.m_age << endl;

}

int main()
{
    test01();
    return 0;
}