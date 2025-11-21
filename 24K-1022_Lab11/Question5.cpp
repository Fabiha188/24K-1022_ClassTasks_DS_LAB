#include <iostream>
#include <string>
using namespace std;

class EmployeeHash {
private:
    string table[50];

    int asciiSum(const string& name) {
        int sum = 0;
        for (char c : name) sum += int(c);
        return sum;
    }

    int primaryHash(const string& name) {
        return asciiSum(name) % 50;
    }

    int secondaryHash(const string& name) {
        return 7 - (asciiSum(name) % 7);
    }

public:
    void Add_Employee(const string& name) {
        int h1 = primaryHash(name);
        int h2 = secondaryHash(name);
        int index = h1;
        int i = 0;

        while (!table[index].empty()) {
            i++;
            index = (h1 + i * h2) % 50;
            if (i == 50) {
                cout << "Hash table full. Cannot insert.\n";
                return;
            }
        }

        table[index] = name;
        cout << "Employee '" << name << "' added at index " << index << endl;
    }

    void Search_Employee(const string& name) {
        int h1 = primaryHash(name);
        int h2 = secondaryHash(name);
        int index = h1;
        int i = 0;

        while (!table[index].empty()) {
            if (table[index] == name) {
                cout << "Employee '" << name << "' found at index " << index << endl;
                return;
            }
            i++;
            index = (h1 + i * h2) % 50;
            if (i == 50) break; // all table checked
        }

        cout << "Employee not found in the directory.\n";
    }

    void Display_Table() {
        cout << "\n--- Employee Hash Table ---\n";
        for (int i = 0; i < 50; i++) {
            if (!table[i].empty())
                cout << i << " : " << table[i] << endl;
            else
                cout << i << " : EMPTY\n";
        }
        cout << "---------------------------\n";
    }
};

int main() {
    EmployeeHash empHash;
    int choice;
    string name;

    while (true) {
        cout << "\n1. Add Employee\n2. Search Employee\n3. Display Table\n4. Exit\nEnter choice: ";
        cin >> choice;
        cin.ignore(); // clear input buffer

        if (choice == 1) {
            cout << "Enter employee name: ";
            getline(cin, name);
            empHash.Add_Employee(name);
        }
        else if (choice == 2) {
            cout << "Enter employee name to search: ";
            getline(cin, name);
            empHash.Search_Employee(name);
        }
        else if (choice == 3) {
            empHash.Display_Table();
        }
        else if (choice == 4) {
            break;
        }
    }

    return 0;
}
