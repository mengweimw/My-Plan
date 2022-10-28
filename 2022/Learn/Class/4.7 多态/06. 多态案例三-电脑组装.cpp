#include <iostream>
using namespace std;

class CPU
{
public:
    virtual void calculate() = 0;
};

class DisplayCard
{
public:
    virtual void display() = 0;
};

class RAM
{
public:
    virtual void storage() = 0;
};

class Computer
{
public:
    Computer()
    {
        cout << "Computer's default creator called" << endl;
    }
    Computer(CPU* cpu, DisplayCard* display, RAM* ram)
    {
        cout << "Computer's has param creator called" << endl;
        this->m_CPU = cpu;
        this->m_Display = display;
        this->m_RAM = ram;

    }
    //!< 提供一个析构函数，来释放三个零件
    virtual ~Computer()
    {
        cout << "Computer's destory called" << endl;
        if (NULL != m_CPU)
        {
            delete m_CPU;
            m_CPU = NULL;
        }

        if (NULL != m_Display)
        {
            delete m_Display;
            m_Display = NULL;
        }

        if (NULL != m_RAM)
        {
            delete m_RAM;
            m_RAM = NULL;
        }
    }

    string* m_Vendor;
    void work()
    {
        m_CPU->calculate();
        m_Display->display();
        m_RAM->storage();
    }
private:
    CPU* m_CPU;
    DisplayCard* m_Display;
    RAM* m_RAM;
};

class IntelCPU:public CPU
{
public:
    virtual void calculate()
    {
        cout << "Intel CPU Got CPU calculate successed" << endl;
    }
};

class IntelDisplayCard:public DisplayCard
{
public:
    virtual void display()
    {
        cout << "Intel DisplayCard Got Display display successed" << endl;
    }
};
    
class IntelRAM:public RAM
{
    virtual void storage()
    {
        cout << "Intel RAM Got RAM storage successed" << endl;
    }
};

class LenoveCPU:public CPU
{
public:
    virtual void calculate()
    {
        cout << "Lenove CPU Got CPU calculate successed" << endl;
    }
};

class LenoveDisplayCard:public DisplayCard
{
public:
    virtual void display()
    {
        cout << "Lenove DisplayCard Got Display display successed" << endl;
    }
};
    
class LenoveRAM:public RAM
{
    virtual void storage()
    {
        cout << "Lenove RAM Got RAM storage successed" << endl;
    }
};

class DellCPU:public CPU
{
public:
    virtual void calculate()
    {
        cout << "Dell CPU Got CPU calculate successed" << endl;
    }
};

class DellDisplayCard:public DisplayCard
{
public:
    virtual void display()
    {
        cout << "Dell DisplayCard Got Display display successed" << endl;
    }
};
    
class DellRAM:public RAM
{
    virtual void storage()
    {
        cout << "Dell RAM Got RAM storage successed" << endl;
    }
};

void test01()
{
    //!< 第一台电脑的零件
    CPU* intelCPU = new IntelCPU;
    DisplayCard* intelDisplayCard = new IntelDisplayCard;
    RAM* intelRAM = new IntelRAM;

    //!< 创建第一台电脑
    Computer* intelComputer = new Computer(intelCPU, intelDisplayCard, intelRAM);
    intelComputer->work();
    delete intelComputer;


    //!< 创建第二台电脑
    Computer* lenoveComputer = new Computer(new LenoveCPU, new LenoveDisplayCard, new LenoveRAM);
    lenoveComputer->work();
    delete lenoveComputer;

    //!< 创建第三台电脑
    Computer* dellComputer = new Computer(new DellCPU, new DellDisplayCard, new DellRAM);
    dellComputer->work();
    delete dellComputer;

}

// class PackageComputer:public Computer
// {
// public:
//     PackageComputer(string vendor)
//     {
//         cout << "PackageComputer's creator's called" << endl;
//         m_Vendor = new string(vendor);
//     }

//     ~PackageComputer()
//     {
//         cout << "PackageComputer's destory called" << endl;
//         if (NULL != m_Vendor)
//         {
//             delete m_Vendor;
//             m_Vendor = NULL;
//         }
//     }
// };

// void test01()
// {
//     Computer* pc = new PackageComputer("Intel");

// }

int main()
{
    test01();
    return 0;
}