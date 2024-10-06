/*
a) Write a class named Point3d. The class should contain:

Three private member variables of type int named m_x, m_y, and m_z;
A public member function named setValues() that allows you to set values for m_x, m_y, and m_z.
A public member function named print() that prints the Point in the following format: <m_x, m_y, m_z>

This should print:

<1, 2, 3>

b) Add a function named isEqual() to your Point3d class. The following code should run correctly:

This should print:

point 1 and point 2 are equal
point 1 and point 3 are not equal

*/

#include <iostream>

class Point3d
{
public:
    void setValues(int v1, int v2, int v3)
    {
        m_x = v1;
        m_y = v2;
        m_z = v3;
    }

    void print() const
    {
        std::cout << "<" << m_x << ", " << m_y << ", " << m_z << ">";

    }

    bool isEqual(Point3d a)
    {

        return (m_x == a.m_x && m_y == a.m_y && m_z == a.m_z);
    }

private:
    int m_x{};
    int m_y{};
    int m_z{};
};

int main()
{
    Point3d point1{};
    point1.setValues(1, 2, 3);

    Point3d point2{};
    point2.setValues(1, 2, 3);

    std::cout << "point 1 and point 2 are" << (point1.isEqual(point2) ? "" : " not") << " equal\n";

    Point3d point3{};
    point3.setValues(3, 4, 5);

    std::cout << "point 1 and point 3 are" << (point1.isEqual(point3) ? "" : " not") << " equal\n";

    return 0;
}