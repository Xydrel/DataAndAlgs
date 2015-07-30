#pragma once
#include "Includes.h"

template<typename T> class LinkIterator;
template<typename T> class LinkList;
template<typename T> class DoublyLinkList;

template<typename T>
class LinkNode
{
	friend class LinkIterator<T>;
	friend class LinkList<T>;
	friend class DoublyLinkList<T>;

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

	//////////////////////////////////////////////////////////////////////////
	/************************************************************************/
	/* Constructor/Destructor */
	/************************************************************************/
	LinkIterator() { m_node = NULL; }
	~LinkIterator()	{}
	//////////////////////////////////////////////////////////////////////////
	/************************************************************************/
	/* overloaded operators */
	/************************************************************************/

	// Overloaded assignment
	void operator = (LinkNode<T>* node) { m_node = node; }

	// dereference this nodes data
	T& operator * () { validateNode(m_node); return m_node->m_data; }

	// Increment the iterator to the next node
	void operator ++ (int) { validateNode(m_node); m_node = m_node->m_next; }
	void operator ++ () { validateNode(m_node); m_node = m_node->m_next; }

	// decrement the iterator to the previous node
	void operator -- (int) { validateNode(m_node); m_node = m_node->m_previous; }
	void operator -- () { validateNode(m_node); m_node = m_node->m_previous; }

	// Not equal comparison overload
	bool operator != (LinkNode<T>* node) { return m_node != node; }

	// Equal to comparison overload
	bool operator == (LinkNode<T>* node) { return m_node == node; }

	// Test if this node is less then the passed in node
	bool operator < (LinkNode<T>* node) { return m_node < node; }

	// Test if this node is greater then the passed in node
	bool operator >( LinkNode<T>* node ) { return m_node > node; }

private:
	void validateNode(LinkNode<T>* node) { assert(node != NULL); }
	LinkNode<T>* m_node;	// stores the node to be iterated over
};

template<typename T>
class LinkList
{
public:
	LinkList() : m_size(0), m_root(0), m_lastNode(0) {}					// init all to 0
	~LinkList() { while ( m_root != NULL ){ pop(); } }					// remove all nodes

	LinkNode<T>* Begin() { validateNode(m_root); return m_root; }	// return pointer to root node
	LinkNode<T>* End() { return NULL; }									// return null as end of list

	// Return int size of Linked List
	int GetSize() { return m_size; }

	// Return the last node in the list
	LinkNode<T>* GetLast() { return m_lastNode; }

	//////////////////////////////////////////////////////////////////////////
	/************************************************************************/
	/* overloaded operators */
	/************************************************************************/
	// 
	bool operator <	 (LinkList<T>* list) { return m_size < list->GetSize(); }
	bool operator >	 (LinkList<T>* list) { return m_size > list->GetSize(); }
	bool operator <= (LinkList<T>* list) { return m_size <= list->GetSize(); }
	bool operator >= (LinkList<T>* list) { return m_size >= list->GetSize(); }
	bool operator += (LinkList<T>* list) { return m_size == list->GetSize(); }
	bool operator != (LinkList<T>* list) { return m_size != list->GetSize(); }

	/************************************************************************/
	/* push methods */
	/************************************************************************/
	void push(T newData) 
	{
		LinkNode<T>* node = new LinkNode<T>;
		validateNode(node);

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

	void push(T newData, int index)
	{
		// Create support to add nore to list by index
		// This will need to find the index. if beyond the max size, assert/extend list maxsize, 
		// push the node into the index
		// adjust the node which was already in the index to the next position
		// the the root previous node from the node moved to the next index and assign to the new nodes previous pointer
		// assign next nodes previous pointer to the inserted node
		LinkNode<T>* node = new LinkNode<T>;
		validateNode(node);

		for (; node->m_next != 0; node->m_next)
		{
			// iterate over the collection of nodes to get to the index
			if (m_root)
			{
				LinkNode<T>* tmp = node;
				tmp->m_previous = m_root;
				node->m_next = tmp;
			}
		}
	}

	/************************************************************************/
	/* pop methods */
	/************************************************************************/
	void pop()
	{
		validateNode(m_root);

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

	void pop(int index)
	{
		// TODO: implement pop of index
	}

	void deque()
	{
		// TODO: iterate through the list removing any duped items
	}

	void remove( LinkNode<T> node )
	{
		// TODO: iterate over the list removing all nodes == to node
	}

	void insert_before()
	{
		// TODO: implement
		// Inserts the element before the node the iterator points at
	}

	void insert_after()
	{
		// TODO: implement
		// Insert the element after the node the iterator points at
	}

private:
	void validateNode(LinkNode<T>* node) { assert(node != NULL); }

	int m_size;
	LinkNode<T>* m_root;
	LinkNode<T>* m_lastNode;

};

template<typename T>
class DoublyLinkList : public LinkList<T>
{
	friend class LinkList<T>;

public:
	DoublyLinkList() : m_size(0), m_root(0), m_lastNode(0) {}					// init all to 0
	~DoublyLinkList() { while (m_root != NULL){ pop(); } }					// remove all nodes


	void push_front(T newData)
	{
		LinkNode<T>* node = new LinkNode<T>;
		validateNode(node);

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
		validateNode(m_root);

		LinkNode<T>* temp = m_root;

		m_root = m_root->m_next;

		if (m_root != NULL) { m_root->m_previous = NULL; }

		delete temp;

		m_size = (m_size == 0) ? m_size : m_size - 1;
	}



	//void deque()
	//{
	//	// TODO: iterate through the list removing any duped items
	//}

	//void remove(LinkNode<T> node)
	//{
	//	// TODO: iterate over the list removing all nodes == to node
	//}

	void insert_before()
	{
		// TODO: implement
		// Inserts the element before the node the iterator points at
	}

	void insert_after()
	{
		// TODO: implement
		// Insert the element after the node the iterator points at
	}

private:
	void validateNode(LinkNode<T>* node) { assert(node != NULL); }

	int m_size;
	LinkNode<T>* m_root;
	LinkNode<T>* m_lastNode;

};

