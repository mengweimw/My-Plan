#include <iostream>
using namespace std;


class Building
{
    //!< goodGay 全局函数是Building的好朋友，可以访问Building中的私有成员
    friend void goodGay(Building* building);
public:
    Building()
    {
        m_SittingRoom = "SittingRoom";
        m_BedRoom = "BedRoom";
    }
    string m_SittingRoom;
private:
    string m_BedRoom;
};

//!< 全局函数
void goodGay(Building* building)
{
    cout << "Good gay's global function access to: " << building->m_SittingRoom << endl;

    cout << "Good gay's global function access to: " << building->m_BedRoom << endl;
}


int main()
{
    Building building;

    goodGay(&building);

    return 0;
}