#include <iostream>
#include <string>
using namespace std;

struct Node {
    string word;
    Node* next;
    Node(string w) : word(w), next(nullptr) {}
};

class HashTable {
private:
    int bucketCount;
    Node** buckets;

    int hashValue(const string& s) {
        int sum = 0;
        for (char c : s) sum += int(c);
        return sum % bucketCount;
    }

public:
    HashTable(int size) {
        bucketCount = size;
        buckets = new Node*[bucketCount];
        for (int i = 0; i < bucketCount; i++)
            buckets[i] = nullptr;
    }

    void addWord(const string& s) {
        int index = hashValue(s);
        Node* newNode = new Node(s);
        newNode->next = buckets[index];
        buckets[index] = newNode;
    }

    bool findWord(const string& s) {
        int index = hashValue(s);
        Node* temp = buckets[index];
        while (temp) {
            if (temp->word == s) return true;
            temp = temp->next;
        }
        return false;
    }

    void showTable() {
        for (int i = 0; i < bucketCount; i++) {
            cout << "Bucket " << i << ": ";
            Node* temp = buckets[i];
            while (temp) {
                cout << temp->word << " -> ";
                temp = temp->next;
            }
            cout << "NULL\n";
        }
    }

    ~HashTable() {
        for (int i = 0; i < bucketCount; i++) {
            Node* temp = buckets[i];
            while (temp) {
                Node* del = temp;
                temp = temp->next;
                delete del;
            }
        }
        delete[] buckets;
    }
};

int main() {
    HashTable table(7);

    table.addWord("abc");
    table.addWord("cab");
    table.addWord("hello");
    table.addWord("ad");
    table.addWord("bc");

    cout << (table.findWord("hello") ? "Found\n" : "Not Found\n");

    table.showTable();

    return 0;
}
