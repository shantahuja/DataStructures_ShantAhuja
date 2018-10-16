#include "stdafx.h"
#include "CppUnitTest.h"
#include "CrtCheckMemory.h"
#include "DoubleLinkedList.h"
#include "Exception.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(Iterators)
	{
	public:
		TEST_METHOD(LinkedListDefaultConstructor)
		{
			CrtCheckMemory check;
			try
			{
				DoubleLinkedList<int> list;

				Assert::IsTrue(list.isEmpty());
				Assert::IsNull(list.getHead());

			}
			catch (Exception exception)
			{
				Assert::Fail(exception.getMessageWcharT());
			}
		}
		
		TEST_METHOD(LinkedListCopyConstructor)
		{
			CrtCheckMemory check;
			try
			{
				DoubleLinkedList<int> aList;
				aList.Append(5);

				DoubleLinkedList<int> bList(aList);

				Assert::IsFalse(bList.isEmpty());
				Assert::AreEqual(5, bList.First());

			}
			catch (Exception exception)
			{
				Assert::Fail(exception.getMessageWcharT());
			}
		}

		TEST_METHOD(LinkedListCopyConstructorString)
		{
			CrtCheckMemory check;
			try
			{
				DoubleLinkedList<std::string> aList;
				aList.Append("yeah boi");

				DoubleLinkedList<std::string> bList(aList);

				Assert::IsFalse(bList.isEmpty());
				Assert::AreEqual(aList.First(), bList.First());

			}
			catch (Exception exception)
			{
				Assert::Fail(exception.getMessageWcharT());
			}
		}
		
		TEST_METHOD(LinkedListAssignmentOperator)
		{
			CrtCheckMemory check;
			try
			{
				DoubleLinkedList<size_t> aList;
				DoubleLinkedList<size_t> bList;

				size_t i;

				size_t values[] = { 5, 15, 25, 35, 45 };

				for (i = 0; i < 5; ++i)
				{
					aList.Append(values[i]);
				}

				bList = aList;

				i = 0;
				for (DLLNode<size_t> * DLLNode = bList.getHead(); DLLNode != nullptr; DLLNode = DLLNode->getNext())
				{
					Assert::AreEqual(values[i++], DLLNode->getInfo());
				}
			}
			catch (Exception exception)
			{
				Assert::Fail(exception.getMessageWcharT());
			}
		}
		
		TEST_METHOD(LinkedListAssignmentOperatorConstString)
		{
			CrtCheckMemory check;
			try
			{
				DoubleLinkedList<std::string> aList;

				size_t i;

				std::string values[] = { "boi", "toi", "loi", "zoi", "croi!" };

				for (i = 0; i < 5; ++i)
				{
					aList.Append(values[i]);
				}

				const DoubleLinkedList<std::string> bList = aList;

				i = 0;
				for (DLLNode<std::string> * DLLNode = bList.getHead(); DLLNode != nullptr; DLLNode = DLLNode->getNext())
				{
					Assert::AreEqual(values[i++], DLLNode->getInfo());
				}
			}
			catch (Exception exception)
			{
				Assert::Fail(exception.getMessageWcharT());
			}
		}

		TEST_METHOD(LinkedListAccessors)
		{
			CrtCheckMemory check;
			try
			{
				DoubleLinkedList<int> aList;

				int values[] = { 5, 15, 25, 35, 45 };
				for (int i = 0; i < 5; ++i)
				{
					aList.Append(values[i]);
				}

				Assert::AreEqual(5, aList.getHead()->getInfo());
				Assert::AreEqual(45, aList.getTail()->getInfo());

			}
			catch (Exception exception)
			{
				Assert::Fail(exception.getMessageWcharT());
			}
		}
		
		TEST_METHOD(LinkedListAppend)
		{
			CrtCheckMemory check;
			try
			{
				DoubleLinkedList<size_t> aList;
				size_t i;

				size_t values[] = { 5, 15, 25, 35, 45 };
				for (i = 0; i < 5; ++i)
				{
					aList.Append(values[i]);
				}

				i = 0;
				for (DLLNode<size_t> * DLLNode = aList.getHead(); DLLNode != nullptr; DLLNode = DLLNode->getNext())
				{
					Assert::AreEqual(values[i++], DLLNode->getInfo());
				}
			}
			catch (Exception exception)
			{
				Assert::Fail(exception.getMessageWcharT());
			}
		}

		TEST_METHOD(LinkedListAppendString)
		{
			CrtCheckMemory check;
			try
			{
				DoubleLinkedList<std::string> aList;
				size_t i;

				std::string values[] = { "lol", "brol", "fol", "dol", "gol" };
				for (i = 0; i < 5; ++i)
				{
					aList.Append(values[i]);
				}

				i = 0;
				for (DLLNode<std::string> * DLLNode = aList.getHead(); DLLNode != nullptr; DLLNode = DLLNode->getNext())
				{
					Assert::AreEqual(values[i++], DLLNode->getInfo());
				}
			}
			catch (Exception exception)
			{
				Assert::Fail(exception.getMessageWcharT());
			}
		}
		
		TEST_METHOD(LinkedListFirstAndLast)
		{
			CrtCheckMemory check;
			try
			{
				DoubleLinkedList<int> aList;

				int values[] = { 5, 15, 25, 35, 45 };
				for (int i = 0; i < 5; ++i)
				{
					aList.Append(values[i]);
				}

				Assert::AreEqual(5, aList.First());
				Assert::AreEqual(45, aList.Last());
			}
			catch (Exception exception)
			{
				Assert::Fail(exception.getMessageWcharT());
			}
		}

		TEST_METHOD(LinkedListFirstAndLastString)
		{
			CrtCheckMemory check;
			try
			{
				DoubleLinkedList<std::string> aList;

				std::string values[] = { "joi", "boi", "loi", "foi", "croi"};
				for (int i = 0; i < 5; ++i)
				{
					aList.Append(values[i]);
				}

				Assert::AreEqual(values[0], aList.First());
				Assert::AreEqual(values[4], aList.Last());
			}
			catch (Exception exception)
			{
				Assert::Fail(exception.getMessageWcharT());
			}
		}

		TEST_METHOD(LinkedListFirstFail)
		{
			CrtCheckMemory check;
			try
			{
				DoubleLinkedList<std::string> aList;
				aList.First();
			}
			catch (Exception exception)
			{
				Assert::IsTrue(true);
			}
		}

		TEST_METHOD(LinkedListLastFail)
		{
			CrtCheckMemory check;
			try
			{
				DoubleLinkedList<std::string> aList;
				aList.Last();
			}
			catch (Exception exception)
			{
				Assert::IsTrue(true);
			}
		}
		
		TEST_METHOD(LinkedListPrepend)
		{
			CrtCheckMemory check;
			try
			{
				DoubleLinkedList<size_t> aList;
				size_t i;

				size_t values[] = { 5, 15, 25, 35, 45 };
				for (i = 0; i < 5; ++i)
				{
					aList.Prepend(values[i]);
				}

				i = 5;
				for (DLLNode<size_t> * DLLNode = aList.getHead(); DLLNode != nullptr; DLLNode = DLLNode->getNext())
				{
					Assert::AreEqual(values[--i], DLLNode->getInfo());
				}
			}
			catch (Exception exception)
			{
				Assert::Fail(exception.getMessageWcharT());
			}
		}

		TEST_METHOD(LinkedListPrependString)
		{
			CrtCheckMemory check;
			try
			{
				DoubleLinkedList<std::string> aList;
				size_t i;

				std::string values[] = { "lol", "brol", "fol", "dol", "gol" };
				for (i = 0; i < 5; ++i)
				{
					aList.Prepend(values[i]);
				}

				i = 5;
				for (DLLNode<std::string> * DLLNode = aList.getHead(); DLLNode != nullptr; DLLNode = DLLNode->getNext())
				{
					Assert::AreEqual(values[--i], DLLNode->getInfo());
				}
			}
			catch (Exception exception)
			{
				Assert::Fail(exception.getMessageWcharT());
			}
		}
		
		TEST_METHOD(LinkedListPurge)
		{
			CrtCheckMemory check;
			try
			{
				DoubleLinkedList<size_t> aList;

				size_t values[] = { 5, 15, 25, 35, 45 };
				for (size_t i = 0; i < 5; ++i)
				{
					aList.Append(values[i]);
				}

				aList.Purge();

				Assert::IsNull(aList.getHead());
				Assert::IsNull(aList.getTail());
				Assert::IsTrue(aList.isEmpty());

			}
			catch (Exception exception)
			{
				Assert::Fail(exception.getMessageWcharT());
			}
		}

		TEST_METHOD(LinkedListPurgeString)
		{
			CrtCheckMemory check;
			try
			{
				DoubleLinkedList<std::string> aList;

				std::string values[] = { "lol", "brol", "fol", "dol", "gol" };
				for (size_t i = 0; i < 5; ++i)
				{
					aList.Append(values[i]);
				}

				aList.Purge();

				Assert::IsNull(aList.getHead());
				Assert::IsNull(aList.getTail());
				Assert::IsTrue(aList.isEmpty());

			}
			catch (Exception exception)
			{
				Assert::Fail(exception.getMessageWcharT());
			}
		}
		
		TEST_METHOD(LinkedListInsertBefore)
		{
			CrtCheckMemory check;
			try
			{
				DoubleLinkedList<int> aList;
				int i;

				int values[] = { 5, 15, 25, 35, 45 };

				aList.Append(values[4]);
				for (i = 3; i >= 0; --i)
				{
					aList.InsertBefore(values[i], values[i + 1]);
				}

				i = 0;
				for (DLLNode<int> * DLLNode = aList.getHead(); DLLNode != nullptr; DLLNode = DLLNode->getNext())
				{
					Assert::AreEqual(values[i++], DLLNode->getInfo());
				}
			}
			catch (Exception exception)
			{
				Assert::Fail(exception.getMessageWcharT());
			}
		}

		TEST_METHOD(LinkedListInsertBeforeString)
		{
			CrtCheckMemory check;
			try
			{
				DoubleLinkedList<std::string> aList;
				int i;

				std::string values[] = { "lol", "brol", "fol", "dol", "gol" };

				aList.Append(values[4]);
				for (i = 3; i >= 0; --i)
				{
					aList.InsertBefore(values[i], values[i + 1]);
				}

				i = 0;
				for (DLLNode<std::string> * DLLNode = aList.getHead(); DLLNode != nullptr; DLLNode = DLLNode->getNext())
				{
					Assert::AreEqual(values[i++], DLLNode->getInfo());
				}
			}
			catch (Exception exception)
			{
				Assert::Fail(exception.getMessageWcharT());
			}
		}

		TEST_METHOD(LinkedListInsertBeforeStringFail)
		{
			CrtCheckMemory check;
			try
			{
				DoubleLinkedList<std::string> aList;
				int i;

				std::string values[] = { "lol", "brol", "fol", "dol", "gol" };

				aList.Append(values[4]);
				for (i = 3; i >= 0; --i)
				{
					aList.InsertBefore(values[i], "haha");
				}

				i = 0;
				for (DLLNode<std::string> * DLLNode = aList.getHead(); DLLNode != nullptr; DLLNode = DLLNode->getNext())
				{
					Assert::AreEqual(values[i++], DLLNode->getInfo());
				}
			}
			catch (Exception exception)
			{
				Assert::IsTrue(true);
			}
		}
		
		
		TEST_METHOD(LinkedListInsertAfter)
		{
			CrtCheckMemory check;
			try
			{
				DoubleLinkedList<int> aList;
				int i;

				int values[] = { 5, 15, 25, 35, 45 };

				aList.Append(values[0]);
				for (i = 1; i < 5; ++i)
				{
					aList.InsertAfter(values[i], values[i - 1]);
				}

				i = 0;
				for (DLLNode<int> * DLLNode = aList.getHead(); DLLNode != nullptr; DLLNode = DLLNode->getNext())
				{
					Assert::AreEqual(values[i++], DLLNode->getInfo());
				}
			}
			catch (Exception exception)
			{
				Assert::Fail(exception.getMessageWcharT());
			}
		}

		TEST_METHOD(LinkedListInsertAfterFail)
		{
			CrtCheckMemory check;
			try
			{
				DoubleLinkedList<int> aList;
				int i;

				int values[] = { 5, 15, 25, 35, 45 };

				aList.Append(values[0]);
				for (i = 1; i < 5; ++i)
				{
					aList.InsertAfter(values[i], 99);
				}

				i = 0;
				for (DLLNode<int> * DLLNode = aList.getHead(); DLLNode != nullptr; DLLNode = DLLNode->getNext())
				{
					Assert::AreEqual(values[i++], DLLNode->getInfo());
				}
			}
			catch (Exception exception)
			{
				Assert::IsTrue(true);
			}
		}


		TEST_METHOD(LinkedListInsertAfterString)
		{
			CrtCheckMemory check;
			try
			{
				DoubleLinkedList<std::string> aList;
				int i;

				std::string values[] = { "lol", "brol", "fol", "dol", "gol" };

				aList.Append(values[0]);
				for (i = 1; i < 5; ++i)
				{
					aList.InsertAfter(values[i], values[i - 1]);
				}

				i = 0;
				for (DLLNode<std::string> * DLLNode = aList.getHead(); DLLNode != nullptr; DLLNode = DLLNode->getNext())
				{
					Assert::AreEqual(values[i++], DLLNode->getInfo());
				}
			}
			catch (Exception exception)
			{
				Assert::Fail(exception.getMessageWcharT());
			}
		}

		TEST_METHOD(LinkedListInsertAfterStringFail)
		{
			CrtCheckMemory check;
			try
			{
				DoubleLinkedList<std::string> aList;
				int i;

				std::string values[] = { "lol", "brol", "fol", "dol", "gol" };

				aList.Append(values[0]);
				for (i = 1; i < 5; ++i)
				{
					aList.InsertAfter(values[i], "haha");
				}

				i = 0;
				for (DLLNode<std::string> * DLLNode = aList.getHead(); DLLNode != nullptr; DLLNode = DLLNode->getNext())
				{
					Assert::AreEqual(values[i++], DLLNode->getInfo());
				}
			}
			catch (Exception exception)
			{
				Assert::IsTrue(true);
			}
		}
		
		TEST_METHOD(LinkedListExtract)
		{
			CrtCheckMemory check;
			try
			{
				DoubleLinkedList<int> list;

				list.Append(5);
				list.Extract(5);

				Assert::IsTrue(list.isEmpty());
				Assert::IsNull(list.getHead());

				list.Append(5);
				list.Append(10);
				list.Append(15);

				list.Extract(10);

				Assert::AreEqual(5, list.First());
				Assert::AreEqual(15, list.Last());
			}
			catch (Exception exception)
			{
				Assert::Fail(exception.getMessageWcharT());
			}
		}

		TEST_METHOD(LinkedListExtractString)
		{
			CrtCheckMemory check;
			try
			{
				DoubleLinkedList<std::string> list;

				list.Append("lol");
				list.Extract("lol");

				Assert::IsTrue(list.isEmpty());
				Assert::IsNull(list.getHead());

				list.Append("billy");
				list.Append("silly");
				list.Append("dilly");

				list.Extract("silly");

				Assert::IsTrue("billy" == list.First());
				Assert::IsTrue("dilly" == list.Last());
			}
			catch (Exception exception)
			{
				Assert::Fail(exception.getMessageWcharT());
			}
		}

		TEST_METHOD(LinkedListExtractStringFail)
		{
			CrtCheckMemory check;
			try
			{
				DoubleLinkedList<std::string> list;
				list.Append("lol");
				list.Extract("bye");
			}
			catch (Exception exception)
			{
				Assert::IsTrue(true);
			}
		}
		
	};
}