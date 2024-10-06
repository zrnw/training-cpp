/*
a) Write a class named Point3d. The class should contain:

Three private member variables of type int named m_x, m_y, and m_z;
A public member function named setValues() that allows you to set values for m_x, m_y, and m_z.
A public member function named print() that prints the Point in the following format: <m_x, m_y, m_z>

This should print:

<1, 2, 3>
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

private:
    int m_x{};
    int m_y{};
    int m_z{};
};


int main()
{
    Point3d point;
    point.setValues(1, 2, 3);

    point.print();
    std::cout << '\n';

    return 0;
}