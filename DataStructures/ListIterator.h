#ifndef LISTITERATOR_H
#define LISTITERATOR_H
#include "AbstractIterator.h"
#include "DoubleLinkedList.h"

template <class T>
class ListIterator : public AbstractIterator<T>
{
protected:
	DLLNode<T> * _node = nullptr;
	bool _done = false;
public:
	virtual void Reset() = 0;
	virtual bool IsDone() = 0;
	virtual void MoveNext() = 0;
	T & GetCurrent();
	virtual DLLNode<T> operator=(DLLNode<T> * rhs) = 0;
	T & operator*();
	T & operator*() const;

};

template<class T>
inline void ListIterator<T>::Reset()
{
}

template<class T>
inline bool ListIterator<T>::IsDone()
{
	return false;
}

template<class T>
inline void ListIterator<T>::MoveNext()
{
}

template<class T>
inline T & ListIterator<T>::GetCurrent()
{
	return _node->info;
}

template<class T>
inline DLLNode<T> ListIterator<T>::operator=(DLLNode<T> * rhs)
{

}

template<class T>
inline T & ListIterator<T>::operator*()
{
	return _node->getInfo();
}

template<class T>
inline T & ListIterator<T>::operator*() const
{
	return _node->getInfo();
}

#endif // !LISTITERATOR_H
