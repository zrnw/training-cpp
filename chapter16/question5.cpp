/*
Goals:

We’ll start by defining our list of words and writing a random word picker. You can use the Random.h from lesson 8.15 -- Global random numbers (Random.h) to assist.
Tasks:

First define a namespace named WordList. The starter list of words is: “mystery”, “broccoli” , “account”, “almost”, “spaghetti”, “opinion”, “beautiful”, “distance”, “luggage”. You can add others if you like.
Write a function to pick a random word and display the word picked. Run the program several times to make sure the word is randomized.
Here is a sample output from this step:

Welcome to C++man (a variant of Hangman)
To win: guess the word.  To lose: run out of pluses.

The word is: broccoli
*/

/*
STEP 2
As we develop complex programs, we want to work incrementally, adding one or two things at a time and then making sure they work. What makes sense to add next?

Goals:

Be able to draw the basic state of the game, showing the word as underscores.
Accept a letter of input from the user, with basic error validation.
In this step, we will not yet keep track of which letters the user has entered.

Here is the sample output from this step:

Welcome to C++man (a variant of Hangman)
To win: guess the word.  To lose: run out of pluses.

The word: ________
Enter your next letter: %
That wasn't a valid input.  Try again.
Enter your next letter: a
You entered: a
Tasks:

Create a class named Session that will be used to store all of the data the game needs to manage in a game session. 
For now, we just need to know what the random word is.
Create a function to display the basic state of the game, where the word is displayed as underscores.
Create a function to accept a letter of input from the user. Do basic input validation to filter out non-letters or extraneous input.

*/

#include <iostream>
#include <vector>
#include "random.h"
#include <string>

namespace WordList
{
    std::vector<std::string_view> words {"mystery", "broccoli", "account", "almost", "spaghetti", "opinion", "beautiful", "distance", "luggage"};

    std::string_view getRandomWord()
    {
        return words[Random::get<std::size_t>(0, words.size()-1)];
    }

};

void undescores(std::string_view words)
{

    for (std::string::size_type i = 0; i < words.size(); i++)
    {
        std::cout << "_";
    }

}

char userInput()
{
    while(true){

        std::cout << "enter your next letter: ";
        char str;

        std::cin >> str;

        if (!std::cin)
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // remove any extra input

            continue;
        }

        if (str < 'a'|| str > 'z')
        {
            std::cout << "invalid input" << str << "\n";
            continue;
        }
        
        return str;
    }

}

class Session
{
private:

public:
    
};



int main(){

    std::cout << "Welcome to C++man (a variant of Hangman)\n To win: guess the word.  To lose: run out of pluses.\n";

    std::string words{WordList::getRandomWord()};

    std::cout << "the word : " << undescores(words) << "\n";

    char rt {userInput()};
    std::cout << "You entered: " <<rt;


    return 0;
}