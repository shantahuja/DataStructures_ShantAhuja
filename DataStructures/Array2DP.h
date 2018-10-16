#ifndef ARRAY2DP_H
#define ARRAY2DP_H
#include "Row2DP.h"
#include "Exception.h"

template <class T>
class Row2DP;

template <class T>
class Array2DP
{
private:
	T * * m_array;
	int m_row;
	int m_col;
public:
	Array2DP();
	Array2DP(int row, int col);
	Array2DP(const Array2DP & copy);
	~Array2DP();
	Array2DP & operator =(const Array2DP & rhs);
	Row2DP<T> operator [](int index);
	Row2DP<T> operator [](int index) const;
	int getRow();
	int getRow() const;
	void setRow(int rows);
	int getColumn();
	int getColumn() const;
	void setColumn(int columns);
	T & Select(int row, int column);
	T&Select(int row, int column) const;
};

template <class T>
//make sure that default constructor has row, column, and length of zero
inline Array2DP<T>::Array2DP() : m_array(nullptr), m_row(0), m_col(0) {}

template<class T>
//make sure row, col, and length equal to what you set it
inline Array2DP<T>::Array2DP(int row, int col)
{
	try
	{
		if (row < 0)
		{
			throw Exception("negative row");
		}
		if (col < 0)
		{
			throw Exception("negative col");
		}
		m_array = new T*[row];
		for (std::size_t i = 0; i < row; i++)
		{
			m_array[i] = new T[col];
		}
		m_row = row;
		m_col = col;
	}
	catch (std::bad_alloc ba)
	{
		throw ba;
	}
}

template<class T>
//const
//string
inline Array2DP<T>::Array2DP(const Array2DP & copy)
{
	m_array = new T*[copy.getRow()];
	for (std::size_t i = 0; i < copy.getRow(); i++)
	{
		m_array[i] = new T[copy.getColumn()];
	}
	m_row = copy.getRow();
	m_col = copy.getColumn();
	for (int i = 0; i < m_row; i++)
	{
		for (int j = 0; j < m_col; j++)
		{
			m_array[i][j] = copy.m_array[i][j];
		}
	}
}

template<class T>
inline Array2DP<T>::~Array2DP()
{
	for (std::size_t i = 0; i < m_row; i++)
	{
		delete[] m_array[i];
	}
	delete[] m_array;
}

template<class T>
//use assignment operator to make two 2d arrays equal each other
inline Array2DP<T> & Array2DP<T>::operator=(const Array2DP & rhs)
{
	for (std::size_t i = 0; i < m_row; i++)
	{
		delete[] m_array[i];
	}
	delete[] m_array;
	m_array = new T*[rhs.getRow()];
	for (std::size_t i = 0; i < rhs.getRow(); i++)
	{
		m_array[i] = new T[rhs.getColumn()];
	}
	m_row = rhs.getRow();
	m_col = rhs.getColumn();
	for (int i = 0; i < m_row; i++)
	{
		for (int j = 0; j < m_col; j++)
		{
			m_array[i][j] = rhs.m_array[i][j];
		}
	}
	return *this;
}

template<class T>
inline Row2DP<T> Array2DP<T>::operator[](int index)
{
	return Row2DP<T>(*this, index);
}

template<class T>
inline Row2DP<T> Array2DP<T>::operator[](int index) const
{
	return Row2DP<T>(*this, index);
}

template<class T>
inline int Array2DP<T>::getRow()
{
	return m_row;
}

template<class T>
inline int Array2DP<T>::getRow() const
{
	return m_row;
}

template<class T>
//set new amount of rows and verify data inside
inline void Array2DP<T>::setRow(int rows)
{
	if (rows >= 0)
	{
		T ** temp = new T*[rows];
		for (int i = 0; i < rows; i++)
		{
			temp[i] = new T[m_col];
		}
		int actual_row = (m_row < rows) ? m_row : rows;
		for (int i = 0; i < actual_row; i++)
		{
			for (int j = 0; j < m_col; j++)
			{
				temp[i][j] = m_array[i][j];
			}
		}
		for (std::size_t i = 0; i < m_row; i++)
		{
			delete[] m_array[i];
		}
		delete[] m_array;
		m_row = rows;
		m_array = temp;
	}
	else
	{
		throw Exception("row is negative");
	}
}

template<class T>
inline int Array2DP<T>::getColumn()
{
	return m_col;
}

template<class T>
inline int Array2DP<T>::getColumn() const
{
	return m_col;
}

template<class T>
inline void Array2DP<T>::setColumn(int columns)
{
	if (columns >= 0)
	{
		T ** temp = new T*[m_row];
		for (int i = 0; i < m_row; i++)
		{
			temp[i] = new T[columns];
		}
		int actual_column = (m_col < columns) ? m_col : columns;
		for (int i = 0; i < m_row; i++)
		{
			for (int j = 0; j < actual_column; j++)
			{
				temp[i][j] = m_array[i][j];
			}
		}
		for (std::size_t i = 0; i < m_row; i++)
		{
			delete[] m_array[i];
		}
		delete[] m_array;
		m_col = columns;
		m_array = temp;
	}
	else
	{
		throw Exception("column is negative");
	}
}

template<class T>
inline T & Array2DP<T>::Select(int row, int column)
{
	try
	{
		if (row <= m_row && column <= m_col && row >= 0 && column >= 0)
		{
			return m_array[row][column];
		}
		else
			throw Exception("out of bounds");
	}
	catch (std::bad_alloc & ba)
	{
		throw ba;
	}
}

template<class T>
inline T & Array2DP<T>::Select(int row, int column) const
{
	try
	{
		if (row <= m_row && column <= m_col && row >= 0 && column >= 0)
		{
			return m_array[row][column];
		}
		else
			throw Exception("out of bounds");
	}
	catch (std::bad_alloc & ba)
	{
		throw ba;
	}
}

#endif // !Array2DP_H
