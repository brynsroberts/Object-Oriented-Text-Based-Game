# Pokemon Command Line Game

## Authors

* **Bryan Roberts**

## Objective

This project was based around designing and implementing a one-player, text-based game where the player can move through spaces to get items and accomplish goals.  The game uses a Space class, which represents the space the player can be in. The Space class is an abstract class that has pure virtual functions.  Inside the Space class, there are Space pointers to different locations available to interact with in the game.  The game has 4 derived classes that are derived from the Space class, each representing a different type of Space, and have a special action for the player to interact with. 

## To Run

Change to src directory.  In command line type "make".  Executable will be named main.  To run type "./main".

## Spaces                              

 * Town Center:    The central hub for all other spaces. Can use this
                space to travel to other spaces or exit the game.

 * Hospital:       Use this space to heal your Pokemon. It will cost you one coin
                for every Pokemon you heal.

 * Store:          Purchase potions or Pokeballs from this space. Potions will
                restore full health to your Pokemon and can be used in battle.
                Use Pokeballs to catch wild Pokemon you find at the Catch space.

  * Catch:          Find wild Pokemon to battle and catch. You can hold up to three 
                Pokemon in your inventory, including your starting Pokemon.
                Pokemon are easier to catch when they have lower health.

 * Gym:            Battle Brock and gym master Misty in order to get the gym badge
                and win the game. Once you enter the gym, you must beat both
                Brock and Misty to win the game.
               
## Source

* CS 162   Introduction to Computer Science II Programming Portfolio Project


