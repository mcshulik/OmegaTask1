#include "nodeChar.h"
#include "nodeDouble.h"
#include "nodeInt.h"

void NodeInt::outputAll(int level)
{
	for (int i = 0; i < level; i++)
		std::cout << " ";
	std::cout << data << std::endl;
	for (unsigned int i = 0; i < objects.size(); i++)
		objects[i].get()->outputAll(level + 1);
}

void NodeInt::addInt(int &&data)
{
	std::unique_ptr<Tree> ptr(new NodeInt(data));
	objects.push_back(std::move(ptr));
}

void NodeInt::addChar(char data[10])
{
	std::unique_ptr<Tree> ptr(new NodeChar(data));
	objects.push_back(std::move(ptr));
}

void NodeInt::addDouble(double &&data)
{
	std::unique_ptr<Tree> ptr(new NodeDouble(data));
	objects.push_back(std::move(ptr));
}

void NodeInt::outputData()
{
	std::cout << data;
}

Tree* NodeInt::getNode(unsigned int index)
{
	if (index < objects.size() && objects.size() > 0)
		return objects[index].get();
	else return nullptr;
}

void NodeInt::writeToFile(std::ofstream& out, int level)
{
	out << 'i';
	out << level << ' ' << data << std::endl;
	for (unsigned int i = 0; i < objects.size(); i++)
	{
		objects[i].get()->writeToFile(out, level + 1);
	}
}
