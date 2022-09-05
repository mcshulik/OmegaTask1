#include <iostream>
#include "nodeInt.h"
#include "nodeDouble.h"
#include "nodeChar.h"

int main()
{
    std::unique_ptr<Tree> root;

    int i = 1;
    while (i)
    {
        std::cout << "Choose an action" << std::endl << "0 - exit" << std::endl << "1 - add" << std::endl << "2 - output" << std::endl;
        std::cin >> i;
        if (!i)
            break;
        switch (i)
        {
        case 1:
        {
            Tree* node_temp = root.get();
            Tree* node_temp2 = root.get();
            int getBottom = 0;
            int index = 0;
            while (true)
            {
                std::cout << "1 - get bottom node" << std::endl << "2 - get next node" << std::endl;
                std::cin >> i;
                if (i == 1)
                {
                    getBottom++;
                    if (getBottom == 2)
                    {
                        getBottom--;
                        node_temp = node_temp2;
                    }
                    if (root.get() && root.get()->getNode(index))
                    {
                        node_temp2 = node_temp->getNode(index);
                        std::cout << "Node data:";
                        node_temp2->outputData();
                    }
                    std::cout << std::endl;
                    index++;
                }
                else if (i == 2)
                {
                    index++;
                    if (node_temp && node_temp->getNode(index))
                        node_temp = node_temp->getNode(index);
                    else index = 0;
                }
                else break;
            }
            std::cout << "Choose what to enter" << std::endl << "1 - integer" << std::endl << "2 - string" << std::endl << "3 - fractional" << std::endl;
            std::cin >> i;
            switch (i)
            {
            case 1:
            {
                int data;
                std::cout << "Enter integer" << std::endl;
                std::cin >> data;
                if (!root)
                    root = std::unique_ptr<NodeInt>(new NodeInt(data));
                else
                    node_temp2->addInt(std::move(data));
                break;
            }
            case 2:
            {
                char data[10];
                std::cout << "Enter string" << std::endl;
                std::cin >> data;
                if (!root)
                    root = std::unique_ptr<NodeChar>(new NodeChar(data));
                else
                    node_temp2->addChar(data);
                break;
            }
            case 3:
            {
                std::cout << "Enter fractional" << std::endl;
                double data;
                std::cin >> data;
                if (!root)
                    root = std::unique_ptr<NodeDouble>(new NodeDouble(data));
                else
                    node_temp2->addDouble(std::move(data));
                break;
            }
            }
            break;
            delete node_temp;
            delete node_temp2;
        }
        case 2:
        {
            if (!root.get())
                std::cout << "Tree is empty!" << std::endl;
            else
            {
                std::cout << "-----------------------------" << std::endl;
                root->outputAll(0);
                std::cout << "-----------------------------" << std::endl;
            }
            break;
        }
        }
    }
}
