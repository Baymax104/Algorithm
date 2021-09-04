/**
*@Description
*@Author Jake
*@email wzy1048168235@163.com
*@Date 2021/9/3 20:51
*@Version
*/

#include "HuffmanTree.h"
HuffmanTree::HuffmanTree(int num_weight) :num_weight(num_weight) {
    heap = priority_queue<node_heap, vector<node_heap>, Comparator>();
    tree = new node_tree[2 * num_weight - 1];
    for_each(tree, tree + 2 * num_weight - 1, [=](node_tree &n){
        n.weight = 0;
        n.parent = n.left = n.right = -1;
    });
    int weight;
    int i = 0;
    cout << "请输入权值:(按-1结束输入)" << endl;
    while (true) {
        cin >> weight;
        if (weight == -1) break;
        heap.push(node_heap(weight, i));
        tree[i++].weight = weight;
    }
    create_tree();
}

void HuffmanTree::create_tree() {
    int i_p = num_weight;
    node_heap left;
    node_heap right;

    while (!heap.empty()) {
        left = heap.top();
        heap.pop();
        right = heap.top();
        heap.pop();

        tree[i_p].weight = left.weight + right.weight;
        tree[i_p].left = left.index;
        tree[i_p].right = right.index;
        tree[left.index].parent = i_p;
        tree[right.index].parent = i_p;
        heap.push(node_heap(left.weight + right.weight, i_p));
        i_p++;
    }
}

void HuffmanTree::encode(string &str, int weight) {
    int parent = 0;
    int child;
    for (int i = 0; i < num_weight; i++) {
        if (tree[i].weight == weight) {
            child = i;
            break;
        }
    }
    while (parent != 2 * num_weight - 2) {
        parent = tree[child].parent;
        if (tree[parent].left == child) {
            str.push_back('0');
        } else {
            str.push_back('1');
        }
        child = parent;
    }
}

ostream& HuffmanTree::list_tree(ostream &os) {
    for (int i = 0; i < 2 * num_weight - 1; i++) {
        os << tree[i].weight << " ";
        os << tree[tree[i].parent].weight << " ";
        os << (tree[i].left != -1 ? tree[tree[i].left].weight : -1) << " ";
        os << (tree[i].right != -1 ? tree[tree[i].right].weight : -1) << endl;
    }
    return os;
}

HuffmanTree::~HuffmanTree() {
    delete[] tree;
}

void HuffmanTree::list_code() {
    string str;
    for (int i = 0; i < num_weight; i++) {
        encode(str, tree[i].weight);
        cout << tree[i].weight << " : " << str << endl;
        str.clear();
    }
}
ostream& operator<<(ostream &os, HuffmanTree &rhs) {
    return rhs.list_tree(os);
}