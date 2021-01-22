/*********************************************************************
** Program name: finalProject.cpp
** Author: Bryan Roberts
** Date: 5/26/19
** Description: FinalProject class source file.  User can play
Pokemon game.
*********************************************************************/

#include <iostream>
#include <cstdlib> //for random number generation
#include <ctime>   //for random number generation
#include "game.hpp"
//#include "pokemon.hpp"
//#include "character.hpp"
//#include "space.hpp"
//#include "charmander.hpp"
//#include "bulbasaur.hpp"
//#include "squirtle.hpp"

int main()
{
    //initialize random number generator
    //seed random number generator srand
    unsigned seed;
    seed = time(0);
    srand(seed);

    Game g;

    g.playGame();

    return 0;
}