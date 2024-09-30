#include "Pokemon.h"

Pokemon::Pokemon(std::string pokemonName, int MaxHP, Move startMove, Type primaryType, Type secondaryType) : AbstractPokemon(pokemonName, MaxHP, startMove, primaryType, secondaryType)
{
}

int Pokemon::DamageThis(Move moveUsed)
{
	//README! VERY IMPORTANT!
	//Whenever a function is inherited from a parent class, and you override it (see line 12 in Pokemon.h)
	//you must call the parent class function in the child class function.
	//This is because the parent class function may have some important code that you need to run.

	//in this case, it allows you to implement the important code in the parent, and let the child modify it if needed.

	int damageTaken = AbstractPokemon::DamageThis(moveUsed); // example of how to call a parent class function
	return damageTaken;
}

bool Pokemon::hasFainted()
{
	return false;
}

Move Pokemon::GetMove(int moveIndex)
{
	return Move();
}

bool Pokemon::AddMove(Move newMove)
{
	return false;
}
