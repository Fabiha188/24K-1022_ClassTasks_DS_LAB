#include <iostream>
#include <string>
using namespace std;

class Hash {
private:
    string* table;
    int size;

    int hashFunc(const string& key) {
        int sum = 0;
        for (char c : key) sum += int(c);
        return sum % size;
    }

public:
    Hash(int s) {
        size = s;
        table = new string[size];
        for (int i = 0; i < size; i++)
            table[i] = ""; // empty slot
    }

    void insert(const string& key) {
        int index = hashFunc(key);
        int start = index;
        while (table[index] != "" && table[index] != "DELETED") {
            index = (index + 1) % size;
            if (index == start) {
                cout << "Hash table full. Cannot insert.\n";
                return;
            }
        }
        table[index] = key;
        cout << "Inserted '" << key << "' at index " << index << endl;
    }

    void search(const string& key) {
        int index = hashFunc(key);
        int start = index;
        while (table[index] != "") {
            if (table[index] == key) {
                cout << "Found '" << key << "' at index " << index << endl;
                return;
            }
            index = (index + 1) % size;
            if (index == start) break;
        }
        cout << "Not found '" << key << "'\n";
    }

    void remove(const string& key) {
        int index = hashFunc(key);
        int start = index;
        while (table[index] != "") {
            if (table[index] == key) {
                table[index] = "DELETED";
                cout << "Deleted '" << key << "' from index " << index << endl;
                return;
            }
            index = (index + 1) % size;
            if (index == start) break;
        }
        cout << "Cannot delete. '" << key << "' not found.\n";
    }

    void display() {
        cout << "\nHash Table Contents:\n";
        for (int i = 0; i < size; i++) {
            cout << i << " : " << (table[i] == "" ? "EMPTY" : table[i]) << endl;
        }
    }

    ~Hash() {
        delete[] table;
    }
};

int main() {
    Hash h(10); // hash table size 10
    int choice;
    string key;

    while (true) {
        cout << "\n1. Insert\n2. Search\n3. Delete\n4. Display\n5. Exit\nEnter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter key to insert: ";
            cin.ignore();
            getline(cin, key);
            h.insert(key);
        }
        else if (choice == 2) {
            cout << "Enter key to search: ";
            cin.ignore();
            getline(cin, key);
            h.search(key);
        }
        else if (choice == 3) {
            cout << "Enter key to delete: ";
            cin.ignore();
            getline(cin, key);
            h.remove(key);
        }
        else if (choice == 4) {
            h.display();
        }
        else if (choice == 5) {
            break;
        }
    }

    return 0;
}
