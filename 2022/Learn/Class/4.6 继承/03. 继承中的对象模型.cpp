#include <iostream>
using namespace std;

//!< 继承中的对象模型
class Base
{
public:
    int m_A;
protected:
    int m_B;
private:
    int m_C;
};

//!< 父类中，所有的非静态成员属性，都会被子类继承
//!< 父类中，私有的成员属性是被编译器隐藏了，因此访问不到，但确实被继承了
class Son:public Base
{
public:
    int m_D;
};

void test01()
{
    //!< 4/12/16   结果 16
    cout << sizeof(Son) << endl;
}

int main()
{
    test01();
    return 0;

}