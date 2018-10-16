#include "stdafx.h"
#include "CppUnitTest.h"
#include<iostream>
#include "CrtCheckMemory.h"
#include "AVLTree.h"
#include <vector>
using std::string;
using std::vector;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

static vector<int> testVec;
static vector<string> testVecString;

namespace UnitTests
{

	TEST_CLASS(AVLTest)
	{
	public:
		static void ToVector(AVLNode<int> * p)
		{
			if (p != nullptr)
				testVec.push_back(p->el);
		}

		
		static void ToVector(AVLNode<std::string> * p)
		{
			if (p != nullptr)
				testVecString.push_back(p->el);
		}
		

		TEST_METHOD_INITIALIZE(Init)
		{
			testVec.clear();
		}

		TEST_METHOD(AVLTestsBreadthFirstString)
		{
			//CrtCheckMemory check;
			AVLTree<std::string> test;
			test.Insert("a");
			test.Insert("b");
			test.Insert("c");
			test.Insert("d");
			test.Insert("e");
			test.Insert("f");
			test.Insert("g");
			test.Insert("h");
			test.Insert("i");
			test.Insert("j");
			test.Insert("k");

			test.Delete("f");
			test.Delete("g");
			test.Delete("a");
			test.Delete("b");

			test.SetFunction(ToVector);

			std::string BF[7] = { "d", "c", "j", "h", "k", "e", "i" };

			test.BreadthFirst();
			for (size_t i = 0; i < 7; i++)
				Assert::AreEqual(BF[i], testVecString[i]);
			testVecString.clear();

		}

		TEST_METHOD(AVLTestsBreadthFirst)
		{
			//CrtCheckMemory check;
			AVLTree<int> test;
			test.Insert(20);
			test.Insert(21);
			test.Insert(22);
			test.Insert(14);
			test.Insert(13);
			test.Insert(17);
			test.Insert(15);
			test.Insert(18);
			test.Insert(16);
			test.Insert(19);
			test.Insert(23);

			test.Delete(17);
			test.Delete(15);
			test.Delete(20);
			test.Delete(21);

			test.SetFunction(ToVector);

			int BF[7] = { 19, 16, 22, 14, 18, 23, 13 };

			test.BreadthFirst();
			for (size_t i = 0; i < 7; i++)
				Assert::AreEqual(BF[i], testVec[i]);
			testVec.clear();

		}

		TEST_METHOD(AVLTestsInOrder)
		{
			//CrtCheckMemory check;
			AVLTree<int> test;
			test.Insert(20);
			test.Insert(21);
			test.Insert(22);
			test.Insert(14);
			test.Insert(13);
			test.Insert(17);
			test.Insert(15);
			test.Insert(18);
			test.Insert(16);
			test.Insert(19);
			test.Insert(23);

			test.Delete(17);
			test.Delete(15);
			test.Delete(20);
			test.Delete(21);

			test.SetFunction(ToVector);

			int IO[7] = { 13, 14, 16, 18, 19, 22, 23 };

			test.InOrder();
			for (size_t i = 0; i < 7; i++)
				Assert::AreEqual(IO[i], testVec[i]);
			testVec.clear();
		}

		TEST_METHOD(AVLTestsPostOrder)
		{
			//CrtCheckMemory check;
			AVLTree<int> test;
			test.Insert(20);
			test.Insert(21);
			test.Insert(22);
			test.Insert(14);
			test.Insert(13);
			test.Insert(17);
			test.Insert(15);
			test.Insert(18);
			test.Insert(16);
			test.Insert(19);
			test.Insert(23);

			test.Delete(17);
			test.Delete(15);
			test.Delete(20);
			test.Delete(21);

			test.SetFunction(ToVector);

			int PostO[7] = { 13, 14, 18, 16, 23, 22, 19 };

			test.PostOrder();
			for (size_t i = 0; i < 7; i++)
				Assert::AreEqual(PostO[i], testVec[i]);
			testVec.clear();
		}

		TEST_METHOD(AVLTestsPreOrder)
		{
			//CrtCheckMemory check;
			AVLTree<int> test;
			test.Insert(20);
			test.Insert(21);
			test.Insert(22);
			test.Insert(14);
			test.Insert(13);
			test.Insert(17);
			test.Insert(15);
			test.Insert(18);
			test.Insert(16);
			test.Insert(19);
			test.Insert(23);

			test.Delete(17);
			test.Delete(15);
			test.Delete(20);
			test.Delete(21);

			test.SetFunction(ToVector);

			int PreO[7] = { 19, 16, 14, 13, 18, 22, 23 };

			test.PreOrder();
			for (size_t i = 0; i < 7; i++)
				Assert::AreEqual(PreO[i], testVec[i]);
			testVec.clear();
		}

	};
}