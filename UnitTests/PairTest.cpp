#include "stdafx.h"
#include "CppUnitTest.h"

#include "CrtCheckMemory.h"
#include "Pair.h"

#include <string>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{		
	TEST_CLASS(PairTest)
	{
	public:
		
		TEST_METHOD(PairCopyConstructorTest)
		{
			// Arrange
			CrtCheckMemory check;
			Pair<int, int> pair1(5, 10);

			
			// Act
			Pair<int, int> pair2(pair1); //deep copy

			// Assert
			Assert::IsTrue(pair1.GetKey() == pair2.GetKey() && pair1.GetValue() == pair1.GetValue());
		}

		TEST_METHOD(PairAssignmentOperatorTest)
		{
			CrtCheckMemory check;
			Pair<int, int> pair1(5, 10);


			// Act
			Pair<int, int> pair2(9, 10);

			pair2 = pair1; //shallow copy

			// Assert
			Assert::IsTrue(pair1.GetKey() == pair2.GetKey() && pair1.GetValue() == pair1.GetValue());
		}

		TEST_METHOD(PairAssignmentOperatorTestStrings)
		{
			CrtCheckMemory check;
			Pair<std::string, std::string> pair1("lol", "dub");


			// Act
			Pair<std::string, std::string> pair2("yes", "no");

			pair2 = pair1; //shallow copy

						   // Assert
			Assert::IsTrue(pair1.GetKey() == pair2.GetKey() && pair1.GetValue() == pair1.GetValue());
		}

		TEST_METHOD(PairBoolOperatorTest)
		{
			CrtCheckMemory check;
			Pair<int, int> pair1(5, 10);


			// Act
			Pair<int, int> pair2(5, 10);

						   // Assert
			Assert::IsTrue(pair1 == pair2);
		}

		TEST_METHOD(PairBoolOperatorTestString)
		{
			CrtCheckMemory check;
			Pair < std::string, std::string > pair1("lol", "string");


			// Act
			Pair<std::string, std::string> pair2("lol", "string");

			// Assert
			Assert::IsTrue(pair1 == pair2);
		}

		TEST_METHOD(PairCopyConstructorTestStringInt)
		{
			// Arrange
			CrtCheckMemory check;
			Pair<std::string, int> pair1("lol", 10);

			
			// Act
			Pair<std::string, int> pair2(pair1); //deep copy

										 // Assert
			Assert::IsTrue(pair1.GetKey() == pair2.GetKey() && pair1.GetValue() == pair1.GetValue());
		}
		TEST_METHOD(PairCopyConstructorTestStringString)
		{
			// Arrange
			CrtCheckMemory check;
			Pair<std::string, std::string> pair1("lol", "dub");


			// Act
			Pair < std::string, std::string > pair2(pair1); //deep copy

												 // Assert
			Assert::IsTrue(pair1.GetKey() == pair2.GetKey() && pair1.GetValue() == pair1.GetValue());
		}

		TEST_METHOD(PairGetKeyTest)
		{
			Pair<std::string, std::string> pair1("lol", "dub");
			std::string test = "lol";
			Assert::AreEqual(pair1.GetKey(), test);
		}

		TEST_METHOD(PairGetValueTest)
		{
			Pair<std::string, std::string> pair1("lol", "dub");
			std::string test = "dub";
			Assert::AreEqual(pair1.GetValue(), test);
		}

		TEST_METHOD(PairSetKeyTest)
		{
			Pair<std::string, std::string> pair1("lol", "dub");
			std::string test = "yes";
			pair1.SetKey("yes");
			Assert::AreEqual(pair1.GetKey(), test);
		}

		TEST_METHOD(PairSetValueTest)
		{
			Pair<std::string, std::string> pair1("lol", "dub");
			std::string test = "no";
			pair1.SetValue("no");
			Assert::AreEqual(pair1.GetValue(), test);
		}
	};
}