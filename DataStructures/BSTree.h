#ifndef BSTREE_H
#define BSTREE_H

#include "LinkedListQueue.h"
#include "LinkedListStack.h"
#include "Exception.h"
#include <iostream>

template<class T>
class BSTNode
{
public:
	BSTNode<T> *left, *right;
	T el;
	BSTNode(){ left = right = nullptr; };
	BSTNode(const T& e, BSTNode<T> *l = nullptr, BSTNode<T> *r = nullptr)
	{
		el = e;
		left = l;
		right = r;
	}
	T & getData();
};

template<class T>
void Visit(BSTNode<T> * p)
{
	if (p != nullptr)
	{
		std::cout << p->el << ' ';
	}
}

template<class T>
class BSTree
{
private:
	BSTNode<T>* m_root;
	void(*_Visit)(BSTNode<T>* p) = Visit;
	void Clear(BSTNode<T>*);
	T* Search(BSTNode<T> *root , const T& data) const;

	void PreOrder(void(*func)(BSTNode<T> *), BSTNode<T> *p);
	void InOrder(void(*func)(BSTNode<T> *), BSTNode<T> *p);
	void PostOrder(void(*func)(BSTNode<T> *), BSTNode<T> *p);
	void BreadthFirst(void(*func)(BSTNode<T> *), BSTNode<T> *p);
	int Height(BSTNode<T> * n);

	void DeleteNode(BSTNode<T> * p, BSTNode<T> * d);
	void Insert(BSTNode<T> *& _root, const T & data);
public:
	BSTree() { m_root = nullptr; };
	~BSTree() { Clear(); };

	void Clear() { Clear(m_root); m_root = nullptr; };
	bool IsEmpty(); 
	bool IsEmpty() const;

	void PreOrder() { PreOrder(_Visit, m_root); };
	void InOrder() { InOrder(_Visit, m_root); };
	void PostOrder() { PostOrder(_Visit, m_root); };
	T* Search(const T& el) { return Search(_root, data); };
	T* Search(const T& el) const { return Search(_root, data); };
	void BreadthFirst() { BreadthFirst(_Visit, m_root); };
	void Insert(const T & data) { Insert(m_root, data); };
	int Height() { return Height(m_root); };

	void SetFunction(void(*func)(BSTNode<T> *));
	void Delete(const T & data);
};

template<class T>
inline void BSTree<T>::Clear(BSTNode<T>* node)
{
	if (node != nullptr)
	{
		Clear(node->left);
		Clear(node->right);
		delete node;
	}
}

template<class T>
inline T * BSTree<T>::Search(BSTNode<T>* root, const T & data) const
{
	if (root == nullptr || root->el == data)
		return root;
	else if (root->el < data)
		return Search(root->right, data);
	else
		return Search(root->left, data);
}

template<class T>
inline void BSTree<T>::PreOrder(void(*func)(BSTNode<T> *), BSTNode<T> *p)
{
	if (p != nullptr)
	{
		func(p);
		if (p->left != nullptr)
			PreOrder(func, p->left);
		if (p->right != nullptr)
			PreOrder(func, p->right);
	}
}

template<class T>
inline void BSTree<T>::InOrder(void(*func)(BSTNode<T> *), BSTNode<T> * p)
{
	if (p != nullptr)
	{
		if (p->left != nullptr)
			InOrder(func, p->left);
		func(p);
		if (p->right != nullptr)
			InOrder(func, p->right);
	}
}

template<class T>
inline void BSTree<T>::PostOrder(void(*func)(BSTNode<T> *), BSTNode<T> * p)
{
	if (p != nullptr)
	{
		if (p->left != nullptr)
			PostOrder(func, p->left);
		if (p->right != nullptr)
			PostOrder(func, p->right);
		func(p);
	}
}

template<class T>
inline void BSTree<T>::BreadthFirst(void(*func)(BSTNode<T> *), BSTNode<T> *p)
{
	LinkedListQueue<BSTNode<T>*> queue;
	p = m_root;
	if (p != nullptr)
	{
		queue.Enqueue(p);
		while (!queue.IsEmpty())
		{
			p = queue.Dequeue();
			func(p);
			if (p->left != nullptr)
				queue.Enqueue(p->left);
			if (p->right != nullptr)
				queue.Enqueue(p->right);
		}
	}
}

template<class T>
inline int BSTree<T>::Height(BSTNode<T> * n)
{
	if (n == nullptr)
		return 0;
	int l = n->left ? Height(n->left) : 0;
	int r = n->right ? Height(n->right) : 0;
	return ((l > r) ? l : r);
}

template<class T>
inline void BSTree<T>::DeleteNode(BSTNode<T> * p, BSTNode<T> * d)
{
	BSTNode<T> * cur = d;
	BSTNode<T> * prev = p;

	if (p == nullptr)
		throw Exception("Parent is nullptr.");
	else if (d->left == nullptr && d->right == nullptr) // leaf
	{
		if (p->el > d->el)
			p->left = nullptr;
		else
			p->right = nullptr;
	}
	else if (d->left == nullptr && d->right != nullptr) // right tree
	{
		if (p->el > d->el)
			p->left = d->right;
		else
			p->right = d->right;
	}
	else if (d->right == nullptr && d->left != nullptr) // left tree
	{
		if (p->el > d->el)
			p->left = d->left;
		else
			p->right = d->left;
	}
	else 
	{
		cur = d->right;
		prev = cur;
		while (cur->left != nullptr)
		{
			prev = cur;
			cur = cur->left;
		}
		d->el = cur->el;
		if (cur->right != nullptr)
			d->right = cur->right;
		else
		{
			prev->left = nullptr;
		}
	}
	delete cur;
	cur = nullptr;
}

template<class T>
inline void BSTree<T>::Insert(BSTNode<T> *& root, const T & data)
{
	if (root == nullptr)
		root = new BSTNode<T>(data);
	else
	{
		if (data < root->el)
			Insert(root->left, data);
		else
			Insert(root->right, data);
	}
}

template<class T>
inline T & BSTNode<T>::getData()
{
	return el;
}

template<class T>
inline bool BSTree<T>::IsEmpty()
{
	return m_root == 0;
}

template<class T>
inline bool BSTree<T>::IsEmpty() const
{
	return m_root == 0;
}

template<class T>
inline void BSTree<T>::SetFunction(void(*func)(BSTNode<T>*))
{
	_Visit = func;
}

template<class T>
inline void BSTree<T>::Delete(const T & data)
{
	if (IsEmpty())
		throw Exception("Tree is empty!");
	else
	{
		BSTNode<T> * cur, *prev;
		cur = prev = m_root;
		while (cur != nullptr && cur->el != data)
		{
			prev = cur;
			if (cur->el > data)
				cur = cur->left;
			else
				cur = cur->right;
		}
		if (cur == nullptr)
			throw Exception("Error.");
		else
			DeleteNode(prev, cur);
	}
}

#endif