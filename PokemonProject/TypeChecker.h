#pragma once
#include "Type.h"
#include <map>
#include <vector>

class TypeChecker
{
private:
	TypeChecker();
	~TypeChecker();

	void initWeakness();
	void initResistance();

	std::map< Type, std::vector<Type> > weakness;
	std::map< Type, std::vector<Type> > resistance;

public:
	static TypeChecker& getInstance();
	static void deleteInstance();
	
	bool isWeakTo(Type typePokemon, Type typeMove);
	bool isResistantTo(Type typePokemon, Type typeMove);

	
};

