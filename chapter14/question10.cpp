/*
b) Now add a member function named distanceTo() that takes another Point2d as a parameter, 
and calculates the distance between them. Given two points (x1, y1) and (x2, y2), 
the distance between them can be calculated using the formula std::sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2)). The std::sqrt function lives in header cmath.

This should print:

Point2d(0, 0)
Point2d(3, 4)
Distance between two points: 5
*/

#include <cmath>
#include <iostream>

class Point2d
{
public:

    Point2d() = default;

    Point2d(double x, double y)
        : m_x{ x }, m_y{ y }
    {
    }

    void print() const
    {
        std::cout << "Poin2d(" << m_x << ", " << m_y << ")\n";

    }

    int distanceTo(const Point2d& a) const
    {

        return  std::sqrt((m_x - a.m_x) * (m_x - a.m_x) + (m_y - a.m_y) * (m_y - a.m_y));
    }


private:

    double m_x{ 0.0 };
    double m_y{ 0.0 };

};




int main()
{
    Point2d first{};
    Point2d second{ 3.0, 4.0 };

    first.print();
    second.print();

    std::cout << "Distance between two points: " << first.distanceTo(second) << '\n';

    return 0;
}