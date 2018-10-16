#ifndef ARRAY_STACK_H
#define ARRAY_STACK_H
#include "Array.h"

template<class T>
class ArrayStack
{
private:
	Array<T> m_stack;
	int m_top, m_length;
public:
	ArrayStack();
	ArrayStack(int length);
	ArrayStack(ArrayStack<T> &in_stack);
	~ArrayStack();

	ArrayStack<T> & operator= (const ArrayStack<T> & rhs);
	ArrayStack<T> & operator= (const ArrayStack<T> & rhs) const;

	void Push(const T & in_data);
	T & Pop();
	T & Peek();
	T & Peek() const;

	int Size();
	int Size() const;

	bool IsEmpty();
	bool IsEmpty() const;
	bool IsFull();
};

template<class T>
inline ArrayStack<T>::ArrayStack() 
{
	m_stack.setLength(0);
	m_top = -1;
	m_length = 0;
}

template<class T>
inline ArrayStack<T>::ArrayStack(int length)
{
	m_length = length;
	m_stack.setLength(length);
	m_top = -1;
}

template<class T>
inline ArrayStack<T>::ArrayStack(ArrayStack<T>& in_stack)
{
	m_stack = in_stack.m_stack;
	m_top = in_stack.m_top;
	m_length = in_stack.m_length;
}



template<class T>
inline ArrayStack<T>::~ArrayStack()
{
}

template<class T>
inline ArrayStack<T> & ArrayStack<T>::operator=(const ArrayStack<T> & rhs)
{
	m_stack = rhs.m_stack;
	m_top = rhs.m_top;
	m_length = rhs.m_length;

	return *this;
}

template<class T>
inline ArrayStack<T> & ArrayStack<T>::operator=(const ArrayStack<T> & rhs) const
{
	m_stack = rhs.m_stack;
	m_top = rhs.m_top;
	m_length = rhs.m_length;

	return *this;
}

template<class T>
inline void ArrayStack<T>::Push(const T & in_data)
{
	if (IsFull())
	{
		throw Exception("is full");
	}
	else
	{
		m_stack[++m_top] = in_data;
	}
}

template<class T>
inline T & ArrayStack<T>::Pop()
{
	if (IsEmpty())
	{
		throw Exception("isempty!");
	}
	else
	{
		return m_stack[m_top--];
	}
}

template<class T>
inline T & ArrayStack<T>::Peek()
{
	if (IsEmpty())
	{
		throw Exception("isempty!");
	}
	else
	{
		return m_stack[m_top];
	}
}

template<class T>
inline T & ArrayStack<T>::Peek() const
{
	if (IsEmpty())
	{
		throw Exception("isempty!");
	}
	else
	{
		return m_stack[m_top];
	}
}

template<class T>
inline int ArrayStack<T>::Size()
{
	return m_top+1;
}

template<class T>
inline int ArrayStack<T>::Size() const
{
	return m_top+1;
}

template<class T>
inline bool ArrayStack<T>::IsEmpty()
{
	if (m_length = 0)
	{
		return true;
	}
	else
		return false;
}

template<class T>
inline bool ArrayStack<T>::IsEmpty() const
{
	if (m_length == 0)
	{
		return true;
	}
	else
		return false;
}

template<class T>
inline bool ArrayStack<T>::IsFull()
{
	if (m_top == m_length)
	{
		return true;
	}
	else
	{
		return false;
	}
}

#endif // !ARRAY_STACK_H
