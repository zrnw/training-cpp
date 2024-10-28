/*
Using a std::vector, write a program that asks the user to enter 3 integral values. Print the sum and product of those values.

The output should match the following:

Enter 3 integers: 3 4 5
The sum is: 12
The product is: 60
*/

#include <iostream>
#include <vector>

int main()
{
	std::cout << "enter 3 integers: ";
	std::vector<int> value(3);

	std::cin >> value[0] >> value[1] >> value[2];

	std::cout << "The sum is: " << value[0] + value[1] + value[2] << "\nThe product is: " << value[0] * value[1] * value[2] << "\n";
}