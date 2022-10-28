#include <iostream>
using namespace std;

class Person
{
public:
    Person()
    {
        cout << "Person default creator called" << endl; 
    }

    Person(int age, int height)
    {

        m_age = age;
        m_height = new int(height);
        
        cout << "Person has param creator called" << endl;
    }

    //!< 自己实现深拷贝
    Person(const Person& p)
    {
        cout << "Person copy creator called" << endl;
        m_age = p.m_age;

        m_height = new int(*p.m_height);
    }

    ~Person()
    {
        //!< 将堆区申请的数据，在此处释放掉
        if (NULL != m_height) {
            delete m_height;
            m_height = NULL;
        }
        cout << "Person destory called" << endl;
    }

    int m_age;
    int* m_height;
};

void test01()
{
    Person p1(18, 160);

    cout << "P1 age " << p1.m_age << " P1 height " << *p1.m_height << endl;

    //!< 编译器浅拷贝
    Person p2(p1);
    cout << "P2 age " << p2.m_age << " P2 height " << *p2.m_height << endl;
}

int main()
{
    test01();

    return 0;
}