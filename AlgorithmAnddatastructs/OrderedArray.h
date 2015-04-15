#pragma once
#include "Includes.h"

template<typename T>
class OrderedArray
{
public:
	OrderedArray(int size, int growBy = 1) :
		m_array(NULL), 
		m_maxSize(0), 
		m_numElemets(0),
		m_growSize(0)
	{
		if (size)
		{
			m_maxSize = size;
			m_array = new T[m_maxSize];
			memset( m_array, 0, sizeof(T)* m_maxSize );

			m_growSize = ((growBy > 0) ? growBy : 0);
		}
	}


	virtual ~OrderedArray()
	{
		if (m_array != NULL)
		{
			delete[] m_array;
			m_array = NULL;
		}
	}

	virtual T& operator[]( int index )
	{
		assert( m_array != NULL );
		return m_array[index];
	}
	
	virtual bool operator==(const T* paramArray)
	{
		return paramArray == m_array;
	}

	virtual void operator=(T& assignArray)
	{
		delete[] m_array;
		m_array = &assignArray;
	}

	int capacity()		{ return m_numElemets; }
	int GetSize()		{ return m_numElemets; }
	int GetMaxSize()	{ return m_maxSize; }
	int GetGrowSize()	{ return m_growSize; }
	void clear()		{ m_numElemets = 0; }

	int push(T val)
	{
		assert(m_array != NULL);
		if (m_numElemets >= m_maxSize)
		{
			expand();
		}

		for ( int i = 0; i < m_numElemets; i++ )
		{
			if (m_array[i] > val)
			{
				break;
			}
		}

		for (int k = m_numElemets; k > 0; k--)
		{
			m_array[k] = m_array[k - 1];
		}

		m_array[m_numElemets] = val;
		m_numElemets++;

		return m_numElemets;
	}

	void pop()
	{
		if ( m_numElemets > 0 )
		{
			m_numElemets--;
		}
	}

	void remove( int index )
	{
		assert( m_array != NULL );
		if ( index >= m_maxSize )
		{
			return;
		}

		for ( int k = index; k < m_maxSize - 1; k++ )
		{
			m_array[k] = m_array[k + 1];
		}

		m_maxSize--;

		if ( m_numElemets >= m_maxSize )
		{
			m_numElemets = maxSize - 1;
		}
	}


	bool expand()
	{
		if ( m_growSize <= 0 ) return false;
		T* temp = new T[m_maxSize + m_growSize];
		assert(temp != NULL);

		memcpy( temp, m_array, sizeof(T)* m_maxSize );

		delete[] m_array;
		m_array = temp;

		m_maxSize += m_growSize;
		return true;
	}

	int search(T searchKey)
	{
		if ( !m_array )
		{
			return -1;
		}

		int lowerBound = 0;
		int upperBound = m_numElemets - 1;
		int current = 0;

		while ( 1 )
		{
			/*
			 * This is devinding by two, but with bit math and there is
			 * no remainder, also, once a bit has been shifted off the 
			 * end, there is no recovering it. 
			 */
			current = (lowerBound + upperBound) >> 1;

			if ( m_array[current] == searchKey )
			{
				return current;
			}
			else if ( lowerBound > upperBound )
			{
				return -1;
			}
			else
			{
				if ( m_array[current] < searchKey)
				{
					lowerBound = current + 1;
				}
				else
				{
					upperBound = current - 1;
				}
			}
			return -1;
		}
	}

private:
	T *m_array;

	int m_maxSize;
	int m_numElemets;
	int m_growSize;
};