#include "stdafx.h"
#include "CppUnitTest.h"
#include "CrtCheckMemory.h"
#include "LinkedListQueue.h"
#include "Exception.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(LinkedListQueueTest)
	{
	public:
		TEST_METHOD(LinkedListQueueCopyConstructorString)
		{
			CrtCheckMemory check;
			LinkedListQueue<std::string> queue1;
			queue1.Enqueue("Yes");
			queue1.Enqueue("No");
			queue1.Enqueue("Maybe");
			queue1.Enqueue("So");
			std::string queue1_data, queue2_data;
			LinkedListQueue<std::string> queue2(queue1);
			Assert::IsTrue(queue1.Size() == queue2.Size());
			int limit = queue1.Size();

			for (int i = 0; i < limit; i++)
			{
				queue1_data = queue1.Dequeue();
				queue2_data = queue2.Dequeue();
				Assert::IsTrue(queue1_data == queue2_data);
			}
		}
		
		TEST_METHOD(LinkedListQueueCopyConstructorInt)
		{
			CrtCheckMemory check;
			LinkedListQueue<int> queue1;
			queue1.Enqueue(1);
			queue1.Enqueue(2);
			queue1.Enqueue(3);
			queue1.Enqueue(4);
			LinkedListQueue<int> queue2(queue1);
			Assert::IsTrue(queue1.Size() == queue2.Size());
			int limit = queue1.Size();

			for (int i = 0; i < limit; i++)
			{
				int queue1_data = queue1.Dequeue();
				int queue2_data = queue2.Dequeue();
				Assert::IsTrue(queue1_data == queue2_data);
			}
		}
		
		TEST_METHOD(LinkedListQueueAssignmentOperatorConstString)
		{
			CrtCheckMemory check;
			LinkedListQueue<std::string> queue1;
			queue1.Enqueue("Yes");
			queue1.Enqueue("No");
			queue1.Enqueue("Maybe");
			queue1.Enqueue("So");
			const LinkedListQueue<std::string> queue2 = queue1;

			std::string queue1_data = queue1.Front();
			std::string queue2_data = queue2.Front();
			Assert::IsTrue(queue1_data == queue2_data);
		}
		
		TEST_METHOD(LinkedListQueueAssignmentOperatorConstInt)
		{
			CrtCheckMemory check;
			LinkedListQueue<int> queue1;
			queue1.Enqueue(1);
			queue1.Enqueue(2);
			queue1.Enqueue(3);
			queue1.Enqueue(4);
			const LinkedListQueue<int> queue2 = queue1;
			Assert::IsTrue(queue1.Front() == queue2.Front());
		}
		
		TEST_METHOD(LinkedListQueueDefaultConstructor)
		{
			CrtCheckMemory check;
			LinkedListQueue<std::string> queue1;
			Assert::IsTrue(queue1.Size() == 0);
		}
		
		TEST_METHOD(LinkedListQueueEnqueueandFrontInt)
		{
			CrtCheckMemory check;
			LinkedListQueue<int> queue1;
			queue1.Enqueue(1);
			queue1.Enqueue(2);
			queue1.Enqueue(3);
			queue1.Enqueue(4);
			Assert::IsTrue(queue1.Front() == 1);
		}
		
		TEST_METHOD(LinkedListQueueEnqueueandFrontString)
		{
			CrtCheckMemory check;
			LinkedListQueue<std::string> queue1;
			queue1.Enqueue("yes");
			queue1.Enqueue("no");
			queue1.Enqueue("maybe");
			queue1.Enqueue("so");
			Assert::IsTrue(queue1.Front() == "yes");
		}
		
		TEST_METHOD(LinkedListQueueDequeueInt)
		{
			CrtCheckMemory check;
			LinkedListQueue<int> queue1;
			queue1.Enqueue(1);
			queue1.Enqueue(2);
			queue1.Enqueue(3);
			queue1.Enqueue(4);
			Assert::IsTrue(queue1.Dequeue() == 1);
		}
		
		TEST_METHOD(LinkedListQueueDequeueString)
		{
			CrtCheckMemory check;
			LinkedListQueue<std::string> queue1;
			queue1.Enqueue("yes");
			queue1.Enqueue("no");
			queue1.Enqueue("maybe");
			queue1.Enqueue("so");
			Assert::IsTrue(queue1.Dequeue() == "yes");
		}
		
		TEST_METHOD(LinkedListQueueFrontEmptyList)
		{
			try
			{
				CrtCheckMemory check;
				LinkedListQueue<std::string> queue1;
				queue1.Front();
			}
			catch (Exception e)
			{
				Assert::IsTrue(true);
			}
		}
		
		TEST_METHOD(LinkedListQueueSize)
		{
			CrtCheckMemory check;
			LinkedListQueue<std::string> queue1;
			queue1.Enqueue("yes");
			queue1.Enqueue("no");
			queue1.Enqueue("maybe");
			queue1.Enqueue("so");
			Assert::IsTrue(queue1.Size() == 4);
		}
		
		TEST_METHOD(LinkedListQueueIsEmptyFail)
		{
			CrtCheckMemory check;
			LinkedListQueue<std::string> queue1;
			queue1.Enqueue("yes");
			queue1.Enqueue("no");
			queue1.Enqueue("maybe");
			queue1.Enqueue("so");
			
			Assert::IsFalse(queue1.IsEmpty());
			
		}

		TEST_METHOD(LinkedListQueueIsEmptyUnderflowFail)
		{
			try
			{
				CrtCheckMemory check;
				LinkedListQueue<std::string> queue1;
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

		TEST_METHOD(LinkedListQueueIsEmptyPass)
		{
			CrtCheckMemory check;
			LinkedListQueue<std::string> queue1;
			queue1.IsEmpty();
		}
	};
}