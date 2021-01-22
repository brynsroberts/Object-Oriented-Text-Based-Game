/*********************************************************************
** Program name: gym.cpp
** Author: Bryan Roberts
** Date: 5/26/19
** Description: Gym class source file.
*********************************************************************/

#include <iostream>
#include "gym.hpp"
#include "character.hpp"
#include "validation.hpp"
#include "pokemon.hpp"
#include "bellsprout.hpp"

/********************************************************************* 
** Description: Constructor.
*********************************************************************/
Gym::Gym()
{
    setTop(nullptr);
    setBottom(nullptr);
    setLeft(nullptr);
    setBottom(nullptr);
    setSpaceName("Gym");
}

/********************************************************************* 
** Description: Performs all actions for gym class.  Fight Brock.
User cannot back out of fight.  If user defeats brock, will move onto
Misty fight.
*********************************************************************/
bool Gym::menu(Character &c)
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

        std::cout << "Current Space:\t\tGym\n";
        std::cout << "Bottom Space:\t\tTown Center\n";
        line();

        return true;
        break;
    }
    case 3:
    {
        line();
        centerText("BATTLE BROCK");
        line();

        Pokemon *brock = new Bellsprout;
        bool victory = false;

        line();
        centerText("Brock uses " + brock->getName() + "!");
        line();

        centerText("Which Pokemon you would like to use?");
        line();

        //Diplay user Pokemon to pick from
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

        //User picks Pokemon
        bool b = false;  //for return type
        int choice = -1; //for user input
        bool d;

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

            //if user picks a Pokemon that fainted
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

        //determine if at least on user Pokemon is alive
        bool atLeastOneAlive = false;
        for (int i = 0; i < c.getPokemon().size(); ++i)
        {
            if (c.getPokemon()[i]->getHealth() > 0)
            {
                atLeastOneAlive = true;
            }
        }

        //perform fight until there is a winner
        while (brock->getHealth() > 0 && atLeastOneAlive)
        {

            int attackingMove = -1; //for user input

            //if user does not need to pick a Pokemon
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

            //user Pokemon has fainted and must pick a new Pokemon
            else
            {
                attackingMove = 3;
            }

            //perform user move
            switch (attackingMove)
            {

            //attack type 1, normal move
            case 1:
            {
                int attack = c.getPokemon()[choice - 1]->attackPokemon(brock, 0);
                brock->defend(attack);

                //display attack
                line();
                std::cout << c.getPokemon()[choice - 1]->getCharacterName() << " used " << c.getPokemon()[choice - 1]->getAttackName(0);
                std::cout << ". Attack did " << attack << " damage." << std::endl;

                std::cout << c.getPokemon()[choice - 1]->getCharacterName() << " health: "
                          << c.getPokemon()[choice - 1]->getHealth() << std::endl;
                std::cout << brock->getName() << " health: "
                          << brock->getHealth();
                line();

                break;
            }

            //attack type 2, special attack type
            case 2:
            {
                int attack = c.getPokemon()[choice - 1]->attackPokemon(brock, 1);
                brock->defend(attack);

                //display attack
                line();
                std::cout << c.getPokemon()[choice - 1]->getCharacterName() << " used " << c.getPokemon()[choice - 1]->getAttackName(1);
                std::cout << ". Attack did " << attack << " damage." << std::endl;

                std::cout << c.getPokemon()[choice - 1]->getCharacterName() << " health: "
                          << c.getPokemon()[choice - 1]->getHealth() << std::endl;
                std::cout << brock->getName() << " health: "
                          << brock->getHealth();
                line();

                break;
            }

            //change Pokemon mid battle
            case 3:
            {
                line();
                centerText("CHANGE POKEMON");
                line();

                bool b = false; //for return type
                atLeastOneAlive = false;
                for (int i = 0; i < c.getPokemon().size(); ++i)
                {
                    if (c.getPokemon()[i]->getHealth() > 0)
                    {
                        atLeastOneAlive = true;
                    }
                }

                //if at least one Pokemon is alive, display user Pokemon and let user pick one
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

                        //if user picks a fainted Pokemon
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

            //use potion mid battle to get full health back to fighting Pokemon
            case 4:
            {
                line();
                centerText("USE POTION");
                line();

                if (c.getPotions() > 0)
                {
                    c.setPotions(c.getPotions() - 1);
                    c.getPokemon()[choice - 1]->setHealth(c.getPokemon()[choice - 1]->getHealth() + 100);

                    //restore full health to fighting Pokemon
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
                else
                {
                    line();
                    centerText("You don't have any potions.");
                    line();
                }
            }
            }

            //Brocks Pokemon attacks
            if (brock->getHealth() > 0 && c.getPokemon()[choice - 1]->getHealth() > 0)
            {
                line();
                centerText("Enemy " + brock->getName() + " attacking");
                line();

                int randomAttack = rand() % 2;

                int attackPokemonDamage = brock->attackPokemon(c.getPokemon()[choice - 1], randomAttack);
                c.getPokemon()[choice - 1]->defend(attackPokemonDamage);

                //display attack
                line();
                std::cout << brock->getName() << " used " << brock->getAttackName(randomAttack);
                std::cout << ". Attack did " << attackPokemonDamage << " damage." << std::endl;
                std::cout << c.getPokemon()[choice - 1]->getCharacterName() << " health: "
                          << c.getPokemon()[choice - 1]->getHealth() << std::endl;
                std::cout << brock->getName() << " health: "
                          << brock->getHealth();
                line();
            }

            //if Brocks Pokemon health is 0, user has defeated Brock
            else if (brock->getHealth() < 1)
            {
                victory = true;
            }

            //determine if user still has a Pokemon that is alive for next loop
            for (int i = 0; i < c.getPokemon().size(); ++i)
            {

                if (c.getPokemon()[i]->getHealth() > 0)
                {
                    atLeastOneAlive = true;
                }
            }
        }

        //move on to fight Misty
        if (victory == true)
        {
            c.setCurrentSpace(boss);
            line();
            centerText("You beat Brock!");
            line();
        }

        delete brock;

        return victory;
        break;
    }
    }

    return true;
}
