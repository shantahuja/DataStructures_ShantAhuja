#include "stdafx.h"
#include "CppUnitTest.h"
#include "CrtCheckMemory.h"
#include "ArrayStack.h"
#include "Exception.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(ArrayStackTest)
	{
	public:
		TEST_METHOD(ArrayStackCopyConstructorString)
		{
			CrtCheckMemory check;
			ArrayStack<std::string> stack1(10);
			stack1.Push("Yes");
			stack1.Push("No");
			stack1.Push("Maybe");
			stack1.Push("So");
			ArrayStack<std::string> stack2(stack1);
			Assert::IsTrue(stack1.Size() == stack2.Size());

			for (int i = 0; i < stack1.Size(); i++)
			{
				Assert::IsTrue(stack1.Pop() == stack2.Pop());
			}
		}
		
		TEST_METHOD(ArrayStackCopyConstructorInt)
		{
			CrtCheckMemory check;
			ArrayStack<int> stack1(10);
			stack1.Push(1);
			stack1.Push(2);
			stack1.Push(3);
			stack1.Push(4);
			ArrayStack<int> stack2(stack1);
			Assert::IsTrue(stack1.Size() == stack2.Size());

			for (int i = 0; i < stack1.Size(); i++)
			{
				Assert::IsTrue(stack1.Pop() == stack2.Pop());
			}
		}

		TEST_METHOD(ArrayStackAssignmentOperatorConstString)
		{
			CrtCheckMemory check;
			ArrayStack<std::string> stack1(10);
			stack1.Push("Yes");
			stack1.Push("No");
			stack1.Push("Maybe");
			stack1.Push("So");
			const ArrayStack<std::string> stack2 = stack1;
			Assert::IsTrue(stack1.Size() == stack2.Size());

			for (int i = 0; i < stack1.Size(); i++)
			{
				Assert::IsTrue(stack1.Peek() == stack2.Peek());
			}
		}

		TEST_METHOD(ArrayStackAssignmentOperatorConstInt)
		{
			CrtCheckMemory check;
			ArrayStack<int> stack1(10);
			stack1.Push(1);
			stack1.Push(2);
			stack1.Push(3);
			stack1.Push(4);
			const ArrayStack<int> stack2 = stack1;
			Assert::IsTrue(stack1.Size() == stack2.Size());

			for (int i = 0; i < stack1.Size(); i++)
			{
				Assert::IsTrue(stack1.Peek() == stack2.Peek());
			}
		}

		TEST_METHOD(ArrayStackDefaultConstructor)
		{
			CrtCheckMemory check;
			ArrayStack<std::string> stack1;
			Assert::IsTrue(stack1.Size() == 0);
		}

		TEST_METHOD(ArrayStackPushandPeekInt)
		{
			CrtCheckMemory check;
			ArrayStack<int> stack1(10);
			stack1.Push(1);
			stack1.Push(2);
			stack1.Push(3);
			stack1.Push(4);
			Assert::IsTrue(stack1.Peek() == 4);
		}

		TEST_METHOD(ArrayStackPushandPeekString)
		{
			CrtCheckMemory check;
			ArrayStack<std::string> stack1(10);
			stack1.Push("yes");
			stack1.Push("no");
			stack1.Push("maybe");
			stack1.Push("so");
			Assert::IsTrue(stack1.Peek() == "so");
		}

		TEST_METHOD(ArrayStackPopInt)
		{
			CrtCheckMemory check;
			ArrayStack<int> stack1(10);
			stack1.Push(1);
			stack1.Push(2);
			stack1.Push(3);
			stack1.Push(4);
			Assert::IsTrue(stack1.Pop() == 4);
		}

		TEST_METHOD(ArrayStackPopString)
		{
			CrtCheckMemory check;
			ArrayStack<std::string> stack1(10);
			stack1.Push("yes");
			stack1.Push("no");
			stack1.Push("maybe");
			stack1.Push("so");
			Assert::IsTrue(stack1.Pop() == "so");
		}

		TEST_METHOD(ArrayStackPeekEmptyList)
		{
			try
			{
				CrtCheckMemory check;
				ArrayStack<std::string> stack1(10);
				stack1.Peek();
			}
			catch (Exception e)
			{
				Assert::IsTrue(true);
			}
		}

		TEST_METHOD(ArrayStackSize)
		{
			CrtCheckMemory check;
			ArrayStack<std::string> stack1(10);
			stack1.Push("yes");
			stack1.Push("no");
			stack1.Push("maybe");
			stack1.Push("so");
			Assert::IsTrue(stack1.Size() == 4);
		}

		TEST_METHOD(ArrayStackIsEmptyFail)
		{
			try
			{
				CrtCheckMemory check;
				ArrayStack<std::string> stack1(10);
				stack1.Push("yes");
				stack1.Push("no");
				stack1.Push("maybe");
				stack1.Push("so");
				stack1.IsEmpty();
			}
			catch (Exception e)
			{
				Assert::IsTrue(true);
			}
		}

		TEST_METHOD(ArrayStackIsEmptyUnderflowFail)
		{
			try
			{
				CrtCheckMemory check;
				ArrayStack<std::string> stack1(4);
				stack1.Push("yes");
				stack1.Push("no");
				stack1.Push("maybe");
				stack1.Push("so");
				stack1.Pop();
				stack1.Pop();
				stack1.Pop();
				stack1.Pop();
				stack1.Pop();
			}
			catch (Exception e)
			{
				Assert::IsTrue(true);
			}
		}

		TEST_METHOD(ArrayStackIsEmptyPass)
		{
			CrtCheckMemory check;
			ArrayStack<std::string> stack1(10);
			stack1.IsEmpty();
		}

		TEST_METHOD(ArrayStackIsFullPass)
		{
			CrtCheckMemory check;
			ArrayStack<std::string> stack1(4);
			stack1.Push("yes");
			stack1.Push("no");
			stack1.Push("maybe");
			stack1.Push("so");
			stack1.IsFull();
		}

		TEST_METHOD(ArrayStackIsFullOverflowFail)
		{
			try
			{
				CrtCheckMemory check;
				ArrayStack<std::string> stack1(4);
				stack1.Push("yes");
				stack1.Push("no");
				stack1.Push("maybe");
				stack1.Push("so");
				stack1.Push("so");
				stack1.IsFull();
			}
			catch (Exception e)
			{
				Assert::IsTrue(true);
			}
		}

		TEST_METHOD(ArrayStackIsFullFail)
		{
			try
			{
				CrtCheckMemory check;
				ArrayStack<std::string> stack1(4);
				stack1.Push("yes");
				stack1.Push("no");
				stack1.Push("maybe");
				stack1.Push("so");
				stack1.Push("gang");
				stack1.IsFull();
			}
			catch (Exception e)
			{
				Assert::IsTrue(true);
			}
		}
	};
}