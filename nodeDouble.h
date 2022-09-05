#pragma once
#include "tree.h"

class NodeDouble : public Tree
{
public:
	NodeDouble(double data) : data(data) {}
	void addInt(int &&data) override;
	void addChar(char data[10]) override;
	void addDouble(double &&data) override;
	void outputAll(int level) override;
	void outputData() override;
	Tree* getNode(int index) override;
private:
	double data;
	std::vector<std::unique_ptr<Tree>> objects;
};
