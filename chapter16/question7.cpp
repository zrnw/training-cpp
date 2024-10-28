/*
Write a short program that prints the elements of the following vector to the screen using a loop:
The output should look like this:

4 6 7 3 8 2 1 9

Update your code for the prior quiz solution so that the following program compiles and has the same output:


*/

#include <iostream>
#include <vector>

// Implement printArray() here
void printArray(const std::vector<int> arr)
{
    for (std::size_t i = 0; i < arr.size(); i++)
    {
        std::cout << arr[i] << " ";
    }

}

int main()
{
    std::vector arr{ 4, 6, 7, 3, 8, 2, 1, 9 };

    printArray(arr); // use function template to print array

    return 0;
}