#include <iostream>
using namespace std;

/**
 * 1. 如果调用者未传入则使用形参的默认值；
 * 2. 如果调用者传入，则使用传输的参数值；
*/
int  func(int a, int b = 20, int c = 30)
{
    return a + b +c;
}


/**
 * 1. 如果某个位置已经有了默认值，那么从这个位置往后，所有的参数都需要有默认值；
*/
int func2(int a, int b, int c, int d)
{
    return a + b + c + d;
}

/**
 * 1. 如果函数声明有默认参数，那么函数实现就不能有默认参数
*/
int func3(int a = 10, int b = 100, int c = 1000);

int main()
{
    cout << func(10, 30) << endl;

    cout << func3() << endl;

    return 0;
}

int func3(int a, int b, int c)
{
    return a + b + c;
}