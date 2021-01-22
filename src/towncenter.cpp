/*********************************************************************
** Program name: towncenter.cpp
** Author: Bryan Roberts
** Date: 5/26/19
** Description: Town Center class source file.
*********************************************************************/

#include <iostream>
#include "towncenter.hpp"
#include "character.hpp"
#include "validation.hpp"

/********************************************************************* 
** Description: Constructor.  
*********************************************************************/
TownCenter::TownCenter()
{
    setTop(nullptr);
    setBottom(nullptr);
    setLeft(nullptr);
    setBottom(nullptr);
    setSpaceName("Town Center");
}

/********************************************************************* 
** Description: Performs all actions for towncenter class.  Town
center is the hub for all other locations and user can travel to
other locations or exit the game. 
*********************************************************************/
bool TownCenter::menu(Character &c)
{
    line();
    centerText("TOWN CENTER");
    line();

    std::cout << "1) Display Inventory and Pokemon\n";
    std::cout << "2) Change space\n";
    std::cout << "3) Display location\n";
    std::cout << "4) Exit Game\n";

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

    //display user inventory
    case 1:
    {
        c.displayInventory();
        return true;
        break;
    }

    //change space
    case 2:
    {
        line();
        centerText("CHANGE SPACE");
        line();

        std::cout << "1) Hospital\n";
        std::cout << "2) Catch Pokemon\n";
        std::cout << "3) Store\n";
        std::cout << "4) Gym\n";
        std::cout << "5) Stay in current location\n";

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

            b = intRange(choice, 1, 5);
        } while (!dataType() || !b);

        //switch user space to selected space
        switch (choice)
        {
        case 1:
        {
            c.setCurrentSpace(hospital);
            break;
        }
        case 2:
        {
            c.setCurrentSpace(catchPokemon);
            break;
        }
        case 3:
        {
            c.setCurrentSpace(store);
            break;
        }
        case 4:
        {
            if (c.getPokemon().size() > 1)
            {
                c.setCurrentSpace(gym);
            }
            else
            {
                line();
                centerText("You need at least 2 Pokemon to enter the gym");
                line();
            }
            
            break;
        }
        case 5:
        {

            break;
        }
        }
        return true;
        break;
    }

    //dispay current and surrounding locations
    case 3:
    {
        line();
        centerText("DISPLAY LOCATION");
        line();

        std::cout << "Current Space:\t\tTown Center\n";
        std::cout << "Top Space:\t\tGym\n";
        std::cout << "Left Space:\t\tHospital\n";
        std::cout << "Bottom Space:\t\tStore\n";
        std::cout << "Right Space:\t\tCatch Pokemon";
        line();

        return true;
        break;
    }

    //exit game
    case 4:
    {
        line();
        centerText("EXIT GAME");
        line();

        return false;
        break;
    }
    }
}