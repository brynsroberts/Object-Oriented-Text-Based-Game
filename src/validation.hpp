/*********************************************************************
** Program name: validation.hpp
** Author: Bryan Roberts
** Date: 4/14/19
** Description: Validation header file.
*********************************************************************/

#ifndef VALIDATION_HPP
#define VALIDATION_HPP

#include <string>

bool intRange(int userValue, int min, int max);
bool dataType();
bool isInt(std::string);
int stringToInt(std::string);
void line();
void centerText(std::string);

#endif