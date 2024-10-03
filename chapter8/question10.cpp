/*
A prime number is a natural number greater than 1 that is evenly divisible (with no remainder) only by 1 and itself.

Complete the following program by writing the isPrime() function using a for-loop. When successful, the program will print “Success!”.
*/



// Make sure that assert triggers even if we compile in release mode
#undef NDEBUG

#include <cassert> // for assert
#include <iostream>

bool isPrime(int x)
{

    if (x <= 1)
    return false;

    // write this function using a for loop
    for(int verif {2}; verif < x; ++verif ){

        if (x % verif == 0)
            return false;

    }

    return true;

}

int main()
{
    assert(!isPrime(0)); // terminate program if isPrime(0) is true
    assert(!isPrime(1));
    assert(isPrime(2));  // terminate program if isPrime(2) is false
    assert(isPrime(3));
    assert(!isPrime(4));
    assert(isPrime(5));
    assert(isPrime(7));
    assert(!isPrime(9));
    assert(isPrime(11));
    assert(isPrime(13));
    assert(!isPrime(15));
    assert(!isPrime(16));
    assert(isPrime(17));
    assert(isPrime(19));
    assert(isPrime(97));
    assert(!isPrime(99));
    assert(isPrime(13417));

    std::cout << "Success!\n";

    return 0;
}