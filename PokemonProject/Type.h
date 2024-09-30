#pragma once

/**
* Enum to store Pokemon and Move elemental types.
* 
* Type weaknesses are handeled in TypeChecker
* 
* Note: this is an enum also known as enumeration. it lets you give a name to integer values
* and also restrict which values are valid to use, which makes the code more robust to human error
* as well as increasing readability.
*/
enum Type {
	NONE = 1,
	FIRE = 2,
	WATER = 4,
	GRASS = 8
};