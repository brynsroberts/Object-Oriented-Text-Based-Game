/*********************************************************************
** Program name: bellsprout.cpp
** Author: Bryan Roberts
** Date: 5/26/19
** Description: Bellsprout class source file.
*********************************************************************/

#include "bellsprout.hpp"
#include "pokemon.hpp"

/********************************************************************* 
** Description: Constructor.  Initiates Bellsprout derived from 
Pokemon.  Bellsprout used for Brock Gym battle.
*********************************************************************/
Bellsprout::Bellsprout()
{
    setName("Bellsprout");
    setType(grass);
    setAttack("Slam", normal, 8, 1000, 1000, 0);
    setAttack("Vine Whip", grass, 10, 1000, 1000, 1);
    setHealth(40);
}