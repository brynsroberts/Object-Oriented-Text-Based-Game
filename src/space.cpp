/*********************************************************************
** Program name: space.cpp
** Author: Bryan Roberts
** Date: 5/26/19
** Description: Space abstract class source file.
*********************************************************************/

#include "space.hpp"

/********************************************************************* 
** Description: Destructor.
*********************************************************************/
Space::~Space()
{
}

/********************************************************************* 
** Description: Returns Space pointer to top data member.
*********************************************************************/
Space *Space::getTop()
{
    return top;
}

/********************************************************************* 
** Description: Returns Space pointer to right data member.
*********************************************************************/
Space *Space::getRight()
{
    return right;
}

/********************************************************************* 
** Description: Returns Space pointer to left data member.
*********************************************************************/
Space *Space::getLeft()
{
    return left;
}

/********************************************************************* 
** Description: Returns Space pointer to bottom data member.
*********************************************************************/
Space *Space::getBottom()
{
    return bottom;
}

/********************************************************************* 
** Description: Returns string to spaceName data member.
*********************************************************************/
std::string Space::getSpaceName()
{
    return spaceName;
}

/********************************************************************* 
** Description: Sets data member top.  Takes in Space pointer.
*********************************************************************/
void Space::setTop(Space *top)
{
    this->top = top;
}

/********************************************************************* 
** Description: Sets data member right.  Takes in Space pointer.
*********************************************************************/
void Space::setRight(Space *right)
{
    this->right = right;
}

/********************************************************************* 
** Description: Sets data member left.  Takes in Space pointer.
*********************************************************************/
void Space::setLeft(Space *left)
{
    this->left = left;
}

/********************************************************************* 
** Description: Sets data member bottom.  Takes in Space pointer.
*********************************************************************/
void Space::setBottom(Space *bottom)
{
    this->bottom = bottom;
}

/********************************************************************* 
** Description: Set data member spaceName.  Takes in string.
*********************************************************************/
void Space::setSpaceName(std::string spaceName)
{
    this->spaceName = spaceName;
}
