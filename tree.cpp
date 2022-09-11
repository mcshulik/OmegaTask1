#include "tree.h"
#include "nodeChar.h"
#include "nodeInt.h"
#include "nodeDouble.h"

std::unique_ptr<Tree> Tree::ReadFromFile(std::ifstream& in)
{
    std::unique_ptr<Tree> root;
    int getBottom = 0;
    char firstChar = 0;
    Tree* nodeTemp;
	while (true)
	{
        if (root)
        {
            system("cls");
            std::cout << "-----------------------------" << std::endl;
            root->outputAll(0);
            std::cout << "-----------------------------" << std::endl;
        }
        nodeTemp = root.get();
        getBottom = 0;
        in >> firstChar;
        if(!in)
            break;
        in >> getBottom;
        for(int i = 0; i < getBottom - 1; i++)
        {
            for (int index = 0; ; index++)
            {
                if (!nodeTemp->getNode(index))
                {
                    nodeTemp = nodeTemp->getNode(index - 1);
                    break;
                }
            }
        }
		switch (firstChar)
		{
		case 'i':
		{
			int data;
			in >> data;
            if(!root)
                root = std::unique_ptr<NodeInt>(new NodeInt(data));
            else
                nodeTemp->addInt(std::move(data));
            break;
		}
        case 'c':
        {
            char data[10];
            in >> data;
            if (!root)
                root = std::unique_ptr<NodeChar>(new NodeChar(data));
            else
                nodeTemp->addChar(std::move(data));
            break;
        }
        case 'd':
        {
            double data;
            in >> data;
            if (!root)
                root = std::unique_ptr<NodeDouble>(new NodeDouble(data));
            else
                nodeTemp->addDouble(std::move(data));
            break;
        }
		}
	}
    return root;
}
