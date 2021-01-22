/*********************************************************************
** Program name: boss.hpp
** Author: Bryan Roberts
** Date: 5/26/19
** Description: Boss class header file.
*********************************************************************/

#ifndef BOSS_HPP
#define BOSS_HPP

#include "space.hpp"

#include "character.hpp"

class Boss : public Space
{
public:
    Boss();
    bool menu(Character &c);
};

#endif