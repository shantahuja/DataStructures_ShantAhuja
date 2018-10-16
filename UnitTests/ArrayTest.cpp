#include "stdafx.h"
#include "CppUnitTest.h"
#include "CrtCheckMemory.h"
#include "Array.h"
#include "Exception.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(ArrayTest)
	{
	public:
		TEST_METHOD(ArrayDefaultConstructorCheckSizeZero)
		{
			CrtCheckMemory check;
			Array<int> MyArray;
			Assert::AreEqual(MyArray.getLength(), 0);
		}

		TEST_METHOD(ArrayDefaultConstructorCheckStartIndexZero)
		{
			CrtCheckMemory check;
			Array<int> MyArray;
			Assert::AreEqual(MyArray.getStartIndex(), 0);
		}

		TEST_METHOD(ArrayParameterizeConstructorLengthTest)
		{
			CrtCheckMemory check;
			try
			{
				Array<int> array1(5, -5);
				for (int i = -5; i < 0; i++)
				{
					array1[i] = i;
				}
			Assert::AreEqual(5, array1.getLength());
			}
			catch (std::bad_alloc ba)
			{
				throw Exception("bad alloc");
			}
		}

		TEST_METHOD(ArrayParameterizeConstructorStartIndexTest)
		{
			CrtCheckMemory check;
			try
			{
				Array<int> array(5, -5);

				Assert::AreEqual(-5, array.getStartIndex());
			}
			catch (std::bad_alloc ba)
			{
				throw Exception("bad_alloc");
			}
		}

		TEST_METHOD(ArrayParameterizeConstructorTestNegativeLength)
		{
			CrtCheckMemory check;
			try
			{
				Array<int> array(-1, 0); 
			}
			catch (Exception e)
			{
				Assert::IsTrue(true);
			}
			catch (std::bad_alloc ba)
			{
				Assert::IsTrue(true);
			}
		}

		TEST_METHOD(ArrayCopyConstructorEqualTest)
		{
			CrtCheckMemory check;
			Array<int> myarray(5, -10);
			for (int i = -10; i < -5; i++)
			{
				myarray[i] = i;
			}
			try
			{
				Array<int> myarray2(myarray);
				Assert::IsTrue(myarray.getLength() == myarray2.getLength() && myarray.getStartIndex() == myarray2.getStartIndex());
				for (int i = -10; i < -5; i++)
				{
					Assert::IsTrue(myarray[i] == myarray2[i]);
				}
			}
			catch (std::bad_alloc ba)
			{
				throw Exception("out of bounds");
			}
		}
		
		TEST_METHOD(ArrayAssignmentOperatorEqualTest)
		{
			CrtCheckMemory check;
			Array<int> myarray(5, -10);
			for (int i = -10; i < -5; i++)
			{
				myarray[i] = i;
			}
			Array<int> myarray2{};
			myarray2 = myarray;
			Assert::IsTrue(myarray.getLength() == myarray2.getLength() && myarray.getStartIndex() == myarray2.getStartIndex());
			for (int i = -10; i < -5; i++)
			{
				Assert::IsTrue(myarray[i] == myarray2[i]);
			}
		}

		TEST_METHOD(ArrayAssignmentOperatorSelftoSelfAssignment)
		{
			CrtCheckMemory check;
			Array<int> myarray(5, -10);
			for (int i = -10; i < -5; i++)
			{
				myarray[i] = i;
			}
			try
			{
				myarray = myarray;
				Assert::IsTrue(myarray.getLength() == myarray.getLength() && myarray.getStartIndex() == myarray.getStartIndex());
				for (int i = -10; i < -5; i++)
				{
					Assert::IsTrue(myarray[i] == myarray[i]);
				}
			}
			catch (Exception e)
			{
				Assert::IsTrue(true);
			}
		}
		
		TEST_METHOD(ArrayInBoundsPositiveIndexTest)
		{
			CrtCheckMemory check;
			Array<int> myarray1(5, 10);
			try
			{
				for (int i = 10; i < 15; i++)
				{
					myarray1[i] = i;
				}
			}
			catch (Exception e)
			{
				Assert::IsTrue(true);
			}
		}

		TEST_METHOD(ArrayInBoundsNegativeIndexTest)
		{
			CrtCheckMemory check;
			Array<int> myarray1(5, -10);
			try
			{
				for (int i = -10; i < -5; i++)
				{
					myarray1[i] = i;
				}
			}
			catch (Exception e)
			{
				Assert::IsTrue(true);
			}
		}

		TEST_METHOD(ArrayOutOfBoundsMaxPositiveIndexTest)
		{
			CrtCheckMemory check;
			Array<int> myarray1(5, 10);
			try
			{
				for (int i = 11; i < 15; i++)
				{
					myarray1[i] = i;
				}
			}
			catch (Exception e)
			{
				Assert::IsTrue(true);
			}
		}

		TEST_METHOD(ArrayOutOfBoundsMinPositiveIndexTest)
		{
			CrtCheckMemory check;
			Array<int> myarray1(5, 10);
			try
			{
				for (int i = 9; i < 15; i++)
				{
					myarray1[i] = i;
				}
			}
			catch (Exception e)
			{
				Assert::IsTrue(true);
			}
		}

		TEST_METHOD(ArrayOutOfBoundsMaxNegativeIndexTest)
		{
			CrtCheckMemory check;
			Array<int> myarray1(5, -10);
			try
			{
				for (int i = -10; i < -4; i++)
				{
					myarray1[i] = i;
				}
			}
			catch (Exception e)
			{
				Assert::IsTrue(true);
			}
		}

		TEST_METHOD(ArrayOutOfBoundsMinNegativeIndexTest)
		{
			CrtCheckMemory check;
			Array<int> myarray1(5, -10);
			try
			{
				for (int i = -11; i < -5; i++)
				{
					myarray1[i] = i;
				}
			}
			catch (Exception e)
			{
				Assert::IsTrue(true);
			}
		}

		TEST_METHOD(ArraySetStartIndexTest)
		{
			CrtCheckMemory Check;
			Array<int> myarray1(5, -10);
			myarray1.setStartIndex(-11);
			Assert::AreEqual(-11, myarray1.getStartIndex());
		}

		TEST_METHOD(ArraySetLength)
		{
			CrtCheckMemory Check;
			Array<int> myarray1(5, -10);
			myarray1.setLength(6);
			Assert::AreEqual(6, myarray1.getLength());
		}
	};
}