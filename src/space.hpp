/*********************************************************************
** Program name: space.hpp
** Author: Bryan Roberts
** Date: 5/26/19
** Description: Space abstract class header file.
*********************************************************************/

#ifndef SPACE_HPP
#define SPACE_HPP

#include "character.hpp"

class Space
{
protected:
    Space *top;
    Space *right;
    Space *left;
    Space *bottom;
    std::string spaceName;

public:
    virtual ~Space();
    virtual Space *getTop();
    virtual Space *getRight();
    virtual Space *getLeft();
    virtual Space *getBottom();
    virtual std::string getSpaceName();
    virtual void setTop(Space *);
    virtual void setRight(Space *);
    virtual void setLeft(Space *);
    virtual void setBottom(Space *);
    virtual void setSpaceName(std::string);
    virtual bool menu(Character &c) = 0;
};

#endif
