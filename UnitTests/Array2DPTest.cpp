#include "stdafx.h"
#include "CppUnitTest.h"
#include "CrtCheckMemory.h"
#include "Exception.h"
#include "Array2DP.h"
#include <string>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(Array2DTest)
	{
	public:
		TEST_METHOD(Array2DPDefaultConstructorRowIsZero)
		{
			CrtCheckMemory check;
			Array2DP<int> array1;
			Assert::AreEqual(array1.getRow(), 0);
		}

		TEST_METHOD(Array2DPDefaultConstructorColumnIsZero)
		{
			CrtCheckMemory check;
			Array2DP<int> array1;
			Assert::AreEqual(array1.getColumn(), 0);
		}

		TEST_METHOD(Array2DPParameterizeNegativeRow)
		{
			CrtCheckMemory check;
			try
			{
				Array2DP<int> array1(-1, 0);
			}
			catch (Exception e)
			{
				Assert::IsTrue(true);
			}
		}

		TEST_METHOD(Array2DPParameterizeNegativeColumn)
		{
			CrtCheckMemory check;
			try
			{
				Array2DP<int> array1(0, -1);
			}
			catch (Exception e)
			{
				Assert::IsTrue(true);
			}
		}

		TEST_METHOD(Array2DPParameterizeConstructorRowCheck)
		{
			CrtCheckMemory check;
			Array2DP<int> array1(5, 10);
			Assert::AreEqual(array1.getRow(), 5);
		}

		TEST_METHOD(Array2DPParameterizeConstructorColumnCheck)
		{
			CrtCheckMemory check;
			Array2DP<int> array1(5, 10);
			Assert::AreEqual(array1.getColumn(), 10);
		}

		TEST_METHOD(Array2DPCopyConstructorTest)
		{
			CrtCheckMemory check;
			{
				Array2DP<int> array1(3, 3);

				for (int i = 0; i < 3; i++)
				{
					for (int j = 0; j < 3; j++)
					{
						array1[i][j] = i * j;
					}
				}
				Array2DP<int> array2(array1);
				Assert::IsTrue(array2.getColumn() == array1.getColumn() && array2.getRow() == array1.getRow());
				for (int i = 0; i < 3; i++)
				{
					for (int j = 0; j < 3; j++)
					{
						Assert::IsTrue(array1[i][j] == array2[i][j]);
					}
				}
			}
		}

		TEST_METHOD(Array2DPCopyConstructorTestConst)
		{
			CrtCheckMemory check;
			{
				Array2DP<int> array1(3, 3);

				for (int i = 0; i < 3; i++)
				{
					for (int j = 0; j < 3; j++)
					{
						array1[i][j] = i * j;
					}
				}
				const Array2DP<int> array2(array1);
				Assert::IsTrue(array2.getColumn() == array1.getColumn() && array2.getRow() == array1.getRow());
				for (int i = 0; i < 3; i++)
				{
					for (int j = 0; j < 3; j++)
					{
						Assert::IsTrue(array1[i][j] == array2[i][j]);
					}
				}
			}
		}

		TEST_METHOD(Array2DPCopyConstructorTestString)
		{
			CrtCheckMemory check;
			{
				Array2DP<std::string> array1(3, 3);
				array1[1][1] = "lol";
				Array2DP<std::string> array2(array1);
				Assert::IsTrue(array2.getColumn() == array1.getColumn() && array2.getRow() == array1.getRow());
				Assert::AreEqual(array1[1][1], array2[1][1]);
			}
		}


		TEST_METHOD(Array2DPAssignmentOperatorTest)
		{
			CrtCheckMemory check;
			Array2DP<int> array1(3, 3);
			Array2DP<int> array2(3, 2);
			array2 = array1;
			Assert::IsTrue(array2.getColumn() == array1.getColumn() && array2.getRow() == array1.getRow());
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 2; j++)
				{
					Assert::IsTrue(array1[i][j] == array2[i][j]);
				}
			}
		}

		TEST_METHOD(Array2DPAssignmentOperatorTestString)
		{
			CrtCheckMemory check;
			Array2DP<std::string> array1(3, 3);
			Array2DP<std::string> array2(3, 2);
			array1[1][1] = "lol";
			array2[1][1] = "bad";
			array2[1][1] = array1[1][1];
			Assert::IsTrue(array1[1][1] == array2[1][1]);
		}

		TEST_METHOD(Array2DPSetRowTest)
		{
			CrtCheckMemory check;
			{
				Array2DP<int> array1(3, 3);
				int index = 0;
				for (int i = 0; i < 3; i++)
				{
					for (int j = 0; j < 3; j++)
					{
						//array1[i][j] = i * j;
						array1[i][j] = index++;
					}
				}
				array1.setRow(2);
				int verify = 0;
				for (int i = 0; i < 2; i++)
				{
					for (int j = 0; j < 3; j++)
					{
						//array1[i][j] = i * j;
						verify += array1[i][j];
					}
				}
				Assert::AreEqual(2, array1.getRow());
				Assert::AreEqual(15, verify);
			}
		}

		TEST_METHOD(Array2DPSetColumn)
		{
			CrtCheckMemory check;
			Array2DP<int> array1(3, 3);
			int index = 0;
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					//array1[i][j] = i * j;
					array1[i][j] = index++;
				}
			}
			array1.setColumn(2);
			int verify = 0;
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 2; j++)
				{
					//array1[i][j] = i * j;
					verify += array1[i][j];
				}
			}
			Assert::AreEqual(2, array1.getColumn());
			Assert::AreEqual(21, verify);
		}

		TEST_METHOD(Array2DPSetColumn3to5)
		{
			CrtCheckMemory check;
			Array2DP<int> array1(3, 4);
			array1.setColumn(5);
			Assert::AreEqual(5, array1.getColumn());
		}

		TEST_METHOD(Array2DPSetRow3to5)
		{
			CrtCheckMemory check;
			Array2DP<int> array1(3, 4);
			array1.setRow(5);
			Assert::AreEqual(5, array1.getRow());
		}

		TEST_METHOD(Array2DPOutOfBoundsTest)
		{
			CrtCheckMemory check;
			try
			{
				Array2DP<int> array1(3, 3);
				array1[5][0] = 0;
			}
			catch (Exception e)
			{
				Assert::IsTrue(true);
			}
		}

		TEST_METHOD(Array2DPOutOfBoundsRowNegativeTest)
		{
			CrtCheckMemory check;
			try
			{
				Array2DP<int> array1(3, 3);
				array1[-1][0] = 0;
			}
			catch (Exception e)
			{
				Assert::IsTrue(true);
			}
		}

		TEST_METHOD(Array2DPOutOfBoundsColumnNegativeTest)
		{
			CrtCheckMemory check;
			try
			{
				Array2DP<int> array1(3, 3);
				array1[0][-1] = 0;
			}
			catch (Exception e)
			{
				Assert::IsTrue(true);
			}
		}
	};
}