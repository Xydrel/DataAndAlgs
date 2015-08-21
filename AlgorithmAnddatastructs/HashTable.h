#pragma once
#include "Includes.h"

template<typename T>
class HashNode
{
public:
	HashNode() : m_data(NULL) {}
	HashNode(T* data)
	{
		assert(data != NULL);
		if (m_data == NULL) { m_data = data; }
	}

private:

	T* m_data;
};

template<typename T> 
class HashItem
{
public:
	HashItem(int size) {}
	~HashItem() {}
private:

};

template<typename T>
class HashTable
{

public:
	HashTable(int size) : m_size(0), m_totalItems(0)
	{
		if (size > 0)
		{
			m_size = getNextPrimeNum(size);
			m_table = new HashItem<T>[m_size];
		}
	}

	// delete all the things
	~HashTable() 
	{
		if (m_next != NULL) { m_next == NULL; delete m_next; }
		if (m_root != NULL) { m_root == NULL; delete m_root; }
		if (m_container != NULL) { m_table == NULL; delete[] m_table; }
	}

	void insert() {}


	/*bool operator==() {}
	bool operator<=() {}
	bool operator>=() {}
	bool operator<()  {}
	bool operator>()  {}
	void operator=()  {}*/

private:
	// test if num is prime
	bool isNumPrime(int val) 
	{
		for (int i = 2; (i*i) <= val; i++)
		{
			if ((val % i) == 0) { return false; }
		}
		return true;
	}

	// get the next prime number after the passed in val
	int getNextPrimeNum(int nonPrimeNum) 
	{
		for (int i = val + 1;; i++)
		{
			if (isNumPrime(val)) { break; }
		}
		
		return i;
	}


	void deleteHashNode(int k) {}
	HashNode& getHashNode(int k) {}


	int m_size;
	int m_totalItems;

	HashNode<T>* m_root;
	HashNode<T>* m_next;
	std::vector<HashNode<T>*> m_table;
};

