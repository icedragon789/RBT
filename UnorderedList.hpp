//
// Created by benjp on 009, 5/9/2020.
//

#ifndef RBT_UNORDEREDLIST_HPP
#define RBT_UNORDEREDLIST_HPP


#define MAX_ELEMS 100

#include <iostream>
#include <string.h>

using namespace std;

template <typename N>
class UnorderedList{
public:
    virtual void MakeEmpty()=0;
    virtual void PutItem(N item)=0;
    virtual N GetItem(N item)=0;
    virtual void DeleteItem(N item)=0;
    virtual void ResetList()=0;
    virtual N GetNextItem()=0;
    virtual N GetLength()=0;
    virtual ~UnorderedList(){}

};



#endif //RBT_UNORDEREDLIST_HPP
