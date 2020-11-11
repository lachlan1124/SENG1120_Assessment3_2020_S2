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

    tree1.remove("zyx");
    tree1.remove("abc"); // appears to be working more tests need with pen and paper


    std::cout << tree1 << std::endl;

    tree2.add("apple");
    tree2.add("bananana");
    tree2.add("manago");

    std::cout << tree2 << std::endl;

    tree1 += tree2;

    std::cout << tree1 << std::endl;

	clock_t t;
	BSTree<std::string> treeValues;
	BSTree<std::string> treeAux;

	std::string vectorStudents1[] = {"Alex", "John", "Mary", "Peter" , "Miranda" , "Claudia" , "Sandy" , "Daniel" , "Rick" , "Patricia" , "Adam" , "Bianca" , "Nadia", "Sylvia", "Pamela"};
	std::string vectorStudents2[] = {"Travis", "Michelle", "Steve", "Phil", "Hugh", "Oliver", "Kate", "Tim", "David", "Ingrid", "Tom", "Fred", "Bill"};
	
	int numberOfElements1 = 15;
	int numberOfElements2 = 13;
	
	cout << "==================" << endl << "BINARY SEARCH TREE" << endl;
	t = clock(); 																	// gets current time
	for (int i=0; i<numberOfElements1; i++) {treeValues.add(vectorStudents1[i]);} 	// populates the main tree.
	for (int i=0; i<numberOfElements2; i++) {treeAux.add(vectorStudents2[i]);} 		// populates the auxiliary tree ***THIS LINE HAS BEEN CORRECTED****
    	
	treeValues += treeAux; 															// tests overloaded += concatenation operator
	
	cout << "Initial tree: " << treeValues << std::endl; 								// prints the contents of the tree.

    for (int i=0; i<500000; i++)													// add and remove over and over again
    { 								
       	treeValues.remove("Alex");
		treeValues.remove("Peter");
		treeValues.remove("John");
		treeValues.remove("Pamela");
		treeValues.remove("Kate");
		treeValues.remove("Tim");
		treeValues.remove("Steve");
		treeValues.remove("Rick");
		treeValues.remove("Sam");
        treeValues.add("Alex");
		treeValues.add("Peter");
		treeValues.add("John");
		treeValues.add("Pamela");
		treeValues.add("Kate");
		treeValues.add("Tim");
		treeValues.add("Steve");
		treeValues.add("Rick");
	}
	cout << "Final tree  : " << treeValues << std::endl << std::endl; 						// prints the contents of the tree.
	cout << "Time elapsed: " << (clock() - t)/1000.0 << " seconds" << std::endl; 		// prints elapsed time.
	cout << "Time per ins/del operation: " << 1000.0*(double)(clock() - t)/(double)(500000*17) << " milliseconds." << std::endl << std::endl;





    /*
    TODO
    Overload += for BSTree
    create HTable

    */

}