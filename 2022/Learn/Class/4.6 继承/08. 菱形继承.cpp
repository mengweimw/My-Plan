#include <iostream>
using namespace std;

class Animal
{
public:
    int m_Age;
};

//!< 利用虚继承可以解决菱形继承的问题
//!< 在继承前面加上virtual，变为虚继承
//!< Anmial 类为虚基类
class Sheep:virtual public Animal
{
public:

};

class Tuo:virtual public Animal
{
public:

};

class SheepTuo:public Sheep, public Tuo
{
public:
};

void test01()
{
    SheepTuo st;

    st.Sheep::m_Age = 99;
    st.Tuo::m_Age = 89;

    //!< 当菱形继承的时候，两个父类拥有相同的数据，需要加以作用域区分
    cout << "st.Sheep::m_Age: " << st.Sheep::m_Age << endl;
    cout << "st.Tuo::m_Age: " << st.Tuo::m_Age << endl;
    cout << "st.m_Age: " << st.m_Age << endl;

    //!< 这份数据我们只需要一份，菱形继承导致这份数据有两份，资源浪费
    cout << sizeof(st) << endl;

}

int main()
{
    test01();

    return 0;
}