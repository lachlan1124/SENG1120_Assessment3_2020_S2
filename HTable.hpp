#include "HTable.h"

#include <cstdarg>
#include <iostream>
#include <string>
#include <sstream>

template<typename valueType> HTable<valueType>::HTable() {hashTable = new valueType[arraySize];size = 0;}

template<typename valueType> HTable<valueType>::HTable(valueType item)
{
    hashTable = new valueType[arraySize]; // create new array
    size = 0; // size = 0
    add(item); // add item
   
}

template<typename valueType> HTable<valueType>::~HTable() {delete[] hashTable;}

template<typename valueType> void HTable<valueType>::add(valueType toAdd)
{
    int toAddHash = hash(toAdd); // get hash of item to add

    hashTable[toAddHash] = toAdd; // add it

    size++;
}

template<typename valueType> void HTable<valueType>::remove(valueType toRemove)
{
    int toRemoveHash = hash(toRemove); //get hash of item to remove

    hashTable[toRemoveHash] = ""; // remove it

    size--;
}


template<typename valueType> void HTable<valueType>::operator+=( HTable<valueType>& tableAdd)
{
    std::stringstream ss;

    ss << tableAdd; // input the table into the stream

    while(ss) // while items left
    {
        valueType item;
        ss >> item; // stream next item into item

        if(item != "") // if empty item don't add
            add(item); // add item
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
    ss << toHash; // add int to string stream

    return hash(ss.str()); // return hash to other hash function
}

template<typename valueType> void HTable<valueType>::out(std::ostream& os)
{
    for(int i = 0; i < arraySize; i++) // for each item
        if(hashTable[i] != "") // if there is nothing in this spot don't print
            os << hashTable[i] << " "; // add to ostream
}

template<typename valueType> std::ostream& operator <<(std::ostream& os,  HTable<valueType> &p)
{
    p.out(os);
    return os; // return the stream
}
