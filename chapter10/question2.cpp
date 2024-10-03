/*
Update the following program to use type aliases for degrees and radians values:
*/

#include <iostream>


namespace constants
{
    constexpr double pi { 3.14159 };
}

using AliasDegrees = double;
using AliasRadians = double;

double convertToRadians(AliasDegrees degrees)
{
    return degrees * constants::pi / 180;
}

int main()
{
    std::cout << "Enter a number of degrees: ";
    AliasDegrees degrees{};
    std::cin >> degrees;

    AliasRadians radians { convertToRadians(degrees) };
    std::cout << degrees << " degrees is " << radians << " radians.\n";

    return 0;
}