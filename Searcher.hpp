//
// Created by benjp on 009, 5/9/2020.
//

#ifndef RBT_SEARCHER_HPP
#define RBT_SEARCHER_HPP

using namespace std;

template <typename N>
class Searcher {
private:
    string name;
public:
    Searcher(string name):name{name}{}
    virtual void Search(N arr[], long length, N item)=0;
    string GetName(){return name;}
    virtual void findBlackHeights()=0;
    virtual ~Searcher(){}

};

template <typename N>
class ULLSearcher: public Searcher<N> {
private:
    void LinearSearch(N arr[], long length, N item) {
        UnorderedLinkedList<N>* list = new UnorderedLinkedList<N>;
        for(long i =0; i<length; i++) {
            list->PutItem(arr[i]);
        }
            list->GetItem(item);

    }

public:
    ULLSearcher():
            Searcher<N>("UnorderedLinkedList")
    {}
    void Search(N arr[], long length, N item){
        LinearSearch(arr, length, item);
    }
    void findBlackHeights() {}
};

template <typename N>
class RBTSearcher: public Searcher<N> {
private:
    int count = 1;
    RedBlackTree<N> bst;

    void TreeSearch(N arr[], long length, N item) {
        for(long i =0; i<length; i++) {
            bst.insert(arr[i]);
        }
        bst.searchTree(item);

    }

public:
    RBTSearcher():
            Searcher<N>("RBTree")
    {}
    void Search(N arr[], long length, N item){
        TreeSearch(arr, length, item);
    }
    //Find the heights of all of the black node sin the RBT
    void findBlackHeights() {

    }
};


#endif //RBT_SEARCHER_HPP
