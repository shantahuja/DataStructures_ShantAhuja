#ifndef ROW2DP_H
#define ROW2DP_H
#include "Array2DP.h"

template <class T>
class Array2DP;

template <class T>
class Row2DP
{
private:
	const Array2DP<T> & m_array2DP;
	int m_row;
public:
	Row2DP(const Array2DP<T> & in_array, int row);
	T & operator [](int column);
};
template<class T>
inline Row2DP<T>::Row2DP(const Array2DP<T>& in_array, int row) : m_array2DP(in_array), m_row(row) {}

template<class T>
inline T & Row2DP<T>::operator[](int column)
{
	return m_array2DP.Select(m_row, column);
}

#endif // !ROW_H
