#include "BSTree.h"

#include <iostream>

int main()
{
    BSTree<std::string> tree1;
    BSTree<std::string> tree2;

    BSTree<int> intTree;


    tree1.add("test");
    tree1.add("abc");
    tree1.add("Anothertest");
    tree1.add("zyx");
    tree1.add("r");


    std::cout << tree1 << std::endl;

    tree1.remove("zyx");
    tree1.remove("abc"); // appears to be working more tests need with pen and paper


    std::cout << tree1 << std::endl;


    /*
    TODO
    Overload += for BSTree
    Fix << overload for BSTree
    create HTable

    *\
}