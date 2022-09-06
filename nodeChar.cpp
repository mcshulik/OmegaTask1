#include "nodechar.h"
#include "nodedouble.h"
#include "nodeint.h"

NodeChar::NodeChar(char m_data[10])
{
	for (int i = 0; i < 10; i++)
		data[i] = m_data[i];
}

void NodeChar::outputAll(int level)
{
	for (unsigned int i = 0; i < objects.size(); i++)
	{
		objects[i].get()->outputAll(level + 1);
	}
	for (int i = 0; i < level; i++)
		std::cout << " ";
	std::cout << data << std::endl;
}

void NodeChar::addInt(int &&data)
{
	std::unique_ptr<Tree> ptr(new NodeInt(data));
	objects.push_back(std::move(ptr));
}

void NodeChar::addChar(char data[10])
{
	std::unique_ptr<Tree> ptr(new NodeChar(data));
	objects.push_back(std::move(ptr));
}

void NodeChar::addDouble(double &&data)
{
	std::unique_ptr<Tree> ptr(new NodeDouble(data));
	objects.push_back(std::move(ptr));
}

void NodeChar::outputData()
{
	std::cout << data;
}

Tree* NodeChar::getNode(int index)
{
	if (index < objects.size() && objects.size() > 0)
		return objects[index].get();
	else return nullptr;
}
