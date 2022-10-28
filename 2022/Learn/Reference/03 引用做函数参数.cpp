#include <iostream>
using namespace std;

/** 值传递的方式，函数内使用的是局部变量，形参会交换数据，但不会对实参做交换 */
void swapValue(int a, int b)
{
    int temp = 0;
    temp = a;
    a = b;
    b = temp;
}

/** 地址传递的方式，函数内部使用的传入实参的地址，对实参的地址操作，可以对实参进行交换 */
void swapAddress(int *a, int *b)
{
    int temp = 0;
    temp = *a;
    *a = *b;
    *b = temp;
}

/** 引用传递的方式，函数内部使用的是实参的别名的方式，操作的是实参的地址，因此可以对实参进行交换 */
void swapReference(int& a, int& b)
{
    int temp = 0;
    temp = a;
    a = b;
    b = temp;
}


int main()
{
    int a = 10;
    int b = 20;

    swapReference(a ,b);

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    return 0;
}
