#pragma once
#include "Includes.h"
#include "NetMessage.h"

// Queue comparison class for less comparisons
template<typename T>
class less_cmp
{
public:
	inline bool operator () (T lVal, T rVal) { return (lVal < rVal); }
};

// Queue comparison class for ptr less comparisons
template<typename T>
class less_cmp_ptr
{
public:
	inline bool operator () (T lVal, T rVal) { return ((*lVal) < (*rVal)); }
};

// Queue comparison class for greater than comparisons
template<typename T>
class greater_cmp
{
public:
	inline bool operator () (T lVal, T rVal) { return (lVal > rVal); }
};

// Queue comparison class for greater then ptr comparisons
template<typename T>
class greater_cmp_ptr
{
public:
	inline bool operator () (T lVal, T rVal) { return ((*lVal) > (*rVal)); }
};


template<typename T>
class Queue
{

	/*
		singly ended Queue functionality
	*/
public:

	// Constructor and Destructor
	Queue(int size)			{ assert(size > 0); m_size = size; }
	~Queue()				{}

	// insertion and deletion operations
	void Push(T val)		{ if (m_container.GetSize() < m_size) m_container.push(val); }
	void Pop()				{ m_container.pop_front() }

	// view start of queue without deletion
	const T& Front()		{ LinkIterator<T> itr; itr = m_container.Begin(); return *itr; }

	// informative methods for viewing data about the current Queue
	int GetSize()			{ return m_container.GetSize(); }
	int GetMaxSize()		{ return m_size; }
	bool IsEmpty()			{ return (m_container.GetSize() == 0); }

	// resize the queue to store more data
	void Resize(int size)	{ assert(size > 0); m_size = size; }

private:
	int m_size;
	LinkList<T> m_container;
};

template<typename T>
class Dequeue
{

	/*
		doubly ended Queue functionality
	*/
public:

	// Constructor and Destructor
	Dequeue(int size)		{ assert(size > 0); m_size = size; }
	~Dequeue()				{}

	// insertion and deletion operations
	void Push_front(T val)	{ if (m_container.GetSize() < m_size) m_container.push_front(val); }
	void Pop_front()		{ m_container.pop() }

	void Push_back(T val)	{ if (m_container.GetSize() < m_size) m_container.push(val); }
	void Pop_back()			{ m_container.pop_front() }

	// view start of queue without deletion
	const T& Front()		{ LinkIterator<T> itr; itr = m_container.GetLast(); return *itr; }
	const T& Back()			{ LinkIterator<T> itr; itr = m_container.Begin(); return *itr; }

	// informative methods for viewing data about the current Queue
	int GetSize()			{ return m_container.GetSize(); }
	int GetMaxSize()		{ return m_size; }
	bool IsEmpty()			{ return (m_container.GetSize() == 0); }


	void Resize(int size)	{ assert(size > 0); m_size = size; }

private:
	int m_size;
	LinkList<T> m_container;
};

template<typename T, typename CMP>
class PriorityQueue
{

	/*
		Priority Queue functionality
	*/
public:

	// Constructor and Destructor
	PriorityQueue(int size)	{ assert(size > 0); m_size = size; }
	~PriorityQueue()		{}

	// Add element to the priority queue
	void Push(T val)
	{
		assert(m_container.GetSize() < m_size);

		if (m_container.GetSize() == 0)
		{
			m_container.push(val);
		}
		else
		{
			// error here!! attempting to convert link node to link iterator
			LinkIterator<T>* itr = m_container.Begin();
			CMP cmp;

			while (itr->isValid())
			{
				if (cmp(val, *itr))
				{
					break;
				}

				itr++
			}

			if (itr->isValid()) { m_container.insert_before(itr, val); }
			else { m_container.push(val); }
		}
	}

	// view front of queue
	const T& Front()		{ LinkIterator<T> itr; itr = m_container.GetLast(); return *itr; }
	// view lest element in queue
	const T& Back()			{ LinkIterator<T> itr; itr = m_container.Begin(); return *itr; }

	// informative methods for viewing data about the current Queue
	int GetSize()			{ return m_container.GetSize(); }
	int GetMaxSize()		{ return m_size; }
	bool IsEmpty()			{ return (m_container.GetSize() == 0); }

	// overloaded operators
	/*bool operator< (T lVal, T rVal)		{ return (lVal < rVal); }
	bool operator< (T* lVal, T* rVal)	{ return (*(lVal) < *(rVal)); }
	bool operator> (T lVal, T rVal)		{ return (lVal > rVal); }
	bool operator> (T* lVal, T* rVal)	{ return (*(lVal) > *(rVal)); }*/

	// resize the queue
	void Resize(int size)	{ assert(size > 0); m_size = size; }

private:
	int m_size;
	LinkList<T> m_container;
};