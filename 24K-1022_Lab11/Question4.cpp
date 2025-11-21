#include <iostream>
#include <string>
using namespace std;

struct Student {
    int roll;
    string name;
    bool isEmpty; // true if slot is empty
    bool isDeleted; // true if slot deleted
    Student() { roll = 0; name = ""; isEmpty = true; isDeleted = false; }
};

class StudentHashTable {
private:
    static const int tableSize = 15;
    Student table[tableSize];

    int hashFunc(int roll) {
        return roll % tableSize;
    }

public:
    void InsertRecord(int roll, const string& name) {
        int index = hashFunc(roll);
        int attempt = 0;
        int newIndex;

        while (attempt < tableSize) {
            newIndex = (index + attempt * attempt) % tableSize;
            if (table[newIndex].isEmpty || table[newIndex].isDeleted) {
                table[newIndex].roll = roll;
                table[newIndex].name = name;
                table[newIndex].isEmpty = false;
                table[newIndex].isDeleted = false;
                cout << "Inserted (" << roll << ", " << name << ") at index " << newIndex << endl;
                return;
            }
            attempt++;
        }
        cout << "Hash table is full! Cannot insert record.\n";
    }

    void SearchRecord(int roll) {
        int index = hashFunc(roll);
        int attempt = 0;
        int newIndex;

        while (attempt < tableSize) {
            newIndex = (index + attempt * attempt) % tableSize;
            if (table[newIndex].isEmpty) {
                cout << "Record not found for roll " << roll << endl;
                return;
            }
            if (!table[newIndex].isEmpty && !table[newIndex].isDeleted && table[newIndex].roll == roll) {
                cout << "Roll: " << roll << ", Name: " << table[newIndex].name << endl;
                return;
            }
            attempt++;
        }
        cout << "Record not found for roll " << roll << endl;
    }

    void DisplayTable() {
        cout << "\n--- Student Hash Table ---\n";
        for (int i = 0; i < tableSize; i++) {
            if (!table[i].isEmpty && !table[i].isDeleted)
                cout << i << " : Roll " << table[i].roll << ", Name " << table[i].name << endl;
            else
                cout << i << " : EMPTY\n";
        }
        cout << "--------------------------\n";
    }
};

int main() {
    StudentHashTable sht;
    int choice, roll;
    string name;

    while (true) {
        cout << "\n1. Insert Record\n2. Search Record\n3. Display Table\n4. Exit\nEnter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter Roll Number: ";
            cin >> roll;
            cin.ignore();
            cout << "Enter Name: ";
            getline(cin, name);
            sht.InsertRecord(roll, name);
        }
        else if (choice == 2) {
            cout << "Enter Roll Number to Search: ";
            cin >> roll;
            sht.SearchRecord(roll);
        }
        else if (choice == 3) {
            sht.DisplayTable();
        }
        else if (choice == 4) {
            break;
        }
    }

    return 0;
}
