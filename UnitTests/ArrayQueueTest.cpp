#include "stdafx.h"
#include "CppUnitTest.h"
#include "CrtCheckMemory.h"
#include "ArrayQueue.h"
#include "Exception.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(ArrayQueueTest)
	{
	public:
		TEST_METHOD(ArrayQueueCopyConstructorString)
		{
			CrtCheckMemory check;
			ArrayQueue<std::string> queue1(10);
			queue1.Enqueue("Yes");
			queue1.Enqueue("No");
			queue1.Enqueue("Maybe");
			queue1.Enqueue("So");
			ArrayQueue<std::string> queue2(queue1);

			for (int i = 0; i < 4; i++)
			{
				Assert::IsTrue(queue1.Dequeue() == queue2.Dequeue());
			}
		}

		TEST_METHOD(ArrayQueueCopyConstructorInt)
		{
			CrtCheckMemory check;
			ArrayQueue<int> queue1(10);
			queue1.Enqueue(1);
			queue1.Enqueue(2);
			queue1.Enqueue(3);
			queue1.Enqueue(4);
			ArrayQueue<int> queue2(queue1);

			for (int i = 0; i < 4; i++)
			{
				Assert::IsTrue(queue1.Dequeue() == queue2.Dequeue());
			}
		}

		TEST_METHOD(ArrayQueueAssignmentOperatorConstString)
		{
			CrtCheckMemory check;
			ArrayQueue<std::string> queue1(10);
			queue1.Enqueue("Yes");
			queue1.Enqueue("No");
			queue1.Enqueue("Maybe");
			queue1.Enqueue("So");
			const ArrayQueue<std::string> queue2 = queue1;

			Assert::IsTrue(queue1.Front() == queue2.Front());
			
		}

		TEST_METHOD(ArrayQueueAssignmentOperatorConstInt)
		{
			CrtCheckMemory check;
			ArrayQueue<int> queue1(10);
			queue1.Enqueue(1);
			queue1.Enqueue(2);
			queue1.Enqueue(3);
			queue1.Enqueue(4);
			const ArrayQueue<int> queue2 = queue1;

			Assert::IsTrue(queue1.Front() == queue2.Front());
		}

		TEST_METHOD(ArrayQueueDefaultConstructor)
		{
			CrtCheckMemory check;
			ArrayQueue<std::string> queue1;
			Assert::IsTrue(queue1.Size() == 0);
		}

		TEST_METHOD(ArrayQueueEnqueueandFrontInt)
		{
			CrtCheckMemory check;
			ArrayQueue<int> queue1(10);
			queue1.Enqueue(1);
			queue1.Enqueue(2);
			queue1.Enqueue(3);
			queue1.Enqueue(4);
			Assert::IsTrue(queue1.Front() == 1);
		}

		TEST_METHOD(ArrayQueueEnqueueandFrontString)
		{
			CrtCheckMemory check;
			ArrayQueue<std::string> queue1(10);
			queue1.Enqueue("yes");
			queue1.Enqueue("no");
			queue1.Enqueue("maybe");
			queue1.Enqueue("so");
			Assert::IsTrue(queue1.Front() == "yes");
		}

		TEST_METHOD(ArrayQueueDequeueInt)
		{
			CrtCheckMemory check;
			ArrayQueue<int> queue1(10);
			queue1.Enqueue(1);
			queue1.Enqueue(2);
			queue1.Enqueue(3);
			queue1.Enqueue(4);
			Assert::IsTrue(queue1.Dequeue() == 1);
		}

		TEST_METHOD(ArrayQueueDequeueString)
		{
			CrtCheckMemory check;
			ArrayQueue<std::string> queue1(10);
			queue1.Enqueue("yes");
			queue1.Enqueue("no");
			queue1.Enqueue("maybe");
			queue1.Enqueue("so");
			Assert::IsTrue(queue1.Dequeue() == "yes");
		}

		TEST_METHOD(ArrayQueueFrontEmptyList)
		{
			try
			{
				CrtCheckMemory check;
				ArrayQueue<std::string> queue1(10);
				queue1.Front();
			}
			catch (Exception e)
			{
				Assert::IsTrue(true);
			}
		}

		TEST_METHOD(ArrayQueueSize)
		{
			CrtCheckMemory check;
			ArrayQueue<std::string> queue1(10);
			queue1.Enqueue("yes");
			queue1.Enqueue("no");
			queue1.Enqueue("maybe");
			queue1.Enqueue("so");
			Assert::IsTrue(queue1.Size() == 10);
		}

		TEST_METHOD(ArrayQueueIsEmptyFail)
		{
			CrtCheckMemory check;
			ArrayQueue<std::string> queue1(10);
			queue1.Enqueue("yes");
			queue1.Enqueue("no");
			queue1.Enqueue("maybe");
			queue1.Enqueue("so");

			Assert::IsFalse(queue1.IsEmpty());
		}

		TEST_METHOD(ArrayQueueIsEmptyUnderflowFail)
		{
			try
			{
				CrtCheckMemory check;
				ArrayQueue<std::string> queue1(4);
				queue1.Enqueue("yes");
				queue1.Enqueue("no");
				queue1.Enqueue("maybe");
				queue1.Enqueue("so");
				queue1.Dequeue();
				queue1.Dequeue();
				queue1.Dequeue();
				queue1.Dequeue();
				queue1.Dequeue();
			}
			catch (Exception e)
			{
				Assert::IsTrue(true);
			}
		}

		TEST_METHOD(ArrayQueueIsEmptyPass)
		{
			CrtCheckMemory check;
			ArrayQueue<std::string> queue1(10);
			queue1.IsEmpty();
		}

		TEST_METHOD(ArrayQueueIsFullPass)
		{
			CrtCheckMemory check;
			ArrayQueue<std::string> queue1(4);
			queue1.Enqueue("yes");
			queue1.Enqueue("no");
			queue1.Enqueue("maybe");
			queue1.Enqueue("so");
			queue1.IsFull();
		}

		TEST_METHOD(ArrayQueueIsFullOverflowFail)
		{
			try
			{
				CrtCheckMemory check;
				ArrayQueue<std::string> queue1(4);
				queue1.Enqueue("yes");
				queue1.Enqueue("no");
				queue1.Enqueue("maybe");
				queue1.Enqueue("so");
				queue1.Enqueue("so");
				queue1.IsFull();
			}
			catch (Exception e)
			{
				Assert::IsTrue(true);
			}
		}

		TEST_METHOD(ArrayQueueIsFullFail)
		{
			CrtCheckMemory check;
			ArrayQueue<std::string> queue1(4);
			queue1.Enqueue("yes");
			queue1.Enqueue("no");
			queue1.Enqueue("maybe");
			Assert::IsFalse(queue1.IsFull());
		}
	};
}