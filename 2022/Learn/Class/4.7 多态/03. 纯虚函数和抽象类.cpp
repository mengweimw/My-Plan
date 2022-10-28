#include <iostream>
using namespace std;

class AbstractCalculator
{
public:
    //!< 纯虚函数
    //!< 只要有一个纯虚函数，这个类成为抽象类
    //!< 抽象类的特点
    //!< 1. 无法实例化对象
    //!< 2. 抽象类的子类，必须要重写父类中的纯虚函数，否则也属于抽象类
    virtual int getResult(int a, int b) = 0;
    int m_A;
    int m_B;
};

class AddCalculator:public AbstractCalculator
{
public:
    virtual int getResult(int a, int b)
    {
        return m_A + m_B + a + b;
    }
};

class SubCalculator:public AbstractCalculator
{
public:
    virtual int getResult(int a, int b)
    {
        return m_A - m_B - a - b;
    }
};

class MulCalculator:public AbstractCalculator
{
public:
    virtual int getResult(int a, int b)
    {
        return m_A * m_B * a * b;
    }
};

int calculator(AbstractCalculator& abc, int a, int b)
{
    return abc.getResult(a, b);
}

void test01()
{
    // AbstractCalculator abc;  //!< 抽象类是无法实例化对象的
    // new AbstractCalculator;

    // AddCalculator add;
    // add.m_A = 1000;
    // add.m_B = 1000;
    // int a = 10;
    // int b = 10;
    // cout << calculator(add, a, b) << endl;

    AbstractCalculator* abc = new AddCalculator;
    abc->m_A = 10;
    abc->m_B = 10;
    int a = 10;
    int b = 10;
    cout << abc->getResult(a, b) << endl;
}

int main()
{
    test01();
    return 0;
}