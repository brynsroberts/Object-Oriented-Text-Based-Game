/*********************************************************************
** Program name: boss.cpp
** Author: Bryan Roberts
** Date: 5/26/19
** Description: Boss class source file.  Used for boss space after
defeating Brock in the gym.  Boss space stores final fight against
Misty.  If user defeats Misty, user wins the game and collects the 
gym badge.
*********************************************************************/

#include <iostream>
#include "boss.hpp"
#include "character.hpp"
#include "validation.hpp"
#include "ponyta.hpp"

/********************************************************************* 
** Description: Constructor.
*********************************************************************/
Boss::Boss()
{
    setTop(nullptr);
    setBottom(nullptr);
    setLeft(nullptr);
    setBottom(nullptr);
    setSpaceName("Boss");
}

/********************************************************************* 
** Description: Performs all actions for Boss space.  Fight gym leader 
Misty.  After defeating Misty, user will win the game and collect 
the gym badge.
*********************************************************************/
bool Boss::menu(Character &c)
{
    int choice = 3;

    switch (choice)
    {
    case 1:
    {
        //decided against using this option
        c.displayInventory();
        return true;
        break;
    }
    case 2:
    {
        //decided against using this option
        line();
        centerText("DISPLAY LOCATION");
        line();

        std::cout << "Current Space:\t\tGym Master Misty\n";
        line();

        return true;
        break;
    }
    case 3:
    {
        line();
        centerText("BATTLE GYM MASTER MISTY");
        line();

        Pokemon *misty = new Ponyta;
        bool victory = false;

        line();
        centerText("Misty uses " + misty->getName() + "!");
        line();

        centerText("Which Pokemon you would like to use?");
        line();

        //Display Pokemon for user to choose from
        for (int i = 0; i < c.getPokemon().size(); ++i)
        {
            if (c.getPokemon()[i]->getHealth() > 0)
            {
                std::cout << i + 1 << ") " << c.getPokemon()[i]->getCharacterName()
                          << std::endl;
            }
            //if Pokemon has fainted
            else
            {
                std::cout << i + 1 << ") " << c.getPokemon()[i]->getCharacterName() << " fainted\n";
            }
        }

        //User picks Pokemon
        bool b = false;  //for return type
        int choice = -1; //for user input
        bool d = false;

        do
        {
            std::string input; //place holder for string input
            std::cin >> input;

            //input validation
            if (isInt(input))
            {
                choice = stringToInt(input);
            }

            b = intRange(choice, 1, c.getPokemon().size());

            if (choice <= c.getPokemon().size() && (choice > 0))
            {
                d = c.getPokemon()[choice - 1]->getHealth() > 0;
            }
            else
            {
                d = false;
            }

            //if user picks a Pokemon that has fainted
            if (!(d) && b)
            {
                line();
                centerText("Please pick a Pokemon that has not fainted");
                line();
            }

        } while (!dataType() || !b || !(d));

        line();
        centerText("Begin battle");
        line();

        //determine if at least on user Pokemon is alive for battle
        bool atLeastOneAlive = false;
        for (int i = 0; i < c.getPokemon().size(); ++i)
        {
            if (c.getPokemon()[i]->getHealth() > 0)
            {
                atLeastOneAlive = true;
            }
        }

        //perform fighting actions while Mistys Pokemon is alive and at least one
        //user Pokemon is alive
        while (misty->getHealth() > 0 && atLeastOneAlive)
        {

            //user decides move from menu
            int attackingMove = -1; //for user input
            if (c.getPokemon()[choice - 1]->getHealth() > 0)
            {
                line();
                centerText(c.getPokemon()[choice - 1]->getCharacterName() + " attacking");
                line();

                std::cout << "1) " << c.getPokemon()[choice - 1]->getAttackName(0) << std::endl;
                std::cout << "2) " << c.getPokemon()[choice - 1]->getAttackName(1) << std::endl;
                std::cout << "3) Change Pokemon\n";
                std::cout << "4) Use Potion\n";

                bool b = false; //for return type

                do
                {
                    std::string input; //place holder for string input
                    std::cin >> input;

                    //input validation
                    if (isInt(input))
                    {
                        attackingMove = stringToInt(input);
                    }

                    b = intRange(attackingMove, 1, 4);
                } while (!dataType() || !b);
            }
            //if user Pokemon has fainted, automatically choose new Pokemon
            else
            {
                attackingMove = 3;
            }

            //Perform user choice
            switch (attackingMove)
            {

            //Perform attack 1, normal attack
            case 1:
            {
                int attack = c.getPokemon()[choice - 1]->attackPokemon(misty, 0);
                misty->defend(attack);

                line();
                std::cout << c.getPokemon()[choice - 1]->getCharacterName() << " used " << c.getPokemon()[choice - 1]->getAttackName(0);
                std::cout << ". Attack did " << attack << " damage." << std::endl;

                std::cout << c.getPokemon()[choice - 1]->getCharacterName() << " health: "
                          << c.getPokemon()[choice - 1]->getHealth() << std::endl;
                std::cout << misty->getName() << " health: "
                          << misty->getHealth();
                line();

                break;
            }

            //Perform attack 2, special type attack
            case 2:
            {
                int attack = c.getPokemon()[choice - 1]->attackPokemon(misty, 1);
                misty->defend(attack);

                line();
                std::cout << c.getPokemon()[choice - 1]->getCharacterName() << " used " << c.getPokemon()[choice - 1]->getAttackName(1);
                std::cout << ". Attack did " << attack << " damage." << std::endl;

                std::cout << c.getPokemon()[choice - 1]->getCharacterName() << " health: "
                          << c.getPokemon()[choice - 1]->getHealth() << std::endl;
                std::cout << misty->getName() << " health: "
                          << misty->getHealth();
                line();

                break;
            }

            //Change Pokemon
            case 3:
            {
                line();
                centerText("CHANGE POKEMON");
                line();

                bool b = false; //for return type

                //if at least one Pokemon is alive, display Pokemon to choose from and pick one
                atLeastOneAlive = false;
                for (int i = 0; i < c.getPokemon().size(); ++i)
                {
                    if (c.getPokemon()[i]->getHealth() > 0)
                    {
                        atLeastOneAlive = true;
                    }
                }

                //Display Pokemon
                if (atLeastOneAlive)
                {
                    choice = -1;
                    do
                    {
                        for (int i = 0; i < c.getPokemon().size(); ++i)
                        {
                            if (c.getPokemon()[i]->getHealth() > 0)
                            {
                                std::cout << i + 1 << ") " << c.getPokemon()[i]->getCharacterName()
                                          << std::endl;
                            }
                            else
                            {
                                std::cout << i + 1 << ") " << c.getPokemon()[i]->getCharacterName() << " fainted\n";
                            }
                        }
                        std::string input; //place holder for string input
                        std::cin >> input;

                        //input validation
                        if (isInt(input))
                        {
                            choice = stringToInt(input);
                        }

                        b = intRange(choice, 1, c.getPokemon().size());

                        if (choice <= c.getPokemon().size() && (choice > 0))
                        {
                            d = c.getPokemon()[choice - 1]->getHealth() > 0;
                        }
                        else
                        {
                            d = false;
                        }

                        //If user picks a Pokemon that fainted
                        if (!(d) && b)
                        {
                            line();
                            centerText("Please pick a Pokemon that has not fainted");
                            line();
                        }

                    } while (!dataType() || (!b && atLeastOneAlive));
                }
                break;
            }

            //User uses potion to bring current Pokemon to full health
            case 4:
            {
                line();
                centerText("USE POTION");
                line();

                //If user has a potion in inventory
                if (c.getPotions() > 0)
                {
                    c.setPotions(c.getPotions() - 1);
                    c.getPokemon()[choice - 1]->setHealth(c.getPokemon()[choice - 1]->getHealth() + 100);

                    if (static_cast<int>(c.getPokemon()[choice - 1]->getType()) == 0 && c.getPokemon()[choice - 1]->getHealth() > 45)
                    {
                        c.getPokemon()[choice - 1]->setHealth(45);
                    }
                    else if (static_cast<int>(c.getPokemon()[choice - 1]->getType()) == 1 && c.getPokemon()[choice - 1]->getHealth() > 44)
                    {
                        c.getPokemon()[choice - 1]->setHealth(44);
                    }
                    else if (static_cast<int>(c.getPokemon()[choice - 1]->getType()) == 2 && c.getPokemon()[choice - 1]->getHealth() > 39)
                    {
                        c.getPokemon()[choice - 1]->setHealth(39);
                    }
                }

                //user does not have any potions to use
                else
                {
                    line();
                    centerText("You don't have any potions.");
                    line();
                }
            }
            }

            //Misty performs attacking move if her pokemon has Health and user Pokemon has health
            if (misty->getHealth() > 0 && c.getPokemon()[choice - 1]->getHealth() > 0)
            {
                line();
                centerText("Enemy " + misty->getName() + " attacking");
                line();

                int randomAttack = rand() % 2;

                int attackPokemonDamage = misty->attackPokemon(c.getPokemon()[choice - 1], randomAttack);
                c.getPokemon()[choice - 1]->defend(attackPokemonDamage);

                //Display attack and Pokemon health
                line();
                std::cout << misty->getName() << " used " << misty->getAttackName(randomAttack);
                std::cout << ". Attack did " << attackPokemonDamage << " damage." << std::endl;
                std::cout << c.getPokemon()[choice - 1]->getCharacterName() << " health: "
                          << c.getPokemon()[choice - 1]->getHealth() << std::endl;
                std::cout << misty->getName() << " health: "
                          << misty->getHealth();
                line();
            }

            //If Misty Pokemon fainted
            else if (misty->getHealth() < 1)
            {
                victory = true;
            }

            //determine if at least one user Pokemon is alive
            for (int i = 0; i < c.getPokemon().size(); ++i)
            {

                if (c.getPokemon()[i]->getHealth() > 0)
                {
                    atLeastOneAlive = true;
                }
            }
        }

        //If user defeated Misty, display final resualts and give user gym badge
        if (victory == true)
        {
            c.setCurrentSpace(townCenter);
            c.setBadge(true);
            line();
            centerText("Congratulations!  You beat Misty!");
            std::cout << std::endl;
            centerText("You earned the gym badge!");
            std::cout << std::endl;
            centerText("Final stats");
            line();

            c.displayInventory();

            line();
            centerText("Game Over");
            line();
        }

        delete misty;

        return false;
        break;
    }
    }

    return false;
}