#include "HTable.h"

#include <cstdarg>
#include <iostream>
#include <string>
#include <sstream>

template<typename valueType> HTable<valueType>::HTable() {hashTable = new valueType[arraySize];size = 0;  std::cout << "Updated" << std::endl;}

template<typename valueType> HTable<valueType>::HTable(valueType item)
{
    hashTable = new valueType[arraySize];
    size = 0;
    add(item);
   
}

template<typename valueType> HTable<valueType>::~HTable() {delete[] hashTable;}

template<typename valueType> void HTable<valueType>::add(valueType toAdd)
{
    int toAddHash = hash(toAdd);

    hashTable[toAddHash] = toAdd;

    size++;
}

template<typename valueType> void HTable<valueType>::remove(valueType toRemove)
{
    int toRemoveHash = hash(toRemove);

    hashTable[toRemoveHash] = "";
}


template<typename valueType> void HTable<valueType>::operator+=( HTable<valueType>& hashTable)
{
    std::stringstream ss;

    ss << hashTable;

    while(ss)
    {
        valueType item;
        ss >> item;

        if(item != "")
            add(item);
    }
}

// A function used to hash strings
template<typename valueType> int HTable<valueType>::hash(std::string toHash)
{
    int hOut = 0; // stores the hash output
    // for each char in string
    for(int i = 0; i < toHash.length(); i++)
    {
        hOut += int(toHash.at(i)); // adds each char to the hash output
    }

    return hOut % arraySize;
}

// A function used to hash ints
template<typename valueType> int HTable<valueType>::hash(int toHash)
{
    std::stringstream ss;

    ss << toHash;

    return hash(ss.str());
}

template<typename valueType> void HTable<valueType>::out(std::ostream& os)
{
    for(int i = 0; i < arraySize; i++)
        if(hashTable[i] != "")
            os << hashTable[i] << " ";
}

template<typename valueType> std::ostream& operator <<(std::ostream& os,  HTable<valueType> &p)
{
    p.out(os);
    return os; // return the stream
}
