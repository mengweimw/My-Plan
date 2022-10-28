#include <iostream>
using namespace std;
#include <string>

class MyPrint
{
public:
    //!< 重载函数调用运算符
    void operator()(string test)
    {
        cout << test << endl;
    }
};

void MyPrint02(string test)
{
    cout << test << endl;
}


void test01()
{
    MyPrint mp;

    //!< 仿函数
    mp("Hello world");

    MyPrint02("Hello world");

    return;
}

//!< 仿函数没有固定的写法，非常灵活
class MyAdd
{
public:
    int operator()(int a, int b)
    {
        return a + b;
    }
};

void test02()
{
    MyAdd myadd;
    int ret = myadd(100, 100);
    cout << ret << endl;

    //!< 匿名函数对象，调用仿函数
    cout << MyAdd()(100, 100) << endl;
}


int main()
{
    test01();
    test02();
    return 0;
}