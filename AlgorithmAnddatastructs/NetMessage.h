#pragma once
#include "Includes.h"


class NetMessage
{
public:
	NetMessage() : m_priority(0), m_id(0) {}
	NetMessage(int p, int id) : m_priority(p), m_id(id) {}
	~NetMessage() {}

	int GetPriority() { return m_priority; }
	int GetID()		  { return m_id; }

	//////////////////////////////////////////////////////////////////////////
	// Overloaded Operators ////////
	//////////////////////////////////////////////////////////////////////////
	// Less than NetMessage compare
	bool operator < (NetMessage& m)
	{
		if (m_priority < m.GetPriority()) { return true; }
		else if (m_id < m.GetID())		  { return true; }
		return false;
	}

	// Greater than NetMessage compare
	bool operator >(NetMessage& m) { return *this > m; }

private:
	int m_priority;
	int m_id;
};


class ExtendedNetMessage : public NetMessage
{
	typedef NetMessage BASE;
public:
	ExtendedNetMessage() : m_id(0), m_priority(0) {}
	ExtendedNetMessage(int p, int id) : m_priority(p), m_id(id) {}
	~ExtendedNetMessage() {}

private:
	int m_id;
	int m_priority;
};