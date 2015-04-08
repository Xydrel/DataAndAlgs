#pragma once
#include "Includes.h"

template<typename T> class LinkIterator;
template<typename T> class LinkList;

template<typename T>
class LinkNode
{
	friend class LinkIterator<T>;
	friend class LinkList<T>;

private:
	T m_data;
	LinkNode* m_next;
};

template<typename T>
class LinkIterator
{
public:
	LinkIterator() { m_node = NULL; }
	~LinkIterator()	{}

	// overloaded operators
	void operator = (LinkNode<T>* node) { m_node = node; }						// overload assignement operator
	T& operator * () { assert(m_node != NULL); return m_node->m_data; }			// overload dereference operator
	void operator ++ (int) { assert(m_node != NULL); m_node = m_node->m_next; }	// overload increment operator for iteration
	void operator ++ () { assert(m_node != NULL); m_node = m_node->m_next; }	// overload increment operator for iteration
	bool operator != (LinkNode<T>* node) { return m_node != node; }				// overload not equal comparison operator
	bool operator == (LinkNode<T>* node) { return m_node == node; }				// overload equal comparison operator

private:
	LinkNode<T>* m_node;	// stores the node to be iterated over
};

template<typename T>
class LinkList
{
public:
	LinkList() : m_size(0), m_root(0), m_next(0) {}						// init all to 0
	~LinkList() { while ( m_root != NULL ){ Pop(); } }					// remove all nodes
	LinkNode<T>* Begin() { assert( m_root != NULL ); return m_root; }	// return pointer to root node
	LinkNode<T>* End() { return NULL; }									// return null as end of list
	int GetSize() { return m_size; }									// return int size of Linked List

	void Push(T newData) 
	{
		LinkNode<T>* node = new LinkNode();
		assert(node != NULL);

		// Set the new node data to this newData
		node->m_data = newData;
		// This is the last node, so no next node yet
		node->m_next = NULL;
		if ( m_lastNode != NULL )
		{
			// because there is another node, next node is node
			m_lastNode->m_next = node;
			// node is nowe the last node as it was just created
			m_lastNode = node;
		}
		else
		{
			// no previous node so set root to new node
			m_root = node;
			// setting lastNode to node as this is the last node for now
			m_lastNode = node;
		}

		// Increase the count of the list size
		m_size++;
	}

	void Pop()
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
			// perform deletion of node
			LinkNode<T>* prevNode = m_root;

			while ( prevNode->m_next != NULL
				&& prevNode->m_next != m_lastNode )
			{
				prevNode = prevNode->m_next;
			}

			delete m_lastNode;
			prevNode->m_next = NULL;
			m_lastNode = prevNode;
		}

		m_size = (m_size == 0 ? m_size : m_size - 1);
	}


private:
	int m_size;
	LinkNode<T>* m_root;
	LinkNode<T>* m_lastNode;

};