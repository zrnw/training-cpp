/*
Question #1

Write a program that asks the user to enter two integers, one named smaller, the other named larger. 
If the user enters a smaller value for the second integer, use a block and a temporary variable to swap the smaller and larger values. 
Then print the values of the smaller and larger variables. Add comments to your code indicating where each variable dies. 
Note: When you print the values, smaller should hold the smaller input and larger the larger input, no matter which order they were entered in.

The program output should match the following:

Enter an integer: 4
Enter a larger integer: 2
Swapping the values
The smaller value is 2
The larger value is 4
*/


#include <iostream>

int main()
{
    std::cout << "Enter an integer: ";
    int smaller{};
    std::cin >> smaller;

    std::cout << "Enter a larger integer: ";
    int larger{};
    std::cin >> larger;

    // if user did it wrong
    if (smaller > larger)
    {
        // swap values of smaller and larger
        std::cout << "Swapping the values\n";

        int temp{ larger };
        larger = smaller;
        smaller = temp;
    } // temp dies here

    std::cout << "The smaller value is: " << smaller << '\n';
    std::cout << "The larger value is: " << larger << '\n';

    return 0;
} // smaller and larger die here