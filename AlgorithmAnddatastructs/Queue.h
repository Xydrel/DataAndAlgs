#pragma once
#include "Includes.h"

template<typename T>
class Queue
{
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