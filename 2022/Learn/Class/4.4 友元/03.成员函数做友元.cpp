#include <iostream>
using  namespace std;

class Building;

class Goodgay
{
public:
    Goodgay();
    ~Goodgay();
    void visitor();       //!< visit 可以访问Building 中的私有成员
    void visitor2();        //!< visitor 不可以访问Building中的私有成员

    Building* building;
};

class Building
{
    friend void Goodgay::visitor();
public:
    Building();
    ~Building();
    string m_sittingRoom;
private:
    string m_bedRoom;
};

Goodgay::Goodgay()
{
    building = new Building;
}

Goodgay::~Goodgay()
{
    if (NULL != building)
    {
        delete building;
    }
}

Building::Building()
{
    m_sittingRoom = "sittingRoom";
    m_bedRoom = "bedRoom";
}

Building::~Building()
{
    return;
}

void Goodgay::visitor()
{
    cout << "vistor access to " << building->m_sittingRoom << endl;
    cout << "vistor access to " << building->m_bedRoom << endl;
}

void Goodgay::visitor2()
{
    cout << "visitor2 access to " << building->m_sittingRoom << endl;
    // cout << "visitor2 access to " << building->m_bedRoom << endl;    //!< 非友元函数，无法访问Building类中的私有成员
}

void test01()
{
    Goodgay gg;
    gg.visitor();
    gg.visitor2();
}

int main()
{
    test01();
    return 0;
}