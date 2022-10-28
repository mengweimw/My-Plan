#include <iostream>
using namespace std;

const double PI = 3.1415926;    //!< PI

//!< 设计一个圆类，求圆的周长
//!< 圆求周长的公式 2 * PI * 半径


//!< class代表要设计一个类，类后面紧跟着类的名称
class Circle {
    //!< 访问权限
public:     //!< 公共权限
    //!< 属性，用变量
    double m_r; //!< 半径
    //!< 行为，用函数
    double calculateZC()
    {
        return 2 * PI * m_r;
    }
} ;

int main()
{
    //!< 通过圆类创建一个具体的对象，圆（对象）
    //!< 实例化一个对象
    Circle circle;
    circle.m_r = 10000;

    cout << "ZC: " << circle.calculateZC() << endl;

    return 0;
}