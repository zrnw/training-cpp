/*
Write the following program: The user is asked to enter 2 floating point numbers (use doubles). 
The user is then asked to enter one of the following mathematical symbols: +, -, *, or /. 
The program computes the answer on the two numbers the user entered and prints the results. If the user enters an invalid symbol, the program should print nothing.

Example of program:

Enter a double value: 6.2
Enter a double value: 5
Enter +, -, *, or /: *
6.2 * 5 is 31

*/
#include <iostream>

double enterdouble(){

    std::cout << "enter a floating number: ";
    double x{};
    std::cin >> x;

    return x;

}

void entersymbol(double x, double y){

    std::cout << "enter a symbols +, -, *, or / : ";
    char z{};
    std::cin >> z;

    if (z == '+')
        std::cout << "the result is: " << x + y;
    else if (z == '-')
        std::cout << "the result is: " << x - y;
    else if (z == '*')
        std::cout << "the result is: " << x * y;
    else if (z == '/')
        std::cout << "the result is: " << x / y;
    else
        std::cout << "the symbols is false";

}

int main(){

    double x {enterdouble()};
    double y {enterdouble()};

    entersymbol(x,y);

    return 0;

}