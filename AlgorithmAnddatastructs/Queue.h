#pragma once
#include "Includes.h"

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

	// resize the queue to store more data
	void Resize(int size)	{ assert(size > 0); m_size = size; }

private:
	int m_size;
	LinkList<T> m_container;
};

template<typename T>
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

	// resize the queue to store more data
	void Resize(int size)	{ assert(size > 0); m_size = size; }

private:
	int m_size;
	LinkList<T> m_container;
};