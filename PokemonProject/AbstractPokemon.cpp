#include "AbstractPokemon.h"

AbstractPokemon::AbstractPokemon(int MaxHP, Move startMove, Type primaryType, Type secondaryType)
{
    //TODO: set value of field variables to values passed to the constructor. Hint: the vector requires .push_back()
}

int AbstractPokemon::DamageThis(Move moveUsed)
{
    return 0;
}

bool AbstractPokemon::hasFainted()
{
    return false;
}

Move AbstractPokemon::GetMove(int moveIndex)
{
    return Move();
}

bool AbstractPokemon::AddMove(Move newMove)
{
    return false;
}
