#include <iostream>
using namespace std;

class Person 
{
public:
    /** 构造函数的分类  */
    //!< 无参构造函数 或 默认构造函数
    Person()
    {
        cout << "No param creator!" << endl;
    }

    //!< 有参构造函数
    Person(int a)
    {
        age = a;
        cout << "Has param creator!" << endl;
    }

    //!< 拷贝构造函数，形参为：引用常量，不可以修改此数据
    Person(const Person& p)
    {
        //!< 将传入的人身上的所有属性，copy到此人的身上
        age = p.age;
        cout << "Copy creator" << endl;
    }

    ~Person()
    {
        cout << "Destory Persom" << endl;
    }
    int getAge()
    {
        return age;
    }

private:
    int age;
};

//!< 调用
//!< 括号法
//!< 分类法
//!< 隐式转换法
void test01()
{
    //!< 括号法
    Person p1;   //!< 默认构造函数
    Person p2(100); //!< 调用有参构造函数
    Person p3(p2);
    //!< 注意：
    //!< 1. 调用默认构造函数时候，不要加()，
    // Person p1();     //!< 此处不会创建对象，因为编译器会认为这是一个函数的声明
    cout << "p2 age: " << p2.getAge() << endl;
    cout << "p3 age: " << p3.getAge() << endl;
    
    //!< 显示法
    Person p4;                  //!< 无参
    Person p5 = Person(100);    //!< 有参
    Person p6 = Person(p5);     //!< 显示

    Person(100);  //!< 匿名对象，特点：当前行执行结束后，系统会立即回收掉匿名对象
    //!< 注意：
    //!< 2. 不要使用拷贝构造函数来初始化匿名对象，编译器会认为 Persion(p5) === Person p5; 编译器会认为这是一个变量声明
    // Person(p5);      //!< 会报重定义

    //!< 隐式转换法
    Person p6 = 10;     //!< 相当于写了 Person p6 = Person(10);     有参构造
    Person p7 = p6;     //!< 相当于写了 Person p7 = Person(p6);     有参构造

}

int main()
{
    test01();

    return 0;
}