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
    case pig: return "2";
    case chicken: return "2";
    case goat: return "4";
    case cat: return "4";
    case dog: return "4";
    case duck; return "4";

    default: return "???";

    }
}



int main(){

    Animal nbpatte{ Animal::cat };

    std::cout << "l'animal à " << getAnimal(nbpatte) << "\n";

    return 0;
}