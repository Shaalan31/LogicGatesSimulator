#include "Component.h"
int Component::count = 0;
ComponentType Component::gettype()
{
	return type;
}
void Component::setGraphicsInfo(int x1, int y1, int x2, int y2)
{
	m_GfxInfo.x1 = x1;
	m_GfxInfo.x2 = x2;
	m_GfxInfo.y1 = y1;
	m_GfxInfo.y2 = y2;
	
}

bool Component::Inside(int x, int y)
{
	if ((x >= m_GfxInfo.x1) && (y >= m_GfxInfo.y1) && (x <= m_GfxInfo.x2 && (y <= m_GfxInfo.y2)))
	{
		return true;
	}
	return false;
}

bool Component::getcopy()
{
	return copycheck;
}

bool Component::getcut()
{
	return cutcheck;
}

bool Component::getselected()
{
	return selected;
}

bool Component::getmarked()
{
	return marked;
}

void Component::setcopy(bool x)
{
	copycheck = x;
}

void Component::setcut(bool x)
{
	cutcheck = x;
}

void Component::setmarked(bool x)
{
	marked = x;
}

void Component::setselected(bool x)
{
	selected = x;
}

Component::Component(const GraphicsInfo &r_GfxInfo)
{
	m_GfxInfo = r_GfxInfo;	
	ID = count++;
}

Component::Component()
{
	ID = count++;
}

Component::~Component()
{}

bool Component::checkEmpty(int x, int y, GraphicsInfo GI)
{
	int xleftdown = x - 25;
	int xleftup = x - 25;
	int xrightdown = x + 25;
	int xrightup = x + 25;
	int yleftdown = y - 25;
	int yleftup = y + 25;
	int yrightdown = y - 25;
	int yrightup = y + 25;
	if ((xleftdown >= GI.x1 && xleftdown <= GI.x2 && yleftdown >= GI.y1 && yleftdown <= GI.y2) || (xleftup >= GI.x1 && xleftup <= GI.x2 && yleftup >= GI.y1 && yleftup <= GI.y2) || (xrightdown >= GI.x1 && xrightdown <= GI.x2 && yrightdown >= GI.y1 && yrightdown <= GI.y2) || (xrightdown >= GI.x1 && xrightdown <= GI.x2 && yrightdown >= GI.y1 && yrightdown <= GI.y2))
		return false;
	return true;
}

GraphicsInfo  Component::getGraphics()
{
	return m_GfxInfo;
}

void Component::setConnection(Connection * Con)
{
	InputConnection = Con;
}

Connection* Component::getConnection()
{
	return InputConnection;
}


void Component::setLabel(string name)
{
	m_Label = name;
}

bool Component::inside(int x, int y)
{
	if (m_GfxInfo.x1<x && m_GfxInfo.x2>x && m_GfxInfo.y1<y && m_GfxInfo.y2>y)
		return 1;
	return 0;
}


int Component::getID()
{
	return ID;
}

string Component::getLabel()
{
	return m_Label;
}

void Component::setID(int x)
{
	ID = x;
}
