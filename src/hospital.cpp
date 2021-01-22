/*********************************************************************
** Program name: hospital.cpp
** Author: Bryan Roberts
** Date: 5/26/19
** Description: Hospital class source file.
*********************************************************************/

#include <iostream>
#include "hospital.hpp"
#include "character.hpp"
#include "validation.hpp"

/********************************************************************* 
** Description: Constructor. 
*********************************************************************/
Hospital::Hospital()
{
    setTop(nullptr);
    setBottom(nullptr);
    setLeft(nullptr);
    setBottom(nullptr);
    setSpaceName("Hospital");
}

/********************************************************************* 
** Description: Performs all options for Hospital class.
*********************************************************************/
bool Hospital::menu(Character &c)
{
    line();
    centerText("HOSPITAL");
    line();

    std::cout << "1) Display inventory\n";
    std::cout << "2) Change space\n";
    std::cout << "3) Display location\n";
    std::cout << "4) Heal Pokemon\n";

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

        //change to decided space
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

        std::cout << "Current Space:\t\tHospital\n";
        std::cout << "Right Space:\t\tTown Center";
        line();

        return true;
        break;
    }

    //Heal all Pokemon at cost of 1 money per Pokemon
    case 4:
    {
        line();
        centerText("HEAL POKEMON");
        line();

        int cost = 0;

        //if user has enough money to heal all Pokemon
        if (c.getPokemon().size() <= c.getMoney())
        {

            for (int i = 0; i < c.getPokemon().size(); ++i)
            {

                cost++;

                if (static_cast<int>(c.getPokemon()[i]->getType()) == 0)
                {
                    c.getPokemon()[i]->setHealth(45);
                }
                else if (static_cast<int>(c.getPokemon()[i]->getType()) == 1)
                {
                    c.getPokemon()[i]->setHealth(44);
                }
                else if (static_cast<int>(c.getPokemon()[i]->getType()) == 2)
                {
                    c.getPokemon()[i]->setHealth(39);
                }
            }

            line();
            centerText("All Pokemon brought back to full health");
            std::cout << std::endl;
            centerText("Total Money Cost: " + std::to_string(cost));
            line();

            c.setMoney(c.getMoney() - cost);
        }

        //user does not have enough money to heal all Pokemon
        else
        {
            line();
            centerText("You don't have enough money to heal all pokemon");
            line();
        }

        return true;
        break;
    }
    }
}