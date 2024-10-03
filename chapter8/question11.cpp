/*
Implement a game of Hi-Lo. First, your program should pick a random integer between 1 and 100. The user is given 7 tries to guess the number.

If the user does not guess the correct number, the program should tell them whether they guessed too high or too low. 
If the user guesses the right number, the program should tell them they won. If they run out of guesses, the program should tell them they lost, 
and what the correct number is. At the end of the game, the user should be asked if they want to play again. If the user doesn’t enter ‘y’ or ‘n’, ask them again.

For this quiz, assume the user enters a valid number.


*/

#include <iostream>
#include <Random>


bool guessnumber(int tries, int min, int max){

    std::random_device rd; // obtain a random number from hardware
    std::mt19937 gen(rd()); // seed the generator
    std::uniform_int_distribution<> distr(1, 100); // define the range
    int randomnumber {distr(gen)};

    int count{1};
    int usernumber {};
    
    std::cout << "FOR THE TEST CORRECT NUMBER: "<< randomnumber << "\n";
    std::cout << "Let's play a game. I'm thinking of a number between 1 and 100. You have 7 tries to guess what it is.\n";
    for (count; count <= tries; ++count){
        
        std::cout << "Guess #" << count << ": ";
        std::cin >> usernumber;

        if (usernumber < randomnumber){
            std::cout << "Your guess is too low. \n";
        }
        else if (usernumber > randomnumber){
            std::cout << "Your guess is too high. \n";

        }
        else{
            std::cout << "Correct! You win!. \n";
            return true;
        }
    }

    std::cout << "sorry, you lose. the correct number was " << randomnumber;
    return false;

}

bool playagain(){

	while (true)
	{
		char ch{};
		std::cout << "Would you like to play again (y/n)? ";
		std::cin >> ch;

		switch (ch)
		{
		case 'y': return true;
		case 'n': return false;
		}
	}
}




int main(){

    constexpr int tries {7};
    constexpr int min {1};
    constexpr int max {100};

    do
    {
        guessnumber(tries,min,max);
    } while (playagain());
    
    std::cout << "thank you for playing";

    return 0;
}