#include <iostream>
using namespace std;

class Animal
{
public:
    virtual void speak()
    {
        cout << "Animal are speaking~~~" << endl;
    }
};

class Cat:public Animal
{
public:
    //!< 重写 函数的返回值类型和参数列表完全相同
    void speak()
    {
        cout << "Cat are speaking~~~" << endl;
    }
};

class Dog:public Animal
{
public:
    void speak()
    {
        cout << "Dog are speaking~~~" << endl;
    }
};

//!< 执行说话的函数
//!< 地址早绑定，在编译阶段就确定了函数的地址为 Animal下的speak函数
//!< 如果想执行 Cat类下的speak，此地址就不能早绑定，需要在运行时绑定，即：地址晚绑定;  父类里的speak变为虚函数，就可以访问子类里的speak函数了

//!< 动态多态的满足条件：
//!< 1. 有继承关系
//!< 2. 子类重写父类的函数，例如：这里子类重写了speak函数

//!< 动态多态的使用：
//!< 父类的指针或引用，指向子类的对象
void doSpeak(Animal& animal)    //!< Animal& = Cat;
{
    animal.speak();
}

void test01()
{
    Cat cat;
    doSpeak(cat);

    Dog dog;
    doSpeak(dog);
}

void test02()
{
    //!< virtual 去掉之后，占用 1 个字节，因为非静态成员函数，不属于类内，是分开存储的
    //!< virtual 加上之后，占用 8 个字节（64位系统），因为这里有个指针；vfptr: virtual function pointer
    cout << "sizeof animal: " << sizeof(Animal) << endl;
}

int main()
{
    test01();
    test02();
    return 0;
}