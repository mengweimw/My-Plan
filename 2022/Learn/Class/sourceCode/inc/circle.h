#pragma once
#include <iostream>
#include "point.h"
using namespace std;

//!< 定义圆类
class Circle
{
private:
    int m_R;         //!< 圆的半径
    Point m_center;            //!< 圆心
public:
    void setm_R(int R);
    int getm_R(void);
    void setCenter(Point center);
    Point getCenter();
};