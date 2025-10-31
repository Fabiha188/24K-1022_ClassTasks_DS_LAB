#include <iostream>
using namespace std;

class node {
public:
    int empID;
    node* left;
    node* right;

    node() {
        empID = 0;
        left = right = nullptr;
    }
    node(int id) {
        empID = id;
        left = right = nullptr;
    }
};

class EmployeeHierarchy {
public:
    node* head;

    EmployeeHierarchy() {
        head = nullptr;
    }

    node* insert(int id, node* head) {
        if (head == nullptr) {
            head = new node(id);
            return head;
        }
        if (id < head->empID)
            head->left = insert(id, head->left);
        else if (id > head->empID)
            head->right = insert(id, head->right);
        // duplicate IDs are ignored
        return head;
    }

    void inOrder(node* head) {
        if (head == nullptr) return;
        inOrder(head->left);
        cout << head->empID << " ";
        inOrder(head->right);
    }

    // --- Function to find Lowest Common Ancestor ---
    node* findLCA(node* head, int id1, int id2) {
        if (head == nullptr) return nullptr;

        // If both IDs are smaller, LCA is in the left subtree
        if (id1 < head->empID && id2 < head->empID)
            return findLCA(head->left, id1, id2);

        // If both IDs are greater, LCA is in the right subtree
        if (id1 > head->empID && id2 > head->empID)
            return findLCA(head->right, id1, id2);

        // Otherwise, this node is the LCA
        return head;
    }

    node* search(node* head, int id) {
        if (head == nullptr) return nullptr;
        if (head->empID == id) return head;
        if (id < head->empID) return search(head->left, id);
        return search(head->right, id);
    }
};

int main() {
    EmployeeHierarchy e;
    int choice;

    do {
        cout << "\n--- Employee Hierarchy System ---\n";
        cout << "1. Add Employee\n";
        cout << "2. Display Employee IDs (In-order)\n";
        cout << "3. Find Closest Common Manager (LCA)\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            int id;
            cout << "Enter Employee ID: ";
            cin >> id;
            e.head = e.insert(id, e.head);
        }
        else if (choice == 2) {
            cout << "\nEmployees (sorted by ID): ";
            e.inOrder(e.head);
            cout << endl;
        }
        else if (choice == 3) {
            int id1, id2;
            cout << "Enter first Employee ID: ";
            cin >> id1;
            cout << "Enter second Employee ID: ";
            cin >> id2;

            node* emp1 = e.search(e.head, id1);
            node* emp2 = e.search(e.head, id2);

            if (emp1 == nullptr || emp2 == nullptr) {
                cout << "One or both employee IDs not found in the hierarchy.\n";
            } else {
                node* lca = e.findLCA(e.head, id1, id2);
                if (lca != nullptr)
                    cout << "Closest Common Manager (LCA) for " << id1 << " and " << id2 << " is Employee ID: " << lca->empID << endl;
                else
                    cout << "No common manager found.\n";
            }
        }

    } while (choice != 4);

    cout << "Exiting program. Goodbye!\n";
    return 0;
}
