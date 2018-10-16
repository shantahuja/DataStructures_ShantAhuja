#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H

//used Adam Drozdek Data Structures and Algorithms in C 4th edition to implement classes

template <class T>
class DLLNode
{
public:
	DLLNode();
	DLLNode(const T& el, DLLNode *p = 0, DLLNode *n = 0);
	T info;
	DLLNode *prev = nullptr;
	DLLNode *next = nullptr;
	DLLNode * getPrevious();
	DLLNode * getNext();
	T & getInfo();
};

template<class T>
DLLNode<T>::DLLNode()
{
	next = prev = 0;
}

template<class T>
DLLNode<T>::DLLNode(const T& el, DLLNode *p, DLLNode *n)
{
	info = el;
	prev = p;
	next = n;
}

template<class T>
inline DLLNode<T> * DLLNode<T>::getPrevious()
{
	return prev;
}

template<class T>
inline DLLNode<T> * DLLNode<T>::getNext()
{
	return next;
}

template<class T>
inline T & DLLNode<T>::getInfo()
{
	return info;
}

template <class T>
class DoubleLinkedList
{
public:
	DoubleLinkedList();
	DoubleLinkedList(const DoubleLinkedList & copy);
	~DoubleLinkedList();
	DoubleLinkedList & operator=(const DoubleLinkedList & rhs);
	DoubleLinkedList & operator=(const DoubleLinkedList & rhs) const;
	void Append(const T&);
	void Prepend(const T&);
	void InsertBefore(const T& insert, const T& find);
	void InsertAfter(const T& insert, const T& find);
	void Extract(const T & el);
	void Purge();
	T & First();
	T & Last();
	bool isEmpty();
	bool isEmpty() const;
	DLLNode<T> * getHead();
	DLLNode<T> * getHead() const;
	DLLNode<T> * getTail();
	DLLNode<T> * getTail() const;
protected:
	DLLNode<T> *head = nullptr;
	DLLNode<T> *tail = nullptr;
};

template <class T>
DoubleLinkedList<T>::DoubleLinkedList() : head(nullptr), tail(nullptr) {}

template<class T>
inline DoubleLinkedList<T>::DoubleLinkedList(const DoubleLinkedList & copy)
{
	Purge();
	DLLNode<T> * travel;
	travel = copy.getHead();
	while (travel != nullptr)
	{
		Append(travel->getInfo());
		travel = travel->getNext();
	}
}

template<class T>
inline DoubleLinkedList<T>::~DoubleLinkedList()
{
	Purge();
}

template<class T>
inline DoubleLinkedList<T> & DoubleLinkedList<T>::operator=(const DoubleLinkedList & rhs)
{
	Purge();
	DLLNode<T> * travel;
	travel = rhs.getHead();
	while (travel != nullptr)
	{
		Append(travel->getInfo());
		travel = travel->getNext();
	}
	return *this;
}

template<class T>
inline DoubleLinkedList<T> & DoubleLinkedList<T>::operator=(const DoubleLinkedList & rhs) const
{
	Purge();
	DLLNode<T> * travel;
	travel = rhs.getHead();
	while (travel != nullptr)
	{
		Append(travel->getInfo());
		travel = travel->getNext();
	}
	return *this;
}

template<class T>
void DoubleLinkedList<T>::Append(const T& el)
{
	if (tail != 0)
	{
		tail = new DLLNode<T>(el, tail, 0);
		tail->prev->next = tail;
	}
	else head = tail = new DLLNode<T>(el);
}

template<class T>
void DoubleLinkedList<T>::Prepend(const T& el)
{
	if (head != 0)
	{
		head = new DLLNode<T>(el, 0, head);
		head->next->prev = head;
	}
	else head = tail = new DLLNode<T>(el);
}

template<class T>
inline void DoubleLinkedList<T>::InsertBefore(const T & insert, const T & find)
{
	if (head != nullptr)
	{
		DLLNode<T> * travel;
		travel = head;
		while (travel != nullptr && travel->getInfo() != find)
		{
			travel = travel->getNext();
		}
		if (travel == head)
		{
			Prepend(insert);
		}
		else if (travel == nullptr)
		{
			throw Exception("target not found");
		}
		else
		{
			DLLNode<T> * temp = new DLLNode<T>(insert, travel->prev, travel);
			travel->prev->next = temp;
			travel->prev = temp;
		}
	}
}

template<class T>
inline void DoubleLinkedList<T>::InsertAfter(const T & insert, const T & find)
{
	if (head != nullptr)
	{
		DLLNode<T> * travel;
		travel = head;
		while (travel != nullptr && travel->getInfo() != find)
		{
			travel = travel->getNext();
		}
		if (travel == tail)
		{
			Append(insert);
		}
		else if (travel == nullptr)
		{
			throw Exception("target not found");
		}
		else
		{
			DLLNode<T> * temp = new DLLNode<T>(insert, travel, travel->next);
			travel->next = temp;
			travel->next->prev = temp;
		}
	}
	else
	{
		throw Exception("list is empty");
	}
}

template<class T>
inline void DoubleLinkedList<T>::Extract(const T & el)
{
	if (head != nullptr)
	{
		DLLNode<T> * travel = nullptr;
		DLLNode<T> * trail;

		if (head->info == el)
		{
			if (head->next == nullptr)
			{
				delete head;
				head = tail = nullptr;
			}
			else
			{
				trail = head;
				head = head->getNext();
				delete trail;
			}
		}
		else if (tail->info == el)
		{
			trail = tail;
			tail = tail->getPrevious();
			delete trail;
			tail->next = nullptr;
		}
		else
		{
			travel = head;
			while (travel != nullptr && travel->info != el)
			{
				travel = travel->getNext();
			}
			if (travel == nullptr)
			{
				throw Exception("element not found");
			}
			else
			{
				travel->prev->next = travel->getNext();
				travel->next->prev = travel->getPrevious();
				delete travel;
				travel = nullptr;
			}
		}
	}
}

template<class T>
inline void DoubleLinkedList<T>::Purge()
{
	DLLNode<T> *current = head;
	while (current)
	{
		DLLNode<T> * next = current->getNext();
		delete current;
		current = next;
	}
	head = tail = nullptr;
}

template<class T>
inline T & DoubleLinkedList<T>::First()
{
	if (head == nullptr)
	{
		throw Exception("head is null");
	}
	else
	{
		return head->getInfo();
	}
}

template<class T>
inline T & DoubleLinkedList<T>::Last()
{
	if (tail == nullptr)
	{
		throw Exception("tail is null");
	}
	else
	{
		return tail->getInfo();
	}
}

template <class T>
bool DoubleLinkedList<T>::isEmpty()
{
	if (head == nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template <class T>
bool DoubleLinkedList<T>::isEmpty() const
{
	if (head == nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}


template<class T>
inline DLLNode<T> * DoubleLinkedList<T>::getHead()
{
	if (head != nullptr)
	{
		return head;
	}
	else
		return nullptr;
}

template<class T>
inline DLLNode<T> * DoubleLinkedList<T>::getHead() const
{
	if (head != nullptr)
	{
		return head;
	}
	else
		return nullptr;
}

template<class T>
inline DLLNode<T> * DoubleLinkedList<T>::getTail()
{
	if (tail != nullptr)
	{
		return tail;
	}
	else
		return nullptr;
}

template<class T>
inline DLLNode<T> * DoubleLinkedList<T>::getTail() const
{
	if (tail != nullptr)
	{
		return tail;
	}
	else
		return nullptr;
}
#endif // !DOUBLELINKEDLIST_H
