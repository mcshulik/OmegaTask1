#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <iostream>

class Tree
{
public:
	virtual ~Tree() {}

	virtual void addInt(int &&data) = 0;
	virtual void addChar(char data[10]) = 0;
	virtual void addDouble(double &&data) = 0;
	virtual void outputAll(int level) = 0;
	virtual void outputData() = 0;
	virtual Tree* getNode(int index) = 0;
};
