/*********************************************************************
** Program name: catch.hpp
** Author: Bryan Roberts
** Date: 5/26/19
** Description: Catch class header file.
*********************************************************************/

#ifndef CATCH_HPP
#define CATCH_HPP

#include "space.hpp"
#include "character.hpp"

class Catch : public Space
{
public:
    Catch();
    bool menu(Character &c);
};

#endif