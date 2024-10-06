/*
In designing a game, we decide we want to have monsters, because everyone likes fighting monsters. Declare a struct that represents your monster. 
The monster should have a type that can be one of the following: an ogre, a dragon, an orc, a giant spider, or a slime.

Each individual monster should also have a name (use a std::string or std::string_view), 
as well as an amount of health that represents how much damage they can take before they die. 
Write a function named printMonster() that prints out all of the struct’s members. Instantiate an ogre and a slime, initialize them using an initializer list, and pass them to printMonster().

Your program should produce the following output:

This Ogre is named Torg and has 145 health.
*/


#include <iostream>
#include <string>
#include <string_view> // C++17

// Our monster struct represents a single monster
// We use std::string_view here because we're making a design decision that the monster's name
// will always be set from a C-style string literal and does not need to be modified

struct Monster
{
	// Define our different monster types as an enum
	enum Type
	{
		ogre,
		dragon,
		orc,
		giant_spider,
		slime,
	};

	Type type{};
	std::string_view name{};
	int health{};
};

// Return the name of the monster's type as a string
// Since this could be used elsewhere, it's better to make this its own function
constexpr std::string_view getMonsterTypeString(Monster::Type type)
{
	switch (type)
	{
	case Monster::ogre:          return "Ogre";
	case Monster::dragon:        return "Dragon";
	case Monster::orc:           return "Orc";
	case Monster::giant_spider:  return "Giant Spider";
	case Monster::slime:         return "Slime";
	}

	return "Unknown";
}

// Print our monster's stats
void printMonster(const Monster& monster)
{
	std::cout << "This " << getMonsterTypeString(monster.type) <<" is named " << monster.name << " and has " << monster.health << " health.\n";
}

int main()
{
	Monster ogre{ Monster::ogre, "Torg", 145 };
	Monster slime{ Monster::slime, "Blurp", 23 };

	printMonster(ogre);
	printMonster(slime);

	return 0;
}