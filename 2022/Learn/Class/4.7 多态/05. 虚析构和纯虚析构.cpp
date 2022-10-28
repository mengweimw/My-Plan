#include <iostream>
using namespace std;

class Animal
{
public:
    Animal()
    {
        cout << "Animal's creator called" << endl;
    }
    //!< 利用虚析构可以解决父类指针释放子类对象释放不干净的问题
    // virtual ~Animal()
    // {
    //     cout << "Animal's destory called " << endl;
    // }
    //!< 纯虚析构, 需要声明也需要实现
    //!< 有了纯虚析构之后，这个类也属于抽象类，无法实例化对象
    virtual ~Animal() = 0;
    virtual void speak() = 0;
    string* m_Name;
};

Animal::~Animal()
{
    cout << "Animal's virtual destory called " << endl;
}

class Cat:public Animal
{
public:
    Cat(string name)
    {
        cout << "Cat's creator called" << endl;
        m_Name = new string(name);
    }

    virtual void speak()
    {
        cout << "Cat: "<< *m_Name << " is speaking" << endl; 
    }
    ~Cat()
    {
        if (NULL != m_Name)
        {
            cout << "Cat's destory called" << endl;
            delete m_Name;
            m_Name = NULL;
        }
    }
};

void test01()
{
    Animal* a = new Cat("Tom");
    a->speak();
    //!< 父类的指针在析构的时候，不会调用子类中的析构，导致子类如果有堆区属性，出现内存泄漏
    delete a;
}

int main()
{
    test01();
    return 0;
}