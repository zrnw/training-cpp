/*
Write a program that asks for the name and age of two people, then prints which person is older.

Here is the sample output from one run of the program:
Enter the name of person #1: John Bacon
Enter the age of John Bacon: 37
Enter the name of person #2: David Jenkins
Enter the age of David Jenkins: 44
David Jenkins (age 44) is older than John Bacon (age 37).

*/

#include <iostream>

std::string getname (int x){

    std::cout << "enter the name of the person #" << x <<": ";
    std::string name;
    std::getline(std::cin >> std::ws, name);

    return name;

}


int getage(std::string_view sv){

    std::cout << "enter the age of " << sv << ": ";
    int age;
    std::cin >> age;

    return age;

}

void printolder(std::string name1, int age1, std::string name2, int age2){

    if (age1 > age2)
        std::cout << name1 << "(age " << age1 << ") is older than " << name2 << "(age " << age2 << ").";

    else
        std::cout << name2 << "(age " << age2 << ") is older than " << name1 << "(age " << age1 << ").";

}



int main(){

    const std::string name1 {getname(1)};
    const int age1 {getage(name1)};

    const std::string name2 {getname(2)};
    const int age2 {getage(name2)};

    printolder(name1,age1,name2,age2);

    return 0;

}