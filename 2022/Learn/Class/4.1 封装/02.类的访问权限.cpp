#include <iostream>
#include <string>
using namespace std;


//!< 访问权限：
//!< 公共权限 public: 成员在类内可以访问，类外也可以访问
//!< 保护权限 protected: 成员在类内可以访问，类外不可以访问，儿子可以访问父亲中的保护的内容
//!< 私有权限 private: 成员在类内可以访问，类外不可以访问，儿子不可以访问父亲的私有内容

class Person
{
public:
    string m_name;
protected:
    string m_car;
private:
    string m_password;

public:
    void initInformation()
    {
        m_name = "zhangsan";            //!< 公共权限，类内可以访问
        m_car = "BYD";                  //!< 保护权限，类内可以访问
        m_password = "123456";          //!< 私有权限，类内可以访问
    }
};

int main()
{
    Person p1;
    p1.initInformation();
    p1.m_name = "lisi"; 
    // p1.m_car = "jike";       //!< 保护权限，类外不可以访问
    // p1.m_password = "111";   //!< 私有权限，类外不可以访问

    return 0;
}