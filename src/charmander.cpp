/*********************************************************************
** Program name: charmander.cpp
** Author: Bryan Roberts
** Date: 5/26/19
** Description: Charmander class source file.
*********************************************************************/

#include "charmander.hpp"
#include "pokemon.hpp"

/********************************************************************* 
** Description: Constructor for Charmander derived Pokemon class.
Gives 2 attacking moves.
*********************************************************************/
Charmander::Charmander()
{
    setName("Charmander");
    setType(fire);
    setAttack("Scratch", normal, 15, 35, 35, 0);
    setAttack("Ember", fire, 20, 25, 25, 1);
    setHealth(39);
}