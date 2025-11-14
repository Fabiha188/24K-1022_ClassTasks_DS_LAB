#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node *left, *right;
    int h;

    Node(int v) {
        val = v;
        left = right = nullptr;
        h = 1;
    }
};

int height(Node* n) {
    return n ? n->h : 0;
}

int bal(Node* n) {
    return n ? height(n->left) - height(n->right) : 0;
}

Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* t = y->left;
    y->left = x;
    x->right = t;
    x->h = 1 + max(height(x->left), height(x->right));
    y->h = 1 + max(height(y->left), height(y->right));
    return y;
}

Node* rightRotate(Node* x) {
    Node* y = x->left;
    Node* t = y->right;
    y->right = x;
    x->left = t;
    x->h = 1 + max(height(x->left), height(x->right));
    y->h = 1 + max(height(y->left), height(y->right));
    return y;
}

Node* insert(Node* r, int v) {
    if (!r) return new Node(v);

    if (v < r->val) r->left = insert(r->left, v);
    else if (v > r->val) r->right = insert(r->right, v);
    else return r;

    r->h = 1 + max(height(r->left), height(r->right));
    int bf = bal(r);

    if (bf > 1 && v < r->left->val) return rightRotate(r);
    if (bf < -1 && v > r->right->val) return leftRotate(r);
    if (bf > 1 && v > r->left->val) {
        r->left = leftRotate(r->left);
        return rightRotate(r);
    }
    if (bf < -1 && v < r->right->val) {
        r->right = rightRotate(r->right);
        return leftRotate(r);
    }

    return r;
}

void show(Node* r) {
    if (!r) return;
    cout << r->val << " ";
    show(r->left);
    show(r->right);
}

int main() {
    Node* root = nullptr;

    int nums[] = {10, 5, 15, 3, 7};
    for (int x : nums) root = insert(root, x);

    root = insert(root, 12);

    cout << "Final AVL Tree (Preorder): ";
    show(root);

    cout << "\nHeight: " << height(root);

    return 0;
}
