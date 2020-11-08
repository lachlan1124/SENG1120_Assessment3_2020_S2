#ifndef GAURD_BTNODE
#define GAURD_BTNODE

#include <iostream>

template<typename valueType>
class BTNode
{

    public:

    BTNode(valueType nData, BTNode* nLeft = NULL, BTNode* nRight = NULL);
    ~BTNode();

    valueType getData();

    bool isRightNULL();
    bool isLeftNULL();

    BTNode* getRight();
    BTNode* getLeft();

    void setRight(BTNode* nRight);
    void setLeft(BTNode* nLeft);
    
    private:
    
    BTNode* left;
    BTNode* right;

    valueType data;


};

#include "BTNode.hpp"

#endif