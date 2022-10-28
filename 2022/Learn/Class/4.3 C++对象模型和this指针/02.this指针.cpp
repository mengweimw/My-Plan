#include <iostream>
using namespace std;

//!< 返回对象本身用 *this
class Person
{
public:
    int age;
    Person(int age)
    {
        //!< this 指针指向的是被调用的成员函数所属的对象
        this->age = age;
    }

    //!< 1. 此处需要使用引用回传
    //!< 2. 不使用引用的回传时，返回值会拷贝构造
    Person& PersonAddAge(const Person& p)
    {
        age += p.age;
        return *this;
    }
};

//!< 解决名称冲突
void test01()
{
    Person p1(18);
    cout << "p1 age: " << p1.age << endl;
}

void test02()
{
    Person p1(10);

    Person p2(10);

    // p2.PersonAddAge(p1);

    // cout << "p2 age " << p2.age << endl;

    //!< 链式编程思想
    p2.PersonAddAge(p1).PersonAddAge(p1).PersonAddAge(p1);
    cout << "p2 age " << p2.age << endl;

}

int main()
{
    test01();
    test02();
    return 0;
}