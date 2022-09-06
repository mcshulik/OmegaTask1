#include <iostream>
#include "nodeInt.h"
#include "nodeDouble.h"
#include "nodeChar.h"
#include <windows.h>

int main()
{
    std::unique_ptr<Tree> root;
    int i;
    srand(time(nullptr));

    std::cout << "1 - random" << std::endl;
    std::cin >> i;
    if (i == 1)
    {
        std::cout << "Enter the number of elements" << std::endl;
        int elementsQuantity;
        std::cin >> elementsQuantity;
        for (int i2 = 0; i2 < elementsQuantity; i2++)
        {
            i = 1;
            Tree* nodeTemp = root.get();
            Tree* nodeTemp2 = root.get();
            int getBottom = 0;
            int index = 0;
            while (true)
            {
                i = rand() % 3 + 1;
                if (i == 1)
                {
                    getBottom++;
                    if (getBottom == 2)
                    {
                        getBottom--;
                        nodeTemp = nodeTemp2;
                    }
                    if (nodeTemp && nodeTemp->getNode(index))
                        nodeTemp2 = nodeTemp->getNode(index);
                    index++;
                }
                else if (i == 2)
                {
                    index++;
                    if (nodeTemp && nodeTemp->getNode(index))
                        nodeTemp = nodeTemp->getNode(index);
                    else index = 0;
                }
                else break;
            }
            i = rand() % 3 + 1;
            switch (i)
            {
            case 1:
            {
                int data;
                data = rand();
                if (!root)
                    root = std::unique_ptr<NodeInt>(new NodeInt(data));
                else
                    nodeTemp2->addInt(std::move(data));
                break;
            }
            case 2:
            {
                char data[10];
                for (int i3 = 0; i3 < 9; i3++)
                    data[i3] = rand() % 93 + 33;
                data[9] = '\0';
                if (!root)
                    root = std::unique_ptr<NodeChar>(new NodeChar(data));
                else
                    nodeTemp2->addChar(data);
                break;
            }
            case 3:
            {
                double data;
                data = (double)rand() / (double)rand();
                if (!root)
                    root = std::unique_ptr<NodeDouble>(new NodeDouble(data));
                else
                    nodeTemp2->addDouble(std::move(data));
                break;
            }
            }
        }
        if (!root.get())
            std::cout << "Tree is empty!" << std::endl;
        else
        {
            std::cout << "-----------------------------" << std::endl;
            root->outputAll(0);
            std::cout << "-----------------------------" << std::endl;
        }
    }
    else
    {
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
                Tree* nodeTemp = root.get();
                Tree* nodeTemp2 = root.get();
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
                            nodeTemp = nodeTemp2;
                        }
                        if (root.get() && root.get()->getNode(index))
                        {
                            nodeTemp2 = nodeTemp->getNode(index);
                            std::cout << "Node data:";
                            nodeTemp2->outputData();
                        }
                        std::cout << std::endl;
                        index++;
                    }
                    else if (i == 2)
                    {
                        index++;
                        if (nodeTemp && nodeTemp->getNode(index))
                            nodeTemp = nodeTemp->getNode(index);
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
                        nodeTemp2->addInt(std::move(data));
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
                        nodeTemp2->addChar(data);
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
                        nodeTemp2->addDouble(std::move(data));
                    break;
                }
                }
                break;
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
}
