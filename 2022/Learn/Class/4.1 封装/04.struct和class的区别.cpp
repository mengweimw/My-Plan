#include <iostream>
#include <string>
using namespace std;

//!< struct 和 class的区别
//!< struct 默认是公共权限，public
//!< class 默认是私有权限，private

class C1
{
    int m_A;    //!< 默认权限是private
};

struct C2
{
    int m_A;    //!< 默认权限是public
};

int main()
{
    C1 c1;
    // c1.m_A = 100;    //!< 类外不可访问

    C2 c2;
    c2.m_A = 100;       //!< 类外可以访问

    return 0;
}