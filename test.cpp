#include "BSTree.h"

#include <iostream>

int main()
{
    BSTree<std::string> tree1;
    BSTree<std::string> tree2;

    tree1.add("test");
    tree1.add("abc");
    tree1.add("zyx");

    std::cout << tree1 << std::endl;
}