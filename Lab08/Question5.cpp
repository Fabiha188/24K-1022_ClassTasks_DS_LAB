#include <iostream>
#include <string>
using namespace std;

class node {
public:
    int productID;
    int quantity;
    node* left;
    node* right;

    node() {
        productID = 0;
        quantity = 0;
        left = right = nullptr;
    }

    node(int id, int q) {
        productID = id;
        quantity = q;
        left = right = nullptr;
    }
};

class ProductTracker {
public:
    node* head;

    ProductTracker() {
        head = nullptr;
    }

    // Insert new product or update existing
    node* insert(int id, int qty, node* head) {
        if (head == nullptr) {
            head = new node(id, qty);
            return head;
        }

        if (id < head->productID) {
            head->left = insert(id, qty, head->left);
        }
        else if (id > head->productID) {
            head->right = insert(id, qty, head->right);
        }
        else {
            // Product already exists → update quantity
            head->quantity += qty;
            cout << "Product ID " << id << " already exists. Quantity updated to " << head->quantity << endl;
        }
        return head;
    }

    void inOrder(node* head) {
        if (head == nullptr) return;
        inOrder(head->left);
        cout << "Product ID: " << head->productID << " | Quantity: " << head->quantity << endl;
        inOrder(head->right);
    }

    node* search(node* head, int id) {
        if (head == nullptr) return nullptr;
        if (head->productID == id) return head;
        if (id < head->productID) return search(head->left, id);
        return search(head->right, id);
    }

    node* findMaxQuantity(node* head, node*& maxNode) {
        if (head == nullptr) return maxNode;

        if (maxNode == nullptr || head->quantity > maxNode->quantity) {
            maxNode = head;
        }

        findMaxQuantity(head->left, maxNode);
        findMaxQuantity(head->right, maxNode);

        return maxNode;
    }

    int height(node* head) {
        if (head == nullptr)
            return -1;

        int leftHeight = height(head->left);
        int rightHeight = height(head->right);

        // manual max without <algorithm>
        return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
    }
};

int main() {
    ProductTracker p;
    int choice;

    do {
        cout << "\n--- Online Retailer Product Tracker ---\n";
        cout << "1. Add or Update Product\n";
        cout << "2. Display All Products (In-order)\n";
        cout << "3. Search Product by ID\n";
        cout << "4. Product with Highest Quantity\n";
        cout << "5. Show Tree Height\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            int id, qty;
            cout << "Enter Product ID: ";
            cin >> id;
            cout << "Enter Quantity: ";
            cin >> qty;
            p.head = p.insert(id, qty, p.head);
        }
        else if (choice == 2) {
            cout << "\n--- Product List (In-order Traversal) ---\n";
            p.inOrder(p.head);
        }
        else if (choice == 3) {
            int id;
            cout << "Enter Product ID to search: ";
            cin >> id;
            node* result = p.search(p.head, id);
            if (result != nullptr)
                cout << "Product found → ID: " << result->productID << ", Quantity: " << result->quantity << endl;
            else
                cout << "Product not found.\n";
        }
        else if (choice == 4) {
            node* maxNode = nullptr;
            p.findMaxQuantity(p.head, maxNode);
            if (maxNode != nullptr)
                cout << "Product with highest quantity → ID: " << maxNode->productID << ", Quantity: " << maxNode->quantity << endl;
            else
                cout << "No products in stock.\n";
        }
        else if (choice == 5) {
            cout << "Tree height: " << p.height(p.head) << endl;
        }

    } while (choice != 6);

    cout << "Exiting program. Goodbye!\n";
    return 0;
}
