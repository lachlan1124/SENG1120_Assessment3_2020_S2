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
	    
    std::cout << "1. Before remove: " << removeTest << std::endl;
    removeTest.remove("Jeff");
    
    std::cout << "1. After remove: " << removeTest << std::endl;


    std::cout << "TEST 2" << std::endl;

    removeTest.add("Jeff");
    removeTest.add("Alice");
    removeTest.add("Lachlan");
    removeTest.add("Beth");

    std::cout << "2. Before remove: " << removeTest << std::endl;

    removeTest.remove("Lachlan");
    std::cout << "2. After remove(Lachlan): " << removeTest << std::endl;

    removeTest.remove("Beth");
    std::cout << "2. After remove(Beth): " << removeTest << std::endl;

    removeTest.remove("Alice");
    std::cout << "2. After remove(Alice): " << removeTest << std::endl;

    removeTest.remove("Jeff");
    std::cout << "2. After remove: " << removeTest << std::endl;


    std::cout << "TEST 3" << std::endl;

    removeTest.add("Jeff");
    removeTest.add("Alice");
    removeTest.add("Lachlan");
    removeTest.add("Beth");
    removeTest.add("Kat");

    std::cout << "3. Before remove: " << removeTest << std::endl;

    removeTest.remove("Alice");
    std::cout << "3. After remove(Alice): " << removeTest << std::endl;

        removeTest.remove("Lachlan");
    std::cout << "3. After remove(Lachlan): " << removeTest << std::endl;

    removeTest.remove("Beth"); // causing seg fault
    removeTest.remove("Jeff");
    std::cout << "3. After remove(Beth & Jeff): " << removeTest << std::endl;

    removeTest.remove("Kat");

    std::cout << "3. After remove(all): " << removeTest << std::endl;

    /*
    TODO
    Overload += for BSTree
    create HTable

    */

}