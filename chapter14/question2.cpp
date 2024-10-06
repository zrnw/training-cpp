/*
Update the animal OOP-like example above and instantiate a snake instead of a cat.
*/

#include <iostream>
#include <string_view>

struct Cat
{
    std::string_view name{ "cat" };
    int numLegs{ 4 };
};

struct Dog
{
    std::string_view name{ "dog" };
    int numLegs{ 4 };
};

struct Chicken
{
    std::string_view name{ "chicken" };
    int numLegs{ 2 };
};

struct Snake // modification here we add struct
{
    std::string_view name{ "snake" };
    int numLegs{ 0 };
};

int main()
{
    constexpr Snake animal; // modification here
    std::cout << "a " << animal.name << " has " << animal.numLegs << " legs\n";

    return 0;
}