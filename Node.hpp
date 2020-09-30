//
// Created by benjp on 009, 5/9/2020.
//

#ifndef RBT_NODE_HPP
#define RBT_NODE_HPP

using namespace std;

template <typename N>
struct Node {
    N data;
    Node *parent;
    Node *left;
    Node *right;
    int color;
    Node* next;
};


#endif //RBT_NODE_HPP
