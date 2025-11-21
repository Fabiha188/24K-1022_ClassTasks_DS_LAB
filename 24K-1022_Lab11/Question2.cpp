#include <iostream>
#include <cstring>
using namespace std;

struct Node {
    char w[50];
    Node *nxt;
};

class asciiDictionary {
    
    Node *tab[100];

public:

    asciiDictionary() {
        for(int i = 0; i < 100; i++)
            tab[i] = NULL;
    }

    int getHash(char s[]) {
        int sum = 0;
        for(int i = 0; s[i] != '\0'; i++)
            sum += (int)s[i];
        return sum % 100;
    }

    void addRec() {
        char s[50];
        cout << "\nEnter word: ";
        cin.ignore();
        cin.getline(s, 50);

        int h = getHash(s);

        Node *p = new Node;
        strcpy(p->w, s);
        p->nxt = NULL;

        if(tab[h] == NULL)
            tab[h] = p;
        else {
            p->nxt = tab[h];
            tab[h] = p;
        }

        cout << "Added at index " << h << "\n";
    }

    void findWord() {
        char s[50];
        cout << "\nSearch word: ";
        cin.ignore();
        cin.getline(s, 50);

        int h = getHash(s);
        Node *t = tab[h];

        while(t != NULL) {
            if(strcmp(t->w, s) == 0) {
                cout << "FOUND at index " << h << "\n";
                return;
            }
            t = t->nxt;
        }
        cout << "NOT FOUND\n";
    }

    void printAll() {
        cout << "\n----- Dictionary -----\n";
        for(int i = 0; i < 100; i++) {

            if(tab[i] != NULL) {
                cout << "Index " << i << ": ";
                Node *t = tab[i];

                while(t != NULL) {
                    cout << t->w << "  ";
                    t = t->nxt;
                }
                cout << "\n";
            }
        }
        cout << "----------------------\n";
    }
};

int main() {

    asciiDictionary d;
    int c;

    while(true) {

        cout << "\n1. Add Record";
        cout << "\n2. Search Word";
        cout << "\n3. Print Dictionary";
        cout << "\n4. Exit";
        cout << "\nEnter choice: ";
        cin >> c;

        if(c == 1)
            d.addRec();
        else if(c == 2)
            d.findWord();
        else if(c == 3)
            d.printAll();
        else
            break;
    }
    return 0;
}

