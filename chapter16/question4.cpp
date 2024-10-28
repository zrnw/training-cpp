/*
Modify the prior program so that the user can enter as many integers as they like. Stop accepting input when the user enters -1.

Print the vector and find the min and max elements.

When run with the input 3 8 5 2 3 7 -1, the program should produce the following output:

Enter numbers to add (use -1 to stop): 3 8 5 2 3 7 -1
With array ( 3, 8, 5, 2, 3, 7 ):
The min element has index 3 and value 2
The max element has index 1 and value 8
Do something reasonable when the user enters -1 as the first input.
*/

#include <iostream>
#include <vector>
#include <string_view>
#include <limits>


template <typename T>
void ar(const std::vector<T>& arr1)
{

    for (size_t index{0}; index < arr1.size(); index++)
    {
        std::cout << arr1[index] << ", ";
    }

}

template <typename T>
std::pair <std::size_t, std::size_t> minmax(const std::vector<T>& arr)
{

    std::size_t min {0};
    std::size_t max {0};

    for (size_t index{0}; index < arr.size(); index++)
    {
        if (arr[index] < arr[min])
        {
            min = index;
        }
        if (arr[index] > arr[max])
        {
            max = index;
        }
    }

    return {min,max};



}


int main(){

    std::vector<int> v1{};
    std::cout << "Enter a score (or -1 to fininsh): ";


    while(true)
    {
        int input{};
        std::cin >> input;

        if(!std::cin)
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        if (input == -1)
            break;

        v1.push_back(input);

    }


    if (v1.size() == 0)
    {
        std::cout <<"vector is empty\n";
    }
    else
    {
        int x{minmax(v1)};

        std::cout << "with array ( ";
        ar(v1);

        std::cout << ")\n";
        std::cout << "the min element has index " << x.first << " and value " << v1[x.first] << "\n";
        std::cout << "the max element has index " << x.second << " and value " << v1[x.second] << "\n";
    }

    return 0;
}   