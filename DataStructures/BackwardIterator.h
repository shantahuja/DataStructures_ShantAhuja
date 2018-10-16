#ifndef BACKWARDITERATOR_H
#define BACKWARDITERATOR_H
#include "ListIterator.h"

template<class T>
class BackwardIterator : public ListIterator<T>
{
public:
	void Reset();
	bool IsDone();
	void MoveNext();
	DLLNode<T> operator=(DLLNode<T> * rhs);
	BackwardIterator<T> & operator++();
	BackwardIterator<T> operator++(int);
};

template<class T>
inline void BackwardIterator<T>::Reset()
{
	if (!_node)
	{
		throw Exception("this list has not been assigned an iterator");
	}
	else
	{
		while (_node->getNext() != nullptr)
		{
			_node = _node->getNext();
		}
		_done = false;
	}
}

template<class T>
inline bool BackwardIterator<T>::IsDone()
{
	if (!_node)
	{
		throw Exception("List has not been assigned an iterator");
	}
	else
	{
		if (_node->getPrevious() == nullptr)
			return true;
		else
			return false;
	}
}

template<class T>
inline void BackwardIterator<T>::MoveNext()
{
	if (_node->getPrevious() != nullptr)
	{
		_node = _node->getPrevious();
	}
	else
		throw Exception("You're at the beginning of the list and can't go backwards!");
}

template<class T>
inline DLLNode<T> BackwardIterator<T>::operator=(DLLNode<T>* rhs)
{
	_node = rhs;
	return * _node;
}

template<class T>
inline BackwardIterator<T> & BackwardIterator<T>::operator++()
{
	if (_node->getPrevious() != nullptr)
	{
		MoveNext();
		return *this;
	}
	else
	{
		throw Exception("already at beginning of list");
	}
}

template<class T>
inline BackwardIterator<T> BackwardIterator<T>::operator++(int)
{
	if (_node->getPrevious() != nullptr)
	{
		BackwardIterator<T> temp = *this;
		MoveNext();
		return temp;
	}
	else
	{
		throw Exception("already at beginning of list");
	}
}

#endif // !BACKWARDITERATOR_H
