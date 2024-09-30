#include "pch.h"
#include "CppUnitTest.h"
#include "../PokemonProject/TypeChecker.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TypeCheckerTest
{
	TEST_CLASS(TypeCheckerTestClass)
	{
	public:

		TEST_METHOD(Control)
		{
			Assert::IsTrue(true);
		}

		TEST_METHOD(Weakness_Fire)
		{
			TypeChecker& checker = TypeChecker::getInstance();

			Assert::IsTrue(checker.isWeakTo(FIRE, WATER));

			Assert::IsFalse(checker.isWeakTo(FIRE, GRASS));
			Assert::IsFalse(checker.isWeakTo(FIRE, FIRE));
			Assert::IsFalse(checker.isWeakTo(FIRE, NONE));
		}

		TEST_METHOD(Weakness_Water)
		{
			TypeChecker& checker = TypeChecker::getInstance();

			Assert::IsTrue(checker.isWeakTo(WATER, GRASS));

			Assert::IsFalse(checker.isWeakTo(WATER, FIRE));
			Assert::IsFalse(checker.isWeakTo(WATER, WATER));
			Assert::IsFalse(checker.isWeakTo(WATER, NONE));
		}

		TEST_METHOD(Weakness_Grass)
		{
			TypeChecker& checker = TypeChecker::getInstance();

			Assert::IsTrue(checker.isWeakTo(GRASS, FIRE));

			Assert::IsFalse(checker.isWeakTo(GRASS, WATER));
			Assert::IsFalse(checker.isWeakTo(GRASS, GRASS));
			Assert::IsFalse(checker.isWeakTo(WATER, NONE));
		}

		TEST_METHOD(Weakness_None)
		{
			TypeChecker& checker = TypeChecker::getInstance();

			Assert::IsFalse(checker.isWeakTo(NONE, FIRE));
			Assert::IsFalse(checker.isWeakTo(NONE, WATER));
			Assert::IsFalse(checker.isWeakTo(NONE, GRASS));
			Assert::IsFalse(checker.isWeakTo(NONE, NONE));
		}
	};
}