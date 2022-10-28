#include <iostream>
using namespace std;

//!< 函数重载需要发生在同一作用域下；
//!< 函数的个数、顺序或类型不同
//!< 函数名相同
//!< 函数的返回值不可以作为函数重载的条件
void func()
{
    cout << "func was called" << endl;
    return ;
}

void func(int a)
{
    cout << "func(int a) was called" << endl;
}

void func(double a)
{
    cout << "func(double a) was called" << endl;
}

void func(int a, double b)
{
    cout << "func(int a, double b) was called" << endl;
}

void func(double a, int b)
{
    cout << "func(double a, int b) was called" << endl;
}

int main()
{
    func();

    func(10);

    func(3.14);

    func(100, 3.14);

    func(3.14, 100);

    return 0;
}