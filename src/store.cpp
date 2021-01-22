/*********************************************************************
** Program name: store.cpp
** Author: Bryan Roberts
** Date: 5/26/19
** Description: Store class source file.
*********************************************************************/

#include <iostream>
#include "store.hpp"
#include "character.hpp"
#include "validation.hpp"

/********************************************************************* 
** Description: Constructor. 
*********************************************************************/
Store::Store()
{
    setTop(nullptr);
    setBottom(nullptr);
    setLeft(nullptr);
    setBottom(nullptr);
    setSpaceName("Store");
}

/********************************************************************* 
** Description: Performs all options for store class.  Lets user 
purchase Pokeball and potion for money.  
*********************************************************************/
bool Store::menu(Character &c)
{
    line();
    centerText("STORE");
    line();

    std::cout << "1) Display Inventory and Pokemon\n";
    std::cout << "2) Change space\n";
    std::cout << "3) Display location\n";
    std::cout << "4) Purchase item\n";

    bool b = false;  //for return type
    int choice = -1; //for user input

    do
    {
        std::string input; //place holder for string input
        std::cin >> input;

        //input validation
        if (isInt(input))
        {
            choice = stringToInt(input);
        }

        b = intRange(choice, 1, 4);
    } while (!dataType() || !b);

    switch (choice)
    {

    //display inventory
    case 1:
    {
        c.displayInventory();
        return true;
        break;
    }

    //change to another space
    case 2:
    {
        line();
        centerText("CHANGE SPACE");
        line();

        std::cout << "1) Town Center\n";
        std::cout << "2) Stay in current location\n";

        bool b = false;  //for return type
        int choice = -1; //for user input

        do
        {
            std::string input; //place holder for string input
            std::cin >> input;

            //input validation
            if (isInt(input))
            {
                choice = stringToInt(input);
            }

            b = intRange(choice, 1, 2);
        } while (!dataType() || !b);

        //set user choice of space to change to
        switch (choice)
        {
        case 1:
        {
            c.setCurrentSpace(townCenter);
            break;
        }
        case 2:
        {

            break;
        }
        }
        return true;
        break;
    }

    //display current and surrounding locations
    case 3:
    {
        line();
        centerText("DISPLAY LOCATION");
        line();

        std::cout << "Current Space:\t\tStore\n";
        std::cout << "Left Space:\t\tTown Center";
        line();

        return true;
        break;
    }

    //purchase items from store
    case 4:
    {
        line();
        centerText("PURCHASE ITEM");
        line();

        centerText("Prices");
        std::cout << std::endl;

        std::cout << "Potion:\t\t2\n";
        std::cout << "Pokeball:\t3";
        line();

        std::cout << "1) Potion\n";
        std::cout << "2) Pokeball\n";

        bool b = false;  //for return type
        int choice = -1; //for user input

        do
        {
            std::string input; //place holder for string input
            std::cin >> input;

            //input validation
            if (isInt(input))
            {
                choice = stringToInt(input);
            }

            b = intRange(choice, 1, 2);
        } while (!dataType() || !b);

        //add items to user inventory and subtract cost
        switch (choice)
        {

        //purchase potion
        case 1:
        {
            if ((c.getMoney() - 2) >= 0)
            {
                c.setPotions(c.getPotions() + 1);
                c.setMoney(c.getMoney() - 2);
            }
            else
            {
                line();
                centerText("You do not have enough money for a potion");
                line();
            }
            break;
        }

        //purchase Pokeball
        case 2:
        {
            if ((c.getMoney() - 3) >= 0)
            {
                c.setPokeballs(c.getPokeballs() + 1);
                c.setMoney(c.getMoney() - 3);
            }
            else
            {
                line();
                centerText("You do not have enough money for a Pokeball");
                line();
            }
            break;
        }
        }

        return true;
        break;
    }
    }
}