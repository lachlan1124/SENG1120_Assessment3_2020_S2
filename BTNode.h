#ifndef GAURD_BTNODE
#define GAURD_BTNODE

#include <iostream>

template<typename valueType>
class BTNode
{

    public:

    BTNode(valueType nData, BTNode* nLeft = NULL, BTNode* nRight = NULL, BTNode* nParent = NULL);
    ~BTNode();

    valueType getData();

    bool isRightNULL();
    bool isLeftNULL();

    BTNode* getRight();
    BTNode* getLeft();
    BTNode* getParent();

    void setRight(BTNode* nRight);
    void setLeft(BTNode* nLeft);
    void setParent(BTNode* nParent);
    void setData(valueType nData);
    private:
    
    BTNode* left;
    BTNode* right;
    BTNode* parent;

    valueType data;



};

#include "BTNode.hpp"

#endif