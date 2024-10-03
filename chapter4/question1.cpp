// Write a short program where the user is asked to enter a single character. Print the value of the character and its ASCII code, using static_cast.
#include <iostream>



int readcharacter(){

    std::cout << "enter a single character ";
    char ch1;
    std::cin >> ch1;

    return ch1;
}



int main(){

    int x {readcharacter()};
    std::cout << "the character entered is " << x << "the value in ASCII " << static_cast<int>(x);

    return 0;
}