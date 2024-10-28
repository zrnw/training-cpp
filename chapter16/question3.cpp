/*
Write a function that takes a std::vector, returns a std::pair containing the indices of the elements with the min and max values in the array. 
The documentation for std::pair can be found here. Call the function on the following two vectors:

The program should output the following:

With array ( 3, 8, 2, 5, 7, 8, 3 ):
The min element has index 2 and value 2
The max element has index 1 and value 8

With array ( 5.5, 2.7, 3.3, 7.6, 1.2, 8.8, 6.6 ):
The min element has index 4 and value 1.2
The max element has index 5 and value 8.8



*/

#include <iostream>
#include <vector>
#include <string_view>

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

    std::vector v1 { 3, 8, 2, 5, 7, 8, 3 };
    std::vector v2 { 5.5, 2.7, 3.3, 7.6, 1.2, 8.8, 6.6 };

    auto x{minmax(v1)};
    auto y{minmax(v2)};


    std::cout << "with array ( ";
    ar(v1);
    std::cout << ")\n";
    std::cout << "the min element has index " << x.first << " and value " << v1[x.first] << "\n";
    std::cout << "the max element has index " << x.second << " and value " << v1[x.second] << "\n";



    std::cout << "with array ( ";
    ar(v2);
    std::cout << ")\n";    
    std::cout << "the min element has index " << y.first << " and value " << v2[y.first] << "\n";
    std::cout << "the max element has index " << y.second << " and value " << v2[y.second] << "\n";


    return 0;
}   