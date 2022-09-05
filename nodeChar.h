#pragma once
#include "tree.h"

class NodeChar : public Tree
{
public:
	NodeChar(char data[10]);
	void addInt(int &&data) override;
	void addChar(char data[10]) override;
	void addDouble(double &&data) override;
	void outputAll(int level) override;
	void outputData() override;
	Tree* getNode(int index) override;
private:
	char data[10];
	std::vector<std::unique_ptr<Tree>> objects;
};
