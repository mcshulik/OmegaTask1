#pragma once
#include <iostream>
#include <fstream>

class Tree
{
public:
	virtual ~Tree() {}
	virtual void addInt(int &&data) = 0;
	virtual void addChar(char data[10]) = 0;
	virtual void addDouble(double &&data) = 0;
	virtual void outputAll(int level) = 0;
	virtual void outputData() = 0;
	virtual Tree* getNode(unsigned int index) = 0;
	virtual void writeToFile(std::ofstream &out, int level) = 0;
	std::unique_ptr<Tree> ReadFromFile(std::ifstream &in);
};
