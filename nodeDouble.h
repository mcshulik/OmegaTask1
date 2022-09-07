#pragma once
#include "tree.h"
#include "vector"

class NodeDouble : public Tree
{
public:
	NodeDouble(double data) : data(data) {}
	void addInt(int &&data) override;
	void addChar(char data[10]) override;
	void addDouble(double &&data) override;
	void outputAll(int level) override;
	void outputData() override;
	Tree* getNode(unsigned int index) override;
	void writeToFile(std::ofstream& out, int level) override;
private:
	double data;
	std::vector<std::unique_ptr<Tree>> objects;
};
