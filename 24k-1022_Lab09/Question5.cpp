#include <iostream>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
    int height;
    Node(int k) : key(k), left(nullptr), right(nullptr), height(1) {}
};

int myMax(int a, int b) {
    return (a > b) ? a : b;
}

int getHeight(Node* n) {
    return n ? n->height : 0;
}

int getBalance(Node* n) {
    return n ? getHeight(n->left) - getHeight(n->right) : 0;
}

Node* rotateRight(Node* y) {
    Node* x = y->left;
    Node* t = x->right;
    x->right = y;
    y->left = t;
    y->height = 1 + myMax(getHeight(y->left), getHeight(y->right));
    x->height = 1 + myMax(getHeight(x->left), getHeight(x->right));
    return x;
}

Node* rotateLeft(Node* x) {
    Node* y = x->right;
    Node* t = y->left;
    y->left = x;
    x->right = t;
    x->height = 1 + myMax(getHeight(x->left), getHeight(x->right));
    y->height = 1 + myMax(getHeight(y->left), getHeight(y->right));
    return y;
}

Node* insertNode(Node* root, int key) {
    if (!root) return new Node(key);

    if (key < root->key)
        root->left = insertNode(root->left, key);
    else if (key > root->key)
        root->right = insertNode(root->right, key);
    else
        return root;

    root->height = 1 + myMax(getHeight(root->left), getHeight(root->right));

    int bal = getBalance(root);

    if (bal > 1 && key < root->left->key)
        return rotateRight(root);

    if (bal < -1 && key > root->right->key)
        return rotateLeft(root);

    if (bal > 1 && key > root->left->key) {
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }

    if (bal < -1 && key < root->right->key) {
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }

    return root;
}

Node* buildTree(const int arr[], int n) {
    Node* root = nullptr;
    for (int i = 0; i < n; i++)
        root = insertNode(root, arr[i]);
    return root;
}

void preorder(Node* root) {
    if (!root) return;
    cout << root->key << " ";
    preorder(root->left);
    preorder(root->right);
}

void printInfo(Node* root) {
    if (!root) return;
    printInfo(root->left);
    cout << root->key << " h=" << root->height << " bf=" << getBalance(root) << endl;
    printInfo(root->right);
}

void freeTree(Node* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

int main() {
    int arr[] = {40, 30, 50, 25, 35, 45, 60};
    int n = sizeof(arr) / sizeof(arr[0]);

    Node* root = buildTree(arr, n);

    cout << "Preorder before: ";
    preorder(root);
    cout << endl << endl;

    cout << "Info before:" << endl;
    printInfo(root);
    cout << "------------------" << endl;

    root = insertNode(root, 55);

    cout << "Preorder after: ";
    preorder(root);
    cout << endl << endl;

    cout << "Info after:" << endl;
    printInfo(root);

    freeTree(root);
}
