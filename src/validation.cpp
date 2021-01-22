/*********************************************************************
** Program name: validation.cpp
** Author: Bryan Roberts
** Date: 4/14/19
** Description: Various reusable functions.
*********************************************************************/

#include "validation.hpp"
#include <limits>
#include <iostream>
#include <string>
#include <cctype>

/********************************************************************* 
** Description: Validates user input is integer and is between
specified minimum and maximum integer values.  Returns true if input
is valid and false if input is not valid.
http://www.cplusplus.com/forum/beginner/121194/
*********************************************************************/
bool intRange(int userValue, int min, int max)
{

    //if not between min and max return false
    if (userValue < min)
    {
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "\nInvalid entry. Integer needs to be between " << min << " and " << max << ".\n";
        return false;
    }
    else if (userValue > max)
    {
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "\nInvalid entry. Integer needs to be between " << min << " and " << max << ".\n";
        return false;
    }
    else
    {
        //input valid, flush buffer and return true
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return true;
    }
}

/********************************************************************* 
** Description: Validates user input is correct data type of cin.
Will return true if correct data type is entered, will return false
if incorrect data type is entered.
http://www.cplusplus.com/forum/beginner/121194/
*********************************************************************/
bool dataType()
{

    //if cin fails, clear error, flush buffer, return false
    if (std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        //std::cout << "\nWrong data type.";
        return false;
    }

    //data is right type, return true
    else
    {
        return true;
    }
}

/********************************************************************* 
** Description: Checks if string input is only a digit.  Will
return false for anything that is not purely digits including floats
and characters.  Will return true if it can be converted to an int.
*********************************************************************/
bool isInt(std::string s)
{
    int size = s.size();
    for (int i = 0; i < size; i++)
    {
        if (isdigit(s[i]) || (i == 0 && s[i] == '-'))
        {
            //string element is a digit
        }
        else
        {
            return false;
        }
    }

    return true;
}

/********************************************************************* 
** Description: Converts input string to integer.  Must check that
string is an integer first.  Source:
http://www.cplusplus.com/forum/general/13135/
*********************************************************************/
int stringToInt(std::string s)
{
    return atoi(s.c_str());
}

/********************************************************************* 
** Description: Print line to console 80 characters long.
*********************************************************************/
void line()
{
    std::cout << "\n";
    for (int i = 0; i < 80; i++)
    {
        std::cout << "-";
    }
    std::cout << "\n";
}

/********************************************************************* 
** Description: Takes in string.  Prints to console text entered
centered in an 80 length line with * at both ends.
*********************************************************************/
void centerText(std::string s)
{
    int size = s.size();
    int padding = ((80 - size) / 2) - 1;

    std::cout << "*";
    for (int i = 0; i < padding; i++)
    {
        std::cout << " ";
    }

    std::cout << s;

    for (int j = 0; j < padding; j++)
    {
        std::cout << " ";
    }

    if ((size % 2) == 0)
    {
        std::cout << "*";
    }
    else
    {
        std::cout << " *";
    }
}