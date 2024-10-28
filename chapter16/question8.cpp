/*
Ask the user for a value between 1 and 9. If the user does not enter a value between 1 and 9, repeatedly ask for an integer value until they do. If the user enters a number followed by extraneous input, ignore the extraneous input.
Print the array.
Write a function template to search the array for the value that the user entered. If the value is in the array, return the index of that element. If the value is not in the array, return an appropriate value.
If the value was found, print the value and index. If the value was not found, print the value and that it was not found.
We cover how to handle invalid input in lesson 9.5 -- std::cin and handling invalid input.

Here are two sample runs of this program:

Enter a number between 1 and 9: d
Enter a number between 1 and 9: 6
4 6 7 3 8 2 1 9
The number 6 has index 1
Enter a number between 1 and 9: 5
4 6 7 3 8 2 1 9
The number 5 was not found
*/
#include <iostream>
#include <limits>
#include <vector>

template <typename T>
void printArray(const std::vector<T>& arr)
{
    for (std::size_t index{ 0 }; index < arr.size(); ++index)
    {
        std::cout << arr[index] << ' ';
    }

    if (arr.size() > 0)
        std::cout << '\n';
}

template <typename T>
int findIndex(const std::vector<T>& arr, T val)
{
    for (std::size_t index{ 0 }; index < arr.size(); ++index)
    {
        if (arr[index] == val)
            return static_cast<int>(index);
    }

    return -1; // -1 is not a valid index, so we can use it as an error return value
}


int getValidNumber()
{
    // First, read in valid input from user
    int num{};
    do
    {
        std::cout << "Enter a number between 1 and 9: ";
        std::cin >> num;

        // if the user entered an invalid character
        if (!std::cin)
            std::cin.clear(); // reset any error flags

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignore any extra characters in the input buffer (regardless of whether we had an error or not)

    } while (num < 1 || num > 9);

    return num;
}

int main()
{
    std::vector arr{ 4, 6, 7, 3, 8, 2, 1, 9 };

    int num{ getValidNumber() };

    printArray(arr);

    int index{ findIndex(arr, num) };

    if (index != -1)
        std::cout << "The number " << num << " has index " << index << '\n';
    else
        std::cout << "The number " << num << " was not found\n";

    return 0;
}