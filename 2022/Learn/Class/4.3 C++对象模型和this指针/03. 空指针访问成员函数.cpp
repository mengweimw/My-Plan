#include <iostream>
using namespace std;

class Person
{
public:
    void showClassName()
    {
        cout << "class name: Person" << endl;
    }

    void showPersonAge()
    {
        //!< 报错原因，是因为传入的指针为NULL
        if (NULL != this){
            cout << "Person age: " << this->age << endl;
        }
    }
    int age;
};

void test01()
{
    Person* p = NULL;

    p->showClassName();
    //!< this 是一个空指针
    p->showPersonAge();

}

int main()
{
    test01();
    return 0;
}