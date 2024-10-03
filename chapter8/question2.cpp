/*
Write a program that prints out the letters a through z along with their ASCII codes. Use a loop variable of type char.


Hint: To print characters as integers, you have to use a static_cast.

*/

#include <iostream>

int main(){

    char mychar{'a'};

    while (mychar <= 'z') {

        std::cout << "letters : " << mychar << " ASCII: "<< static_cast<int>(mychar) << "\n";

        mychar++;
    }

    return 0;

}