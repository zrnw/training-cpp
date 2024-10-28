/*
Write a short program that prints the elements of the following vector to the screen using a loop:
The output should look like this:

4 6 7 3 8 2 1 9
*/

#include <iostream>
#include <vector>

int main()
{
    std::vector arr{ 4, 6, 7, 3, 8, 2, 1, 9 };

	for (std::size_t i = 0; i < arr.size(); i++)
	{
		std::cout << arr[ i ] << " ";
	}

    return 0;
}