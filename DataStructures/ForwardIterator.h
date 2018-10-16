#ifndef FORWARDITERATOR_H
#define FORWARDITERATOR_H
#include "ListIterator.h"

template<class T>
class ForwardIterator : public ListIterator<T>
{
public:
	void Reset();
	bool IsDone();
	void MoveNext();
	DLLNode<T> operator=(DLLNode<T> * rhs);
	ForwardIterator<T> & operator++();
	ForwardIterator<T> operator++(int);
};

template<class T>
inline void ForwardIterator<T>::Reset()
{
	if (!_node)
	{
		throw Exception("this list has not been assigned an iteration!");
	}
	else
	{
		while (_node->getPrevious() != nullptr)
		{
			_node = _node->getPrevious();
		}
		_done = false;
	}
}

template<class T>
inline bool ForwardIterator<T>::IsDone()
{
	if (!_node)
	{
		throw Exception("List has not been assigned an iterator");
	}
	else
	{
		if (_node->getNext() == nullptr)
			return true;
		else
			return false;
	}
}

template<class T>
inline void ForwardIterator<T>::MoveNext()
{
	if (_node->getNext() != nullptr)
	{
		_node = _node->getNext();
	}
	else
	{
		throw Exception("You're at the end of the last and can't move forward!");
	}
}

template<class T>
inline DLLNode<T> ForwardIterator<T>::operator=(DLLNode<T>* rhs)
{
	_node = rhs;

	return * _node;
}

template<class T>
inline ForwardIterator<T>& ForwardIterator<T>::operator++()
{
	if (_node->getNext() != nullptr)
	{
		MoveNext();
		return *this;
	}
	else
	{
		throw Exception("already at end of list");
	}
}

template<class T>
inline ForwardIterator<T> ForwardIterator<T>::operator++(int)
{
	if (_node->getNext() != nullptr)
	{
		ForwardIterator<T> temp = *this;
		MoveNext();
		return temp;
	}
	else
	{
		throw Exception("already at end of list");
	}
}

#endif // !FORWARDITERATOR_H
