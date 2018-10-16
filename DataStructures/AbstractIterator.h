#ifndef ABSTRACTITERATOR_H
#define ABSTRACTITERATOR_H
#include "ListIterator.h"

template<class T>
class AbstractIterator
{
public:
	virtual void MoveNext() = 0;
	virtual void Reset() = 0;
	virtual bool IsDone() = 0;
	virtual T& GetCurrent() = 0;
};


#endif // !ABSTRACTITERATOR_H
