/*********************************************************************
** Program name: hospital.hpp
** Author: Bryan Roberts
** Date: 5/26/19
** Description: Hospital class header file.
*********************************************************************/

#ifndef HOSPITAL_HPP
#define HOSPITAL_HPP

#include "space.hpp"
#include "character.hpp"

class Hospital : public Space
{
public:
    Hospital();
    bool menu(Character &c);
};

#endif