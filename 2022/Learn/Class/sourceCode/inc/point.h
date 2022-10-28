#pragma once
#include <iostream>
using namespace std;

class Point
{
private:
    int m_X;      //!< X坐标
    int m_Y;      //!< Y坐标
public:
    void setX(int X);
    int getX();
    void setY(int Y);
    int getY();

};