#pragma once
#include "Includes.h"

template<typename T>
class AStack
{
public:
	//////////////////////////////////////////////////////////////////////////
	/************************************************************************/
	/* Public Methods */
	/************************************************************************/
	AStack() : m_unArray(NULL), m_size(0), m_top(0) {}
	~AStack() { if (m_unArray != NULL){ delete m_unArray; m_unArray = NULL; } }

	//////////////////////////////////////////////////////////////////////////
	/************************************************************************/
	/* Public Methods */
	/************************************************************************/
	void Push(T val)	{ validateAssignment(); m_unArray->push(val); }
	void Pop()			{ validateAssignment(); m_unArray->pop(); }
	const T& Top()		{ validateAssignment(); m_unArray->GetSize() - 1; }
	int GetSize()		{ validateAssignment(); m_unArray->GetSize(); }
	int GetMaxSize()	{ validateAssignment(); m_unArray->GetMaxSize(); }

	bool isEmpty()		{ validateAssignment(); m_unArray->GetSize() == 0; }
	bool isFull()		{ Top() == m_unArray->GetMaxSize() - 1; }

private:
	//////////////////////////////////////////////////////////////////////////
	/************************************************************************/
	/* Private Methods */
	/************************************************************************/
	validateAssignment() { assert(m_unArray != NULL); }

	//////////////////////////////////////////////////////////////////////////
	/************************************************************************/
	/* Private Properties */
	/************************************************************************/
	UnorderedArray<T>* m_unArray;
	int m_size;
	int m_top;
};

template<typename T>
class LLStack
{
public:
	//////////////////////////////////////////////////////////////////////////
	/************************************************************************/
	/* Constructor/Destructor */
	/************************************************************************/
	LLStack() : m_lList(NULL), m_size(0), m_top(0) {}
	~LLStack() { if (m_lList != NULL){ delete m_lList; m_lList = NULL; } }

	//////////////////////////////////////////////////////////////////////////
	/************************************************************************/
	/* Public Methods */
	/************************************************************************/
	void Push(T val)	{ validateAssignment(); m_lList->push(val); }
	void Pop()			{ validateAssignment(); m_lList->pop(); }
	int GetSize()		{ validateAssignment(); m_lList->GetSize(); }

	const T& Top()		{ LinkIterator<T> it = m_lList->GetLast(); return *it; }
	bool isEmpty()		{ return m_lList->GetSize() == 0; }

private:
	//////////////////////////////////////////////////////////////////////////
	/************************************************************************/
	/* Private Methods */
	/************************************************************************/
	validateAssignment() { assert(m_lList != NULL); }

	//////////////////////////////////////////////////////////////////////////
	/************************************************************************/
	/* Private Properties */
	/************************************************************************/
	LinkList<T>* m_lList;
	int m_size;
	int m_top;
};