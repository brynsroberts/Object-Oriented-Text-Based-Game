/*********************************************************************
** Program name: character.cpp
** Author: Bryan Roberts
** Date: 5/26/19
** Description: Character class source file.
*********************************************************************/

#include "space.hpp"
#include "character.hpp"
#include "pokemon.hpp"
#include "squirtle.hpp"
#include "charmander.hpp"
#include "bulbasaur.hpp"
#include "validation.hpp"
#include <iostream>

/********************************************************************* 
** Description: Constructor
*********************************************************************/
Character::Character()
{
    setPotions(0);
    setPokeballs(2);
    setMoney(20);
    setCurrentSpace(townCenter);
    setBadge(false);
}
/********************************************************************* 
** Description: Destructor.
*********************************************************************/
Character::~Character()
{
    for (int i = 0; i < pokemon.size(); ++i)
    {
        delete pokemon[i];
        pokemon[i] = nullptr;
    }
}

/********************************************************************* 
** Description: Returns pokemon at vector position number of 
pokemon data member.
*********************************************************************/
std::vector<Pokemon *> Character::getPokemon()
{
    return pokemon;
}

/********************************************************************* 
** Description: Returns int of data member pokeballs.
*********************************************************************/
int Character::getPokeballs()
{
    return pokeballs;
}

/********************************************************************* 
** Description: Returns int of data member potions.
*********************************************************************/
int Character::getPotions()
{
    return potions;
}

/********************************************************************* 
** Description: Returns int of data member money.
*********************************************************************/
int Character::getMoney()
{
    return money;
}

/********************************************************************* 
** Description: Returns CurrentSpace of data member space.
enum CurrentSpace:
townCenter - 0 
store - 1
hospital - 2
catchPokemon - 3
gym - 4
boss - 5
*********************************************************************/
CurrentSpace Character::getCurrentSpace()
{
    return currentSpace;
}

bool Character::getBadge()
{
    return badge;
}

/********************************************************************* 
** Description: Sets data member Pokemon with new pokemon captured.
If user already has 3 pokemon, will not add pokemon to inventory. 
*********************************************************************/
bool Character::setPokemon(Type pokemonIn)
{
    if (pokemon.size() < 4)
    {
        if (pokemonIn == water)
        {
            pokemon.push_back(new Squirtle);
            return true;
        }
        else if (pokemonIn == fire)
        {
            pokemon.push_back(new Charmander);
            return true;
        }
        else if (pokemonIn == grass)
        {
            pokemon.push_back(new Bulbasaur);
            return true;
        }
    }

    return false;
}

/********************************************************************* 
** Description: Sets data member pokeballs.  Takes in int.
*********************************************************************/
void Character::setPokeballs(int pokeballs)
{
    this->pokeballs = pokeballs;
}

/********************************************************************* 
** Description: Sets data member potions.  Takes in int.
*********************************************************************/
void Character::setPotions(int potions)
{
    this->potions = potions;
}

/********************************************************************* 
** Description: Sets data member money.  Takes in int.
*********************************************************************/
void Character::setMoney(int money)
{
    this->money = money;
}

/********************************************************************* 
** Description: Sets data member space.  Takes in enum CurrentSpace.
enum CurrentSpace:
townCenter - 0 
store - 1
hospital - 2
catchPokemon - 3
gym - 4
boss - 5
*********************************************************************/
void Character::setCurrentSpace(CurrentSpace currentSpace)
{
    this->currentSpace = currentSpace;
}

/********************************************************************* 
** Description: Sets data member badge.  Takes in bool.
*********************************************************************/
void Character::setBadge(bool badge)
{
    this->badge = badge;
}

/********************************************************************* 
** Description: Displays inventory of character.
*********************************************************************/
void Character::displayInventory()
{
    line();
    centerText("INVENTORY");
    line();

    std::cout << "Money:\t\t" << getMoney() << std::endl;
    std::cout << "Pokeballs:\t" << getPokeballs() << std::endl;
    std::cout << "Potions:\t" << getPotions() << std::endl;
    std::cout << "Badge:\t\t" << getBadge() << std::endl;

    line();
    centerText("POKEMON");
    line();

    for (int i = 0; i < getPokemon().size(); ++i)
    {
        std::cout << "Pokemon:\t" << i + 1 << " of 3" << std::endl;
        std::cout << "Type:\t\t" << getPokemon()[i]->getName() << std::endl;
        std::cout << "Name:\t\t" << getPokemon()[i]->getCharacterName() << std::endl;
        std::cout << "Health:\t\t" << getPokemon()[i]->getHealth() << std::endl;
        std::cout << "Attack 1:\t" << getPokemon()[i]->getAttackName(0) << std::endl;
        std::cout << "Attack 2:\t" << getPokemon()[i]->getAttackName(1);
        line();
    }
}