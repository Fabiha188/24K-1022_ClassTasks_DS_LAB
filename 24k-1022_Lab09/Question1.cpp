#include <iostream>
using namespace std;

class Node {
public:
    int roll;
    Node *left, *right;
    int height;

    Node(int r) {
        roll = r;
        left = right = nullptr;
        height = 1;
    }
};

int ht(Node* n) {
    return n ? n->height : 0;
}

int bal(Node* n) {
    return n ? ht(n->left) - ht(n->right) : 0;
}

Node* rotateLeft(Node* x) {
    Node* y = x->right;
    Node* temp = y->left;

    y->left = x;
    x->right = temp;

    x->height = 1 + max(ht(x->left), ht(x->right));
    y->height = 1 + max(ht(y->left), ht(y->right));

    return y;
}

Node* rotateRight(Node* y) {
    Node* x = y->left;
    Node* temp = x->right;

    x->right = y;
    y->left = temp;

    y->height = 1 + max(ht(y->left), ht(y->right));
    x->height = 1 + max(ht(x->left), ht(x->right));

    return x;
}

Node* insertNode(Node* root, int roll) {
    if (!root) return new Node(roll);

    if (roll < root->roll)
        root->left = insertNode(root->left, roll);
    else if (roll > root->roll)
        root->right = insertNode(root->right, roll);
    else
        return root;

    root->height = 1 + max(ht(root->left), ht(root->right));
    int balance = bal(root);

    if (balance > 1 && roll < root->left->roll)
        return rotateRight(root);

    if (balance < -1 && roll > root->right->roll)
        return rotateLeft(root);

    if (balance > 1 && roll > root->left->roll) {
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }

    if (balance < -1 && roll < root->right->roll) {
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }

    return root;
}

void show(Node* root) {
    if (!root) return;
    cout << root->roll << " ";
    show(root->left);
    show(root->right);
}

int main() {
    Node* root = nullptr;

    int arr[] = {10, 20, 30, 40, 50};
    for (int r : arr)
        root = insertNode(root, r);

    root = insertNode(root, 15);

    root = rotateLeft(root);

    cout << "Preorder: ";
    show(root);

    cout << "\nTree Height: " << ht(root);

    return 0;
}
