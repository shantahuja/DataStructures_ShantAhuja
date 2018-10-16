#ifndef ARRAY_H
#define ARRAY_H
#include "Exception.h"
#include <math.h>
#include <new>

template <class T>
class Array
{
private:
	T * m_array;
	int m_length;
	int  m_start_index;
public:
	Array();
	Array(std::size_t length, int start_index = 0);
	Array(const Array & In_Array);
	~Array();
	Array & operator =(const Array & rhs);
	T & operator [](int index);
	T & operator [](int index) const;
	int getStartIndex();
	int getStartIndex() const;
	void setStartIndex(int start_index);
	int getLength();
	int getLength() const;
	void setLength(int length);	
};

template<class T>
inline Array<T>::Array() : m_array(nullptr), m_length(0), m_start_index(0) {}

template<class T>
inline Array<T>::Array(std::size_t length, int start_index) : m_array(nullptr), m_length(0), m_start_index(0)
{
	if (length < 0)
	{
		throw Exception("negative length");
	}
	m_array = new T[length];
	m_length = length;
	m_start_index = start_index;
}

template<class T>
inline Array<T>::Array(const Array<T> & In_Array) : m_array(nullptr), m_length(0), m_start_index(0)
{
	std::size_t Length = In_Array.getLength();
	if (Length < 0)
	{
		throw Exception("negative length");
	}
	m_array = new T[Length];
	m_length = Length;
	m_start_index = In_Array.getStartIndex();
	for (int i = 0; i < Length; i++)
	{
		m_array[i] = In_Array.m_array[i];
	}
}

template<class T>
inline Array<T>::~Array()
{
	delete []m_array;
}

template<class T>
inline Array<T> & Array<T>::operator=(const Array & rhs)
{
	if (&rhs != this)
	{
		delete[]m_array;
		std::size_t Length = rhs.getLength();
		m_array = new T[Length];
		m_length = Length;
		m_start_index = rhs.getStartIndex();
		for (int i = 0; i < Length; i++)
		{
			m_array[i] = rhs.m_array[i];
		}
	}
	else
	{
		throw Exception ("attempt to self assign");
	}
	return *this;
}

template<class T>
inline T & Array<T>::operator[](const int index)
{
	if (index < m_start_index || index >= m_length - abs(m_start_index))
	{
		throw Exception("outofbounds");
	}
	return m_array[index + abs(m_start_index)];
}

template<class T>
inline T & Array<T>::operator[](int index) const
{
	if (index < m_start_index || index >= m_length - abs(m_start_index))
	{
		throw Exception("outofbounds");
	}
	return m_array[index + abs(m_start_index)];
}

template<class T>
inline int Array<T>::getStartIndex()
{
	return m_start_index;
}

template<class T>
inline int Array<T>::getStartIndex() const
{
	return m_start_index;
}

template<class T>
inline void Array<T>::setStartIndex(int start_index)
{
	m_start_index = start_index;
}

template<class T>
inline int Array<T>::getLength()
{
	return m_length;
}

template<class T>
inline int Array<T>::getLength() const
{
	return m_length;
}

template<class T>
inline void Array<T>::setLength(int length)
{
	try
	{
		if (length >= 0)
		{
			T * temp = new T[length];
			int actual_length = (m_length < length) ? m_length : length;
			for (int i = 0; i < actual_length; i++)
			{
				temp[i] = m_array[i];
			}
			delete[]m_array;
			m_length = length;
			m_array = temp;
		}
		else
		{
			throw Exception("negative length");
		}


	}
	catch (std::bad_alloc ba)
	{
		throw ba;
	}
}

#endif 