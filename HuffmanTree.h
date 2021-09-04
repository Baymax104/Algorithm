/**
*@Description
*@Author Jake
*@email wzy1048168235@163.com
*@Date 2021/9/3 20:51
*@Version
*/

#ifndef ALGORITHM_HUFFMANTREE_H
#define ALGORITHM_HUFFMANTREE_H

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;
class HuffmanTree {
public:
    struct node_heap {
        node_heap() {}
        node_heap(int w, int i)
            :weight(w), index(i) {}

        int weight;
        int index;
    };
    struct node_tree {
        node_tree() {}
        node_tree(int w, int p, int l, int r)
            :weight(w), parent(p), left(l), right(r) {}

        int weight;
        int parent;
        int left;
        int right;
    };
    class Comparator {
    public:
        bool operator()(const node_heap &lhs, const node_heap &rhs) {
            return lhs.weight >= rhs.weight;
        }
    };
    priority_queue<node_heap, vector<node_heap>, Comparator> heap; // ×îÐ¡¶Ñ
    node_tree *tree; // HuffmanÊ÷
    int num_weight;

    HuffmanTree(int num_weight);
    ~HuffmanTree();
    void create_tree();
    void encode(string &str, int weight);
    ostream& list_tree(ostream &os);
    void list_code();
};
ostream& operator<<(ostream &os, HuffmanTree &rhs);


#endif //ALGORITHM_HUFFMANTREE_H
