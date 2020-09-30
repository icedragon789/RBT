//
//  UnorderedLinkedList.hpp
//  UList
//
//  Created by Eugene Lymar on 1/30/18.
//  Copyright © 2020 Eugene Lymar. All rights reserved.
//

#ifndef RBT_UNORDEREDLINKEDLIST_HPP
#define RBT_UNORDEREDLINKEDLIST_HPP

#include <iostream>
#include <string>
#include "UnorderedList.hpp"
#include "Node.hpp"

template <typename N>
class UnorderedLinkedList : public UnorderedList<N>{
private:
    int length;
    Node<N> *currentPos;
    Node<N> *head;

public:
    UnorderedLinkedList() : currentPos{nullptr}, head{nullptr}, length{0} {}
    void MakeEmpty();
    void PutItem(N item);
    N GetItem(N item);
    void DeleteItem(N item);
    void ResetList();
    N GetNextItem();
    N GetLength();
    ~UnorderedLinkedList();

};

template <typename N>
std::ostream& operator<<(std::ostream& os, UnorderedLinkedList<N>& o){
    o.ResetList();
    os << "List: [";
    for(int i = 0; i < o.GetLength(); ++i){
        os << "(" << o.GetNextItem() << ")";
        if (i < o.GetLength() - 1) os << ", ";
    }
    os << "]";
    return os;
}

template <typename N>
void UnorderedLinkedList<N>::MakeEmpty(){
    Node<N>* temp = nullptr;
    while(head != nullptr){
        temp = head;
        head = head->next;
        delete temp;
    }
    length = 0;

}

template <typename N>
void UnorderedLinkedList<N>::PutItem(N item){
    Node<N>* temp = new Node<N>;
    temp->data = item;
    temp->next = head;
    head = temp;
    length++;
}

template <typename N>
N UnorderedLinkedList<N>::GetItem(N item){
    Node<N>* temp = head;
    while(temp != nullptr){
        if(temp->data == item){
            return temp->data;
        }
        temp = temp->next;
    }
    throw "not found";
}

template <typename N>
void UnorderedLinkedList<N>::DeleteItem(N item){
    // Empty case
    if(head == nullptr)
        return;

    Node<N>* temp;
    // Deleting head
    if(head->data == item){
        temp = head->next;
        delete head;
        head = temp;
        length--;
        return;
    }

    // Deleting further in the list
    temp = head;
    while(temp->next != nullptr){
        if(temp->next->data == item){
            Node<N>* temp2 = temp->next;
            temp->next = temp->next->next;
            delete temp2;
            length--;
            return;
        }
        temp = temp->next;
    }
}

template <typename N>
void UnorderedLinkedList<N>::ResetList(){
    currentPos = head;
}

template <typename N>
N UnorderedLinkedList<N>::GetNextItem(){
    if(currentPos == nullptr)
        throw "Out of range";

    int data = currentPos->data;
    currentPos = currentPos->next;
    return data;
}

template <typename N>
N UnorderedLinkedList<N>::GetLength(){
    return length;
}

template <typename N>
UnorderedLinkedList<N>::~UnorderedLinkedList(){
    MakeEmpty();
}
#endif /* RBT_UNORDEREDLINKEDLIST_HPP */
