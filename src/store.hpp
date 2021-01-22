/*********************************************************************
** Program name: store.hpp
** Author: Bryan Roberts
** Date: 5/26/19
** Description: Store class header file.
*********************************************************************/

#ifndef STORE_HPP
#define STORE_HPP

#include "space.hpp"
#include "character.hpp"

class Store : public Space
{
public:
    Store();
    bool menu(Character &c);
};

#endif