#pragma once
#include "tree.h"
#include "vector"

class NodeChar : public Tree
{
public:
	NodeChar(char data[10]);
	void addInt(int &&data) override;
	void addChar(char data[10]) override;
	void addDouble(double &&data) override;
	void outputAll(int level) override;
	void outputData() override;
	Tree* getNode(unsigned int index) override;
	void writeToFile(std::ofstream &out, int level) override;
private:
	char data[10];
	std::vector<std::unique_ptr<Tree>> objects;
};
