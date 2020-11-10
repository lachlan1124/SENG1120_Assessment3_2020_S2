#include "BSTree.h"

#include <iostream>

int main()
{
    BSTree<std::string> tree1;
    BSTree<std::string> tree2;

    BSTree<int> intTree;


    tree1.add("test");
    tree1.add("abc");
    tree1.add("zyx");

    std::cout << tree1 << std::endl;

    intTree.add(1);
    intTree.add(2);
    intTree.add(3);
    intTree.add(4);
    intTree.add(5);

    std::cout << intTree << std::endl;
}