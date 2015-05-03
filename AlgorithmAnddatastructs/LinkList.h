#pragma once
#include "Includes.h"

template<typename T> class LinkIterator;
template<typename T> class LinkList;

template<typename T>
class LinkNode
{
	friend class LinkIterator < T > ;
	friend class LinkList < T > ;

	LinkNode() : m_data(0), m_next(0), m_previous(0) {}
	~LinkNode()
	{
		if (m_next != NULL)
		{
			delete m_next;
			m_next = NULL;
		}
	}

private:
	T m_data;
	LinkNode* m_next;
	LinkNode* m_previous;
};

template<typename T>
class LinkIterator
{
public:
	LinkIterator() { m_node = NULL; }
	~LinkIterator()	{}
	// ----------------------------------------------------------------------
	// overloaded operators

	// Overloaded assignment
	void operator = (LinkNode<T>* node) { m_node = node; }

	// dereference this nodes data
	T& operator * () { assert(m_node != NULL); return m_node->m_data; }

	// Increment the iterator to the next node
	void operator ++ (int) { assert(m_node != NULL); m_node = m_node->m_next; }
	void operator ++ () { assert(m_node != NULL); m_node = m_node->m_next; }

	// decrement the iterator to the previous node
	void operator -- (int) { assert( m_node != NULL ); m_node = m_node->m_previous; }
	void operator -- () { assert( m_node != NULL ); m_node = m_node->m_previous; }

	// Not equal comparison overload
	bool operator != (LinkNode<T>* node) { return m_node != node; }

	// Equal to comparison overload
	bool operator == (LinkNode<T>* node) { return m_node == node; }

	// Test if this node is less then the passed in node
	bool operator < (LinkNode<T>* node) { return m_node < node; }

	// Test if this node is greater then the passed in node
	bool operator >( LinkNode<T>* node ) { return m_node > node; }

private:
	LinkNode<T>* m_node;	// stores the node to be iterated over
};

template<typename T>
class LinkList
{
public:
	LinkList() : m_size(0), m_root(0), m_lastNode(0) {}					// init all to 0
	~LinkList() { while ( m_root != NULL ){ pop(); } }					// remove all nodes

	LinkNode<T>* Begin() { assert( m_root != NULL ); return m_root; }	// return pointer to root node
	LinkNode<T>* End() { return NULL; }									// return null as end of list
	/** TODO:
	 * In the book there was a reference to Last function that is not listed
	 * in the code here. Investigate the Last() method.
	 */
	int GetSize() { return m_size; }									// return int size of Linked List

	// ----------------------------------------------------------------------
	// overloaded operators
	bool operator < (LinkList<T>* list) { return *this < list; }
	bool operator > (LinkList<T>* list) { return *this > list; }
	bool operator <= (LinkList<T>* list) { return *this <= list; }
	bool operator >= (LinkList<T>* list) { return *this >= list; }
	bool operator == (LinkList<T>* list) { return *this == list; }
	bool operator != (LinkList<T>* list) { return *this != list; }

	/**
	 * TODO:
	 * implement functionality to add and remove form an index of 
	 * the linked list
	 */

	// ---------------------------------------------------------
	// Doubly linked list functions
	void push_front(T newData)
	{
		LinkNode<T>* node = new LinkNode<T>;
		assert(node != NULL);

		node->m_data = newData;
		node->m_next = NULL;
		node->m_previous = NULL;

		if (m_root != NULL)
		{
			// link the next node in the list to current root
			node->m_next = m_root;
			node->m_previous = node;
			// mark the root as the new node
			m_root = node;
		}
		else
		{
			m_root = node;
			m_lastNode = node;
		}
		// increase the size of the list after
		// the addition of a new node
		m_size++;
	}

	void pop_front()
	{
		assert(m_root != NULL);

		LinkNode<T>* temp = m_root;

		m_root = m_root->m_next;

		if ( m_root != NULL ) { m_root->m_previous = NULL; }

		delete temp;

		m_size = (m_size == 0) ? m_size : m_size - 1;
	}

	// end doubly linked list functons
	// ---------------------------------------------------------

	void push(T newData) 
	{
		LinkNode<T>* node = new LinkNode<T>;
		assert(node != NULL);

		// Set the new node data to this newData
		node->m_data = newData;
		// This is the last node, so no next node yet
		node->m_next = NULL;
		node->m_previous = NULL;

		if ( m_lastNode != NULL )
		{
			// because there is another node, next node is node
			m_lastNode->m_next = node;
			node->m_previous = m_lastNode;
		}
		else
		{
			// no previous node so set root to new node
			m_root = node;
		}

		m_lastNode = node;

		// Increase the count of the list size
		m_size++;
	}

	void pop()
	{
		assert(m_root != NULL);

		// if this is the last node
		if (m_root->m_next == NULL)
		{
			// delete this node and set to NULL
			delete m_root;
			m_root = NULL;
		}
		else
		{
			LinkNode<T>* prevNode = m_root;

			prevNode->m_next = NULL;
			delete m_lastNode;
			m_lastNode = prevNode;
		}

		m_size = (m_size == 0 ? m_size : m_size - 1);
	}

	void unique()
	{
		// TODO: iterate through the list removing any duped items
	}

	void remove( LinkNode<T> node )
	{
		// TODO: iterate over the list removing all nodes == to node
	}


private:
	int m_size;
	LinkNode<T>* m_root;
	LinkNode<T>* m_lastNode;

};