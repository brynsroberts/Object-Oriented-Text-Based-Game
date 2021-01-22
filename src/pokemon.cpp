/*********************************************************************
** Program name: pokemon.cpp
** Author: Bryan Roberts
** Date: 5/26/19
** Description: Pokemon abstract class source file.
*********************************************************************/

#include "pokemon.hpp"
#include <iostream>

/********************************************************************* 
** Description: Destructor.
*********************************************************************/
Pokemon::~Pokemon()
{
}

/********************************************************************* 
** Description: Returns string to name data member.
*********************************************************************/
std::string Pokemon::getName()
{
    return name;
}

/********************************************************************* 
** Description: Returns string to name data characterName.
*********************************************************************/
std::string Pokemon::getCharacterName()
{
    return characterName;
}

/********************************************************************* 
** Description: Returns enum Type to type data member.
Types include:
0 - grass
1 - water
2 - fire
*********************************************************************/
Type Pokemon::getType()
{
    return type;
}

/********************************************************************* 
** Description: Returns int to health data member.
*********************************************************************/
int Pokemon::getHealth()
{
    return health;
}

/********************************************************************* 
** Description: Returns int to struct normal attack data member
damage.
*********************************************************************/
int Pokemon::getAttackDamage(int i)
{
    return attack[i].attackDamage;
}

/********************************************************************* 
** Description: Return string for data member attackName.
*********************************************************************/
std::string Pokemon::getAttackName(int i)
{
    return attack[i].attackName;
}

/********************************************************************* 
** Description: Return enum Type for Pokemon.
Types include:
0 - grass
1 - water
2 - fire
*********************************************************************/
Type Pokemon::getAttackType(int i)
{
    return attack[i].attackType;
}

/********************************************************************* 
** Description: Return int for attack move.
*********************************************************************/
int Pokemon::getAttackMoves(int i)
{
    return attack[i].moves;
}

/********************************************************************* 
** Description: Return int for total moves.
*********************************************************************/
int Pokemon::getAttackTotalMoves(int i)
{
    return attack[i].totalMoves;
}

/********************************************************************* 
** Description: Sets data member name.  Takes in string.
*********************************************************************/
void Pokemon::setName(std::string name)
{
    this->name = name;
}

/********************************************************************* 
** Description: Sets data member characterName.  Takes in string.
*********************************************************************/
void Pokemon::setCharacterName(std::string characterName)
{
    this->characterName = characterName;
}

/********************************************************************* 
** Description: Sets data member type.  Takes in enum Type.
Types include:
0 - grass
1 - water
2 - fire
*********************************************************************/
void Pokemon::setType(Type type)
{
    this->type = type;
}

/********************************************************************* 
** Description: Sets data member health.  Takes in int.
*********************************************************************/
void Pokemon::setHealth(int health)
{
    this->health = health;
}

/********************************************************************* 
** Description: Sets data member normalAttack.  Takes in string
for attackName, enum Type for attack type, and int for attack damage.
*********************************************************************/
void Pokemon::setAttack(std::string attackName, Type attackType, int attackDamage, int moves, int totalMoves, int i)
{
    this->attack[i].attackName = attackName;
    this->attack[i].attackType = attackType;
    this->attack[i].attackDamage = attackDamage;
    this->attack[i].moves = moves;
    this->attack[i].totalMoves = totalMoves;
}

/********************************************************************* 
** Description: Attack function for attacking other pokemon.  Doubles
damage if defending type is vulnerable to attacking type.  Returns
amount of damage.
*********************************************************************/
int Pokemon::attackPokemon(Pokemon *defender, int i)
{
    int randomNumber = rand() % 5;

    if ((this->getAttackType(i) == grass) && (defender->getType() == water))
    {
        return this->getAttackDamage(i) + randomNumber;
    }
    else if ((this->getAttackType(i) == fire) && (defender->getType() == water))
    {
        return this->getAttackDamage(i) + randomNumber;
    }
    else if ((this->getAttackType(i) == water) && (defender->getType() == fire))
    {
        return this->getAttackDamage(i) + randomNumber;
    }
    else
    {
        return this->getAttackDamage(i);
    }
}

/********************************************************************* 
** Description: Defend function for defending from other pokemon. 
Returns final health of defending pokemon.
*********************************************************************/
int Pokemon::defend(int attackingDamage)
{
    this->setHealth(this->getHealth() - attackingDamage);

    if (this->getHealth() < 0)
    {
        this->setHealth(0);
    }

    return this->getHealth();
}
