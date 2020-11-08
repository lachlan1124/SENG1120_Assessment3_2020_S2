#include "BTNode.h"

template<typename valueType> BTNode<valueType>::BTNode(valueType nData, BTNode* nLeft, BTNode* nRight)
{
    data = nData;
    left = nLeft;
    right = nRight;
}

template<typename valueType> BTNode<valueType>::~BTNode() {}

template<typename valueType> valueType BTNode<valueType>::getData()
{
    return data;
}

template<typename valueType> bool BTNode<valueType>::isRightNULL()
{
    if(right == NULL)
    {
        return true; 
    }
    else
    {
        return false;
    }
    
}

template<typename valueType> bool BTNode<valueType>::isLeftNULL()
{
    if(left == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

template<typename valueType> BTNode<valueType>* BTNode<valueType>::getRight()
{
    return right;
}

template<typename valueType> BTNode<valueType>* BTNode<valueType>::getLeft()
{
    return left;
}

template<typename valueType> void BTNode<valueType>::setRight(BTNode* nRight)
{
    right = nRight;
}

template<typename valueType> void BTNode<valueType>::setLeft(BTNode* nLeft)
{
    left = nLeft;
}