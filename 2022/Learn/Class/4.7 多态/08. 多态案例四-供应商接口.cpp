#include <iostream>
using namespace std;

//!< 创建零件基类，CPU
class CPU
{
public:
    //!< 拥有计算能力
    virtual void calculate() = 0;
    //!< 算力
    virtual void hertz() = 0;
    long long int m_hertz;
};

//!< 创建显卡基类，VideoCard
class VideoCard
{
public:
    //!< 拥有显示的能力
    virtual void display() = 0;
    //!< 算力
    virtual void hertz() = 0;
    double m_size; //!< GB
};

//!< 创建内存基类，Memroy
class Memroy
{
public:
    //!< 用于存储的能力
    virtual void storage() = 0;
    //!< 存储空间，单位：GB
    virtual void spaceSize() = 0;
    double m_size;
};

//!< 电脑的基类
class Computer
{
public:
    Computer(CPU* cpu, VideoCard* vc, Memroy* mm, string* name)
    {
        this->m_CPU = cpu;
        this->m_Mm = mm;
        this->m_Vc = vc;
        this->name = name;
    }
    ~Computer()
    {
        cout << "Computer's destory called" << endl;
        if (NULL != this->m_CPU) 
        {
            delete this->m_CPU;
            this->m_CPU = NULL;
        }

        if (NULL != this->m_Mm)
        {
            delete this->m_Mm;
            this->m_Mm = NULL;
        }

        if (NULL != this->m_Vc)
        {
            delete this->m_Vc;
            this->m_Vc = NULL;
        }
        
        if (NULL != this->name)
        {
            delete this->name;
            this->name = NULL;
        }

    }

    void doWork()
    {
        cout << "This " << *this->name << " is working......" << endl;
        this->m_CPU->calculate();
        this->m_CPU->hertz();
        this->m_Mm->spaceSize();
        this->m_Mm->storage();
        this->m_Vc->hertz();
        this->m_Vc->display();
    }

private:
    CPU* m_CPU;
    VideoCard* m_Vc;
    Memroy* m_Mm;
    string* name;
};

class IntelCPU:public CPU
{
public:
    IntelCPU(long long int hertzSize)
    {
        this->m_hertz = hertzSize;
    }
    //!< 拥有计算能力
    virtual void calculate()
    {
        cout << "Intel cpu is calculate ing ..." << endl;
    }
    //!< 算力
    virtual void hertz()
    {
        cout << "Intel cpu hertz " << this->m_hertz << "HZ" << endl;
    }
};

class IntelVideoCard:public VideoCard
{
public:
    IntelVideoCard(double size)
    {
        m_size = size;
    }
    //!< 拥有显示的能力
    virtual void display()
    {
        cout << "Intel video card is working..." << endl;
    }
    //!< 算力
    virtual void hertz()
    {
        cout << "Intel video card hertz: " << this->m_size << " GB" << endl;
    } 
};

class IntelMemroy:public Memroy
{
public:
    IntelMemroy(double size)
    {
        m_size = size;
    }
    //!< 拥有显示的能力
    virtual void storage()
    {
        cout << "Intel Memroy is working..." << endl;
    }
    //!< 算力
    virtual void spaceSize()
    {
        cout << "Intel Memroy hertz: " << this->m_size << " GB" << endl;
    }
};

class DellCPU:public CPU
{
public:
    DellCPU(long long int hertzSize)
    {
        this->m_hertz = hertzSize;
    }
    //!< 拥有计算能力
    virtual void calculate()
    {
        cout << "Dell cpu is calculate ing ..." << endl;
    }
    //!< 算力
    virtual void hertz()
    {
        cout << "Dell cpu hertz " << this->m_hertz << "HZ" << endl;
    }
};

class DellVideoCard:public VideoCard
{
public:
    DellVideoCard(double size)
    {
        m_size = size;
    }
    //!< 拥有显示的能力
    virtual void display()
    {
        cout << "Dell video card is working..." << endl;
    }
    //!< 算力
    virtual void hertz()
    {
        cout << "Dell video card hertz: " << this->m_size << " GB" << endl;
    } 
};

class DellMemroy:public Memroy
{
public:
    DellMemroy(double size)
    {
        m_size = size;
    }
    //!< 拥有显示的能力
    virtual void storage()
    {
        cout << "Dell Memroy is working..." << endl;
    }
    //!< 算力
    virtual void spaceSize()
    {
        cout << "Dell Memroy hertz: " << this->m_size << " GB" << endl;
    }
};


void test01()
{
    //!< 组装第一台电脑，先构建零件
    CPU* cpu = new IntelCPU(1024);
    VideoCard* vc = new IntelVideoCard(2);
    Memroy* mm = new IntelMemroy(256);
    string* name = new string("Intel");

    Computer* pc = new Computer(cpu, vc, mm, name);
    pc->doWork();
    delete pc;

    cout << "-----------------------------------------------------------------" << endl;

    Computer*pc1 = new   Computer(new DellCPU(2048), new DellVideoCard(4), new DellMemroy(512), new string("Dell"));
    pc1->doWork();
    delete pc1;
}

int main()
{
    test01();
    return 0;
}