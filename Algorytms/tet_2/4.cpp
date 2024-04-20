#include <bits/stdc++.h>
#define RED true
#define BLACK false

using namespace std;

struct node {
    int key;
    node *left;
    node *right;
    node *parent;
    bool color;
    node(int value) : key(value), left(nullptr), right(nullptr), color(RED) {}
};


bool getColor(node *root) {
    if (root == nullptr) return BLACK;
    return root->color;
}

void setColor(node *root, bool color) {
    if (root == nullptr) return;
    root->color = color;
}

void insert(node *&root, node *&node, int key) {
    if (root == nullptr) {
        root = new struct node(key);
        setColor(root, BLACK);
        return;
    }

    if (node->key > key) {
        if (node->left == nullptr) {
            node->left = new struct node(key);
            setColor(node->left, !getColor(node));
        }
        else insert(root, node->left, key);
    }
    else if (node->key <= key) {
        if (node->right == nullptr) {
            node->right = new struct node(key);
            setColor(node->right, !getColor(node));
        }
        else insert(root, node->right, key);
    }

    setColor(root, BLACK);
}

void printTree(node *root) {
    if (root == nullptr) return;
    printTree(root->left);
    cout << root->key << " (" << ((root->color == RED) ? "RED" : "BLACK") << ") " << endl;
    printTree(root->right);
}

int blackH(node* root) {
    if (root == nullptr) return 1;
    int leftH = blackH(root->left);
    int rightH = blackH(root->right);

    if (leftH != rightH) return 0;
    if (leftH == 0 || rightH == 0) return 0;
    if (getColor(root) == BLACK) leftH++;

    return leftH;
}

void checkRedBlackTreeProperties(node* root) {
    if (blackH(root) != 0)
        cout << "Correct" << endl;
    else
        cout << "Incorrect" << endl;
}

int main() {
    node *root = nullptr;
    insert(root, root, 8);
    insert(root, root, 4);
    insert(root, root, 12);
    insert(root, root, 2);
    insert(root, root, 6);
    insert(root, root, 10);
    insert(root, root, 14);
    insert(root, root, 1);
    insert(root, root, 3);
    insert(root, root, 5);
    insert(root, root, 7);
    insert(root, root, 9);
    insert(root, root, 11);
    insert(root, root, 13);
    insert(root, root, 15);

    printTree(root);
    cout << endl;
    cout << "Checking for rules: ";
    checkRedBlackTreeProperties(root);

    cout << "Add 16" << endl;

    insert(root, root, 16);
    cout << "Checking for rules: ";
    checkRedBlackTreeProperties(root);
    
}
