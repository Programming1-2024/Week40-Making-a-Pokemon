#pragma once
#include "AbstractPokemon.h"

class Pokemon :
    public AbstractPokemon
{
public:
	Pokemon(std::string pokemonName, int MaxHP, Move startMove, Type primaryType, Type secondaryType = NONE);


	// Inherited via IPokemon
	virtual int DamageThis(Move moveUsed) override;
	virtual bool hasFainted() override;
	virtual Move GetMove(int moveIndex) override;
	virtual bool AddMove(Move newMove) override;
};

