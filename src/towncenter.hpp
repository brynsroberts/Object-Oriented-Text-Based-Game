/*********************************************************************
** Program name: towncenter.hpp
** Author: Bryan Roberts
** Date: 5/26/19
** Description: Town Center class header file.
*********************************************************************/

#ifndef TOWNCENTER_HPP
#define TOWNCENTER_HPP

#include "space.hpp"
#include "character.hpp"

class TownCenter : public Space
{
public:
    TownCenter();
    bool menu(Character &c);
};

#endif