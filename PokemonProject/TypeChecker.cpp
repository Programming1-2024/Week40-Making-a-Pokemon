#include "TypeChecker.h"


static TypeChecker* instance;

TypeChecker::TypeChecker()
{
	initWeakness();
	initResistance();
}

void TypeChecker::initWeakness()
{

	weakness[FIRE].push_back(WATER);
	weakness[WATER].push_back(GRASS);
	weakness[GRASS].push_back(FIRE);
}

void TypeChecker::initResistance()
{
	resistance[FIRE].push_back(GRASS);
	resistance[WATER].push_back(FIRE);
	resistance[GRASS].push_back(WATER);
}

TypeChecker& TypeChecker::getInstance()
{
	if (instance == nullptr)
	{
		instance = new TypeChecker;
	}
	return *instance;
}

void TypeChecker::deleteInstance()
{
	delete instance;
}

bool TypeChecker::isWeakTo(Type typePokemon, Type typeMove)
{
	bool isWeak = false;

	if (typePokemon == NONE || typeMove == NONE)
	{
		return isWeak;
	}

	std::vector<Type> weakVector = weakness.at(typePokemon);
	isWeak = std::count(weakVector.begin(), weakVector.end(), typeMove);
	return isWeak;
}

bool TypeChecker::isResistantTo(Type typePokemon, Type typeMove)
{
	bool isResistant = false;

	if (typePokemon == NONE || typeMove == NONE)
	{
		return isResistant;
	}

	std::vector<Type> resistantVector = resistance.at(typePokemon);
	isResistant = std::count(resistantVector.begin(), resistantVector.end(), typeMove);
	return isResistant;
}

TypeChecker::~TypeChecker()
{
	delete instance;
}
