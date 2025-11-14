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

int balance(Node* n) {
    return n ? height(n->left) - height(n->right) : 0;
}

Node* leftRotate(Node* a) {
    Node* b = a->right;
    Node* t = b->left;

    b->left = a;
    a->right = t;

    a->h = 1 + max(height(a->left), height(a->right));
    b->h = 1 + max(height(b->left), height(b->right));

    return b;
}

Node* rightRotate(Node* a) {
    Node* b = a->left;
    Node* t = b->right;

    b->right = a;
    a->left = t;

    a->h = 1 + max(height(a->left), height(a->right));
    b->h = 1 + max(height(b->left), height(b->right));

    return b;
}

class AVLTree {
public:
    Node* root = nullptr;

    Node* insert(Node* r, int v) {
        if (!r) return new Node(v);

        if (v < r->val) r->left = insert(r->left, v);
        else if (v > r->val) r->right = insert(r->right, v);
        else return r;

        r->h = 1 + max(height(r->left), height(r->right));
        int bf = balance(r);

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

    void insertVal(int v) {
        root = insert(root, v);
    }

    void show(Node* r) {
        if (!r) return;
        cout << r->val << " ";
        show(r->left);
        show(r->right);
    }
};

int main() {
    AVLTree t;

    int nums[] = {50, 30, 70, 20, 40, 60, 80};
    for (int x : nums) t.insertVal(x);

    t.insertVal(55);

    t.root = leftRotate(t.root);

    cout << "Tree after inserting 55 and left rotating root:\n";
    t.show(t.root);

    return 0;
}
