#pragma once
#include "Includes.h"

//////////////////////////////////////////////////////////////////////////
/************************************************************************/
/* Macros */
/************************************************************************/
#define VALIDATE_CONTAINER(_obj) assert(_obj != NULL)


template<typename T>
class AStack
{
public:
	//////////////////////////////////////////////////////////////////////////
	/************************************************************************/
	/* Public Methods */
	/************************************************************************/
	AStack(int size, int growBy = 1) 
	{
		assert(size > 0 && growBy >= 0);
		m_unArray = new UnorderedArray<T>(size, growBy);
		VALIDATE_CONTAINER(m_unArray);
	}
	~AStack() { if (m_unArray != NULL){ delete m_unArray; m_unArray = NULL; } }

	//////////////////////////////////////////////////////////////////////////
	/************************************************************************/
	/* Public Methods */
	/************************************************************************/
	void Push(T val)	{ VALIDATE_CONTAINER(m_unArray); m_unArray->push(val); }
	void Pop()			{ VALIDATE_CONTAINER(m_unArray); m_unArray->pop(); }
	const T& Top()		{ VALIDATE_CONTAINER(m_unArray); return (*m_unArray)[m_unArray->GetSize() - 1]; }
	int GetSize()		{ VALIDATE_CONTAINER(m_unArray); return m_unArray->GetSize(); }
	int GetMaxSize()	{ VALIDATE_CONTAINER(m_unArray); return m_unArray->GetMaxSize(); }

	bool isEmpty()		{ VALIDATE_CONTAINER(m_unArray); return m_unArray->GetSize() == 0; }
	bool isFull()		{ return Top() == m_unArray->GetMaxSize() - 1; }

private:
	//////////////////////////////////////////////////////////////////////////
	/************************************************************************/
	/* Private Methods */
	/************************************************************************/

	//////////////////////////////////////////////////////////////////////////
	/************************************************************************/
	/* Private Properties */
	/************************************************************************/
	UnorderedArray<T>* m_unArray;
};

template<typename T>
class LLStack
{
public:
	//////////////////////////////////////////////////////////////////////////
	/************************************************************************/
	/* Constructor/Destructor */
	/************************************************************************/
	LLStack()	{}
	~LLStack()	{}

	//////////////////////////////////////////////////////////////////////////
	/************************************************************************/
	/* Public Methods */
	/************************************************************************/
	void Push(T val)	{ VALIDATE_CONTAINER(m_lList); m_lList.push(val); }
	void Pop()			{ VALIDATE_CONTAINER(m_lList); m_lList.pop(); }
	int GetSize()		{ VALIDATE_CONTAINER(m_lList); return m_lList.GetSize(); }

	const T& Top()		{ LinkIterator<T> it = m_lList.GetLast(); return *it; }
	bool isEmpty()		{ return m_lList.GetSize() == 0; }


private:
	//////////////////////////////////////////////////////////////////////////
	/************************************************************************/
	/* Private Methods */
	/************************************************************************/

	//////////////////////////////////////////////////////////////////////////
	/************************************************************************/
	/* Private Properties */
	/************************************************************************/
	LinkList<T> m_lList;
	int m_size;
};