/*********************************************************************
** Program name: squirtle.cpp
** Author: Bryan Roberts
** Date: 5/26/19
** Description: Squirtle class source file.
*********************************************************************/

#include "squirtle.hpp"
#include "pokemon.hpp"

/********************************************************************* 
** Description: Constructor.  Derived from Pokemon base class. Gives
2 attack moves.
*********************************************************************/
Squirtle::Squirtle()
{
    setName("Squirtle");
    setType(water);
    setAttack("Tackle", normal, 15, 35, 35, 0);
    setAttack("Surf", water, 18, 25, 25, 1);
    setHealth(44);
}