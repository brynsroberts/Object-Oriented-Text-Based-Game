/*********************************************************************
** Program name: game.hpp
** Author: Bryan Roberts
** Date: 5/26/19
** Description: Game class header file.
*********************************************************************/

#ifndef GAME_HPP
#define GAME_HPP

#include <string>
#include "space.hpp"
#include "character.hpp"
#include "towncenter.hpp"
#include "hospital.hpp"
#include "store.hpp"
#include "catch.hpp"
#include "gym.hpp"
#include "boss.hpp"
#include "pokemon.hpp"

class Game
{
private:
    Character player;
    Space *playerSpace;
    Space *townCenter;
    Space *hospital;
    Space *store;
    Space *catchPokemon;
    Space *gym;
    Space *boss;

public:
    Game();
    ~Game();
    Character getPlayer();
    void setPlayerSpace(Space*);
    void displayInventory();
    void pickStartingPokemon();
    bool exitGame();
    void playGame();
};

#endif