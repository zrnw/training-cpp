/*
Invert the nested loops example so it prints the following:

5 4 3 2 1
4 3 2 1
3 2 1
2 1
1

*/

#include <iostream>

int main()
{
  
    int outer{ 1 };
    while (outer <= 5)
    {
    
        int inner{ 5 };
        while (inner >= 1)
        {
            if (inner <= outer){
                std::cout << inner << ' ';
            }
            else{
                std::cout << "  ";
            }
            --inner;
        }

        
        std::cout << '\n';
        ++outer;
    } 

    return 0;
}