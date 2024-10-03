// Put the MonsterType enumeration inside a namespace. Then, create a main() function and instantiate a troll. The program should compile.

#include <iostream>

namespace MonsterType
{
    enum MonsterType
    {

        orc,
        goblin,
        troll,
        ogre,
        skeleton,

    };
}


int main(){

    MonsterType::MonsterType me{MonsterType::troll};

    return 0;
}