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
        BSTree(const valueType data);
        ~BSTree();

        void add(const valueType data);
        void add(const valueType data, bool firstCall);

        void remove(const valueType toRemove);

        bool search(const valueType toFind);

        BTNode<valueType>* min(BTNode<valueType>* minRoot);

        void out(std::ostream& os);
        void inOrderTraversal(BTNode<valueType>* traversalRoot, std::ostream& os);

        void operator += (BSTree<valueType>& BST);

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