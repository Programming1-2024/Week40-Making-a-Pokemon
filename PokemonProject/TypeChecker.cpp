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
	std::vector<Type> weakVector = weakness.at(typePokemon);
	bool isWeak = std::count(weakVector.begin(), weakVector.end(), typeMove);
	return isWeak;
}

bool TypeChecker::isResistantTo(Type typePokemon, Type typeMove)
{
	std::vector<Type> resistantVector = resistance.at(typePokemon);
	bool isResistant = std::count(resistantVector.begin(), resistantVector.end(), typeMove);
	return isResistant;
}

TypeChecker::~TypeChecker()
{
	delete instance;
}
