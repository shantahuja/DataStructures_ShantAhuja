#include "stdafx.h"
#include "CppUnitTest.h"
#include "CrtCheckMemory.h"
#include "LinkedListStack.h"
#include "Exception.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(LinkedListStackTest)
	{
	public:
		TEST_METHOD(LinkedListStackCopyConstructorString)
		{
			CrtCheckMemory check;
			LinkedListStack<std::string> stack1;
			stack1.Push("Yes");
			stack1.Push("No");
			stack1.Push("Maybe");
			stack1.Push("So");
			std::string stack1_data, stack2_data;
			LinkedListStack<std::string> stack2(stack1);
			Assert::IsTrue(stack1.Size() == stack2.Size());
			int limit = stack1.Size();

			for (int i = 0; i < limit; i++)
			{
				stack1_data = stack1.Pop();
				stack2_data = stack2.Pop();
				Assert::IsTrue(stack1_data == stack2_data);
			}
		}
		
		TEST_METHOD(LinkedListStackCopyConstructorInt)
		{
			//CrtCheckMemory check;
			LinkedListStack<int> stack1;
			stack1.Push(1);
			stack1.Push(2);
			stack1.Push(3);
			stack1.Push(4);
			LinkedListStack<int> stack2(stack1);
			Assert::IsTrue(stack1.Size() == stack2.Size());
			int limit = stack1.Size();

			for (int i = 0; i < limit; i++)
			{
				int stack1_data = stack1.Pop();
				int stack2_data = stack2.Pop();
				Assert::IsTrue(stack1_data == stack2_data);
			}
		}

		TEST_METHOD(LinkedListStackAssignmentOperatorConstString)
		{
			CrtCheckMemory check;
			LinkedListStack<std::string> stack1;
			stack1.Push("Yes");
			stack1.Push("No");
			stack1.Push("Maybe");
			stack1.Push("So");
			const LinkedListStack<std::string> stack2 = stack1;
			Assert::IsTrue(stack1.Size() == stack2.Size());

			for (int i = 0; i < stack1.Size(); i++)
			{
				std::string stack1_data = stack1.Peek();
				std::string stack2_data = stack2.Peek();
				Assert::IsTrue(stack1_data == stack2_data);
			}
		}
		
		TEST_METHOD(LinkedListStackAssignmentOperatorConstInt)
		{
			CrtCheckMemory check;
			LinkedListStack<int> stack1;
			stack1.Push(1);
			stack1.Push(2);
			stack1.Push(3);
			stack1.Push(4);
			const LinkedListStack<int> stack2 = stack1;
			Assert::IsTrue(stack1.Size() == stack2.Size());

			for (int i = 0; i < stack1.Size(); i++)
			{
				Assert::IsTrue(stack1.Peek() == stack2.Peek());
			}
		}
		
		TEST_METHOD(LinkedListStackDefaultConstructor)
		{
			CrtCheckMemory check;
			LinkedListStack<std::string> stack1;
			Assert::IsTrue(stack1.Size() == 0);
		}
		
		TEST_METHOD(LinkedListStackPushandPeekInt)
		{
			CrtCheckMemory check;
			LinkedListStack<int> stack1;
			stack1.Push(1);
			stack1.Push(2);
			stack1.Push(3);
			stack1.Push(4);
			Assert::IsTrue(stack1.Peek() == 4);
		}

		TEST_METHOD(LinkedListStackPushandPeekString)
		{
			CrtCheckMemory check;
			LinkedListStack<std::string> stack1;
			stack1.Push("yes");
			stack1.Push("no");
			stack1.Push("maybe");
			stack1.Push("so");
			Assert::IsTrue(stack1.Peek() == "so");
		}

		TEST_METHOD(LinkedLIstStackPopInt)
		{
			CrtCheckMemory check;
			LinkedListStack<int> stack1;
			stack1.Push(1);
			stack1.Push(2);
			stack1.Push(3);
			stack1.Push(4);
			Assert::IsTrue(stack1.Pop() == 4);
		}

		TEST_METHOD(LinkedListStackPopString)
		{
			CrtCheckMemory check;
			LinkedListStack<std::string> stack1;
			stack1.Push("yes");
			stack1.Push("no");
			stack1.Push("maybe");
			stack1.Push("so");
			Assert::IsTrue(stack1.Pop() == "so");
		}

		TEST_METHOD(LinkedListStackPeekEmptyList)
		{
			try
			{
				CrtCheckMemory check;
				LinkedListStack<std::string> stack1;
				stack1.Peek();
			}
			catch (Exception e)
			{
				Assert::IsTrue(true);
			}
		}

		TEST_METHOD(LinkedListStackSize)
		{
			CrtCheckMemory check;
			LinkedListStack<std::string> stack1;
			stack1.Push("yes");
			stack1.Push("no");
			stack1.Push("maybe");
			stack1.Push("so");
			Assert::IsTrue(stack1.Size() == 4);
		}

		TEST_METHOD(LinkedListStackIsEmptyFail)
		{
			try
			{
				CrtCheckMemory check;
				LinkedListStack<std::string> stack1;
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

		TEST_METHOD(LinkedListStackIsEmptyUnderflowFail)
		{
			try
			{
				CrtCheckMemory check;
				LinkedListStack<std::string> stack1;
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

		TEST_METHOD(LinkedListStackIsEmptyPass)
		{
			CrtCheckMemory check;
			LinkedListStack<std::string> stack1;
			stack1.IsEmpty();
		}
	};
}