#include "Includes.h"

class BitArray
{
public:
	BitArray()
		: size(0)
	{
		for (int i = 0; i <= m_elements.size(); ++i)
		{
			m_elements.push_back(0);
		}
	}

	void SetBit(bool bitVal, int index)
	{
		if (index > m_elements.size())
		{
			for (int i = 0; i < m_elements.size(); ++i)
			{
				//if (m_elements[i] < 0 || m_elements[i] > )
			}
		}
	}
	
	void SetBit(bool bitVal)
	{
		
	}

private:
	int size;
	std::vector<bool> m_elements;
};