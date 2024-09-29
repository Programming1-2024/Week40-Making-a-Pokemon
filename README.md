# Week40-Making-a-Pokemon

Hello gametech students! From now on we will be using object oriented programming in these exercises, and therefore i will use this opportunity to make the exercise video game related. I am also excited to share that i fixed my test not running issues by uninstalling unreal engine test adapter, which means i can now make tests to guide you again. The exercise this time might be quite large, but i hope it will be a fun task! i will also be using a few things you might not have learnt yet: [enumeration](https://en.cppreference.com/w/c/language/enum), [maps](https://cplusplus.com/reference/map/map/), [interfaces](https://learn.microsoft.com/en-us/cpp/cppcx/interfaces-c-cx?view=msvc-170), and [singleton](https://en.wikipedia.org/wiki/Singleton_pattern).

You will be making a pokemon and the functions needed to support a pokemon battle! There are a lot more files than you might be used to here, so i will be explaining what every file needs. for this exercise we will ignore that pokemon have special and physical attacks as well as defence. we also ignore a move's accuracy.

our list of items needs to be
- IPokemon (interface)
- AbstractPokemon (abstract class)
- Pokemon (class)
- Type (enumeration)
- Move (struct)
- TypeChecker (class, our singleton)

## IPokemon

- you can deal damage to a pokemon with Damage(Move moveUsed)
- you can get the pokemon's move with GetMove(int moveIndex), which throws an error if the index is not between 0 and 3, and returns a move of type "None" with Power = 0
- you can check if a pokemon has fainted using HasFainted(), which returns true if pokemon has fainted and 0 otherwise. a pokemon has fainted if it's health is 0 or less
- you can add a move to a pokemon using AddMove(Move newMove), which returns 0 if the pokemon cannot remember any more moves

## AbstractPokemon

an abstract pokemon inherits from IPokemon

- A pokemon has two Type, for this exercise we will be restricting ourself to "NONE", "WATER", "FIRE", and "GRASS".
- A pokemon has from 1 to 4 Move, stored in a vector.
- A pokemon has a HPmax and a HPcurrent of datatype int.
- a protected constructor which takes two Type, a Move, and a int (as MaxHP).

AbstractPokemon implements the functions from IPokemon.
the constructor sets the values of its field variables (also known as its global variables)

## Pokemon

A Pokemon inherits from AbstractPokemon.

- a pokemon has a constructor which takes two Type, a Move, and int. the constructor calls AbstractPokemon constructor and gives it these variables.

## Type

is an enumerator. Note: it is not a class enumerator

type can have four values

- NONE = 1
- WATER = 2
- FIRE = 4
- GRASS = 8

## Move

a move is a struct.

a move has

- a type of datatype Type, which is the damage type of the move.
- a name of datatype std::string
- a power of datatype int.

## TypeChecker
is a class and it's constructor is private.

- has a function `public: static TypeChecker& Get()` which calls the constructor only if `instance == nullptr`, and always returns `*instance`. Note: the & and * symbols are not typos
- has a std::map called Weakness. the key is Type and the value is std::vector<Type>. the value holds all types the key is weak to.
- all elements are added to the Weakness map in the constructor.
- FIRE is weak to WATER. WATER is weak to GRASS. GRASS is weak to FIRE. NONE has no weakness
- has a function IsWeakTo(Type PokemonType, Type TypeMoveType). it gets the vector<Type> from Weakness using PokemonType as the key, and checks if MoveType is in the vector. returns true if MoveType is in the vector, meaning the pokemon is weak to the type; returns false otherwise.
