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

void swap(node *&fir, node *&sec) {
    int firstKey = fir->key;
    fir->key = sec->key;
    sec->key = firstKey;
}

void rightRotate(node *&root) {
    swap(root, root->left);
    node *buf = root->right;
    root->right = root->left;
    root->left = root->right->left;
    root->right->left = root->right->right;
    root->right->right = buf;
    updateH(root->right);
    updateH(root);
}

void leftRotate(node *&root) {
    swap(root, root->right);
    node *buf = root->left;
    root->left = root->right;
    root->right = root->left->right;
    root->left->right = root->left->left;
    root->left->left = buf;
    updateH(root->left);
    updateH(root);
}

void balanceTree(node *&root) {
    int balance = getBalance(root);
    if (balance == -2) {
        if (getBalance(root->left) == 1) leftRotate(root->left);
        rightRotate(root);
    }
    else if (balance == 2) {
        if (getBalance(root->right) == -1) rightRotate(root->right);
        leftRotate(root);
    }
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
    balanceTree(root);
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
    cout << "root height: " << root->h << endl;
    cout << "root key: " << root->key << endl;

}
