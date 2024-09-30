#pragma once
#include "Type.h"
#include <string>

struct Move {
	Type moveType;
	std::string moveName;
	int movePower;
};