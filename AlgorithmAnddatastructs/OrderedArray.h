#pragma once
#include "Includes.h"

template<typename T> class OrderedArray;

template<typename T>
class OrderedArray
{
public:
	OrderedArray(int size, int growBy = 1) :
		m_array(NULL), 
		m_maxSize(0), 
		m_numElemets(0),
	{
		if (size)
		{
			m_maxSize = size;
			m_array = new T[m_maxSize];

			m_growSize = ((growBy > 0) ? growBy : 0);
		}
	}

	~OrderedArray()
	{
		if (m_array != NULL)
		{
			delete[] m_array;
			m_array = NULL;
		}
	}

	int push(T val)
	{
		assert(m_array != NULL);
		if (m_numElemets >= m_maxSize)
		{
			expand();
		}

		for (int i = 0; i < m_numElemets; i++)
		{
			if (m_array[i] > val)
			{
				break;
			}
		}

		for (int k = m_numElemets; k > i; k--)
		{
			m_array[k] = m_array[k - 1];
		}

		m_array[i] = val;
		m_numElemets++;

		return i;
	}

	void expand()
	{
		// create new T temp array 
		// perform a memcpy()
		// delete[] the data in m_array
		// assign new expanded array to m_array
	}

private:
	T *m_array;

	int m_maxSize;
	int m_numElemets;
	int m_growSize;
};