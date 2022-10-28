#include <iostream>
using namespace std;

int func(int a, int)
{
    cout << "this func is called by main"  << endl;
}

/** 占位参数可以有默认值 */
int func1(int a, int = 10)
{
    cout << "this func is called by main" << endl;
}

int main()
{
    func(10, 1000);

    return 0;
}