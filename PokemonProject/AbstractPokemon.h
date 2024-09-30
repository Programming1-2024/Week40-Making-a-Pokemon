#pragma once
#include "IPokemon.h"
#include <vector>

/**
* Abstract class for Pokemon.
* 
* An abstract class is like an interface, but can contain variables and can implement some functions.
* An abstract class can also contain pure virtual functions, which a child class must implement.
* 
* IMPORTANT: An abstract class cannot be instantiated, only inherited.
*/
class AbstractPokemon :
	public IPokemon // this ": public IPokemon" means that AbstractPokemon inherits from IPokemon
{
public: //protected means that only children can access these variables and functions
	AbstractPokemon(std::string pokemonName, int MaxHP, Move startMove, Type typeOne, Type typeTwo = NONE);

	int HPcurrent;
	int HPmax;
	Type typePrimary;
	Type typeSecondary;
	std::vector<Move> moveList;
	std::string name;


public:

	// Inherited via IPokemon.
	//TODO: implement these functions in the AbstractPokemon cpp file
	virtual int DamageThis(Move moveUsed) override;
	virtual bool hasFainted() override;
	virtual Move GetMove(int moveIndex) override;
	virtual bool AddMove(Move newMove) override;



	// Inherited via IPokemon
	std::string GetName() override;

};

