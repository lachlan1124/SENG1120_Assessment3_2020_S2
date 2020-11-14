#include "BSTree.h"
#include "BTNode.h"

#include <cstdarg>
#include <iostream>
#include <string>
#include <sstream>

template<typename valueType> BSTree<valueType>::BSTree() {size = 0; root = NULL; current = NULL;}

template<typename valueType> BSTree<valueType>::BSTree(valueType data) 
{
    root = new BTNode<valueType>(data);
    size = 1;
    current = root;
}

template<typename valueType> BSTree<valueType>::~BSTree() 
{
    while(root !=NULL)
        remove(root->getData());
}

template<typename valueType> void BSTree<valueType>::add(valueType data)
{
    if(size == 0)
    {
        root = new BTNode<valueType>(data);
        current = root;
    }
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
            else if(current->getData() == data) { inserting = false;}

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

template<typename valueType> bool BSTree<valueType>::search(valueType toFind)
{
    if(current != NULL)
    {
        if(current->getData() == toFind)
            return true;
        else if(current->getData() > toFind)
        {
            moveLeft();
            if(!search(toFind))
                return false;
            else
                return true;
            
        }
        else if(current->getData() < toFind)
        {
            moveRight();
            if(!search(toFind))
                return false;
            else
                return true;
        }
        
    }
    else
    {
        return false;
    }
}

template<typename valueType> BTNode<valueType>* BSTree<valueType>::min(BTNode<valueType>* minRoot)
{
    if(minRoot->getLeft() != NULL)
    {
        minRoot = minRoot->getLeft();
        min(minRoot);
    }
    else
    {
        return minRoot;
    }
}


template<typename valueType> void BSTree<valueType>::remove(valueType toRemove)
{
    if(search(toRemove)) // set current to the item being removed and check if the iteam is in the tree
    {
        int childCount = 0;
        bool isRoot = false;

        if (current->getParent() == NULL) // if parent equals Null then node is root
            isRoot = true;

        if (current->getLeft() != NULL)
            childCount++; // count the child
        
        if (current->getRight() != NULL)
            childCount++; // count the child

        switch (childCount)
        {
        case 0: // if the item has no children
            if(isRoot) // if is root
            {
                root = NULL;
            }
            else
            {
                if(current->getParent()->getRight() == current) // if on the right
                {
                    current->getParent()->setRight(NULL); // set parent right to NULL
                }
                else if(current->getParent()->getLeft() == current) // if on the left
                {   
                    current->getParent()->setLeft(NULL); // set parent left to NULL
                }  
            }

            delete current; // delete item
            current = root;
            size--;
            
            break;
        case 1: // if item has one child
            if(isRoot)
            {
                // change the root to the new root
                if(root->getLeft() != NULL)
                    root = root->getLeft();
                else if(root->getRight() != NULL)
                    root = root->getRight();

                root->setParent(NULL); // set the new root parent to NULL

            }
            else if (current->getParent()->getLeft() == current) // if on the left
            {
                // set the parents left to the new left
                if(current->getLeft() != NULL)
                    current->getParent()->setLeft(current->getLeft());
                else if (current->getRight() != NULL)
                    current->getParent()->setLeft(current->getRight());

                // point parents left to parent
                current->getParent()->getLeft()->setParent(current->getParent());
            }
            else if (current->getParent()->getRight() == current) // if on the right
            {
                // set the parents right to the new Right
                if(current->getLeft() != NULL)
                    current->getParent()->setRight(current->getLeft());
                else if (current->getRight() != NULL)
                    current->getParent()->setRight(current->getRight());

                // point parents left to parent
                current->getParent()->getRight()->setParent(current->getParent());
            }
            
            delete current; // delete item
            current = root;
            size--;

            break;

        case 2: // if item has two children
            
            BTNode<valueType>* nodeToRemove = current;
            valueType data = min(current->getRight())->getData(); // find the min in the right side of the node to delete
            remove(data);
            nodeToRemove->setData(data);
            break;
        }


    }
       
}

// CHANGE THIS PASS OS TO THIS FUNCTION
template<typename valueType> void BSTree<valueType>::inOrderTraversal(BTNode<valueType>* traversalRoot, std::ostream& os)
{
    if(traversalRoot != NULL)
    {
        inOrderTraversal(traversalRoot->getLeft(), os);
        os <<  traversalRoot->getData() << " "; 
        inOrderTraversal(traversalRoot->getRight(), os);
    }

} 

template<typename valueType> void BSTree<valueType>::out(std::ostream& os)
{
    current = root;
    inOrderTraversal(current, os);
}

template<typename valueType> void BSTree<valueType>::operator+=( BSTree<valueType>& BST)
{
 

    std::stringstream ss;

    ss << BST; // stream data into ss

    while(ss) // while stuff left
    {
        valueType item;

        ss >> item;
        if(item != "")
        {
            add(item); // add items
        }

    }


}

template<typename valueType> std::ostream& operator <<(std::ostream& os, BSTree<valueType> &p)
{
    p.out(os);
    return os; // return the stream
}

