#pragma once
#include "Move.h"

/**
* Interface for Pokemon class.
* 
* An interface is a class which ONLY contains pure citrual functions.
* If any functions are not pure virtual, or the interface contains variables, it is instead an abstract class.
* 
* An interface is inherited by its children, and the children must implement all its pure virtual functions.
* This means that other classes can cast a pokemon to the IPokemon class, and trust that the implementation
* of the functions will be correct.
* 
* A pure virtual function is a funcion that can be overriden by children, and which is not implemented in the
* parent class.
*/
class IPokemon {
	/**
	* Deal damage to this Pokemon. Damage will leave the Pokemon at minimum 0 HP.
	* Negative Damage values do not affect the Pokemon HP.
	* 
	* Damage done is equal to the move's power.
	* If the move is super effective, the damage is doubled.
	* If the move is not very effective, the damage is halved.
	* 
	* Damage weakness and resistance is stored in TypeChecker.
	* 
	* @param moveUsed The move used to deal damage.
	* @return The damage dealt to the Pokemon. If the pokemon has 2 Hp and move deals 10 damage, the return value is 2.
	*/
	virtual int DamageThis(Move moveUsed) = 0;

	/**
	* Has the pokemon fainted? if the pokemon has 0 or less HP, it has fainted.
	* 
	* @return True if the pokemon has fainted, false otherwise.
	*/
	virtual bool hasFainted() = 0;

	/**
	* Get the Pokemon's move at the given index, zero indexes.
	* If the index is more than 3 or less than 0, return a move with Type NONE and Power 0 and name "ERROR".
	* 
	* @param moveIndex The index of the move to get.
	* @return The move at the given index.
	*/
	virtual Move GetMove(int moveIndex) = 0;

	/**
	* Add a move to the Pokemon's move list.
	* If the Pokemon already has 4 moves, return false and don't add the move.
	* otherwise return 1
	* 
	* @param newMove The move to add to the Pokemon's move list.
	* @return True if the move was added, false otherwise.
	*/
	virtual bool AddMove(Move newMove) = 0;
};