#pragma once
#include "Includes.h"

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

class NetMessage
{
public:
	NetMessage() : m_priority(0), m_id(0) {}
	NetMessage(int p, int id) : m_priority(p), m_id(id) {}
	~NetMessage() {}

	int GetPriority() { return m_priority; }
	int GetID()		  { return m_id; }

	//////////////////////////////////////////////////////////////////////////
	// Overloaded Operators ////////
	//////////////////////////////////////////////////////////////////////////
	// Less than NetMessage compare
	bool operator < (NetMessage& m) 
	{
		if (m_priority < m.GetPriority()) { return true; }
		else if (m_id < m.GetID())		  { return true; }
		return false;
	}

	// Greater than NetMessage compare
	bool operator > (NetMessage& m) { return *this > m; }

private:
	int m_priority;
	int m_id;
};


class ExtendedNetMessage : public NetMessage
{
typedef NetMessage BASE;
public:
	ExtendedNetMessage() : m_id(0), m_priority(0) {}
	ExtendedNetMessage(int p, int id) : m_priority(p), m_id(id) {}
	~ExtendedNetMessage() {}

private:
	int m_id;
	int m_priority;
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
	void push(T val)		{ if (m_container.GetSize() < m_size) m_container.push(val); }
	void pop()				{ m_container.pop_front() }

	// view start of queue without deletion
	const T& front()		{ LinkIterator<T> itr; itr = m_container.Begin(); return *itr; }

	// informative methods for viewing data about the current Queue
	int GetSize()			{ return m_container.GetSize(); }
	int GetMaxSize()		{ return m_size; }
	bool isEmpty()			{ return (m_container.GetSize() == 0); }

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
	void push_front(T val)	{ if (m_container.GetSize() < m_size) m_container.push_front(val); }
	void pop_front()		{ m_container.pop() }

	void push_back(T val)	{ if (m_container.GetSize() < m_size) m_container.push(val); }
	void pop_back()			{ m_container.pop_front() }

	// view start of queue without deletion
	const T& front()		{ LinkIterator<T> itr; itr = m_container.GetLast(); return *itr; }
	const T& back()			{ LinkIterator<T> itr; itr = m_container.Begin(); return *itr; }

	// informative methods for viewing data about the current Queue
	int GetSize()			{ return m_container.GetSize(); }
	int GetMaxSize()		{ return m_size; }
	bool isEmpty()			{ return (m_container.GetSize() == 0); }


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

	// insertion and deletion operations
	void push(T val)
	{
		assert(m_container.GetSize() < m_size);

		if (m_container.GetSize() == 0)
		{
			m_container.push(val);
		}
		else
		{
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
			else () { m_container.push(val); }
		}
	}

	// view start of queue without deletion
	const T& front()		{ LinkIterator<T> itr; itr = m_container.GetLast(); return *itr; }
	const T& back()			{ LinkIterator<T> itr; itr = m_container.Begin(); return *itr; }

	// informative methods for viewing data about the current Queue
	int GetSize()			{ return m_container.GetSize(); }
	int GetMaxSize()		{ return m_size; }
	bool isEmpty()			{ return (m_container.GetSize() == 0); }

	// resize the queue to store more data
	void Resize(int size)	{ assert(size > 0); m_size = size; }

private:
	int m_size;
	LinkList<T> m_container;
};