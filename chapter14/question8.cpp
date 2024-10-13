/*
Write a class named Ball. Ball should have two private member variables, one to hold a color (default value: black), and one to hold a radius (default value: 10.0). 
Add 4 constructors, one to handle each case :
print:
Ball(black, 10)
Ball(blue, 10)
Ball(black, 20)
Ball(blue, 20)


*/

#include <iostream>
#include <string>
#include <string_view>

class Ball
{
private:
	std::string m_color{ "black" };
	double m_radius{ 10.0 };

public:
	// Handles Ball(radius)
	Ball(double radius)
		: Ball{ "black", radius } // delegate to the other constructor
	{
		// We don't need to call print() here since it will be called by
		// the constructor we delegate to
	}

	// Handles Ball(color, radius), Ball(color), and Ball()
	Ball(std::string_view color = "black", double radius = 10.0)
		: m_color{ color }
		, m_radius{ radius }
	{
		print();
	}

	void print() const
	{
		std::cout << "Ball(" << m_color << ", " << m_radius << ")\n";
	}
};

int main()
{
	Ball def{};
	Ball blue{ "blue" };
	Ball twenty{ 20.0 };
	Ball blueTwenty{ "blue", 20.0 };

	return 0;
}