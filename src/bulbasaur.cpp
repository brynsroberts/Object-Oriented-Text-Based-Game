/*********************************************************************
** Program name: bulbasaur.cpp
** Author: Bryan Roberts
** Date: 5/26/19
** Description: Bulbasaur class source file.
*********************************************************************/

#include "bulbasaur.hpp"
#include "pokemon.hpp"

/********************************************************************* 
** Description: Constructor.  Bublasaur derived from Pokemon gets
two attacks.
*********************************************************************/
Bulbasaur::Bulbasaur()
{
    setName("Bulbasaur");
    setType(grass);
    setAttack("Tackle", normal, 12, 35, 35, 0);
    setAttack("Razor Leaf", grass, 18, 25, 25, 1);
    setHealth(45);
}