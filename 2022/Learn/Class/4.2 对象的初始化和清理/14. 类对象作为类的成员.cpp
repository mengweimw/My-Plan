#include <iostream>
using namespace std;

// class Student
// {
// public:
//     Student()
//     {
//         cout  << "Student no param creator called" << endl;
//     }
//     ~Student()
//     {
//         cout  << "Student destory called" << endl;
//     }
//     int age;
// };


// class Person
// {
// public:
//     Person ()
//     {
//         cout  << "Person no param creator called" << endl;
//     }
//     ~Person()
//     {
//         cout << "Person destory called" << endl;
//     }
//     Student stu;
// };


class Phone
{
public:
    Phone(string name):m_Name(name)
    {
        cout << "Phone has param creator called" << endl;
    }

    ~Phone()
    {
        cout << "Phone destory called" << endl;
    }
    string m_Name;
};

class Person
{
public:
    Person(string name, string phoneName):m_name(name), phone(phoneName)
    {
        cout << "Person has param creator called" << endl;
    }
    ~Person()
    {
        cout << "Person destory called" << endl;
    }

    string m_name;
    Phone phone;
};

//!< 当其他类对象作为类成员，构造的时候，先构造对象，再构造自身
//!< 析构函数相反，先析构对象，再析构自身
void test01()
{
    Person p("zhangsan", "iphone14_max");
    cout << "Person name: " << p.m_name << " Phone name: " << p.phone.m_Name << endl;
}

int main()
{
    test01();

    return 0;
}