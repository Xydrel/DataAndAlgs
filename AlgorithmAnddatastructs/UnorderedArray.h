#pragma once
#include "Includes.h"

template<typename T> class UnorderedArray;

template<typename T>
class UnorderedArray
{
public:
	UnorderedArray(int size, int growBy = 1) : 
		m_array(NULL), 
		m_maxSize(0), 
		m_numElements(0),
	{
		if (size)
		{
			m_maxSize = size;
			m_array = new T[m_maxSize];

			m_growSize = ((growBy > 0) ? growBy : 0);
		}
	}

	~UnorderedArray()
	{
		if (m_array != NULL)
		{
			delete[] m_array;
			m_array = NULL;
		}
	}

	virtual T& operator[](int index)
	{
		assert(m_array != NULL && index <= m_numElements);
		return m_array[index];
	}

	virtual void push(T val)
	{
		assert(m_array != NULL);

		if (m_numElements >= m_maxSize)
		{
			expand();
		}

		m_array[m_numElements] = val;
		m_numElements++;
	}

	void pop()
	{
		if (m_numElements > 0)
		{
			// simply change the size of elements
			// note: data still exists
			m_numElements--;
		}
	}

	void remove(int index)
	{
		assert(m_array != NULL);

		if (index >= m_maxSize) return;
		for (int k = index; k < m_maxSize; k++)
		{
			m_array[k] = m_array[k + 1];
		}

		m_maxSize--;

		// assure we don't exceed max array size
		if (m_numElements >= m_maxSize)
		{
			m_numElements = m_maxSize - 1;
		}
	}

	void clear()
	{
		m_numElements = 0;
	}

	bool expand()
	{
		if (m_growSize <= 0) return false;
		T *temp = new T[m_maxSize + m_growSize];
		assert(temp != NULL);

		memcpy(temp, m_array, sizeof(T) * m_maxSize);

		delete[] m_array;
		m_array = temp;

		m_maxSize += m_growSize;

		return true;
	}
	

private:
	T *m_array;

	int m_maxSize;
	int m_growSize;
	int m_numElements;
};