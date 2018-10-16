#ifndef LINKED_LIST_STACK_H
#define LINKED_LIST_STACK_H
#include "DoubleLinkedList.h"

template<class T>
class LinkedListStack
{
private:
	DoubleLinkedList<T> m_stack;
	int m_size;
public:
	LinkedListStack();
	LinkedListStack(LinkedListStack<T> &in_stack);
	~LinkedListStack();

	LinkedListStack<T> & operator= (const LinkedListStack<T> & rhs);
	LinkedListStack<T> & operator= (const LinkedListStack<T> & rhs) const;

	void Push(const T & in_data);
	T Pop();
	T Peek();
	T Peek() const;

	int Size();
	int Size() const;

	bool IsEmpty();
	bool IsEmpty() const;
};

#endif // !LINKED_LIST_STACK_H

template<class T>
inline LinkedListStack<T>::LinkedListStack()
{
	m_size = 0;
}

template<class T>
inline LinkedListStack<T>::LinkedListStack(LinkedListStack<T>& in_stack)
{
	m_stack = in_stack.m_stack;
	m_size = in_stack.m_size;
}

template<class T>
inline LinkedListStack<T>::~LinkedListStack()
{
}

template<class T>
inline LinkedListStack<T> & LinkedListStack<T>::operator=(const LinkedListStack<T>& rhs)
{
	m_stack = rhs.m_stack;
	m_size = rhs.m_size;
	return *this;
}

template<class T>
inline LinkedListStack<T> & LinkedListStack<T>::operator=(const LinkedListStack<T>& rhs) const
{
	m_stack = rhs.m_stack;
	m_size = rhs.m_size;
	return *this;
}

template<class T>
inline void LinkedListStack<T>::Push(const T & in_data)
{
	m_stack.Append(in_data);
	m_size++;
}

template<class T>
inline T LinkedListStack<T>::Pop()
{
	if (IsEmpty())
	{
		throw Exception("isempty");
	}
	else
	{
		T temp;
		temp = m_stack.getTail()->getInfo();
		m_stack.Extract(temp);
		m_size--;
		return temp;
	}
}

template<class T>
inline T LinkedListStack<T>::Peek()
{
	if (IsEmpty())
	{
		throw Exception("isempty");
	}
	else
	{
		T temp;
		temp = m_stack.getTail()->getInfo();
		return temp;
	}
}

template<class T>
inline T LinkedListStack<T>::Peek() const
{
	if (IsEmpty())
	{
		throw Exception("isempty");
	}
	else
	{
		T temp;
		temp = m_stack.getTail()->getInfo();
		return temp;
	}
}

template<class T>
inline int LinkedListStack<T>::Size()
{
	return m_size;
}

template<class T>
inline int LinkedListStack<T>::Size() const
{
	return m_size;
}

template<class T>
inline bool LinkedListStack<T>::IsEmpty()
{
	return m_stack.isEmpty();
}

template<class T>
inline bool LinkedListStack<T>::IsEmpty() const
{
	return m_stack.isEmpty();
}
