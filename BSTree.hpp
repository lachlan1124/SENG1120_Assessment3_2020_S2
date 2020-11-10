#include "BSTree.h"
#include "BTNode.h"
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
                    tmp->setParent(current); // set the new node parent to current
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
                    tmp->setParent(current); // set the new node parent to current
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


template<typename valueType> valueType BSTree<valueType>::getCurrent()
{
    return current->getData();
}

template<typename valueType> void BSTree<valueType>::search(valueType toFind)
{

    if(current->getData() > toFind)
    {
        moveLeft();
        search(toFind);

    }
    else if(current->getData() < toFind)
    {
        moveRight();
        search(toFind);
    }
}

template<typename valueType> void BSTree<valueType>::max()
{
    if(current->getRight() != NULL)
    {
        moveRight();
        max();
    }   
}


template<typename valueType> void BSTree<valueType>::remove(valueType toRemove)
{
    current = root;
    search(toRemove);

    int childCount = 0;

    if(current->getLeft() != NULL)
         childCount++;
    if(current->getRight() != NULL)
        childCount++;
    
    if(childCount == 0) // if the node has no children
    {
        BTNode<valueType>* nodeToRemove = current; // stores the node being delete
 
        current = current->getParent(); // move the current up

        if(current->getLeft() == nodeToRemove) // is node to remove left
        {  
            current->setLeft(NULL); // set left to NULL
        }
        else if(current->getRight() == nodeToRemove) // is node to remove right
        {
            current->setRight(NULL); // set right to NULL
        }

    
        delete nodeToRemove; // delete node
    }

    if(childCount == 1)
    {
        BTNode<valueType>* child;
        // find the child
        if(current->getLeft() != NULL) // child is left
            child = current->getLeft();
        else if(current->getRight() != NULL) // child is right
            child = current->getRight();

        BTNode<valueType>* nodeToRemove = current; // stores the node being delete
 
        current = current->getParent(); // move the current up

        if(current->getLeft() == nodeToRemove) // is node to remove left
        {  
            current->setLeft(child); // set left to child
        }
        else if(current->getRight() == nodeToRemove) // is node to remove right
        {
            current->setRight(child); // set right to child
        }

    
        delete nodeToRemove; // delete node

    }

    if(childCount == 2)
    {
        BTNode<valueType>* nodeToRemove = current; // stores the node being delete

        moveLeft(); // set current to the left

        max(); // find the max from the current

       current->setRight(nodeToRemove->getRight());
        current->getParent()->setRight(NULL); // remove current from tree
       

       // is node delete on left or right?
        if(nodeToRemove->getParent()->getRight() == nodeToRemove) 
            nodeToRemove->getParent()->setRight(current); // set parent right to current
        else if(nodeToRemove->getParent()->getLeft() == nodeToRemove)
            nodeToRemove->getParent()->setLeft(current); // set parent left to current
        


        current->setParent(nodeToRemove->getParent()); // set current parent to remove parent
        
        delete nodeToRemove;
    }

    size--;

}

// CHANGE THIS PASS OS TO THIS FUNCTION
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
   // p.out(os); LIKE THIS NOT LIKE BELOW
    os << p.out(); // get the cards and the value

    return os; // return the stream
}