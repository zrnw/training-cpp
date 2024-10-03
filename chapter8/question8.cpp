/*
Modify the FizzBuzz program you wrote in the previous quiz to add the rule that numbers divisible by seven should be replaced with “pop”. 
Run the program for 150 iterations.

In this version, using an if/else chain to explicitly cover every possible combination of words will result in a function that is too long. 
Optimize your function so only 4 if-statements are used: one for each of the non-compound words (“fizz”, “buzz”, “pop”), and one for the case where a number is printed.
*/


#include <iostream>


void fizzbuzz(int number){

    for (int x{1};x<=number;++x){


        bool verif{false};
        if (x % 3 == 0){
            std::cout << "fizz\n";
            verif = {true};
        }
        if (x % 5 == 0){
            std::cout <<"buzz\n";
            verif = {true};

        }
        if (x % 7 == 0){
            std::cout << "pop\n";
            verif = {true};

        }
        if(!verif){
            std::cout << x << "\n";
        }
    }

}


int main(){

    fizzbuzz(150);

    return 0;
}