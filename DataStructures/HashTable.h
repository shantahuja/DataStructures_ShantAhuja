#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <vector>
#include <list>
#include <iterator>
using std::list;
using std::vector;

template<class V>
void visit(V value)
{
	std::cout << value.Title <<std:: endl;
	std::cout << value.Author << std::endl;
	std::cout << value.Pages <<std:: endl;
};

template<class K>
static int HashFunction(int key, size_t size)
{
	return key % size;
}

template<class K, class V>
class HashNode
{
private:
	K m_key;
	V m_value;

public:
	HashNode(K key, V value) { m_key = key; m_value = value; };
	K GetKey() { return m_key; };
	K GetKey() const { return m_key; };
	V GetValue() { return m_value; };
	V GetValue() const { return m_value; };
	void SetKey(K key) { m_key = key; };
	void SetValue(V value) { m_value = value; };
};

template<class K, class V>
class HashTable
{
private:
	vector<list<HashNode<K, V>>> m_hashtable;
	int(*m_hash)(K key, size_t size) = nullptr;
	void(*m_visit)(V value) = visit;
	size_t m_tablesize = 0;
public:
	HashTable() = delete;
	HashTable(size_t table_size, int(*hash)(K key, size_t size));

	HashTable(const HashTable& copy);
	HashTable& operator=(const HashTable& rhs);

	HashTable(HashTable&& copy) noexcept;
	HashTable<K, V> & operator=(HashTable&& rhs) noexcept;

	~HashTable() = default;
	void Insert(K key, V value);
	bool Find(K key);
	void Delete(K key);
	void Update(K key, V new_value);
	void Rehash(size_t new_size);
	void SetHash(int(*hash)(K key, size_t size), size_t table_size); // remember to rehash table
	V operator [] (K key);
	V operator [] (K key) const;
	void Traverse(void(*visit)(V value));
};

template<class K, class V>
inline HashTable<K, V>::HashTable(size_t table_size, int(*hash)(K key, size_t size))
{
	m_hashtable.resize(table_size);
	m_tablesize = table_size;
	SetHash(hash, table_size);
}

template<class K, class V>
inline HashTable<K, V>::HashTable(const HashTable & copy)
{
	m_hashtable = copy.m_hashtable;
	SetHash(copy.m_hash, copy.m_tablesize);
	m_tablesize = copy.m_tablesize;
}

template<class K, class V>
inline HashTable<K, V> & HashTable<K, V>::operator=(const HashTable & rhs)
{
	m_hashtable = rhs.m_hashtable;
	SetHash(rhs.m_hash, rhs.m_tablesize);
	m_tablesize = rhs.m_tablesize;
	return *this;
}

template<class K, class V>
inline HashTable<K, V>::HashTable(HashTable&& copy) noexcept
{
	m_hashtable = copy.m_hashtable;
	SetHash(copy.m_hash, copy.m_tablesize);
	m_tablesize = copy.m_tablesize;
}

template<class K, class V>
inline HashTable<K, V> & HashTable<K, V>::operator=(HashTable&& rhs) noexcept 
{
	m_hashtable = rhs.m_hashtable;
	SetHash(rhs.m_hash, rhs.m_tablesize);
	m_tablesize = rhs.m_tablesize;
}

template<class K, class V>
inline void HashTable<K, V>::Insert(K key, V value)
{
	HashNode<K, V> new_node(key, value);
	m_hashtable[m_hash(key, m_tablesize)].emplace_back(new_node);
}

template<class K, class V>
inline bool HashTable<K, V>::Find(K key)
{
	for (size_t i = 0; i < m_tablesize; i++)
	{
		if (m_hashtable[i].empty())
			continue;
		else
		{
			for (auto node = m_hashtable[i].begin(); node != m_hashtable[i].end(); node++)
				if ((*node).GetKey() == key)
					return true;
		}
	}
	return false;
}

template<class K, class V>
inline void HashTable<K, V>::Delete(K key)
{
	int i = m_hash(key, m_tablesize);
	if (m_hashtable[i].size() == 1)
		m_hashtable[i].clear();
	else
	{
		for (auto node = m_hashtable[i].begin(); node != m_hashtable[i].end(); node++)
			if ((*node).GetKey() == key)
			{
				m_hashtable[i].erase(node);
				return;
			}
	}
}

template<class K, class V>
inline void HashTable<K, V>::Update(K key, V new_value)
{
	int i = m_hash(key, m_tablesize);
	if (m_hashtable[i].size() == 1)
		m_hashtable[i].front().SetValue(new_value);
	else
	{
		for (auto node = m_hashtable[i].begin(); node != m_hashtable[i].end(); node++)
			if ((*node).GetKey() == key)
				(*node).SetValue(new_value);
	}
}

template<class K, class V>
inline void HashTable<K, V>::Rehash(size_t newsize)
{
	vector<list<HashNode<K, V>>> rehashed;
	rehashed.resize(newsize);
	for (size_t i = 0; i < newsize; i++)
		for (auto node = m_hashtable[i].begin(); node != m_hashtable[i].end(); node++)
		{
			HashNode<K, V> newNode((*node).GetKey(), (*node).GetValue());
			rehashed[i].emplace_back(newNode);
		}
	m_hashtable = rehashed;
}


template<class K, class V>
inline void HashTable<K, V>::SetHash(int(*hash)(K key, size_t size), size_t table_size)
{
	m_hash = hash;
	Rehash(table_size);
}

template<class K, class V>
inline V HashTable<K, V>::operator[](K key)
{
	int i = m_hash(key, m_tablesize);
	if (m_hashtable[i].size() == 1)
		return m_hashtable[i].front().GetValue();
	else
	{
		for (auto node = m_hashtable[i].begin(); node != m_hashtable[i].end(); node++)
			if ((*node).GetKey() == key)
				return (*node).GetValue();
	}
}

template<class K, class V>
inline V HashTable<K, V>::operator[](K key) const
{
	int i = m_hash(key, m_tablesize);
	if (m_hashtable[i].size() == 1)
		return m_hashtable[i].front().GetValue();
	else
	{
		for (auto node = m_hashtable[i].begin(); node != m_hashtable[i].end(); node++)
			if ((*node).GetKey() == key)
				return (*node).GetValue();
	}
}

template<class K, class V>
inline void HashTable<K, V>::Traverse(void(*visit)(V value))
{
	for (size_t i = 0; i < m_tablesize; i++)
	{
		if (m_hashtable[i].empty())
			continue;
		if (m_hashtable[i].size() == 1)
			visit(m_hashtable[i].front().GetValue());
		else
		{
			for (auto node = m_hashtable[i].begin(); node != m_hashtable[i].end(); node++)
				visit(node.GetValue());
		}
	}
}

#endif


