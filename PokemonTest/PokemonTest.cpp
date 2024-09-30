#include "pch.h"
#include "CppUnitTest.h"
#include "../PokemonProject/Pokemon.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace PokemonTest
{
	TEST_CLASS(PokemonTestClass)
	{
	public:
		
		TEST_METHOD(Control)
		{
			Assert::IsTrue(true);
		}

		TEST_METHOD(Piplup) //best starter
		{
			Move Bubble = { Type::WATER, "Bubble", 20 };
			Pokemon Piplup("Piplup", 20, Bubble, Type::WATER);

			Assert::IsFalse(Piplup.GetName().compare("Piplup")); //compare returns 0 if the strings are equal, which casts to false
			Assert::IsTrue(Piplup.GetName().compare("Turtwig"));
			Assert::IsTrue(Piplup.GetName().compare("Chimchar"));
		}

		TEST_METHOD(Turtwig) //and a very happy boi
		{
			Move Absorb = { Type::GRASS, "Absorb", 20 };
			Pokemon Turtwig("Turtwig", 24, Absorb, Type::GRASS);

			Assert::IsFalse(Turtwig.GetName().compare("Turtwig")); //compare returns 0 if the strings are equal, which casts to false
			Assert::IsTrue(Turtwig.GetName().compare("Piplup"));
			Assert::IsTrue(Turtwig.GetName().compare("Chimchar"));
		}

		TEST_METHOD(Chimchar)
		{
			Move Ember = { Type::FIRE, "Ember", 40 };
			Pokemon Chimchar("Chimchar", 16, Ember, Type::FIRE);

			Assert::IsFalse(Chimchar.GetName().compare("Chimchar")); //compare returns 0 if the strings are equal, which casts to false
			Assert::IsTrue(Chimchar.GetName().compare("Turtwig"));
			Assert::IsTrue(Chimchar.GetName().compare("Piplup"));
		}

		TEST_METHOD(NumberOfMoves) {
			Move Ember = { Type::FIRE, "Ember", 40 };
			Move Bubble = { Type::WATER, "Bubble", 20 };
			Move Absorb = { Type::GRASS, "Absorb", 20 };
			Move None = { Type::NONE, "None", 0 };

			Pokemon MissingNo("MissingNo", 100, None, Type::NONE);
			bool SecondMove = MissingNo.AddMove(Ember);
			bool ThirdMove = MissingNo.AddMove(Bubble);
			bool FourthMove = MissingNo.AddMove(Absorb);
			bool FifthMove = MissingNo.AddMove(None);

			Assert::IsTrue(SecondMove);
			Assert::IsTrue(ThirdMove);
			Assert::IsTrue(FourthMove);
			Assert::IsFalse(FifthMove);
		}

		TEST_METHOD(DamageThis) {
			Move Ember = { Type::FIRE, "Ember", 40 };
			Move Bubble = { Type::WATER, "Bubble", 20 };
			Move Absorb = { Type::GRASS, "Absorb", 20 };
			Move None = { Type::NONE, "None", 0 };

			Pokemon MissingNo("MissingNo", 100, None, Type::NONE);
			Pokemon Squishy("Squishy", 10, None, Type::NONE);
			MissingNo.AddMove(Ember);
			MissingNo.AddMove(Bubble);
			MissingNo.AddMove(Absorb);

			int EmberDamage = MissingNo.DamageThis(Ember);
			int BubbleDamage = MissingNo.DamageThis(Bubble);
			int AbsorbDamage = MissingNo.DamageThis(Absorb);
			int NoneDamage = MissingNo.DamageThis(None);

			int NotFullDamage = Squishy.DamageThis(Ember);

			Assert::AreEqual(40, EmberDamage);
			Assert::AreEqual(20, BubbleDamage);
			Assert::AreEqual(20, AbsorbDamage);
			Assert::AreEqual(0, NoneDamage);

			Assert::AreEqual(10, NotFullDamage);
		}
	};
	
}
