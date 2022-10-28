#include <iostream>
using namespace std;

//!< 普通页面实现

//!< Java页面
// class Java
// {
// public:
//     void header()
//     {
//         cout << "首页、公开课、登录、注册...(公共头部)" << endl;
//     }
//     void footer()
//     {
//         cout << "帮助中心、交流中心、站内地图...(公共底部)" << endl;
//     }
//     void left()
//     {
//         cout << "Java、Python、C++...(公共分类列表)" << endl;
//     }
//     void content()
//     {
//         cout << "Java 学科视频" << endl;
//     }

// };

// class Python
// {
// public:
//     void header()
//     {
//         cout << "首页、公开课、登录、注册...(公共头部)" << endl;
//     }
//     void footer()
//     {
//         cout << "帮助中心、交流中心、站内地图...(公共底部)" << endl;
//     }
//     void left()
//     {
//         cout << "Java、Python、C++...(公共分类列表)" << endl;
//     }
//     void content()
//     {
//         cout << "Python 学科视频" << endl;
//     }
// };

// class CPP
// {
// public:
//     void header()
//     {
//         cout << "首页、公开课、登录、注册...(公共头部)" << endl;
//     }
//     void footer()
//     {
//         cout << "帮助中心、交流中心、站内地图...(公共底部)" << endl;
//     }
//     void left()
//     {
//         cout << "Java、Python、C++...(公共分类列表)" << endl;
//     }
//     void content()
//     {
//         cout << "C++ 学科视频" << endl;
//     }
// };

//!< 继承的好处：减少重复的代码
//!< 语法：class 子类 : 继承方式 父类
//!< 子类也成为派生类，父类也成为基类

//!< 继承实现
class BasePage
{
public:
    void header()
    {
        cout << "首页、公开课、登录、注册...(公共头部)" << endl;
    }
    void footer()
    {
        cout << "帮助中心、交流中心、站内地图...(公共底部)" << endl;
    }
    void left()
    {
        cout << "Java、Python、C++...(公共分类列表)" << endl;
    }
};

class Java : public BasePage
{
public:
    void content()
    {
        cout << "Java 学科视频" << endl;
    }
};

class Python : public BasePage
{
public:
    void content()
    {
        cout << "Python 学科视频" << endl;
    }
};

class CPP : public BasePage
{
public:
    void content()
    {
        cout << "C++ 学科视频" << endl;
    }
};

void test01()
{
    cout << "Java 下载视频页面如下：" << endl;
    Java java;
    java.header();
    java.footer();
    java.left();
    java.content();

    cout << "Python 下载视频页面如下：" << endl;
    Python python;
    python.header();
    python.footer();
    python.left();
    python.content();

    cout << "C++ 下载视频页面如下：" << endl;
    CPP cpp;
    cpp.header();
    cpp.footer();
    cpp.left();
    cpp.content();
}

int main()
{
    test01();
    return 0;
}