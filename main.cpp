// NOTE: SOME CODE WAS SOURCED FROM PROFESSOR EUGENE LYMAR.
// BEN PLACZEK 2020

#include <iostream>
#include <chrono>
#include <cstdlib>
#include <vector>
#include "RBTree.hpp"
#include "Searcher.hpp"

using namespace std;
using namespace std::chrono;

//generates a random array
template<typename N>
void RandomArray(N ar[], long length, long min, int max) {
    for (int i = 0; i < length; ++i) {
        ar[i] = rand() % (max - min + 1) + min;
    }
}

template<typename N>
int TimeToSearch(Searcher<N> *s, N *arr, long length, N item) {
    high_resolution_clock::time_point t1 = high_resolution_clock::now();
    s->Search(arr, length, item);
    high_resolution_clock::time_point t2 = high_resolution_clock::now();
    return duration_cast<microseconds>(t2 - t1).count();
}

template<typename N>
void runBlackNodeCheck(Searcher<N> *s) {
    s->findBlackHeights();
}

// Driver Code
int main() {
    //Number of items 100, 1000, 10000, 100000, and 1000000
    const int lenSize = 5;
    long lengths[lenSize] = {100, 1000, 10000, 100000, 100000};

    auto searchers = vector<Searcher<int> *>();
    searchers.push_back(new ULLSearcher<int>());
    searchers.push_back(new RBTSearcher<int>());

    //SET A RANDOM SEED
    srand(time(NULL));

    int value_to_find;
    for (int i = 0; i < searchers.size(); ++i) {
        cout << searchers[i]->GetName() << ": " << endl;
        for (int length:lengths) {
            int *vals = new int[length];
            RandomArray(vals, length, 0, 25);
            value_to_find = rand() % 26;
            int duration = TimeToSearch(searchers[i], vals, length, value_to_find);
            cout << "Time to search for " << value_to_find << " in " << length << " nums with "
                 << searchers[i]->GetName() << ": " << duration << " microseconds" << endl;
        }
    }


//Recursive check of black nodes along a simple path

    RedBlackTree<int> x;
    for (int i = 0; i < 10; i++) {
        x.insert(i);
    }

    x.checkBlackHeights();

    return 0;
}