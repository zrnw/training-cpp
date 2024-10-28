/*
Let’s say you’re writing a game where the player can hold 3 types of items: health potions, torches, and arrows.
*/

/*
Step #1

Define an unscoped enum in a namespace to identify the different types of items. Define an std::vector to store the number of each item type the player is carrying. 
The player should start with 1 health potion, 5 torches, and 10 arrows. Assert to make sure the array has the correct number of initializers.

Hint: Define a count enumerator and use it inside the assert.

The program should output the following:
You have 16 total items

*/

/*
Modify your program from the prior step so it now outputs:

You have 1 health potion
You have 5 torches
You have 10 arrows
You have 16 total items
Use a loop to print out the number of items and the item names for each inventory item. Handle proper pluralization of the names.
*/


#include <iostream>
#include <vector>
#include <cassert>
#include <string>
#include <string_view>



namespace Items
{
	enum Type
	{
		health_potion,
		torches,
		arrow,
		max_items

	};

}

void totalItems(const std::vector<int>& inventory)
{
	int total { 0 };
	for (int nbitems : inventory)
		total += nbitems;

	std::cout << "you have " << total << " total items";
	 

}

constexpr std::string_view getItemsPluralization(Items::Type type)
{

	switch (type)
	{
	case Items::health_potion:	return "healths potions";
	case Items::torches:		return "torchs";
	case Items::arrow:			return "arrows";

	default:					return "??";
	}



}

constexpr std::string_view getItemsNoPluralization(Items::Type type)
{

	switch (type)
	{
	case Items::health_potion:	return "health potion";
	case Items::torches:		return "torch";
	case Items::arrow:			return "arrow";

	default:					return "??";

	}



}

Items::Type getItemByIndex(size_t index)
{
	return static_cast<Items::Type>(index);

}


void printNbItems(const std::vector<int>& inventory) {

	for (int i = 0; i < std::size(inventory); i++)
	{

		Items::Type type = getItemByIndex(i);
		if (inventory[i] > 1)
			std::cout << "you have " << inventory[i] << " " << getItemsPluralization(type) << "\n";
		else 
			std::cout << "you have " << inventory[i] << " " << getItemsNoPluralization(type) << "\n";

	}

}


int main() {

	std::vector inventory{ 1, 5, 10 };
	assert(std::size(inventory) == Items::max_items); // make sure our inventory has the correct number of initializers
	printNbItems(inventory);

	totalItems(inventory);

	return 0;
}