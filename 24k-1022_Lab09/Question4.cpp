#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node *left, *right;
    int height;

    Node(int v) {
        val = v;
        left = right = nullptr;
        height = 1;
    }
};

int getHeight(Node* n) {
    return n ? n->height : 0;
}

int getBalance(Node* n) {
    return n ? getHeight(n->left) - getHeight(n->right) : 0;
}

Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T = x->right;

    x->right = y;
    y->left = T;

    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    return x;
}

Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T = y->left;

    y->left = x;
    x->right = T;

    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

Node* insertNode(Node* root, int key) {
    if (!root) return new Node(key);

    if (key < root->val)
        root->left = insertNode(root->left, key);
    else if (key > root->val)
        root->right = insertNode(root->right, key);
    else
        return root; //duplicate k liye

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    int balance = getBalance(root);

    // LL
    if (balance > 1 && key < root->left->val)
        return rightRotate(root);

    // RR
    if (balance < -1 && key > root->right->val)
        return leftRotate(root);

    // LR
    if (balance > 1 && key > root->left->val) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // RL
    if (balance < -1 && key < root->right->val) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void preorder(Node* root) {
    if (!root) return;
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

int main() {
    Node* root = nullptr;

    int arr[] = {15, 10, 20, 8, 12, 25, 30, 16};

    for (int x : arr)
        root = insertNode(root, x);

    cout << "Preorder Traversal: ";
    preorder(root);
    cout << endl;

    return 0;
}
