#include "BSTree.h"

#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

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


    tree2.add("apple");
    tree2.add("bananana");
    tree2.add("manago");

    std::cout << tree2 << std::endl;

    tree1 += tree2;

    std::cout << tree1 << std::endl;


    std::cout << "=================================================================================================================" << endl << "REMOVE TEST" << endl << "=================================================================================================================" << endl;


    BSTree<string> removeTest;

    removeTest.add("Jeff");
    removeTest.remove("Jeff");
    
    std::cout << removeTest << std::endl;



    /*
    TODO
    Overload += for BSTree
    create HTable

    */

}