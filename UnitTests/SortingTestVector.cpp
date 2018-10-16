#include "stdafx.h"
#include "CppUnitTest.h"
#include <iostream>
#include "CrtCheckMemory.h"
#include "Sorting_Vector_Array.h"
#include <Windows.h>
#include <fstream>
#include <time.h>
#include <random>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;



namespace UnitTests
{
	int VectorArray1[10000];
	int VectorArray2[20000];
	int VectorArray3[30000];
	int sorted_VectorArray1[10000];
	int sorted_VectorArray2[20000];
	int sorted_VectorArray3[30000];
	int VectorArray_a = 0;
	TEST_CLASS(SortingTestVectorArray)
	{
	public:
		TEST_METHOD_INITIALIZE(Init)
		{
			if (VectorArray_a == 0)
			{
				srand(time(0));

				int random1 = rand() % 10000;

				for (int i = 0; i < 10000; i++)
				{
					int random1 = rand() % 10000;
					VectorArray1[i] = random1;
				}

				for (int i = 0; i < 10000; i++)
				{
					VectorArray2[i] = VectorArray1[i];
				}

				for (int i = 10000; i < 20000; i++)
				{
					int random1 = rand() % 10000;
					VectorArray2[i] = random1;
				}

				for (int i = 0; i < 10000; i++)
				{
					VectorArray3[i] = VectorArray1[i];
				}

				for (int i = 10000; i < 20000; i++)
				{
					VectorArray3[i] = VectorArray2[i];
				}

				for (int i = 20000; i < 30000; i++)
				{
					int random1 = rand() % 10000;
					VectorArray3[i] = random1;
				}

				for (int i = 0; i < 10000; i++)
				{
					sorted_VectorArray1[i] = VectorArray1[i];
				}
				for (int i = 0; i < 20000; i++)
				{
					sorted_VectorArray2[i] = VectorArray2[i];
				}
				for (int i = 0; i < 30000; i++)
				{
					sorted_VectorArray3[i] = VectorArray3[i];
				}

				Sorting_Vector_Array<int> sort1(sorted_VectorArray1, 10000);
				Sorting_Vector_Array<int> sort2(sorted_VectorArray2, 20000);
				Sorting_Vector_Array<int> sort3(sorted_VectorArray3, 30000);

				sort1.bruteForceBubbleSort(sorted_VectorArray1, 10000);
				sort2.bruteForceBubbleSort(sorted_VectorArray2, 20000);
				sort3.bruteForceBubbleSort(sorted_VectorArray3, 30000);
			}
			VectorArray_a++;
		}
		TEST_METHOD(SortingVectorArrayBruteForceBubbleSortTest)
		{
			CrtCheckMemory check;

			int test1[10000];
			int test2[20000];
			int test3[30000];

			for (int i = 0; i < 10000; i++)
			{
				test1[i] = VectorArray1[i];
			}
			for (int i = 0; i < 20000; i++)
			{
				test2[i] = VectorArray2[i];
			}
			for (int i = 0; i < 30000; i++)
			{
				test3[i] = VectorArray3[i];
			}

			Sorting_Vector_Array<int> sort1(test1, 10000);
			Sorting_Vector_Array<int> sort2(test2, 20000);
			Sorting_Vector_Array<int> sort3(test3, 30000);

			DWORD start1 = GetTickCount();
			sort1.bruteForceBubbleSort(test1, 10000);
			DWORD end1 = GetTickCount();
			int time1 = end1 - start1;
			DWORD start2 = GetTickCount();
			sort2.bruteForceBubbleSort(test2, 20000);
			DWORD end2 = GetTickCount();
			int time2 = end2- start2;
			DWORD start3 = GetTickCount();
			sort3.bruteForceBubbleSort(test3, 30000);
			DWORD end3 = GetTickCount();
			int time3 = end3 - start3;
			// output to file the sort type
			std::ofstream myfile;
			myfile.open("C:\\Users\\Owner\\source\\repos\\DataStructures\\DataStructures_ShantAhuja\\UnitTests\\output_data_VectorArray.txt", std::ios::app);
			myfile << "sort type: bruteForceBubbleSort, Vector array" << std::endl;
			//output to file
			myfile << "time elapsed 10K " << time1 << std::endl;
			myfile << "time elapsed 20K " << time2 << std::endl;
			myfile << "time elapsed 30K " << time3 << std::endl;
			for (int i = 0; i < 10000; i++)
			{
				Assert::AreEqual(test1[i], sorted_VectorArray1[i]);
			}
			for (int i = 0; i < 20000; i++)
			{
				Assert::AreEqual(test2[i], sorted_VectorArray2[i]);
			}
			for (int i = 0; i < 30000; i++)
			{
				Assert::AreEqual(test3[i], sorted_VectorArray3[i]);
			}
		}

		TEST_METHOD(SortingVectorArrayMergeSortTest)
		{
			CrtCheckMemory check;

			int test1[10000];
			int test2[20000];
			int test3[30000];

			for (int i = 0; i < 10000; i++)
			{
				test1[i] = VectorArray1[i];
			}
			for (int i = 0; i < 20000; i++)
			{
				test2[i] = VectorArray2[i];
			}
			for (int i = 0; i < 30000; i++)
			{
				test3[i] = VectorArray3[i];
			}

			Sorting_Vector_Array<int> sort1(test1, 10000);
			Sorting_Vector_Array<int> sort2(test2, 20000);
			Sorting_Vector_Array<int> sort3(test3, 30000);

			DWORD start1 = GetTickCount();
			sort1.mergeSortHelper(test1, 10000);
			DWORD end1 = GetTickCount();
			int time1 = end1 - start1;
			DWORD start2 = GetTickCount();
			sort2.mergeSortHelper(test2, 20000);
			DWORD end2 = GetTickCount();
			int time2 = end2 - start2;
			DWORD start3 = GetTickCount();
			sort3.mergeSortHelper(test3, 30000);
			DWORD end3 = GetTickCount();
			int time3 = end3 - start3;
			// output to file the sort type
			std::ofstream myfile;
			myfile.open("C:\\Users\\Owner\\source\\repos\\DataStructures\\DataStructures_ShantAhuja\\UnitTests\\output_data_VectorArray.txt", std::ios::app);
			myfile << "sort type: mergeSortHelper, Vector array" << std::endl;
			//output to file
			myfile << "time elapsed 10K " << time1 << std::endl;
			myfile << "time elapsed 20K " << time2 << std::endl;
			myfile << "time elapsed 30K " << time3 << std::endl;
			for (int i = 0; i < 10000; i++)
			{
				Assert::AreEqual(test1[i], sorted_VectorArray1[i]);
			}
			for (int i = 0; i < 20000; i++)
			{
				Assert::AreEqual(test2[i], sorted_VectorArray2[i]);
			}
			for (int i = 0; i < 30000; i++)
			{
				Assert::AreEqual(test3[i], sorted_VectorArray3[i]);
			}
		}

		TEST_METHOD(SortingVectorArrayHeapSortTest)
		{
			CrtCheckMemory check;

			int test1[10000];
			int test2[20000];
			int test3[30000];

			for (int i = 0; i < 10000; i++)
			{
				test1[i] = VectorArray1[i];
			}
			for (int i = 0; i < 20000; i++)
			{
				test2[i] = VectorArray2[i];
			}
			for (int i = 0; i < 30000; i++)
			{
				test3[i] = VectorArray3[i];
			}

			Sorting_Vector_Array<int> sort1(test1, 10000);
			Sorting_Vector_Array<int> sort2(test2, 20000);
			Sorting_Vector_Array<int> sort3(test3, 30000);

			DWORD start1 = GetTickCount();
			sort1.heapSort(test1, 10000);
			DWORD end1 = GetTickCount();
			int time1 = end1 - start1;
			DWORD start2 = GetTickCount();
			sort2.heapSort(test2, 20000);
			DWORD end2 = GetTickCount();
			int time2 = end2 - start2;
			DWORD start3 = GetTickCount();
			sort3.heapSort(test3, 30000);
			DWORD end3 = GetTickCount();
			int time3 = end3 - start3;
			// output to file the sort type
			std::ofstream myfile;
			myfile.open("C:\\Users\\Owner\\source\\repos\\DataStructures\\DataStructures_ShantAhuja\\UnitTests\\output_data_VectorArray.txt", std::ios::app);
			myfile << "sort type: heapSort, Vector array" << std::endl;
			//output to file
			myfile << "time elapsed 10K " << time1 << std::endl;
			myfile << "time elapsed 20K " << time2 << std::endl;
			myfile << "time elapsed 30K " << time3 << std::endl;
			for (int i = 0; i < 10000; i++)
			{
				Assert::AreEqual(test1[i], sorted_VectorArray1[i]);
			}
			for (int i = 0; i < 20000; i++)
			{
				Assert::AreEqual(test2[i], sorted_VectorArray2[i]);
			}
			for (int i = 0; i < 30000; i++)
			{
				Assert::AreEqual(test3[i], sorted_VectorArray3[i]);
			}
		}

		TEST_METHOD(SortingVectorArrayFlaggedBubbleSortTest)
		{
			CrtCheckMemory check;

			int test1[10000];
			int test2[20000];
			int test3[30000];

			for (int i = 0; i < 10000; i++)
			{
				test1[i] = VectorArray1[i];
			}
			for (int i = 0; i < 20000; i++)
			{
				test2[i] = VectorArray2[i];
			}
			for (int i = 0; i < 30000; i++)
			{
				test3[i] = VectorArray3[i];
			}

			Sorting_Vector_Array<int> sort1(test1, 10000);
			Sorting_Vector_Array<int> sort2(test2, 20000);
			Sorting_Vector_Array<int> sort3(test3, 30000);

			DWORD start1 = GetTickCount();
			sort1.flaggedBubbleSort(test1, 10000);
			DWORD end1 = GetTickCount();
			int time1 = end1 - start1;
			DWORD start2 = GetTickCount();
			sort2.flaggedBubbleSort(test2, 20000);
			DWORD end2 = GetTickCount();
			int time2 = end2 - start2;
			DWORD start3 = GetTickCount();
			sort3.flaggedBubbleSort(test3, 30000);
			DWORD end3 = GetTickCount();
			int time3 = end3 - start3;
			// output to file the sort type
			std::ofstream myfile;
			myfile.open("C:\\Users\\Owner\\source\\repos\\DataStructures\\DataStructures_ShantAhuja\\UnitTests\\output_data_VectorArray.txt", std::ios::app);
			myfile << "sort type: flaggedBubbleSort, Vector array" << std::endl;
			//output to file
			myfile << "time elapsed 10K " << time1 << std::endl;
			myfile << "time elapsed 20K " << time2 << std::endl;
			myfile << "time elapsed 30K " << time3 << std::endl;
			for (int i = 0; i < 10000; i++)
			{
				Assert::AreEqual(test1[i], sorted_VectorArray1[i]);
			}
			for (int i = 0; i < 20000; i++)
			{
				Assert::AreEqual(test2[i], sorted_VectorArray2[i]);
			}
			for (int i = 0; i < 30000; i++)
			{
				Assert::AreEqual(test3[i], sorted_VectorArray3[i]);
			}
		}

		TEST_METHOD(SortingVectorArraySelectionSortTest)
		{
			CrtCheckMemory check;

			int test1[10000];
			int test2[20000];
			int test3[30000];

			for (int i = 0; i < 10000; i++)
			{
				test1[i] = VectorArray1[i];
			}
			for (int i = 0; i < 20000; i++)
			{
				test2[i] = VectorArray2[i];
			}
			for (int i = 0; i < 30000; i++)
			{
				test3[i] = VectorArray3[i];
			}

			Sorting_Vector_Array<int> sort1(test1, 10000);
			Sorting_Vector_Array<int> sort2(test2, 20000);
			Sorting_Vector_Array<int> sort3(test3, 30000);

			DWORD start1 = GetTickCount();
			sort1.selectionSort(test1, 10000);
			DWORD end1 = GetTickCount();
			int time1 = end1 - start1;
			DWORD start2 = GetTickCount();
			sort2.selectionSort(test2, 20000);
			DWORD end2 = GetTickCount();
			int time2 = end2 - start2;
			DWORD start3 = GetTickCount();
			sort3.selectionSort(test3, 30000);
			DWORD end3 = GetTickCount();
			int time3 = end3 - start3;
			// output to file the sort type
			std::ofstream myfile;
			myfile.open("C:\\Users\\Owner\\source\\repos\\DataStructures\\DataStructures_ShantAhuja\\UnitTests\\output_data_VectorArray.txt", std::ios::app);
			myfile << "sort type: selectionSort, Vector array" << std::endl;
			//output to file
			myfile << "time elapsed 10K " << time1 << std::endl;
			myfile << "time elapsed 20K " << time2 << std::endl;
			myfile << "time elapsed 30K " << time3 << std::endl;
			for (int i = 0; i < 10000; i++)
			{
				Assert::AreEqual(test1[i], sorted_VectorArray1[i]);
			}
			for (int i = 0; i < 20000; i++)
			{
				Assert::AreEqual(test2[i], sorted_VectorArray2[i]);
			}
			for (int i = 0; i < 30000; i++)
			{
				Assert::AreEqual(test3[i], sorted_VectorArray3[i]);
			}
		}

		TEST_METHOD(SortingVectorArrayInsertionSortTest)
		{
			CrtCheckMemory check;

			int test1[10000];
			int test2[20000];
			int test3[30000];

			for (int i = 0; i < 10000; i++)
			{
				test1[i] = VectorArray1[i];
			}
			for (int i = 0; i < 20000; i++)
			{
				test2[i] = VectorArray2[i];
			}
			for (int i = 0; i < 30000; i++)
			{
				test3[i] = VectorArray3[i];
			}

			Sorting_Vector_Array<int> sort1(test1, 10000);
			Sorting_Vector_Array<int> sort2(test2, 20000);
			Sorting_Vector_Array<int> sort3(test3, 30000);

			DWORD start1 = GetTickCount();
			sort1.insertionSort(test1, 10000);
			DWORD end1 = GetTickCount();
			int time1 = end1 - start1;
			DWORD start2 = GetTickCount();
			sort2.insertionSort(test2, 20000);
			DWORD end2 = GetTickCount();
			int time2 = end2 - start2;
			DWORD start3 = GetTickCount();
			sort3.insertionSort(test3, 30000);
			DWORD end3 = GetTickCount();
			int time3 = end3 - start3;
			// output to file the sort type
			std::ofstream myfile;
			myfile.open("C:\\Users\\Owner\\source\\repos\\DataStructures\\DataStructures_ShantAhuja\\UnitTests\\output_data_VectorArray.txt", std::ios::app);
			myfile << "sort type: insertionSort, Vector array" << std::endl;
			//output to file
			myfile << "time elapsed 10K " << time1 << std::endl;
			myfile << "time elapsed 20K " << time2 << std::endl;
			myfile << "time elapsed 30K " << time3 << std::endl;
			for (int i = 0; i < 10000; i++)
			{
				Assert::AreEqual(test1[i], sorted_VectorArray1[i]);
			}
			for (int i = 0; i < 20000; i++)
			{
				Assert::AreEqual(test2[i], sorted_VectorArray2[i]);
			}
			for (int i = 0; i < 30000; i++)
			{
				Assert::AreEqual(test3[i], sorted_VectorArray3[i]);
			}
		}

		TEST_METHOD(SortingVectorArrayShellSortTest)
		{
			CrtCheckMemory check;

			int test1[10000];
			int test2[20000];
			int test3[30000];

			for (int i = 0; i < 10000; i++)
			{
				test1[i] = VectorArray1[i];
			}
			for (int i = 0; i < 20000; i++)
			{
				test2[i] = VectorArray2[i];
			}
			for (int i = 0; i < 30000; i++)
			{
				test3[i] = VectorArray3[i];
			}

			Sorting_Vector_Array<int> sort1(test1, 10000);
			Sorting_Vector_Array<int> sort2(test2, 20000);
			Sorting_Vector_Array<int> sort3(test3, 30000);

			DWORD start1 = GetTickCount();
			sort1.shellSort(test1, 10000);
			DWORD end1 = GetTickCount();
			int time1 = end1 - start1;
			DWORD start2 = GetTickCount();
			sort2.shellSort(test2, 20000);
			DWORD end2 = GetTickCount();
			int time2 = end2- start2;
			DWORD start3 = GetTickCount();
			sort3.shellSort(test3, 30000);
			DWORD end3 = GetTickCount();
			int time3 = end3 - start3;
			// output to file the sort type
			std::ofstream myfile;
			myfile.open("C:\\Users\\Owner\\source\\repos\\DataStructures\\DataStructures_ShantAhuja\\UnitTests\\output_data_VectorArray.txt", std::ios::app);
			myfile << "sort type: shell sort, Vector array" << std::endl;
			//output to file
			myfile << "time elapsed 10K " << time1 << std::endl;
			myfile << "time elapsed 20K " << time2 << std::endl;
			myfile << "time elapsed 30K " << time3 << std::endl;
			for (int i = 0; i < 10000; i++)
			{
				Assert::AreEqual(test1[i], sorted_VectorArray1[i]);
			}
			for (int i = 0; i < 20000; i++)
			{
				Assert::AreEqual(test2[i], sorted_VectorArray2[i]);
			}
			for (int i = 0; i < 30000; i++)
			{
				Assert::AreEqual(test3[i], sorted_VectorArray3[i]);
			}
		}

		TEST_METHOD(SortingVectorArrayQuickSortTest)
		{
			CrtCheckMemory check;

			int test1[10000];
			int test2[20000];
			int test3[30000];

			for (int i = 0; i < 10000; i++)
			{
				test1[i] = VectorArray1[i];
			}
			for (int i = 0; i < 20000; i++)
			{
				test2[i] = VectorArray2[i];
			}
			for (int i = 0; i < 30000; i++)
			{
				test3[i] = VectorArray3[i];
			}

			Sorting_Vector_Array<int> sort1(test1, 10000);
			Sorting_Vector_Array<int> sort2(test2, 20000);
			Sorting_Vector_Array<int> sort3(test3, 30000);

			DWORD start1 = GetTickCount();
			sort1.quickSortHelper(test1, 10000);
			DWORD end1 = GetTickCount();
			int time1 = end1 - start1;
			DWORD start2 = GetTickCount();
			sort2.quickSortHelper(test2, 20000);
			DWORD end2 = GetTickCount();
			int time2 = end2 - start2;
			DWORD start3 = GetTickCount();
			sort3.quickSortHelper(test3, 30000);
			DWORD end3 = GetTickCount();
			int time3 = end3 - start3;
			// output to file the sort type
			std::ofstream myfile;
			myfile.open("C:\\Users\\Owner\\source\\repos\\DataStructures\\DataStructures_ShantAhuja\\UnitTests\\output_data_VectorArray.txt", std::ios::app);
			myfile << "sort type: quickSortHelper, Vector array" << std::endl;
			//output to file
			myfile << "time elapsed 10K " << time1 << std::endl;
			myfile << "time elapsed 20K " << time2 << std::endl;
			myfile << "time elapsed 30K " << time3 << std::endl;
			for (int i = 0; i < 10000; i++)
			{
				Assert::AreEqual(test1[i], sorted_VectorArray1[i]);
			}
			for (int i = 0; i < 20000; i++)
			{
				Assert::AreEqual(test2[i], sorted_VectorArray2[i]);
			}
			for (int i = 0; i < 30000; i++)
			{
				Assert::AreEqual(test3[i], sorted_VectorArray3[i]);
			}
		}
	};
}