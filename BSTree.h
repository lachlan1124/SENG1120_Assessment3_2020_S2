#ifndef GAURD_ATREE
#define GAURD_ATREE

#include "BTNode.h"
#include <cstdarg>
#include <iostream>


template <typename valueType>
class BSTree
{
    public:

        BSTree();
        BSTree(valueType data);
        ~BSTree();

        void add(valueType data);
        void remove(valueType toRemove);

        void search(valueType toFind);

        void max();

        valueType out();
        void inOrderTraversal(BTNode<valueType>* traversalRoot);

    private:

    void moveRight();
    void moveLeft();

    
 
    valueType getCurrent();


    BTNode<valueType>* root;
    BTNode<valueType>* current;

    int size;

};

template <typename valueType>
std::ostream& operator <<(std::ostream& os, BSTree<valueType> &p);


#include "BSTree.hpp"

#endif