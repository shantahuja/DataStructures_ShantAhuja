#ifndef AVLTREE_H
#define AVLTREE_H

#include "LinkedListQueue.h"
#include "LinkedListStack.h"
#include "Exception.h"
#include <iostream>

enum BF { RH = -1, EH = 0, LH = 1 };

template<class T>
class AVLNode
{
public:
	AVLNode<T> *left, *right;
	T el;
	BF bf;
	AVLNode() { left = right = nullptr; bf = EH; }
	AVLNode(const T & data, AVLNode<T> * l = nullptr, AVLNode<T> * r = nullptr)
	{
		el = data;
		left = l;
		right = r;
		bf = EH;
	}
	T & getData()
	{
		return el;
	}
};

template<class T>
void Visit(AVLNode<T> * p)
{
	if (p != nullptr)
	{
		std::cout << p->el << ' ';
	}
}

template<class T>
class AVLTree
{
private:
	AVLNode<T>* m_root;
	bool shorter;
	bool success;
	bool taller;
	void(*_Visit)(AVLNode<T>* p) = Visit;

	void Clear(AVLNode<T>* p);
	void InOrder(void(*func)(AVLNode<T> *), AVLNode<T> *p);
	void PreOrder(void(*func)(AVLNode<T> *), AVLNode<T> *p);
	void PostOrder(void(*func)(AVLNode<T> *), AVLNode<T> *p);
	void BreadthFirst(void(*func)(AVLNode<T> *), AVLNode<T> *p);

	void Insert(AVLNode<T> *& root, const T & data, bool & taller);
	void LeftBalance(AVLNode<T> *& root, bool & taller);
	void RightBalance(AVLNode<T> *& root, bool & taller);

	AVLNode<T> * RotateRight(AVLNode<T> * root);
	AVLNode<T> * RotateLeft(AVLNode<T> * root);
	AVLNode<T> * Delete(AVLNode<T> *& root, const T & data, bool & success, bool & shorter);
	AVLNode<T> * DeleteRightBalance(AVLNode<T> *& root, bool & shorter);
	AVLNode<T> * DeleteLeftBalance(AVLNode<T> *& root, bool & shorter);
	AVLNode<T> * Search(AVLNode<T> * root, const T & data);
public:
	AVLTree() { m_root = nullptr; };
	~AVLTree() { Clear(); };

	void SetFunction(void(*func)(AVLNode<T> *));
	void InOrder() { { InOrder(_Visit, m_root); } }
	void PreOrder() { PreOrder(_Visit, m_root); }
	void PostOrder() { PostOrder(_Visit, m_root); }
	void BreadthFirst() { BreadthFirst(_Visit, m_root); } 
	bool IsEmpty(); 
	bool IsEmpty() const;

	void Insert(const T & data) { Insert(m_root, data, taller); };
	void Clear() { Clear(m_root); };
	int Height() { return Height(m_root); };
	AVLNode<T> * Delete(const T & data) { return Delete(m_root, data, success, shorter); };
	AVLNode<T> * Search(const T & data) { return Search(m_root, data); };

	int Height(AVLNode<T> * n);
};

template<class T>
inline void AVLTree<T>::Clear(AVLNode<T>* node)
{
	if (node != nullptr)
	{
		Clear(node->left);
		Clear(node->right);
		delete node;
		node = nullptr;
	}
}

template<class T>
inline void AVLTree<T>::InOrder(void(*func)(AVLNode<T> *), AVLNode<T> * p)
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
inline void AVLTree<T>::PreOrder(void(*func)(AVLNode<T> *), AVLNode<T> *p)
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
inline void AVLTree<T>::PostOrder(void(*func)(AVLNode<T> *), AVLNode<T> *p)
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
inline void AVLTree<T>::BreadthFirst(void(*func)(AVLNode<T> *), AVLNode<T> *p)
{
	LinkedListQueue<AVLNode<T> *> queue;
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
inline void AVLTree<T>::Insert(AVLNode<T> *& root, const T & data, bool & taller)
{
	if (root == nullptr)
	{
		root = new AVLNode<T>(data);
		taller = true;
		return;
	}
	if (data < root->el) // left subtree
	{
		Insert(root->left, data, taller);
		if (taller)
		{
			switch (root->bf)
			{
			case LH: LeftBalance(root, taller); break;
			case EH: root->bf = LH; break;
			case RH: root->bf = EH; taller = false; break;
			}
		}
	}
	else if (data > root->el) // right subtree
	{
		Insert(root->right, data, taller);
		if (taller)
		{
			switch (root->bf)
			{
			case LH: root->bf = EH; taller = false; break;
			case EH: root->bf = RH; break;
			case RH: RightBalance(root, taller); break;
			}
		}
	}
}

template<class T>
inline void AVLTree<T>::LeftBalance(AVLNode<T> *& root, bool & taller)
{
	switch (root->left->bf)
	{
	case LH:
		root->bf = EH;
		root->left->bf = EH;
		root = RotateRight(root);
		taller = false;
		break;
	case EH: throw Exception("Error.");
	case RH:
		switch (root->left->right->bf)
		{
		case LH:
			root->bf = RH;
			root->left->bf = EH;
			break;
		case EH:
			root->bf = EH;
			root->left->bf = EH;
			break;
		case RH:
			root->bf = EH;
			root->left->bf = LH;
			break;
		}
		root->left->right->bf = EH;
		root->left = RotateLeft(root->left);
		root = RotateRight(root);
		taller = false;
		break;
	}
}

template<class T>
inline void AVLTree<T>::RightBalance(AVLNode<T> *& root, bool & taller)
{
	switch (root->right->bf)
	{
	case RH:
		root->bf = EH;
		root->right->bf = EH;
		root = RotateLeft(root);
		taller = false;
		break;
	case EH: throw Exception("Error.");
	case LH:
		switch (root->right->left->bf)
		{
		case RH:
			root->bf = LH;
			root->right->bf = EH;
			break;
		case EH:
			root->bf = EH;
			root->right->bf = EH;
			break;
		case LH:
			root->bf = EH;
			root->right->bf = RH;
			break;
		}
		root->right->left->bf = EH;
		root->right = RotateRight(root->right);
		root = RotateLeft(root);
		taller = false;
		break;
	}
}


template<class T>
inline AVLNode<T> * AVLTree<T>::RotateRight(AVLNode<T> * root)
{
	AVLNode<T> * temp = root->left;
	root->left = temp->right;
	temp->right = root;
	return temp;
}

template<class T>
inline AVLNode<T> * AVLTree<T>::RotateLeft(AVLNode<T> * root)
{
	AVLNode<T> * temp = root->right;
	root->right = temp->left;
	temp->left = root;
	return temp;
}

template<class T>
inline AVLNode<T> * AVLTree<T>::Delete(AVLNode<T> *& root, const T & data, bool & success, bool & shorter)
{
	if (root == nullptr)
		throw Exception("Tree is empty!");
	if (data < root->el)
	{
		root->left = Delete(root->left, data, success, shorter);
		if (shorter) // tree shorter?
			root = DeleteRightBalance(root, shorter);
	}
	else if (data > root->el)
	{
		root->right = Delete(root->right, data, success, shorter);
		if (shorter) // tree shorter?
			root = DeleteLeftBalance(root, shorter);
	}
	else
	{
		AVLNode<T> * n_root;
		AVLNode<T> * cur = nullptr;
		//delete root; 
		if (root->left == nullptr && root->right == nullptr) // leaf node
		{
			delete root;
			success = true;
			return nullptr;
		}
		else if (root->left != nullptr && root->right == nullptr) // left subtree, no right
		{
			n_root = root->left;
			delete root;
			success = true;
			return n_root;
		}
		else if (root->left == nullptr && root->right != nullptr) // right subtree, no left
		{
			n_root = root->right;
			delete root;
			success = true;
			return n_root;
		}
		else // left and right subtrees
		{
			//n_root = root;
			cur = root->left;
			while (cur->right != nullptr)
			{
				cur = cur->right;
			}
			T temp = cur->el;
			root->el = temp;
			root->left = Delete(root->left, temp, success, shorter);
			if (shorter) // tree shorter?
				root = DeleteRightBalance(root, shorter);
		}
	}
	return root;
}

template<class T>
inline AVLNode<T> * AVLTree<T>::DeleteRightBalance(AVLNode<T> *& root, bool & shorter)
{
	switch (root->bf)
	{
	case LH:
		root->bf = EH;
		break;
	case EH:
		root->bf = RH;
		break;
	case RH:
		if (root->right->bf == LH)
		{
			AVLNode<T> * leftTree = root->right->left;
			switch (leftTree->bf)
			{
			case LH:
			{
				root->bf = LH;
				root->right->bf = EH;
				break;
			}
			case EH:
			{
				root->bf = EH;
				root->right->bf = EH;
				break;
			}
			case RH:
			{
				root->bf = EH;
				root->right->bf = RH;
				break;
			}
			}
			leftTree->bf = EH;
			root = RotateLeft(root);
		}
		else
		{
			AVLNode<T> * rightTree = root->right;
			switch (rightTree->bf)
			{
			case LH: break;
			case RH:
			{
				root->bf = EH;
				rightTree->bf = EH;
				break;
			}
			case EH:
			{
				root->bf = RH;
				rightTree->bf = LH;
				shorter = false;
				break;
			}
			}
			root = RotateLeft(root);
		}
	}
	return root;
}


template<class T>
inline AVLNode<T> * AVLTree<T>::DeleteLeftBalance(AVLNode<T> *& root, bool & shorter)
{
	switch (root->bf)
	{
	case RH:
		root->bf = EH;
		break;
	case EH:
		root->bf = LH;
		break;
	case LH:
		if (root->left->bf == RH)
		{
			AVLNode<T> * rightTree = root->left->right;
			switch (rightTree->bf)
			{
			case RH:
				root->bf = RH;
				root->left->bf = EH;
				break;
			case EH:
				root->bf = EH;
				root->left->bf = EH;
				break;
			case LH:
				root->bf = EH;
				root->left->bf;
				break;
			}

			rightTree->bf = EH;
			root = RotateRight(root);
		}
		else
		{
			AVLNode<T> * leftTree = root->left;
			switch (leftTree->bf)
			{
			case RH: break;
			case LH:
				root->bf = EH;
				leftTree->bf = EH;
				break;
			case EH:
				root->bf = LH;
				leftTree->bf = RH;
				shorter = false;
				break;
			}
		}
		root = RotateRight(root);
	}
	return root;
}

template<class T>
inline AVLNode<T> * AVLTree<T>::Search(AVLNode<T> * root, const T & data)
{
	if (root == nullptr || root->el == data)
		return root;
	else if (root->el < data)
		return Search(root->right, data);
	else
		return Search(root->left, data);
}

template<class T>
inline void AVLTree<T>::SetFunction(void(*func)(AVLNode<T>*))
{
	_Visit = func;
}

template<class T>
inline bool AVLTree<T>::IsEmpty()
{
	return m_root == 0;
}

template<class T>
inline bool AVLTree<T>::IsEmpty() const
{
	return m_root == 0;
}

template<class T>
inline int AVLTree<T>::Height(AVLNode<T> * n)
{
	if (n == nullptr)
		return 0;
	int l = n->left ? Height(n->left) : 0;
	int r = n->right ? Height(n->right) : 0;
	return ((l > r) ? l : r);
}

#endif