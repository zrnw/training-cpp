/*
Write a function called calculate() that takes two integers and a char representing one of the following mathematical operations: +, -, *, /, or % (remainder). 
Use a switch statement to perform the appropriate mathematical operation on the integers, and return the result. 
If an invalid operator is passed into the function, the function should print an error message. 
For the division operator, do an integer division, and don’t worry about divide by zero.

Hint: “operator” is a keyword, variables can’t be named “operator”.

*/
#include <iostream>

int calculate(int x, int y, char z){

    int result;
    switch (z)
    {
    case '+':
        result = x + y;
        break;
    case '-':
        result = x - y;
        break;
    case '/':
        result = x / y;
        break;
    case '%':
        result = x % y;
        break;
    case '*':
        result = x * y;
        break;

    default:
        std::cout << "the opreator if false";
        break;
    }

    return result;

}


int getnumber(){

    std::cout << "enter number: ";
    int number;
    std::cin >> number;

    return number;


}


char getoperand (){

    std::cout << "enter a mathematical operations: +,-,*,/ or %: ";
    char operand;
    std::cin >> operand;

    return operand;

}

int main(){

    int number1 {getnumber()};
    int number2 {getnumber()};
    int char1 {getoperand()};

    int resultat{calculate(number1,number2,char1)};

    std::cout << resultat;

    return 0;

}