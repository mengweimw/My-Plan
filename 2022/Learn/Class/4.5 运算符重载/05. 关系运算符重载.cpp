#include <iostream>
using namespace std;


class Person
{
    friend bool operator!=(Person& p1, Person&p2);
public:
    Person();
    Person(string name, int age);
    ~Person();
    bool operator==(Person& p)
    {
        if (this->m_Name == p.m_Name && this->m_Age == p.m_Age)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    string m_Name;
private:
    int m_Age;
};

Person::Person()
{
    cout << "Default creator called" << endl;
}

Person::Person(string name, int age)
{
    m_Name = name;
    m_Age = age;
    cout << "Has param creator called" << endl;
}

Person::~Person()
{
    cout << "Default destory called" << endl;
}

bool operator!=(Person& p1, Person&p2)
{
    if (p1.m_Name == p2.m_Name && p1.m_Age == p2.m_Age)
    {
        return false;
    }
    return true;
}

void test01()
{
    Person p1("zhangsan", 18);
    Person p2("zhangsan", 18);

    if (p1 == p2)
    {
        cout << "p1 == p2" << endl;
    }
    else
    {
        cout << "p1 != p2" << endl;
    }

    if (p1 != p2)
    {
        cout << "p1 != p2" << endl;
    }
    else
    {
        cout << "p1 == p2" << endl;
    }


    return ;

}


int main()
{
    test01();

    return 0;
}