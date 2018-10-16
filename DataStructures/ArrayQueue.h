#ifndef ARRAY_QUEUE_H
#define ARRAY_QUEUE_H
#include "Array.h"

template<class T>
class ArrayQueue
{
private:
	Array<T> m_queue;
	int m_first, m_last;
	int m_size;
public:
	ArrayQueue();
	ArrayQueue(int size);
	ArrayQueue(ArrayQueue<T> &in_queue);
	~ArrayQueue();
	ArrayQueue & operator= (const ArrayQueue & rhs);
	ArrayQueue & operator= (const ArrayQueue & rhs) const;
	T & Enqueue(const T & in_data);
	T Dequeue();
	T & Front();
	T & Front() const;
	int Size();
	int Size() const;
	bool IsEmpty();
	bool IsEmpty() const;
	bool IsFull();
};

template<class T>
inline ArrayQueue<T>::ArrayQueue()
{
	m_queue.setLength(0);
	m_first = m_last = -1;
	m_size = 0;
}

template<class T>
inline ArrayQueue<T>::ArrayQueue(int size)
{
	m_size = size;
	m_queue.setLength(size);
	m_first = m_last = -1;
}

template<class T>
inline ArrayQueue<T>::ArrayQueue(ArrayQueue<T>& in_queue)
{
	m_queue = in_queue.m_queue;
	m_first = in_queue.m_first;
	m_size = in_queue.m_size;
}

template<class T>
inline ArrayQueue<T>::~ArrayQueue() {}

template<class T>
inline ArrayQueue<T> & ArrayQueue<T>::operator=(const ArrayQueue & rhs)
{
	m_queue = rhs.m_queue;
	m_first = rhs.m_first;
	m_size = rhs.m_size;

	return *this;
}

template<class T>
inline ArrayQueue<T> & ArrayQueue<T>::operator=(const ArrayQueue & rhs) const
{
	m_queue = rhs.m_queue;
	m_first = rhs.m_first;
	m_size = rhs.m_size;

	return *this;
}

template<class T>
inline T & ArrayQueue<T>::Enqueue(const T & in_data)
{
	if (IsFull())
	{
		throw Exception("is full");
	}
	else
	{
		if (m_last == Size() - 1 || m_last == -1)
		{
			m_queue[0] = in_data;
			m_last = 0;
			if (m_first == -1)
			{
				m_first = 0;
			}
		}

		else
			m_queue[++m_last] = in_data;
	}
}

template<class T>
inline T ArrayQueue<T>::Dequeue()
{
	if (IsEmpty())
	{
		throw Exception("is empty!");
	}
	else
	{
		T temp = m_queue[m_first];
		if (m_first == m_last)
			m_last = m_first = -1;
		else if (m_first == Size() - 1)
			m_first = 0;
		else
			m_first++;
		return temp;
	}
}

template<class T>
inline T & ArrayQueue<T>::Front()
{
	if (IsEmpty())
	{
		throw Exception("is empty!");
	}
	else
	{
		return m_queue[m_first];
	}
}

template<class T>
inline T & ArrayQueue<T>::Front() const
{
	if (IsEmpty())
	{
		throw Exception("is empty!");
	}
	else
	{
		return m_queue[m_first];
	}
}

template<class T>
inline int ArrayQueue<T>::Size()
{
	return m_size;
}

template<class T>
inline int ArrayQueue<T>::Size() const
{
	return m_size;
}

template<class T>
inline bool ArrayQueue<T>::IsEmpty()
{
	return m_first == -1;
}

template<class T>
inline bool ArrayQueue<T>::IsEmpty() const
{
	return m_first == -1;
}

template<class T>
inline bool ArrayQueue<T>::IsFull()
{
	return m_first == 0 && m_last == Size() - 1 || m_first == m_last + 1;
}
#endif