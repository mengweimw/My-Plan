#include <iostream>
#include <string>
using namespace std;

class Student 
{
public:
    string name;        //!< 姓名
    string id;          //!< 学号


    void setStudent(string in_name, string in_id)
    {
        name = in_name;
        id = in_id;
    }
    void showStudent()
    {
        cout << "name: " << name << "   id: " << id << endl;
    }
};

int main()
{
    Student stu;
    stu.setStudent("mengwei", "1881120011");
    stu.showStudent();

    return 0;
}