#ifndef LINKED_LIST_QUEUE_H
#define LINKED_LIST_QUEUE_H
#include "DoubleLinkedList.h"

template <class T>
class LinkedListQueue
{
private:
	DoubleLinkedList<T> m_queue;
	int m_size = 0;
public:
	LinkedListQueue();
	LinkedListQueue(LinkedListQueue<T> &in_queue);
	~LinkedListQueue();

	LinkedListQueue<T> & operator= (const LinkedListQueue<T> & rhs);
	LinkedListQueue<T> & operator= (const LinkedListQueue<T> & rhs) const;
	void Enqueue(const T& el);
	T Dequeue();
	T& Front();
	T& Front() const;
	int Size();
	int Size() const;
	bool IsEmpty() const;	
};



#endif // !LINKED_LIST_QUEUE_H

template<class T>
inline LinkedListQueue<T>::LinkedListQueue()
{
	m_size = 0;
}

template<class T>
inline LinkedListQueue<T>::LinkedListQueue(LinkedListQueue<T>& in_queue)
{
	m_queue = in_queue.m_queue;
	m_size = in_queue.m_size;
}

template<class T>
inline LinkedListQueue<T>::~LinkedListQueue()
{
}

template<class T>
inline LinkedListQueue<T>& LinkedListQueue<T>::operator=(const LinkedListQueue<T>& rhs)
{
	m_queue = rhs.m_queue;
	m_size = rhs.m_size;
	return *this;
}

template<class T>
inline LinkedListQueue<T>& LinkedListQueue<T>::operator=(const LinkedListQueue<T>& rhs) const
{
	m_queue = rhs.m_queue;
	m_size = rhs.m_size;
	return *this;
}

template<class T>
inline void LinkedListQueue<T>::Enqueue(const T & el)
{
	m_queue.Append(el);
	m_size++;
}

template<class T>
inline T LinkedListQueue<T>::Dequeue()
{
	if (IsEmpty())
	{
		throw Exception("isempty");
	}
	else
	{
		T el = m_queue.getHead()->getInfo();
		m_queue.Extract(el);
		m_size--;
		return el;
	}
}

template<class T>
inline T & LinkedListQueue<T>::Front()
{
	if (IsEmpty())
	{
		throw Exception("isempty");
	}
	else
	{
		return m_queue.getHead()->getInfo();
	}
}

template<class T>
inline T & LinkedListQueue<T>::Front() const
{
	if (IsEmpty())
	{
		throw Exception("isempty");
	}
	else
	{
		return m_queue.getHead()->getInfo();
	}
}

template<class T>
inline int LinkedListQueue<T>::Size()
{
	return m_size;
}

template<class T>
inline int LinkedListQueue<T>::Size() const
{
	return m_size;
}

template<class T>
inline bool LinkedListQueue<T>::IsEmpty() const
{
	return m_queue.isEmpty();
}

