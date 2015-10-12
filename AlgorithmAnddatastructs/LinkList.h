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

	LinkNode() : m_next(0), m_previous(0) {}
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
	friend class LinkList<T>;
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
	T& operator* () { validateNode(m_node); return m_node->m_data; }

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
	bool operator <  (LinkNode<T>* node) { return m_node < node; }

	// Test if this node is greater then the passed in node
	bool operator >  ( LinkNode<T>* node ) { return m_node > node; }

	// Test that the passed in node is not NULL
	bool isValid() { return *this != NULL; }

private:
	void validateNode(LinkNode<T>* node) { assert(node != NULL); }
	LinkNode<T>* m_node;	// stores the node to be iterated over
};

template<typename T>
class LinkList
{
public:
	LinkList() : m_size(0), m_root(0), m_lastNode(0) {}					// init all to 0 or NULL
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

	// Insert the new data before the next node in the list
	void insert_before(LinkIterator<T>& itr, T newData)
	{
		assert(itr.m_node != NULL);

		// create new node and validate it
		LinkNode<T>* node = new LinkNode<T>();
		validateNode(node);

		// set the new data in the new node
		node->m_data = newData;

		// set the next node to the current itr node
		node->m_next = itr.m_node;

		// set the new nodes previous pointer to the iter's prev node
		node->m_previous = itr.m_node->m_previous;

		// set the previous node's pointer to the new node
		if (node->m_previous != NULL) 
		{
			node->m_previous->m_next = node;
		}

		// set the iter node prev node to the new node
		itr.m_node->m_previous = node;

		// if the list doesn't have a root set it to the new node
		if (itr.m_node == m_root)
		{
			m_root = node;
		}

		// increase list size counter
		m_size++;
	}
	
	// Insert the new data after the next node in the list
	void insert_after(LinkIterator<T>& itr, T newData)
	{
		validateNode(itr.m_node);

		// create new node and validate it
		LinkNode<T>* node = new LinkNode<T>();
		validateNode(node);

		// set the node data to the new data
		node->m_data = newdata;

		// set the node next to the iter next
		node->m_next = itr.m_node->m_next;

		// set the new nodes previous node to the iter node
		node->m_previous = itr.m_node;

		// if not at end of list
		if (node->m_next != NULL)
		{
			// set next nodes prev to the new node
			node->m_next->m_previous = node;
		}

		// set the iter's next node to the new node
		itr.m_node->m_next = node;

		// if iter is on the last node
		if (itr.m_node == m_lastNode)
		{
			// set the new last node to the new node
			m_lastNode = node;
		}

		// increase the size of the container list
		m_size++;
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

	void insert_before(LinkIterator<T>& it, T newData)
	{
		validateNode(it.m_node);

		LinkNode<T>* node = new LinkNode<T>;
		validateNode(node);

		// set the data and pointers to before iterator node
		node->m_data = newData;
		node->m_next = it.m_node;
		node->m_previous = it.m_node->m_previous;
		
		// set the previous nodes next pointer to this node
		if (node->m_previous != NULL) 
		{ 
			node->m_previous->m_next = node;
		}

		// reset the previous pointer of the iterator
		it.m_node->m_previous = node;

		// if the iterator node was root
		// set the new node to root now
		if (it.m_node == m_root)
		{
			m_root = node;
		}

		// increase list size since a node was added
		m_size++;

	}

	void insert_after(LinkIterator<T>& it, T newData)
	{
		validateNode(it.m_node);

		LinkNode<T>* node = new LinkNode<T>;
		validateNode(node);

		// set the data and list pointers to after the iterator node
		node->m_data = newData;
		node->m_next = it.m_node->m_next;
		node->m_previous = it.m_node;

		// set the next nodes prev pointer to this node
		if (node->m_next != NULL)
		{
			node->m_next->m_previous = node;
		}

		// reset the iterator node's next pointer to this node
		it.m_node->m_next = node;

		// if the iterator was the last node in the list
		// set this node to the last node now
		if (it.m_node == m_lastNode)
		{
			m_lastNode = node;
		}

		m_size++;
	}

private:
	void validateNode(LinkNode<T>* node) { assert(node != NULL); }

	int m_size;
	LinkNode<T>* m_root;
	LinkNode<T>* m_lastNode;

};

