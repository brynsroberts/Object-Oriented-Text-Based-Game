/*********************************************************************
** Program name: ponyta.cpp
** Author: Bryan Roberts
** Date: 5/26/19
** Description: Ponyta class source file.
*********************************************************************/

#include "ponyta.hpp"
#include "pokemon.hpp"

/********************************************************************* 
** Description: Constructor.  Derived from Pokemon base class. Gives
2 attack moves.
*********************************************************************/
Ponyta::Ponyta()
{
    setName("Ponyta");
    setType(fire);
    setAttack("Stomp", normal, 10, 1000, 1000, 0);
    setAttack("Fire Spin", fire, 12, 1000, 1000, 1);
    setHealth(50);
}
