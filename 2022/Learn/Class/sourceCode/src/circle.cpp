#include "circle.h"


void Circle::setm_R(int R)
{
    m_R = R;
}

int Circle::getm_R(void)
{
    return m_R;
}
void Circle::setCenter(Point center)
{
    m_center = center;
}
Point Circle::getCenter()
{
    return m_center;
}