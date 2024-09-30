#pragma once
#include "AbstractPokemon.h"

class Pokemon :
    public AbstractPokemon
{
public:
	Pokemon(int MaxHP, Move startMove, Type primaryType, Type secondaryType = NONE) : AbstractPokemon(MaxHP, startMove, primaryType, secondaryType) {
	}

};

