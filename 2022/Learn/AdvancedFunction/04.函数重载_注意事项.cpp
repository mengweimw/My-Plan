#include <iostream>
using namespace std;

//!< 引用作为函数重载的条件
void func(int& a)   //!< int& a = 100
{
    cout << "func(int& a) was called" << endl;
}

void func(const int& a) //!< const int& a = 100
{
    cout << "func(const int& a) was called" << endl;
}

//!< 函数重载遇到默认参数
void func2(int a, int b = 10)
{
    cout << "func2(int a, int b) was called" << endl;
}

void func2(int a)
{
    cout << "func2(int a = 10) was called" << endl;
}


int main()
{
    int a = 100;
    func(a);    //!< func(int& a)

    func(100);  //!< func(const int& a)

    // func2(10);   //!< 函数重载碰到了默认参数，会出现二义性，不知道该调用哪一个

    return 0;
}