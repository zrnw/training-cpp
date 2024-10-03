/*
Define an enum class named Animal that contains the following animals: pig, chicken, goat, cat, dog, duck.
Write a function named getAnimalName() that takes an Animal parameter and uses a switch statement to return the name for that animal
as a std::string_view (or std::string if you’re using C++14). Write another function named printNumberOfLegs()
that uses a switch statement to print the number of legs each animal walks on. Make sure both functions have a default case that prints an error message.
Call printNumberOfLegs() from main() with a cat and a chicken. Your output should look like this:
*/

#include <iostream>
#include <string_view>

enum class Animal
{

    pig,
    chicken,
    goat,
    cat,
    dog,
    duck,


};


constexpr std::string_view getAnimal(Animal animal)
{

    using enum Animal;

    switch (animal)
    {
    case pig: return "pig";
    case chicken: return "chicken";
    case goat: return "goat";
    case cat: return "cat";
    case dog: return "dog";
    case duck: return "duck";

        default: return "???";

    }
}

void printNumberOflegs(Animal animal)
{

    using enum Animal;

    std::cout << "A " << getAnimal(animal) << " has ";

    switch (animal)
    {
    case duck:;
    case chicken: ;
        std::cout << "2 \n";
        break;
    case goat: ;
    case pig:;
    case cat: ;
    case dog: ;
        std::cout << "4 \n";
        break;
    }
}

int main() {

    printNumberOflegs(Animal::cat);
    printNumberOflegs(Animal::chicken);


    return 0;
}
