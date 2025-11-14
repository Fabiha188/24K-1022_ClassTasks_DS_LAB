#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node *left, *right;
    int h;
    Node(int x) {
        val = x;
        left = right = 0;
        h = 1;
    }
};

int getH(Node* n) {
    return n ? n->h : 0;
}

int getB(Node* n) {
    return n ? getH(n->left) - getH(n->right) : 0;
}

Node* rightTurn(Node* y) {
    Node* x = y->left;
    Node* t = x->right;
    x->right = y;
    y->left = t;
    y->h = 1 + (getH(y->left) > getH(y->right) ? getH(y->left) : getH(y->right));
    x->h = 1 + (getH(x->left) > getH(x->right) ? getH(x->left) : getH(x->right));
    return x;
}

Node* leftTurn(Node* x) {
    Node* y = x->right;
    Node* t = y->left;
    y->left = x;
    x->right = t;
    x->h = 1 + (getH(x->left) > getH(x->right) ? getH(x->left) : getH(x->right));
    y->h = 1 + (getH(y->left) > getH(y->right) ? getH(y->left) : getH(y->right));
    return y;
}

Node* addNode(Node* root, int x) {
    if (!root) return new Node(x);
    if (x < root->val) root->left = addNode(root->left, x);
    else if (x > root->val) root->right = addNode(root->right, x);
    root->h = 1 + (getH(root->left) > getH(root->right) ? getH(root->left) : getH(root->right));
    int b = getB(root);
    if (b > 1 && x < root->left->val) return rightTurn(root);
    if (b < -1 && x > root->right->val) return leftTurn(root);
    if (b > 1 && x > root->left->val) { root->left = leftTurn(root->left); return rightTurn(root); }
    if (b < -1 && x < root->right->val) { root->right = rightTurn(root->right); return leftTurn(root); }
    return root;
}

Node* minNode(Node* n) {
    while (n->left) n = n->left;
    return n;
}

Node* delNode(Node* root, int x) {
    if (!root) return root;

    if (x < root->val) root->left = delNode(root->left, x);
    else if (x > root->val) root->right = delNode(root->right, x);
    else {
        if (!root->left || !root->right) {
            Node* t = root->left ? root->left : root->right;
            if (!t) { t = root; root = NULL; }
            else *root = *t;
        } else {
            Node* t = minNode(root->right);
            root->val = t->val;
            root->right = delNode(root->right, t->val);
        }
    }

    if (!root) return root;

    root->h = 1 + (getH(root->left) > getH(root->right) ? getH(root->left) : getH(root->right));
    int b = getB(root);

    if (b > 1 && getB(root->left) >= 0) return rightTurn(root);
    if (b > 1 && getB(root->left) < 0) { root->left = leftTurn(root->left); return rightTurn(root); }
    if (b < -1 && getB(root->right) <= 0) return leftTurn(root);
    if (b < -1 && getB(root->right) > 0) { root->right = rightTurn(root->right); return leftTurn(root); }

    return root;
}

void preorder(Node* r) {
    if (!r) return;
    cout << r->val << " ";
    preorder(r->left);
    preorder(r->right);
}

int main() {
    Node* root = 0;
    int a[] = {100, 80, 120, 70, 90, 110, 130};
    for (int x : a) root = addNode(root, x);

    cout << "Starting tree created. Now removing product 80..." << endl;
    root = delNode(root, 80);

    cout << "Tree after removing 80 (preorder view): ";
    preorder(root);
}



