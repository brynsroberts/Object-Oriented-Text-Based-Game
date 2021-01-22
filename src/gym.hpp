/*********************************************************************
** Program name: gym.hpp
** Author: Bryan Roberts
** Date: 5/26/19
** Description: Gym class header file.
*********************************************************************/

#ifndef GYM_HPP
#define GYM_HPP

#include "space.hpp"
#include "character.hpp"

class Gym : public Space
{
    public:
        Gym();
        bool menu(Character &c);   
};

#endif