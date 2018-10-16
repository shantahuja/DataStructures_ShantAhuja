#include "stdafx.h"
#include "CppUnitTest.h"
#include <iostream>
#include "CrtCheckMemory.h"
#include "BSTree.h"
#include <vector>

using std::string;
using std::vector;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
static vector<int> testVec;
static vector<std::string> testVecString;

namespace UnitTests
{
	TEST_CLASS(BSTTest)
	{
	public:
		static void ToVector(BSTNode<int> * p)
		{
			if (p != nullptr)
				testVec.push_back(p->el);
		}
		static void ToVector(BSTNode<std::string> * p)
		{
			if (p != nullptr)
				testVecString.push_back(p->el);
		}
		TEST_METHOD_INITIALIZE(Init)
		{
			testVec.clear();
		}

		TEST_METHOD(BSTreeInsertDeleteBFString)
		{
			//CrtCheckMemory check;
			BSTree<std::string> test;
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
			test.Insert("l");
			test.Delete("j");
			test.Delete("c");
			test.Delete("e");
			test.SetFunction(ToVector);
			test.BreadthFirst();
			std::string BF[9] = { "a", "b", "d", "f", "g", "h", "i", "k", "l" };
			for (size_t i = 0; i < 9; i++)
				Assert::AreEqual(BF[i], testVecString[i]);
		}

		TEST_METHOD(BSTreeInsertDeleteBF)
		{
			//CrtCheckMemory check;
			BSTree<int> test;
			test.Insert(39);
			test.Insert(105);
			test.Insert(35);
			test.Insert(44);
			test.Insert(81);
			test.Insert(89);
			test.Insert(26);
			test.Insert(61);
			test.Insert(45);
			test.Insert(54);
			test.Insert(92);
			test.Insert(87);
			test.Delete(54);
			test.Delete(35);
			test.Delete(81);
			test.SetFunction(ToVector);
			test.BreadthFirst();
			int BF[9] = { 39, 26, 105, 44, 87, 61, 89, 45, 92 };
			for (size_t i = 0; i < 9; i++)
				Assert::AreEqual(BF[i], testVec[i]);
		}

		TEST_METHOD(BSTreeInsertDeleteInOrder)
		{
			CrtCheckMemory check;
			BSTree<int> test;
			test.Insert(39);
			test.Insert(105);
			test.Insert(35);
			test.Insert(44);
			test.Insert(81);
			test.Insert(89);
			test.Insert(26);
			test.Insert(61);
			test.Insert(45);
			test.Insert(54);
			test.Insert(92);
			test.Insert(87);
			test.Delete(54);
			test.Delete(35);
			test.Delete(81);
			test.SetFunction(ToVector);
			test.InOrder();
			int IO[9] = { 26, 39, 44, 45, 61, 87, 89, 92, 105 };
			for (size_t i = 0; i < 9; i++)
				Assert::AreEqual(IO[i], testVec[i]);
		}

		TEST_METHOD(BSTreeInsertDeletePreOrder)
		{
			CrtCheckMemory check;
			BSTree<int> test;
			test.Insert(39);
			test.Insert(105);
			test.Insert(35);
			test.Insert(44);
			test.Insert(81);
			test.Insert(89);
			test.Insert(26);
			test.Insert(61);
			test.Insert(45);
			test.Insert(54);
			test.Insert(92);
			test.Insert(87);
			test.Delete(54);
			test.Delete(35);
			test.Delete(81);
			test.SetFunction(ToVector);
			test.PreOrder();
			int PreO[9] = { 39, 26, 105, 44, 87, 61, 45, 89, 92 };
			for (size_t i = 0; i < 9; i++)
				Assert::AreEqual(PreO[i], testVec[i]);
		}

		TEST_METHOD(BSTreeInsertDeletePostOrder)
		{
			CrtCheckMemory check;
			BSTree<int> test;
			test.Insert(39);
			test.Insert(105);
			test.Insert(35);
			test.Insert(44);
			test.Insert(81);
			test.Insert(89);
			test.Insert(26);
			test.Insert(61);
			test.Insert(45);
			test.Insert(54);
			test.Insert(92);
			test.Insert(87);
			test.Delete(54);
			test.Delete(35);
			test.Delete(81);
			test.SetFunction(ToVector);
			test.PostOrder();
			int PostO[9] = { 26, 45, 61, 92, 89, 87, 44, 105, 39 };
			for (size_t i = 0; i < 9; i++)
				Assert::AreEqual(PostO[i], testVec[i]);
		}
	};
}
