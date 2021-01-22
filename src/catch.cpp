/*********************************************************************
** Program name: catch.cpp
** Author: Bryan Roberts
** Date: 5/26/19
** Description: Catch class source file.
*********************************************************************/

#include <iostream>
#include <cstdlib> //for random number generation
#include <ctime>   //for random number generation
#include "catch.hpp"
#include "character.hpp"
#include "validation.hpp"
#include "squirtle.hpp"
#include "charmander.hpp"
#include "bulbasaur.hpp"

/********************************************************************* 
** Description: Constructor for derived space.
*********************************************************************/
Catch::Catch()
{
    setTop(nullptr);
    setBottom(nullptr);
    setLeft(nullptr);
    setBottom(nullptr);
    setSpaceName("Catch");
}

/********************************************************************* 
** Description: Menu function that performs all actions for catch
class.  Catch class allows user to catch wild Pokemon and add them
to their inventory.  User can only add three Pokemon to their
inventory.
*********************************************************************/
bool Catch::menu(Character &c)
{
    bool full = (c.getPokemon().size() > 2);

    line();
    centerText("CATCH POKEMON");
    line();

    //if user Pokemon inventory is full, skip out of function
    if (!full)
    {

        std::cout << "1) Display Inventory and Pokemon\n";
        std::cout << "2) Change space\n";
        std::cout << "3) Display location\n";
        std::cout << "4) Catch Pokemon\n";

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

        //perform based on user choice
        switch (choice)
        {

        //display inventory
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

            //set user space to change to
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

        //display current location
        case 3:
        {
            line();
            centerText("DISPLAY LOCATION");
            line();

            std::cout << "Current Space:\t\tCatch Pokemon\n";
            std::cout << "Top Space:\t\tTown Center\n";
            line();

            return true;
            break;
        }

        //catch wild Pokemon to add to inventory
        case 4:
        {
            line();
            centerText("CATCH POKEMON");
            line();

            int randomPokemon = rand() % 3;
            Pokemon *attackingPokemon;

            //generate random Pokemon to fight
            switch (randomPokemon)
            {
            case 0:
            {
                attackingPokemon = new Squirtle;
                break;
            }
            case 1:
            {
                attackingPokemon = new Charmander;
                break;
            }
            case 2:
            {
                attackingPokemon = new Bulbasaur;
                break;
            }
            }

            line();
            centerText("A wild " + attackingPokemon->getName() + " appeared!");
            line();

            centerText("Which Pokemon you would like to use?");
            line();

            //Display user Pokemon to fight with
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

            //select Pokemon to fight with
            bool b = false;  //for return type
            int choice = -1; //for user input
            bool d = false;  // for number of Pokemon

            do
            {
                std::string input; //place holder for string input
                std::cin >> input;

                //input validation
                if (isInt(input))
                {
                    choice = stringToInt(input);
                }
                if (choice <= c.getPokemon().size() && (choice > 0))
                {
                    d = c.getPokemon()[choice - 1]->getHealth() > 0;
                }
                else
                {
                    d = false;
                }

                b = intRange(choice, 1, c.getPokemon().size());
            } while (!dataType() || !b || !(d));

            line();
            centerText("Begin battle");
            line();

            bool caught = false;
            bool atLeastOneAlive = false;

            //set bool for whether user has Pokemon that is alive
            for (int i = 0; i < c.getPokemon().size(); ++i)
            {
                if (c.getPokemon()[i]->getHealth() > 0)
                {
                    atLeastOneAlive = true;
                }
            }

            //battle wild Pokemon
            while (!caught && attackingPokemon->getHealth() > 0 && atLeastOneAlive)
            {

                int attackingMove = -1; //for user input

                //User decides action for move
                if (c.getPokemon()[choice - 1]->getHealth() > 0)
                {
                    line();
                    centerText(c.getPokemon()[choice - 1]->getCharacterName() + " attacking");
                    line();

                    std::cout << "1) " << c.getPokemon()[choice - 1]->getAttackName(0) << std::endl;
                    std::cout << "2) " << c.getPokemon()[choice - 1]->getAttackName(1) << std::endl;
                    std::cout << "3) Throw Pokeball\n";
                    std::cout << "4) Change Pokemon\n";
                    std::cout << "5) Use Potion\n";

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

                        //if Pokemon has fainted
                        if (!(c.getPokemon()[choice - 1]->getHealth() > 0))
                        {
                            line();
                            centerText("Please pick a Pokemon that has not fainted");
                            line();
                        }

                        b = intRange(attackingMove, 1, 5);
                    } while (!dataType() || !b);
                }

                //If Pokemon has fainted, pick a new Pokemon
                else
                {
                    attackingMove = 4;
                }

                //Peform picked action
                switch (attackingMove)
                {

                //attack 1, normal attack
                case 1:
                {
                    int attack = c.getPokemon()[choice - 1]->attackPokemon(attackingPokemon, 0);
                    attackingPokemon->defend(attack);

                    //Display attack results
                    line();
                    std::cout << c.getPokemon()[choice - 1]->getCharacterName() << " used " << c.getPokemon()[choice - 1]->getAttackName(0);
                    std::cout << ". Attack did " << attack << " damage." << std::endl;

                    std::cout << c.getPokemon()[choice - 1]->getCharacterName() << " health: "
                              << c.getPokemon()[choice - 1]->getHealth() << std::endl;
                    std::cout << attackingPokemon->getName() << " health: "
                              << attackingPokemon->getHealth();
                    line();

                    break;
                }

                //attack 2, special attack type
                case 2:
                {
                    int attack = c.getPokemon()[choice - 1]->attackPokemon(attackingPokemon, 1);
                    attackingPokemon->defend(attack);

                    //Display attack results
                    line();
                    std::cout << c.getPokemon()[choice - 1]->getCharacterName() << " used " << c.getPokemon()[choice - 1]->getAttackName(1);
                    std::cout << ". Attack did " << attack << " damage." << std::endl;

                    std::cout << c.getPokemon()[choice - 1]->getCharacterName() << " health: "
                              << c.getPokemon()[choice - 1]->getHealth() << std::endl;
                    std::cout << attackingPokemon->getName() << " health: "
                              << attackingPokemon->getHealth();
                    line();

                    break;
                }

                //catch pokemon
                case 3:
                {
                    line();
                    centerText("CATCH POKEMON");
                    line();

                    //User throws a Pokeball, different probability for lower attacking Pokemon health
                    if ((c.getPokeballs() > 0) && c.getPokemon().size() < 4)
                    {
                        int chance = rand() % 100 + 1;

                        c.setPokeballs(c.getPokeballs() - 1);

                        //if Pokemon health less than 30
                        if (attackingPokemon->getHealth() > 30)
                        {
                            if (chance >= 75)
                            {
                                c.setPokemon(attackingPokemon->getType());
                                c.getPokemon().back()->setHealth(attackingPokemon->getHealth());
                                caught = true;
                            }
                        }

                        //if Pokemon health less than 20
                        else if (attackingPokemon->getHealth() > 20)
                        {
                            if (chance >= 50)
                            {
                                c.setPokemon(attackingPokemon->getType());
                                c.getPokemon().back()->setHealth(attackingPokemon->getHealth());
                                caught = true;
                            }
                        }

                        //if Pokemon health less than 10
                        else if (attackingPokemon->getHealth() > 10)
                        {
                            if (chance >= 25)
                            {
                                c.setPokemon(attackingPokemon->getType());
                                c.getPokemon().back()->setHealth(attackingPokemon->getHealth());
                                caught = true;
                            }
                        }

                        //if Pokemon health less than 10
                        else
                        {
                            c.setPokemon(attackingPokemon->getType());
                            c.getPokemon().back()->setHealth(attackingPokemon->getHealth());
                            caught = true;
                        }

                        //Display if user caught the Pokemon
                        if (caught)
                        {
                            line();
                            centerText("You caught " + c.getPokemon().back()->getName() + "!");
                            line();

                            std::cout << "Please pick a name for your pokemon:" << std::endl;

                            std::string userName;
                            std::getline(std::cin, userName);

                            c.getPokemon().back()->setCharacterName(userName);
                        }
                        else
                        {
                            line();
                            centerText("Pokeball failed!");
                            line();
                        }
                    }

                    //user has no Pokeballs
                    else if (c.getPokeballs() <= 0)
                    {
                        line();
                        centerText("You don't have any Pokeballs left");
                        line();
                    }

                    //user cant catch a Pokemon, inventory full
                    else if (c.getPokemon().size() > 2)
                    {
                        line();
                        centerText("You can only hold 3 Pokemon in your inventory");
                        line();
                    }

                    break;
                }

                //change Pokemon during battle
                case 4:
                {
                    line();
                    centerText("CHANGE POKEMON");
                    line();

                    bool b = false; //for return type
                    atLeastOneAlive = false;

                    //if at least one user Pokemon is alive
                    for (int i = 0; i < c.getPokemon().size(); ++i)
                    {
                        if (c.getPokemon()[i]->getHealth() > 0)
                        {
                            atLeastOneAlive = true;
                        }
                    }

                    //Display user has alive Pokemon, let user pick alive Pokemon
                    if (atLeastOneAlive)
                    {
                        choice = -1;
                        bool d = false;
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

                            //if user picks a Pokemon that has fainted
                            if (!(d))
                            {
                                line();
                                centerText("Please pick a Pokemon that has not fainted");
                                line();
                            }

                        } while (!dataType() || (!b && atLeastOneAlive) || !(d));
                    }
                    break;
                }

                //use potion during battle
                case 5:
                {
                    line();
                    centerText("USE POTION");
                    line();

                    if (c.getPotions() > 0)
                    {
                        c.setPotions(c.getPotions() - 1);
                        c.getPokemon()[choice - 1]->setHealth(c.getPokemon()[choice - 1]->getHealth() + 100);

                        //update health of different Pokemon types
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

                //attack Pokemon does turn, attacks user Pokemon
                if (attackingPokemon->getHealth() > 0 && !caught && c.getPokemon()[choice - 1]->getHealth() > 0)
                {
                    line();
                    centerText("Enemy " + attackingPokemon->getName() + " attacking");
                    line();

                    int randomAttack = rand() % 2;

                    int attackPokemonDamage = attackingPokemon->attackPokemon(c.getPokemon()[choice - 1], randomAttack);
                    c.getPokemon()[choice - 1]->defend(attackPokemonDamage);

                    //Display attack
                    line();
                    std::cout << attackingPokemon->getName() << " used " << attackingPokemon->getAttackName(randomAttack);
                    std::cout << ". Attack did " << attackPokemonDamage << " damage." << std::endl;
                    std::cout << c.getPokemon()[choice - 1]->getCharacterName() << " health: "
                              << c.getPokemon()[choice - 1]->getHealth() << std::endl;
                    std::cout << attackingPokemon->getName() << " health: "
                              << attackingPokemon->getHealth();
                    line();
                }

                //Display if user defeated attacking Pokemon
                if (attackingPokemon->getHealth() <= 0)
                {
                    line();
                    centerText(attackingPokemon->getName() + " fainted!  Ending combat");
                    line();
                }

                //determine if at least one user Pokemon is alive for next loop iteration
                for (int i = 0; i < c.getPokemon().size(); ++i)
                {

                    if (c.getPokemon()[i]->getHealth() > 0)
                    {
                        atLeastOneAlive = true;
                    }
                }
            }

            delete attackingPokemon;

            return true;
            break;
        }
        }

        return true;
    }
    else
    {
        line();
        centerText("Your Pokemon inventory is full.  You can't catch any more Pokemon");
        line();
        c.setCurrentSpace(townCenter);
        return true;
    }
}