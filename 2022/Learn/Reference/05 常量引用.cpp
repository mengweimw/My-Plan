#include <iostream>
using namespace std;

//!< 形参增加了const修饰，所指向的内容就不可以被更改，防止误操作
void showValue(const int& val)
{
    //!< 形参增加了const修饰，所指向的内容就不可以被更改，防止误操作
    // val = 1000;
    cout << "val = " << val << endl;
}

int main()
{
    int a = 10;
    int& ref = a;

    showValue(a);

    return 0;

}