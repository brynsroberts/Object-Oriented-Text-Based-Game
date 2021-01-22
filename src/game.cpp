/*********************************************************************
** Program name: game.cpp
** Author: Bryan Roberts
** Date: 5/26/19
** Description: Game class source file.
*********************************************************************/

#include <iostream>
#include "game.hpp"
#include "validation.hpp"

/********************************************************************* 
** Description: Constructor.  Set all space pointers to correct
location.  Start player in towncenter.
*********************************************************************/
Game::Game()
{
    townCenter = new TownCenter;
    hospital = new Hospital;
    store = new Store;
    catchPokemon = new Catch;
    gym = new Gym;
    boss = new Boss;

    townCenter->setTop(gym);
    townCenter->setLeft(hospital);
    townCenter->setRight(store);
    townCenter->setBottom(catchPokemon);

    hospital->setRight(townCenter);

    store->setLeft(townCenter);

    catchPokemon->setTop(townCenter);

    gym->setBottom(townCenter);
    gym->setTop(boss);

    boss->setBottom(townCenter);

    playerSpace = townCenter;
}

/********************************************************************* 
** Description: Destructor.  Delete stack memory.
*********************************************************************/
Game::~Game()
{
    delete townCenter;
    delete hospital;
    delete store;
    delete catchPokemon;
    delete gym;
    delete boss;

    townCenter = nullptr;
    hospital = nullptr;
    store = nullptr;
    catchPokemon = nullptr;
    gym = nullptr;
    boss = nullptr;
}

/********************************************************************* 
** Description: Return data member player of type class Character.
*********************************************************************/
Character Game::getPlayer()
{
    return player;
}

/********************************************************************* 
** Description: Set play space to pointer to derived space based
on player data member currentspace.
*********************************************************************/
void Game::setPlayerSpace(Space *temp)
{

    if (temp == townCenter)
    {
        //hospital
        if (static_cast<int>(player.getCurrentSpace()) == 2)
        {
            playerSpace = townCenter->getLeft();
        }
        //store
        else if (static_cast<int>(player.getCurrentSpace()) == 1)
        {
            playerSpace = townCenter->getRight();
        }
        //catch Pokemon
        else if (static_cast<int>(player.getCurrentSpace()) == 3)
        {
            playerSpace = townCenter->getBottom();
        }
        else if (static_cast<int>(player.getCurrentSpace()) == 4)
        {
            playerSpace = townCenter->getTop();
        }
    }
    else if (temp == hospital)
    {
        //town center
        if (static_cast<int>(player.getCurrentSpace()) == 0)
        {
            playerSpace = hospital->getRight();
        }
    }
    else if (temp == store)
    {
        //town center
        if (static_cast<int>(player.getCurrentSpace()) == 0)
        {
            playerSpace = store->getLeft();
        }
    }
    else if (temp == catchPokemon)
    {
        //town center
        if (static_cast<int>(player.getCurrentSpace()) == 0)
        {
            playerSpace = catchPokemon->getTop();
        }
    }
    else if (temp == gym)
    {
        //boss
        if (static_cast<int>(player.getCurrentSpace()) == 5)
        {
            playerSpace = gym->getTop();
        }
    }
}

/********************************************************************* 
** Description: Display character inventory.
*********************************************************************/
void Game::displayInventory()
{
    line();
    centerText("INVENTORY");
    line();

    std::cout << "Money:\t\t" << player.getMoney() << std::endl;
    std::cout << "Pokeballs:\t" << player.getPokeballs() << std::endl;
    std::cout << "Potions:\t" << player.getPotions() << std::endl;
    std::cout << "Badge:\t\t" << player.getBadge() << std::endl;

    line();
    centerText("POKEMON");
    line();

    for (int i = 0; i < player.getPokemon().size(); ++i)
    {
        std::cout << "Type:\t\t" << player.getPokemon()[i]->getName() << std::endl;
        std::cout << "Name:\t\t" << player.getPokemon()[i]->getCharacterName() << std::endl;
        std::cout << "Health:\t\t" << player.getPokemon()[i]->getHealth() << std::endl;
        std::cout << "Attack 1:\t" << player.getPokemon()[i]->getAttackName(0) << " ("
                  << player.getPokemon()[i]->getAttackMoves(0) << "/" << player.getPokemon()[i]->getAttackTotalMoves(0)
                  << ")" << std::endl;
        std::cout << "Attack 2:\t" << player.getPokemon()[i]->getAttackName(1) << " ("
                  << player.getPokemon()[i]->getAttackMoves(1) << "/" << player.getPokemon()[i]->getAttackTotalMoves(1)
                  << ")";
        line();
    }
}

/********************************************************************* 
** Description: Pick starting Pokemon for game.  Can pick from
three starting Pokemon.  Puts them in your Pokemon inventory.
*********************************************************************/
void Game::pickStartingPokemon()
{
    line();
    centerText("Please pick your starting Pokemon");
    line();

    std::cout << "1) Charmander\n";
    std::cout << "2) Bulbasaur\n";
    std::cout << "3) Squirtle\n";

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

        b = intRange(choice, 1, 3);
    } while (!dataType() || !b);

    switch (choice)
    {
    case 1:
    {
        player.setPokemon(fire);
        break;
    }
    case 2:
    {
        player.setPokemon(grass);
        break;
    }
    case 3:
    {
        player.setPokemon(water);
        break;
    }
    }

    line();
    centerText("Please pick a name for your Pokemon");
    line();

    std::string userName;
    std::getline(std::cin, userName);

    player.getPokemon()[0]->setCharacterName(userName);

    line();
    centerText("Starting Inventory");
    line();
    player.displayInventory();
}

/********************************************************************* 
** Description: Game simulation.  Displays how the game works and
different spaces user can go to.  Will cycle through different 
player spaces based on user input.  Game will end player defeats
Misty or all Pokemon faint.
*********************************************************************/
void Game::playGame()
{

    line();
    centerText("Welcome to my Pokemon game!");
    line();
    std::cout << "Objective:\tYou need to defeat Brock and gym master Misty to win the game.\n"
              << "\t\tBoth are located in the gym. You need to have at least two Pokemon\n"
              << "\t\tin your inventory to enter the gym. Once you enter the gym you will\n"
              << "\t\tnot be able to leave until you have defeated both of them or all\n"
              << "\t\tyour Pokemon have fainted. The game will end if all your Pokemon\n"
              << "\t\tfaint. Pokemon faint when their health reaches 0.";

    line();
    centerText("Locations");
    line();
    std::cout << "Town Center:\tThe central hub for all other locations. Can use this\n"
              << "\t\tlocation to travel to other locations or exit the game.\n\n"
              << "Hospital:\tUse this location to heal your Pokemon. It will cost you one coin\n"
              << "\t\tfor every Pokemon you heal.\n\n"
              << "Store:\t\tPurchase potions or Pokeballs from this location. Potions will\n"
              << "\t\trestore full health to your Pokemon and can be used in battle.\n"
              << "\t\tUse Pokeballs to catch wild Pokemon you find at the Catch location.\n\n"
              << "Catch:\t\tFind wild Pokemon to battle and catch. You can hold up to three \n"
              << "\t\tPokemon in your inventory, including your starting Pokemon.\n"
              << "\t\tPokemon are easier to catch when they have lower health.\n\n"
              << "Gym:\t\tBattle Brock and gym master Misty in order to get the gym badge\n"
              << "\t\tand win the game. Once you enter the gym, you must beat both\n"
              << "\t\tBrock and Misty to win the game.";

    line();
    centerText("Requirements");
    line();
    std::cout << "Theme:\t\tPokemon simulation\n\n"
              << "Space Derived:\tTown Center, Hospital, Store, Catch, Gym, Boss\n\n"
              << "Goal:\t\tDefeat Brock and gym master Misty to obtain gym badge. You must\n"
              << "\t\thave at least 2 Pokemon in your inventory to progress to the gym\n" 
              << "\t\tspace.\n\n"
              << "Container:\tPokemon container that is limited to three Pokemon.  Container\n"
              << "\t\tfor Pokeballs and potions as well with no limit.\n\n"
              << "Time limit:\tHealth system.  If all Pokemon in inventory faint, game ends.";
    
    line();

    pickStartingPokemon();
    bool b; //for menu returning true or false
    bool d; //for exit game
    Space *tempPlayerSpace = playerSpace;

    //continue until menu returns false or all user Pokemon have fainted
    do
    {
        
        setPlayerSpace(tempPlayerSpace);
        b = playerSpace->menu(player);
        d = exitGame();

        if (!d)
        {
            line();
            centerText("All your Pokemon have fainted");
            line();

            line();
            centerText("GAME OVER");
            line();
        }

        tempPlayerSpace = playerSpace;
    } while (d && b);
}

/********************************************************************* 
** Description: Check if all Pokemon have fainted.  If so return
bool false.  Otherwise if at least one Pokemon is alive, return true.
*********************************************************************/
bool Game::exitGame()
{
    bool atLeastOneAlive = false;
    for (int i = 0; i < player.getPokemon().size(); ++i)
    {
        if (player.getPokemon()[i]->getHealth() > 0)
        {
            atLeastOneAlive = true;
        }
    }

    return atLeastOneAlive;
}