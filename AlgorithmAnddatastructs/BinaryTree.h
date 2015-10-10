#include "Includes.h"


template<typename T>
struct BinaryNode
{
	/*
		Structure to contain the data of the binary tree.
		Includes pointers to left and right childs
	*/
	friend class SortedBinaryTree;
public:
	BinaryNode() 
		// Default init the struct data
		: m_key(0)
		, m_data(NULL)
		, lChild(NULL)
		, rChild(NULL) 
	{}
	~BinaryNode()
	{
		// Cleanup the pointer data
		if (lChild != NULL) { lChild = NULL, delete lChild; }
		if (rChild != NULL) { rChild = NULL, delete rChild; }
	}

private:
	T			m_data;
	int			m_key;

	BinaryNode* lChild;
	BinaryNode* rChild;
};


template<typename T>
class SortedBinaryTree
{ 
	/*
		Sorted tree structure. This tree will be ordered upon insert when possible
		based on the type of data being inserted.
	*/
public:
	SortedBinaryTree() : m_size(0), m_root(NULL), m_container(NULL) {}
	~SortedBinaryTree() { if (m_root != NULL){ m_root = NULL, delete m_root; } }

	// Operational methods
	void SortedInsert() {}
	void Insert() {}
	void Sort() {}

	// Data Structure informative methods
	inline int GetSize() { return m_size; }
	inline int GetMaxSize() {}

	// Operator overload methods
	inline bool operator<  (T* lVal, T* rVal) { assert(lVal != NULL); assert(rVal != NULL); return lVal < rVal; }
	inline bool operator>  (T* lVal, T* rVal) { assert(lVal != NULL); assert(rVal != NULL); return lVal > rVal; }
	inline bool operator== () {}
	inline bool operator<= () {}
	inline bool operator>= () {}
	inline bool operator=  () {}

private:
	int				m_size;
	BinaryNode*		m_root;
	std::vector<T*> m_container;

};
