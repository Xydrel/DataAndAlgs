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

	// Return the int size of the Queue
	virtual int GetSize()			{ return m_container.GetSize(); }

	// Return the int max size of the Queue
	virtual int GetMaxSize()		{ return m_size; }

	// Tests that the Queue is not empty for conditional operations
	virtual bool IsEmpty()			{ return (m_container.GetSize() == 0); }

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

	// View element data at front of container
	const T& Front()		{ LinkIterator<T> itr; itr = m_container.GetLast(); return *itr; }

	// View element data at back of container
	const T& Back()			{ LinkIterator<T> itr; itr = m_container.Begin(); return *itr; }

	// Gets the size of the container
	int GetSize()			{ return m_container.GetSize(); }

	// Gets the max size of the container
	int GetMaxSize()		{ return m_size; }

	// Tests if the container is empty and returns a bool result
	bool IsEmpty()			{ return (m_container.GetSize() == 0); }

	// Resize the container to the provided size
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

	// Constructor declairing size of list
	PriorityQueue()			{}
	PriorityQueue(int size) { assert(size > 0); m_size = size; }

	~PriorityQueue()		{}

	void ProcessElement()
	{
		// TODO:
		// perform operations to handle the operation as needed
		// In this case just a simple operation to remove the next
		// message in the queue based on priority.

		// elements should be inserted based on their priority, so
		// opperating on the queue should be fast since the top most
		// element would be the one needing handling.
	}

	// Add element to the priority queue
	void Push(T val)
	{

		if (m_container.GetSize() == 0)
		{
			m_container.push(val);
		}
		else
		{

			LinkIterator<T> itr;
			itr = m_container.Begin();

			CMP cmp;

			while (itr.isValid())
			{
				if (cmp(val, *itr))
				{
					break;
				}

				itr++;
			}

			if (itr.isValid()) 
			{ 
				m_container.insert_before(itr, val); 
			}
			else 
			{ 
				m_container.push(val); 
			}
		}
		m_size++;
	}

	// View front element of queue
	const T& Front()		{ LinkIterator<T> itr; itr = m_container.GetLast(); return *itr; }

	// View last element in queue
	const T& Back()			{ LinkIterator<T> itr; itr = m_container.Begin(); return *itr; }

	// Returns the int size of the PriorityQueue
	int GetSize()			{ return m_container.GetSize(); }

	// Returns the max size of the PriorityQueue
	int GetMaxSize()		{ return m_size; }

	// Tests that the PriorityQueue is not empty for conditional operations
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