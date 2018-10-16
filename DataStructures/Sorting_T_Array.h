#ifndef SORTING_T_ARRAY_H
#define SORTING_T_ARRAY_H
#include "Array.h"
#include <vector>

using std::vector;

template <class T>
class Sorting_T_Array
{
private:
	//vector<T> sort_array;
	//Array<T> sort_array2;
	T * sort_array;
public:
	Sorting_T_Array<T>();
	Sorting_T_Array<T>(int a[], int n);
	~Sorting_T_Array<T>();
	void bruteForceBubbleSort(int a[], int n);
	void flaggedBubbleSort(int a[], int n);
	void selectionSort(int a[], int n);
	void insertionSort(int a[], int n);
	void shellSort(int a[], int n);
	void Heapify(int a[], int n, int i);
	void heapSort(int a[], int n);
	void Merge(int a[], int i, int mid, int j);
	void mergeSort(int a[], int i, int j);
	void mergeSortHelper(int a[], int n);
	void quickSort(int a[], int left, int right);
	void quickSortHelper(int a[], int n);
	int Partition(int a[], int left, int right);
};

template<class T>
inline Sorting_T_Array<T>::Sorting_T_Array()
{
	sort_array = 0;
}

template<class T>
inline Sorting_T_Array<T>::Sorting_T_Array(int a[], int n)
{
	sort_array = new T[n];
	for (int i = 0; i < n; i++)
	{
		sort_array[i] = a[i];
	}
}

template<class T>
inline Sorting_T_Array<T>::~Sorting_T_Array()
{
	delete[]sort_array;
}

template<class T>
inline void Sorting_T_Array<T>::bruteForceBubbleSort(int a[], int n)
{
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < n - i; j++)
		{
			if (a[j] > a[j + 1])
			{
				int temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
}

template<class T>
inline void Sorting_T_Array<T>::flaggedBubbleSort(int a[], int n)
{
	for (int i = 1; i < n; i++)
	{
		bool isSorted = true; // isSorted = true if a[] is sorted
		for (int j = 0; j < n - i; j++)
		{
			if (a[j] > a[j + 1])
			{
				int temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
				isSorted = false;
			}
		}
		if (isSorted) return;
	}
}

template<class T>
inline void Sorting_T_Array<T>::selectionSort(int a[], int n)
{
	for (int i = n - 1; i >= 1; i--)
	{
		int index = i; // i is the last item position and
					   // index is the largest element position 
		for (int j = 0; j < i; j++)
		{
			if (a[j] > a[index])
				index = j; // j is the current largest item
		}
		// swap the largest item a[index] with the last item a[i]
		int temp = a[index];
		a[index] = a[i];
		a[i] = temp;
	}
}

template<class T>
inline void Sorting_T_Array<T>::insertionSort(int a[], int n)
{
	for (int i = 1; i < n; i++)
	{
		//a[i] is the next data to insert
		int next = a[i];
		//Scan backwards to find a place
		int j;

		for (j = i - 1; j >= 0 && a[j] > next; j--)
		{
			a[j + 1] = a[j];
		}
		// Now insert the value next after index j at the end of the loop
		a[j + 1] = next;
	}
}

template<class T>
inline void Sorting_T_Array<T>::shellSort(int a[], int n)
{
	int j;
	for (int h = n / 2; h > 0; h /= 2)
	{
		for (int i = h; i < n; i++)
		{
			T tmp = a[i];
			for (j = i; j >= h && tmp < a[j - h]; j -= h)
			{
				a[j] = a[j - h];
			}
			a[j] = tmp;
		}
	}
}

// To heapify a subtree rooted with node i which is
// an index in arr[]. n is size of heap
template<class T>
inline void Sorting_T_Array<T>::Heapify(int a[], int n, int i)
{
	int largest = i;  // Initialize largest as root
	int l = 2 * i + 1;  // left = 2*i + 1
	int r = 2 * i + 2;  // right = 2*i + 2

						// If left child is larger than root
	if (l < n && a[l] > a[largest])
		largest = l;

	// If right child is larger than largest so far
	if (r < n && a[r] > a[largest])
		largest = r;

	// If largest is not root
	if (largest != i)
	{
		int temp = a[i];
		a[i] = a[largest];
		a[largest] = temp;

		// Recursively heapify the affected sub-tree
		Heapify(a, n, largest);
	}
}

template<class T>
inline void Sorting_T_Array<T>::heapSort(int a[], int n)
{
	// Build heap (rearrange array)
	for (int i = n / 2 - 1; i >= 0; i--)
		Heapify(a, n, i);

	// One by one extract an element from heap
	for (int i = n - 1; i >= 0; i--)
	{
		int temp = a[0];
		a[0] = a[i];
		a[i] = temp;
		// call max heapify on the reduced heap
		Heapify(a, i, 0);
	}
}


template<class T>
inline void Sorting_T_Array<T>::Merge(int a[], int i, int mid, int j)
{
	//Merges the 2 sorted sub-arrays
	int * temp = new int[j - i + 1]; // temp storage
	int left = i, right = mid + 1, it = 0;
	// it = next index to store merged item in temp[]

	while (left <= mid && right <= j)
	{
		if (a[left] <= a[right])
			temp[it++] = a[left++];
		else
			temp[it++] = a[right++];
	}
	//copy the remaining elements into temp.
	while (left <= mid)
		temp[it++] = a[left++];
	while (right <= j)
		temp[it++] = a[right++];
	//copy the result in temp back into the original array abort
	for (int k = 0; k < j - i + 1; k++)
		a[i + k] = temp[k];
	delete[]temp;
}

template<class T>
inline void Sorting_T_Array<T>::mergeSort(int a[], int i, int j)
{

	//to sort data from a[i] to a[j], where i<j
	if (i < j)
	{
		int mid = (i + j) / 2; //divide
		mergeSort(a, i, mid); //recursion
		mergeSort(a, mid + 1, j);
		Merge(a, i, mid, j); // conquer
	}
}

template<class T>
inline void Sorting_T_Array<T>::mergeSortHelper(int a[], int n)
{
	int i = 0;
	int j = n - 1;

	mergeSort(a, i, j);
}

template<class T>	
inline void Sorting_T_Array<T>::quickSort(int a[], int left, int right)
{
	if (left < right)
	{
		int p = Partition(a, left, right);
		quickSort(a, left, p - 1);
		quickSort(a, p + 1, right);
	}
}

template<class T>
inline void Sorting_T_Array<T>::quickSortHelper(int a[], int n)
{
	int left = 0;
	int right = n - 1;

	quickSort(a, left, right);
}

template<class T>
inline int Sorting_T_Array<T>::Partition(int a[], int left, int right)
{
	/*
	int p = a[left], l = left + 1, r = right;
	while (l < r)
	{
		while (l < right && a[l] < p)
		{
			l++;
		}
		while (r > left && a[r] >= p)
		{
			r--;
		}
		if (l < r)
		{
			int temp = a[l];
			a[l] = a[r];
			a[r] = temp;
		}
	}
	a[left] = a[r];
	a[r] = p;
	return r;
	*/
	int pivot = a[right], i = left - 1;
	for (int j = left; j <= right - 1; j++)
	{
		if (a[j] <= pivot)
		{
			i++;
			std::swap(a[i], a[j]);
		}
	}
	std::swap(a[i + 1], a[right]);
	return i + 1;
}

#endif // !SORTING_T_ARRAY_H
