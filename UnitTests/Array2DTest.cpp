#pragma once
#include "stdafx.h"
#include "CppUnitTest.h"
#include "CrtCheckMemory.h"
#include "Array.h"
#include "Exception.h"
#include "Array2D.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(Array2DTest)
	{
	public:
		TEST_METHOD(Array2DDefaultConstructorRowIsZero)
		{
			CrtCheckMemory check;
			Array2D<int> array1;
			Assert::AreEqual(array1.getRow(), 0);
		}

		TEST_METHOD(Array2DDefaultConstructorColumnIsZero)
		{
			CrtCheckMemory check;
			Array2D<int> array1;
			Assert::AreEqual(array1.getColumn(), 0);
		}

		TEST_METHOD(Array2DParameterizeNegativeRow)
		{
			CrtCheckMemory check;
			try
			{
				Array2D<int> array1(-1, 0);
			}
			catch (Exception e)
			{
				Assert::IsTrue(true);
			}
		}

		TEST_METHOD(Array2DParameterizeNegativeColumn)
		{
			CrtCheckMemory check;
			try
			{
				Array2D<int> array1(0, -1);
			}
			catch (Exception e)
			{
				Assert::IsTrue(true);
			}
		}

		TEST_METHOD(Array2DParameterizeConstructorRowCheck)
		{
			CrtCheckMemory check;
			Array2D<int> array1(5, 10);
			Assert::AreEqual(array1.getRow(), 5);
		}

		TEST_METHOD(Array2DParameterizeConstructorColumnCheck)
		{
			CrtCheckMemory check;
			Array2D<int> array1(5, 10);
			Assert::AreEqual(array1.getColumn(), 10);
		}

		TEST_METHOD(Array2DCopyConstructorEqualTest)
		{
			CrtCheckMemory check;
			{
				Array2D<int> array1(3, 3);

				for (int i = 0; i < 3; i++)
				{
					for (int j = 0; j < 3; j++)
					{
						array1[i][j] = i * j;
					}
				}
				Array2D<int> array2(array1);
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

		TEST_METHOD(Array2DCopyConstructorTestConst)
		{
			CrtCheckMemory check;
			{
				Array2D<int> array1(3, 3);

				for (int i = 0; i < 3; i++)
				{
					for (int j = 0; j < 3; j++)
					{
						array1[i][j] = i * j;
					}
				}
				const Array2D<int> array2(array1);
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

		TEST_METHOD(Array2DCopyConstructorTestString)
		{
			CrtCheckMemory check;
			{
				Array2D<std::string> array1(3, 3);
				array1[1][1] = "lol";
				Array2D<std::string> array2(array1);
				Assert::IsTrue(array2.getColumn() == array1.getColumn() && array2.getRow() == array1.getRow());
				Assert::AreEqual(array1[1][1], array2[1][1]);
			}
		}

		TEST_METHOD(Array2DAssignmentOperatorTest)
		{
			CrtCheckMemory check;
			Array2D<int> array1(3, 3);
			Array2D<int> array2(3, 2);
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

		TEST_METHOD(Array2DAssignmentOperatorTestString)
		{
			CrtCheckMemory check;
			Array2D<std::string> array1(3, 3);
			Array2D<std::string> array2(3, 2);
			array1[1][1] = "lol";
			array2[1][1] = "bad";
			array2[1][1] = array1[1][1];
			Assert::IsTrue(array1[1][1] == array2[1][1]);
		}

		TEST_METHOD(Array2DSetRowTest)
		{
			CrtCheckMemory check;
			Array2D<int> array1(3, 3);
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

		TEST_METHOD(Array2DSetColumn3to5)
		{
			CrtCheckMemory check;
			Array2D<int> array1(3, 4);
			array1.setColumn(5);
			Assert::AreEqual(5, array1.getColumn());
		}

		TEST_METHOD(Array2DSetRow3to5)
		{
			CrtCheckMemory check;
			Array2D<int> array1(3, 4);
			array1.setRow(5);
			Assert::AreEqual(5, array1.getRow());
		}

		TEST_METHOD(Array2DSetColumn)
		{
			CrtCheckMemory check;
			Array2D<int> array1(3, 3);
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

		TEST_METHOD(Array2DOutOfBoundsTest)
		{
			CrtCheckMemory check;
			try
			{
				Array2D<int> array1(3, 3);
				array1[5][0] = 0;
			}
			catch (Exception e)
			{
				Assert::IsTrue(true);
			}
		}

		TEST_METHOD(Array2DOutOfBoundsRowNegativeTest)
		{
			CrtCheckMemory check;
			try
			{
				Array2D<int> array1(3, 3);
				array1[-1][0] = 0;
			}
			catch (Exception e)
			{
				Assert::IsTrue(true);
			}

		}

		TEST_METHOD(Array2DOutOfBoundsColumnNegativeTest)
		{
			CrtCheckMemory check;
			try
			{
				Array2D<int> array1(3, 3);
				array1[0][-1] = 0;
			}
			catch (Exception e)
			{
				Assert::IsTrue(true);
			}
		}

	};

}
