#include <iostream>
using namespace std;
#include <string>

class Building;

class Goodgay
{
public:
    void visit();   //!< 参观函数访问Building中的公共和私有属性
    Goodgay();
    Building* building;
};

//!< 类做友元
class Building
{
    friend class Goodgay;   //!< Goodgay 是本类的友元，可以访问本类的私有成员
public:
    Building();
public:
    string m_SittingRoom;

private:
    string m_BedRoom;
};

//!< 类外写成员函数
Building::Building()
{
    m_SittingRoom = "sittingRoom";
    m_BedRoom = "bedRoom";
}

Goodgay::Goodgay()
{
    //创建 Building 对象
    building = new Building;
}

void Goodgay::visit()
{
    cout << "Goodgay is accessing to: " << building->m_SittingRoom << endl;

    cout << "Goodgay is accessing to: " << building->m_BedRoom << endl;
}

void test01()
{
    Goodgay gg;
    gg.visit();
}
    

int main()
{

    test01();
    return 0;
}