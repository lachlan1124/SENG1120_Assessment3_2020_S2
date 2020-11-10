#include "BSTree.h"
#include <cstdarg>



template<typename valueType> BSTree<valueType>::BSTree() {size = 0;}

template<typename valueType> BSTree<valueType>::BSTree(valueType data) 
{
    root = new BTNode<valueType>(data);
    size = 1;
}

template<typename valueType> BSTree<valueType>::~BSTree() {}

template<typename valueType> void BSTree<valueType>::add(valueType data)
{
    if(size == 0)
        root = new BTNode<valueType>(data);
    else
    {
        bool inserting = true;

        current = root;

        while(inserting) // while inserting the data
        {
            if(current->getData() < data) // if the current is smaller then the data
            {
                if(current->isRightNULL()) // check if right is null
                {
                    BTNode<valueType>* tmp = new BTNode<valueType>(data);
                    current->setRight(tmp);
                    inserting = false; // end loop
                }
                else
                {
                    moveRight(); // if right has data move right
                }
                
            }
            else if(current->getData() > data) // if current is larger then the data
            {
                if(current->isLeftNULL()) // check if left is null
                {
                    BTNode<valueType>* tmp = new BTNode<valueType>(data);
                    current->setLeft(tmp); // if null, set left with data 
                    inserting = false; // end loop
                }
                else
                {
                    moveLeft(); // move left
                }
                
            }
        }
        
    }

    size++;
}

template<typename valueType> void BSTree<valueType>::moveRight()
{
    current = current->getRight();
}

template<typename valueType> void BSTree<valueType>::moveLeft()
{
    current = current->getLeft();
}

template<typename valueType> void BSTree<valueType>::moveUp()
{
    current = current->getLeft();
}

template<typename valueType> valueType BSTree<valueType>::getCurrent()
{
    return current->getData();
}

template<typename valueType> void BSTree<valueType>::inOrderTraversal(BTNode<valueType>* traversalRoot)
{
    if(traversalRoot != NULL)
    {
        inOrderTraversal(traversalRoot->getLeft());
        std::cout << traversalRoot->getData() << " "; 
        inOrderTraversal(traversalRoot->getRight());
    }

} 

template<typename valueType> valueType BSTree<valueType>::out()
{
    valueType output;
    // go to the bottom of the left sub tree

    current = root;
    inOrderTraversal(current);



    return output;
}


template<typename valueType> std::ostream& operator <<(std::ostream& os, BSTree<valueType> &p)
{
    os << p.out(); // get the cards and the value

    return os; // return the stream
}