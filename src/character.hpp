/*********************************************************************
** Program name: character.hpp
** Author: Bryan Roberts
** Date: 5/26/19
** Description: Character class header file.
*********************************************************************/

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <vector>
#include "pokemon.hpp"
#include "space.hpp"

enum CurrentSpace
{
    townCenter,
    store,
    hospital,
    catchPokemon,
    gym,
    boss
};

class Character
{
private:
    std::vector<Pokemon *> pokemon;
    int pokeballs;
    int potions;
    int money;
    bool badge;
    CurrentSpace currentSpace;

public:
    Character();
    ~Character();
    std::vector<Pokemon *> getPokemon();
    int getPokeballs();
    int getPotions();
    int getMoney();
    bool getBadge();
    CurrentSpace getCurrentSpace();
    bool setPokemon(Type);
    void setPokeballs(int);
    void setPotions(int);
    void setMoney(int);
    void setBadge(bool);
    void setCurrentSpace(CurrentSpace);
    void displayInventory();
};

#endif