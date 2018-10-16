#include "stdafx.h"
#include "CppUnitTest.h"
#include "CrtCheckMemory.h"
#include "ForwardIterator.h"
#include "BackwardIterator.h"
#include "DoubleLinkedList.h"
#include "Exception.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(Iterators)
	{
	public:
		TEST_METHOD(ForwardIteratorAssignment)
		{
			CrtCheckMemory check;
			DoubleLinkedList<std::string> list;
			ForwardIterator<std::string> forwardIterator;

			list.Append("lol");
			list.Append("hai");
			list.Append("bye");
			forwardIterator = list.getHead();

			Assert::AreEqual(list.First(), *forwardIterator);
		}

		TEST_METHOD(BackwardIteratorAssignment)
		{
			CrtCheckMemory check;
			DoubleLinkedList<std::string> list;
			BackwardIterator<std::string> backwardIterator;

			list.Append("lol");
			list.Append("hai");
			list.Append("bye");
			backwardIterator = list.getHead();
			
			Assert::AreEqual(list.First(), *backwardIterator);
		}

		TEST_METHOD(BackwardIteratorAssignmentString)
		{
			CrtCheckMemory check;
			DoubleLinkedList<std::string> list;

			list.Append("lol");
			list.Append("hai");
			list.Append("bye");
			BackwardIterator<std::string> backwardIterator;
			backwardIterator = list.getHead();

			Assert::IsTrue(list.First() == *backwardIterator);
		}
		TEST_METHOD(ForwardIteratorReset)
		{
			CrtCheckMemory check;
			DoubleLinkedList<std::string> list;
			ForwardIterator<std::string> forwardIterator;

			list.Append("lol");
			list.Append("hai");
			list.Append("bye");
			forwardIterator = list.getTail();
			forwardIterator.Reset();

			Assert::AreEqual(list.First(), *forwardIterator);
		}

		TEST_METHOD(BacwardIteratorReset)
		{
			CrtCheckMemory check;
			DoubleLinkedList<std::string> list;
			BackwardIterator<std::string> backwardIterator;

			list.Append("lol");
			list.Append("hai");
			list.Append("bye");
			backwardIterator = list.getHead();
			backwardIterator.Reset();

			Assert::AreEqual(list.Last(), *backwardIterator);
		}

		TEST_METHOD(ForwardIteratorIsDone)
		{
			CrtCheckMemory check;
			DoubleLinkedList<std::string> list;
			ForwardIterator<std::string> forwardIterator;

			list.Append("lol");
			list.Append("hai");
			list.Append("bye");
			forwardIterator = list.getTail();

			Assert::IsTrue(forwardIterator.IsDone());
		}

		TEST_METHOD(BackwardIteratorIsDone)
		{
			CrtCheckMemory check;
			DoubleLinkedList<std::string> list;
			BackwardIterator<std::string> backwardIterator;

			list.Append("lol");
			list.Append("hai");
			list.Append("bye");
			backwardIterator = list.getHead();

			Assert::IsTrue(backwardIterator.IsDone());
		}

		TEST_METHOD(ForwardIteratorMoveNext)
		{
			CrtCheckMemory check;
			DoubleLinkedList<std::string> list;
			ForwardIterator<std::string> forwardIterator;

			list.Append("lol");
			list.Append("hai");
			list.Append("bye");
			forwardIterator = list.getHead();
			forwardIterator.MoveNext();

			Assert::IsTrue("hai" == *forwardIterator);
		}

		TEST_METHOD(BackwardIteratorMoveNext)
		{
			CrtCheckMemory check;
			DoubleLinkedList<std::string> list;
			BackwardIterator<std::string> backwardIterator;

			list.Append("lol");
			list.Append("hai");
			list.Append("bye");
			backwardIterator = list.getTail();
			backwardIterator.MoveNext();

			Assert::IsTrue("hai" == *backwardIterator);
		}

		TEST_METHOD(ForwardIteratorPreIncrement)
		{
			CrtCheckMemory check;
			DoubleLinkedList<std::string> list;
			ForwardIterator<std::string> forwardIterator;

			list.Append("lol");
			list.Append("hai");
			list.Append("bye");
			forwardIterator = list.getHead();

			Assert::IsTrue("hai" == *++forwardIterator);
		}

		TEST_METHOD(ForwardIteratorPostIncrement)
		{
			CrtCheckMemory check;
			DoubleLinkedList<std::string> list;
			ForwardIterator<std::string> forwardIterator;

			list.Append("lol");
			list.Append("hai");
			list.Append("bye");
			forwardIterator = list.getHead();

			Assert::IsTrue("lol" == *forwardIterator++);
		}

		TEST_METHOD(BackwardIteratorPreIncrement)
		{
			CrtCheckMemory check;
			DoubleLinkedList<std::string> list;
			BackwardIterator<std::string> backwardIterator;

			list.Append("lol");
			list.Append("hai");
			list.Append("bye");
			backwardIterator = list.getTail();

			Assert::IsTrue("hai" == *++backwardIterator);
		}

		TEST_METHOD(BackwardIteratorPostIncrement)
		{
			CrtCheckMemory check;
			DoubleLinkedList<std::string> list;
			BackwardIterator<std::string> backwardIterator;

			list.Append("lol");
			list.Append("hai");
			list.Append("bye");
			backwardIterator = list.getTail();

			Assert::IsTrue("bye" == *backwardIterator++);
			Assert::IsTrue("hai"== *backwardIterator);
		}
		
		TEST_METHOD(ForwardIteratorIncrementEndofList)
		{
			try
			{
				CrtCheckMemory check;
				DoubleLinkedList<std::string> list;
				ForwardIterator<std::string> forwardIterator;

				list.Append("lol");
				list.Append("hai");
				list.Append("bye");

				forwardIterator = list.getHead();
				forwardIterator++;
				forwardIterator++;
				forwardIterator++;
			}
			catch (Exception e)
			{
				Assert::IsTrue(true);
			}
		}

		TEST_METHOD(BackwardIteratorIncrementEndofList)
		{
			try
			{
				CrtCheckMemory check;
				DoubleLinkedList<std::string> list;
				BackwardIterator<std::string> backwardIterator;

				list.Append("lol");
				list.Append("hai");
				list.Append("bye");

				backwardIterator = list.getTail();
				backwardIterator++;
				backwardIterator++;
				backwardIterator++;
			}
			catch (Exception e)
			{
				Assert::IsTrue(true);
			}
		}

		TEST_METHOD(ForwardIteratorResetFail)
		{
			try
			{
				CrtCheckMemory check;
				DoubleLinkedList<std::string> list;
				ForwardIterator<std::string> forwardIterator;

				list.Append("lol");
				list.Append("hai");
				list.Append("bye");

				forwardIterator.Reset();
			}
			catch (Exception e)
			{
				Assert::IsTrue(true);
			}
		}

		TEST_METHOD(BackwardIteratorResetFail)
		{
			try
			{
				CrtCheckMemory check;
				DoubleLinkedList<std::string> list;
				BackwardIterator<std::string> backwardIterator;

				list.Append("lol");
				list.Append("hai");
				list.Append("bye");

				backwardIterator.Reset();
			}
			catch (Exception e)
			{
				Assert::IsTrue(true);
			}
		}

		TEST_METHOD(ForwardIteratorIsDoneFail)
		{
			try
			{
				CrtCheckMemory check;
				DoubleLinkedList<std::string> list;
				ForwardIterator<std::string> forwardIterator;

				list.Append("lol");
				list.Append("hai");
				list.Append("bye");

				Assert::IsTrue(forwardIterator.IsDone());
			}
			catch (Exception e)
			{
				Assert::IsTrue(true);
			}
		}

		TEST_METHOD(BackwardIteratorIsDoneFail)
		{
			try
			{
				CrtCheckMemory check;
				DoubleLinkedList<std::string> list;
				BackwardIterator<std::string> backwardIterator;

				list.Append("lol");
				list.Append("hai");
				list.Append("bye");

				Assert::IsTrue(backwardIterator.IsDone());
			}
			catch (Exception e)
			{
				Assert::IsTrue(true);
			}
		}

		TEST_METHOD(ForwardIteratorMoveNextFail)
		{
			try
			{
				CrtCheckMemory check;
				DoubleLinkedList<std::string> list;
				ForwardIterator<std::string> forwardIterator;

				list.Append("lol");
				list.Append("hai");
				list.Append("bye");

				forwardIterator = list.getHead();
				forwardIterator.MoveNext();
				forwardIterator.MoveNext();
				forwardIterator.MoveNext();

				Assert::IsTrue("hai" == *forwardIterator);
			}
			catch (Exception e)
			{
				Assert::IsTrue(true);
			}
		}

		TEST_METHOD(BackwardIteratorMoveNextFail)
		{
			try
			{
				CrtCheckMemory check;
				DoubleLinkedList<std::string> list;
				BackwardIterator<std::string> backwardIterator;

				list.Append("lol");
				list.Append("hai");
				list.Append("bye");

				backwardIterator = list.getTail();
				backwardIterator.MoveNext();
				backwardIterator.MoveNext();
				backwardIterator.MoveNext();

				Assert::IsTrue("lol" == *backwardIterator);
			}
			catch (Exception e)
			{
				Assert::IsTrue(true);
			}
		}
	};
}