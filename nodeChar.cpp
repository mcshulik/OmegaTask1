#include "nodeChar.h"
#include "nodeDouble.h"
#include "nodeInt.h"

NodeChar::NodeChar(char m_data[10])
{
	for (int i = 0; i < 10; i++)
		data[i] = m_data[i];
}

void NodeChar::outputAll(int level)
{
	for (int i = 0; i < level; i++)
		std::cout << " ";
	std::cout << data << std::endl;
	for (unsigned int i = 0; i < objects.size(); i++)
		objects[i].get()->outputAll(level + 1);
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

Tree* NodeChar::getNode(unsigned int index)
{
	if (index < objects.size() && objects.size() > 0)
		return objects[index].get();
	else return nullptr;
}

void NodeChar::writeToFile(std::ofstream& out, int level)
{
	out << 'c';
	out << level << ' ' << data << std::endl;
	for (unsigned int i = 0; i < objects.size(); i++)
	{
		objects[i].get()->writeToFile(out, level + 1);
	}
}
