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
		: key(0)
		, data(NULL)
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
	int			key;
	T			data;
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
	SortedBinaryTree() : root(NULL), container(NULL) {}
	~SortedBinaryTree() { if (root != NULL){ root = NULL, delete root; } }

	// Operational methods
	void SortedInsert() {}
	void Insert() {}

	// Data Structure informative methods
	int GetSize() {}
	int GetMaxSize() {}

	// Operator overload methods
	bool operator<  () {}
	bool operator>  () {}
	bool operator== () {}
	bool operator<= () {}
	bool operator>= () {}
	bool operator=  () {}

private:
	int				size;
	BinaryNode*		root;
	std::vector<T*> container;

};
