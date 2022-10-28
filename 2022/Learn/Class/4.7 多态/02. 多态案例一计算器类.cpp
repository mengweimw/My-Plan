#include <iostream>
using namespace std;
#include <string>

// //!< 普通写法
// class Calculator
// {
// public:
//     int getResult(string oper)
//     {
//         if ("+" == oper)
//         {
//             return m_Num1 + m_Num2;
//         }
//         else if ("=" == oper)
//         {
//             return m_Num1 - m_Num2;
//         }
//         else if ("*" == oper)
//         {
//             return m_Num1 * m_Num2;
//         }
//         return 0;
//         //!< 如果想扩展新的功能，需要增加源码
//         //!< 在真实的开发中，提供开闭原则，
//             //!< 对扩展进行开放，对修改进行关闭
//     }

//     int m_Num1;     //!< 操作数1
//     int m_Num2;     //!< 操作数2
// };

// void test01()
// {
//     Calculator c;
//     c.m_Num1 = 10;
//     c.m_Num2 = 10;

//     cout << "c.m_Num1 + c.m_Num2 = " << c.getResult("+") << endl;
// }

//!< 多态写法
//!< 多态的好处
//!< 1. 组织结构清晰
//!< 2. 可读性强
//!< 3. 对于前期和后期的扩展以及维护性强
class AbstractCalculator
{
public:
    //!< 多态的实现，需要在子类重写，所以此处需要用virtual修饰
    virtual int getResult()
    {
        return 0;
    }
    int m_Num1;
    int m_Num2;
};

class AddCalculator:public AbstractCalculator
{
public:
    //!< 重写成员函数，实现数字相加
    int getResult()
    {
        return m_Num1 + m_Num2;
    }
};

class SubCalculator:public AbstractCalculator
{
public:
    //!< 重写成员函数，实现数字相减
    int getResult()
    {
        return m_Num1 - m_Num2;
    }
};

class MulCalculator:public AbstractCalculator
{
public:
    //!< 重写成员函数，实现数字相乘
    int getResult()
    {
        return m_Num1 * m_Num2;
    }
};

class DivisionCalculator:public AbstractCalculator
{
public:
    //!< 重写成员函数，实现数字相乘
    int getResult()
    {
        if (0 != m_Num2)
        {
            return m_Num1 / m_Num2;
        }

        return -1;
    }
};

void test02()
{
    //!< 多态的使用条件
    //!< 父类的指针或者引用指向子类的对象
    AbstractCalculator* abc = NULL;
    //!< 创建父类对象，使用子类对象new
    abc = new AddCalculator;
    abc->m_Num1 = 10;
    abc->m_Num2 = 20;
    cout << "abc->m_Num1 + abc->m_Num2 = " << abc->getResult() << endl;
    delete abc;

    abc = new SubCalculator;
    abc->m_Num1 = 20;
    abc->m_Num2 = 10;
    cout << "abc->m_Num1 - abc->m_Num2 = " << abc->getResult() << endl;
    delete abc;

    abc = new MulCalculator;
    abc->m_Num1 = 100;
    abc->m_Num2 = 100;
    cout << "abc->m_Num1 * abc->m_Num2 = " << abc->getResult() << endl;
    delete abc;
}


int main()
{
    // test01();
    test02();
    return 0;
}