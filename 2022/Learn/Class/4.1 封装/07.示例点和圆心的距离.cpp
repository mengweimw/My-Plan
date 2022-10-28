#include "circle.h"

//!< 判断点和圆的关系
void isInCircle(Circle& c, Point& p)
{
    //!< 计算两点之间距离，平方
    int distance = (c.getCenter().getX() - p.getX()) * (c.getCenter().getX() - p.getX())  + 
                   (c.getCenter().getY() - p.getY()) * (c.getCenter().getY() - p.getY());

    int rDistance = c.getm_R() * c.getm_R();

    if (distance > rDistance)
    {
        cout << "Point out circle" << endl;
    }
    else if (distance == rDistance)
    {
        cout << "Point on circle" << endl;
    }
    else
    {
        cout << "Point in circle" << endl;
    }

    return;
}

int main()
{
    Circle c;
    c.setm_R(10);
    //!< 在类中，可以让另一个类作为本类中的成员
    Point center;
    center.setX(10);
    center.setY(0);
    c.setCenter(center);

    Point p;
    p.setX(10);
    p.setY(110);

    isInCircle(c, p);

    return 0;

}