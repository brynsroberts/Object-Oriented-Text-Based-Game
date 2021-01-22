/*********************************************************************
** Program name: pokemon.hpp
** Author: Bryan Roberts
** Date: 5/26/19
** Description: Pokemon abstract class header file.
*********************************************************************/

#ifndef POKEMON_HPP
#define POKEMON_HPP

#include <string>

enum Type
{
    grass,
    water,
    fire,
    normal
};
struct Attack
{
    std::string attackName;
    Type attackType;
    int attackDamage;
    int moves;
    int totalMoves;
};

class Pokemon
{
protected:
    std::string name;
    std::string characterName;
    Type type;
    int health;
    Attack attack[2];

public:
    virtual ~Pokemon();
    virtual std::string getName();
    virtual std::string getCharacterName();
    virtual Type getType();
    virtual int getHealth();
    virtual std::string getAttackName(int);
    virtual Type getAttackType(int);
    virtual int getAttackDamage(int);
    virtual int getAttackMoves(int);
    virtual int getAttackTotalMoves(int);
    virtual void setName(std::string);
    virtual void setCharacterName(std::string);
    virtual void setType(Type);
    virtual void setHealth(int);
    virtual void setAttack(std::string, Type, int, int, int, int);
    virtual int attackPokemon(Pokemon *, int);
    virtual int defend(int);
};

#endif