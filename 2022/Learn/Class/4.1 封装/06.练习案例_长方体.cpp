#include <iostream>
using namespace std;

class Cube
{
private:
    double w_length;
    double w_wide;
    double w_high;
public:
    void setInfo(double length, double wide, double high)
    {
        //!< 校验数据的有效性
        if (0 > length || 0 > wide || 0 > high)
        {
            cout << "length: " << length << "  || wide: " << wide << " high: " << high << " invalid!!" << endl;
            return;
        }

        w_length = length;
        w_high = high;
        w_wide = wide;

        return;
    }

    double calculatePerimeter()
    {
        return 2 * (((w_length * w_wide) + (w_length * w_high)));
    }

    double calculateVolume()
    {
        return w_length * w_wide * w_high;
    }

    //!< 成员函数只需要传入一个对象
    bool isCubeEQ(Cube& c1)
    {
        if (c1.getLength() == w_length && c1.getWide() == w_wide && c1.getHigh() == w_high)
        {
            cout << "Cube is equal" << endl;
            return true;
        }
        else
        {
            cout << "Cube is not equal" << endl;
            return false;
        }
    }

    double getLength()
    {
        return w_length;
    }

    double getWide()
    {
        return w_wide;
    }

    double getHigh()
    {
        return w_high;
    }
};

//!< 全局函数需要传入两个对象
bool isCubeEQ(Cube& c1, Cube& c2)
{
    if (c1.getLength() == c2.getLength() && c1.getWide() == c2.getWide() && c1.getHigh() == c2.getHigh())
    {
        cout << "Cube is equal" << endl;
        return true;
    }
    else
    {
        cout << "Cube is not equal" << endl;
        return false;
    }
}

int main()
{
    Cube cube1;
    cube1.setInfo(1, 2, 3);
    cout << "perimeter: " << cube1.calculatePerimeter() << endl;
    cout << "volume: " << cube1.calculateVolume() << endl;

    Cube cube2;
    cube2.setInfo(3, 4, 5);
    cout << "perimeter: " << cube2.calculatePerimeter() << endl;
    cout << "volume: " << cube2.calculateVolume() << endl;

    cube1.isCubeEQ(cube2);

    isCubeEQ(cube1, cube2);

    return 0;
}