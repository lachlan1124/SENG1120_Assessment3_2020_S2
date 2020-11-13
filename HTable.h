#ifndef GAURD_HTABLE
#define GAURD_HTABLE

#include <iostream>

template<typename valueType>
class HTable
{
    public:
        HTable();
        HTable(valueType item);
        ~HTable();

        void add(valueType toAdd);

        void remove(valueType toRemove);

        void out(std::ostream& os);

        void operator += ( HTable<valueType>& BST);


    private:
    int hash(std::string toHash);
    int hash(int toHash);

    valueType* hashTable;
    int const arraySize = 150; // the size of the array
    int size; // how many items are stored
     

};


template <typename valueType>
std::ostream& operator <<(std::ostream& os, HTable<valueType> &p);


#include "HTable.hpp"

#endif