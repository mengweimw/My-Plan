#include <iostream>
using namespace std;

class Person
{
public:
    Person()
    {
        cout << "Person creator called" << endl;
    }

    ~Person()
    {
        cout << "~Person destory called" << endl;
    }
};

void test01()
{
    Person p;
}

int main()
{
    test01();

    return 0;
}   