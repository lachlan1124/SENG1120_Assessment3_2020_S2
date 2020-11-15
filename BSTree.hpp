#include "BSTree.h"
#include "BTNode.h"

#include <cstdarg>
#include <iostream>
#include <string>
#include <sstream>

template<typename valueType> BSTree<valueType>::BSTree() {size = 0; root = NULL; current = NULL;}

template<typename valueType> BSTree<valueType>::BSTree(const valueType data) 
{
    root = new BTNode<valueType>(data);
    size = 1;
    current = root;
}

template<typename valueType> BSTree<valueType>::~BSTree() 
{
    while(root !=NULL) // while items left in BST
        remove(root->getData()); // remove item


}

template<typename valueType> void BSTree<valueType>::add(const valueType data)
{
    if(size == 0) // if first item
    {
        root = new BTNode<valueType>(data); // create the root
        current = root; // set current to root
    }
    else
    {

        if(current->getData() < data) // if the current is smaller then the data
        {
            if(current->isRightNULL()) // check if right is null
            {
                BTNode<valueType>* tmp = new BTNode<valueType>(data);
                current->setRight(tmp);
                tmp->setParent(current); // set the new node parent to current
            }
            else
            {
                moveRight(); // if right has data move right
                add(data);  // recursive call to add
            }
            
        }
        else if(current->getData() > data) // if current is larger then the data
        {
            if(current->isLeftNULL()) // check if left is null
            {
                BTNode<valueType>* tmp = new BTNode<valueType>(data);
                current->setLeft(tmp); // if null, set left with data 
                tmp->setParent(current); // set the new node parent to current
            }
            else
            {
                moveLeft(); // move left
                add(data); // recursive call to add
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

template<typename valueType> bool BSTree<valueType>::search(const valueType toFind)
{
    if(current != NULL) // if current isn't NULL
    {
        if(current->getData() == toFind) // if current is the data return true
            return true;
        else if(current->getData() > toFind) // else if the data is greater then toFind
        {
            moveLeft(); // move left
            if(!search(toFind)) // recurive call toFind
                return false;
            else
                return true;
            
        }
        else if(current->getData() < toFind) // if smaller 
        {
            moveRight(); // move right 
            if(!search(toFind))  // recurive call toFind
                return false;
            else
                return true;
        }
        
    }
    else // if not found
    {
        return false;
    }
}

//finds the min value from the given node
template<typename valueType> BTNode<valueType>* BSTree<valueType>::min(BTNode<valueType>* minRoot)
{
    if(minRoot->getLeft() != NULL) // if left is not NULL
    {
        minRoot = minRoot->getLeft(); // move root left
        min(minRoot); // call minRoot
    }
    else
    {
        return minRoot; // return the min value
    }
}


template<typename valueType> void BSTree<valueType>::remove(const valueType toRemove)
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

template<typename valueType> void BSTree<valueType>::inOrderTraversal(BTNode<valueType>* traversalRoot, std::ostream& os)
{
    if(traversalRoot != NULL) // if the root is not NULL
    {
        inOrderTraversal(traversalRoot->getLeft(), os); // traverse left
        os <<  traversalRoot->getData() << " ";  // add data to the ostream
        inOrderTraversal(traversalRoot->getRight(), os); // traverse right
    }

} 

template<typename valueType> void BSTree<valueType>::out(std::ostream& os)
{
    current = root; // set the current to root
    inOrderTraversal(current, os); // call inOrderTraversal
}

template<typename valueType> void BSTree<valueType>::operator+=(BSTree<valueType>& BST)
{
    current = root;

    std::stringstream ss;

    ss << BST; // stream data into ss

    while(ss) // while stuff left
    {
        valueType item;

        ss >> item; // get item from string stream

        if(item != "") // don't add empty items
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

