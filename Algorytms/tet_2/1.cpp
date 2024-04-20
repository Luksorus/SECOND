#include <bits/stdc++.h>

using namespace std;

struct node {
    int key;
    int count;
    node *left;
    node *right;
    int h;
    node(int value) : key(value), left(nullptr), right(nullptr), h(0), count(1) {}
};

int getH(node *root) {
    return (root == nullptr) ? -1 : root->h;
}

void updateH(node *&root) {
    root->h = max(getH(root->left), getH(root->right)) + 1;
}

int getBalance(node *root) {
    return (root == nullptr) ? 0 : getH(root->right) - getH(root->left);
}

void insert(node *&root, int key) {
    if (root->key > key) {
        if (root->left == nullptr) root->left = new node(key);
        else insert(root->left, key);
    }
    else if (root->key < key) {
        if (root->right == nullptr) root->right = new node(key);
        else insert(root->right, key);
    }
    else root->count++;

    updateH(root);
}

void printTree(node *root) {
    if (root == nullptr) return;
    printTree(root->left);
    cout << root->key << " {count: " << root->count  << ", balance: " << getBalance(root) <<"}" << endl;
    printTree(root->right);
}

node *generateRandomTree(int count_Node) {
    node *root = new node(rand() % 100);
    for (; count_Node > 0; count_Node--)
        insert(root, rand() % 100);
    return root;
}

int main() {
    srand(time(0));
    

    node *root = generateRandomTree(10);
    printTree(root);
    cout << endl;
}


