#include <iostream>
using namespace std;

// class Person
// {
//     friend Person& operator++();
// public:
//     Person();
//     Person(int a, int b);
//     ~Person();
//     void showInfo();

// private:
//     int m_A;
//     int m_B;
// };

// Person::Person()
// {
//     cout << "Has no param Person creator called" << endl; 
// }

// Person::Person(int a, int b)
// {
//     m_A = a;
//     m_B = b;
//     cout << "Has param Person creator called" << endl;
// }

// Person::~Person()
// {
//     cout << "Person destory called" << endl;
// }

// void Person::showInfo()
// {
//     cout << "m_A: " << this->m_A << " m_B: " << this->m_B << endl; 
// }

// Person& operator++()
// {
//     m_A++;
//     m_B++;

//     return this;
// }

// void test01()
// {
//     Person p1(100, 10);
//     // Person p2 = operator++(p1);
//     p1.operator++();
//     p1.showInfo();
// }

class MyInt
{
    friend ostream& operator<<(ostream& out, MyInt& myint);
public:
    MyInt();

    //!< 重载前置运算符，++i。 此处需要返回引用，需要对一个数据进行操作，否则此处会拷贝，++ 
    MyInt& operator++()
    {
        this->m_Num++;

        return *this;
    }

    //!< 重载后置运算符 i++
    // MyInt operator++(int); int 代表占位参数，用于区分前置和后置
    MyInt operator++(int)
    {
        //!< 先记录当时的结果
        MyInt temp = *this;
        //!< 再递增
        this->m_Num++;
        //!< 最后将记录的结果返回
        return temp;
    }   
private:
    int m_Num;
};

MyInt::MyInt()
{
    m_Num = 0;
}

ostream& operator<<(ostream& out, MyInt& myint)
{
    out << myint.m_Num;

    return out;
}

// //!< 重载前置运算符 ++i
// MyInt& operator++()
// {
//     this->m_num;

//     return *this;
// }

// //!< 重载后置运算符 i++
// void MyInt::operator++()
// {
//     this->m_Num++;
// }

void test01()
{
    MyInt myint;
    cout << ++myint << endl;
    cout << ++myint << endl;
}

void test02()
{
    MyInt myint;

    // cout << (myint++) << endl;
}

int main()
{
    test01();
    test02();
    return 0;
}
