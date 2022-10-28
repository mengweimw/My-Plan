#include <iostream>
using namespace std;

class Person;

class Student
{
public:
    Student();
    ~Student();
    void GetInformation();
    Person* person;
};

class Person
{
    friend void Student::GetInformation();  //!< 类成员函数做友元
    friend void getInformation(Student* s); //!< 全局函数作为友元
    friend class Student;       //!< 类作为友元，也需要通过类里的成员函数访问

public:
    Person();
    ~Person();
    string m_name;

private:
    int m_age;
};

Student::Student()
{
    person = new Person; 
}

Student::~Student()
{
    if (NULL != person)
    {
        delete person;
    }
}

void Student::GetInformation()
{
    cout << "Person name " << person->m_name << endl;
    cout << "Person age " << person->m_age << endl;
}

Person::Person()
{
    m_name = "zhangsan";
    m_age = 100;
}

Person::~Person()
{
    return;
}

void test01()
{
    Student s;
    s.GetInformation();
}


void getInformation(Student* s)
{
    cout << "Person name: " << s->person->m_name << endl;
    cout << "Person age: " << s->person->m_age << endl;
}

void test02()
{
    Student s;
    getInformation(&s);
}


void test03()
{
    Student s;
    s.GetInformation();
}

int main()
{
    test01();
    test02();
    test03();
    
    return 0;
}