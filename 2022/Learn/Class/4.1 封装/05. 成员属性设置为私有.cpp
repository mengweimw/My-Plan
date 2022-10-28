#include <iostream>
#include <string>
using namespace std;

//!< 成员属性设置为私有
//!< 1. 可以自己控制读写权限
//!< 2. 对于写可以检测数据的有效性
class Persom
{
public:
    void setName(string name)
    {
        m_name = name;
    }
    string getName()
    {
        return m_name;
    }

    void setAge(int age)
    {
        if (0 > age || 150 < age)
        {
            cout << "set age is " << age << " invalid" << endl;
            m_age = 0;
        } else {
            m_age = age;
        }
    }
    //!< 获取年龄，可读可写，如果想修改（年龄的范围必须是0~150之间）
    int getAge()
    {
        // m_age = 100;
        return m_age;
    }

    void setLover(string lover)
    {
        m_Lover = lover;
    }
    // string getLover()
    // {
    //     return m_Lover;
    // }

    // void showInformation()
    // {
    //     cout << "m_name: " << m_name << " m_age: " << m_age << " m_Lover: " << m_Lover << endl; 
    // }

private:
    //!< name，可读可写
    string m_name;
    //!< age，只读
    int m_age;
    //!< 情人，只写
    string m_Lover;


};

int main()
{
    Persom p1;
    p1.setName("zhangsan");
    cout << "name: " << p1.getName() << endl;

    p1.setAge(100);
    cout << "age: " << p1.getAge() << endl;

    p1.setLover("Lover");

    return 0;
}