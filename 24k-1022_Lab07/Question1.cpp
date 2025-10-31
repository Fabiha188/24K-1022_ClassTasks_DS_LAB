#include <iostream>
#include <string>
using namespace std;

struct Node {
    string name;
    int score;
    Node* next;
    Node(string n, int s) : name(n), score(s), next(nullptr) {}
};

void insert(Node*& head, string name, int score) {
    Node* newNode = new Node(name, score);
    if (!head)
        head = newNode;
    else {
        Node* temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
    }
}

int getMax(Node* head) {
    int mx = 0;
    while (head) {
        if (head->score > mx)
            mx = head->score;
        head = head->next;
    }
    return mx;
}

int getDigit(int num, int exp) {
    return (num / exp) % 10;
}

Node* radixPass(Node* head, int exp) {
    Node* bucketHead[10] = {nullptr};
    Node* bucketTail[10] = {nullptr};

    for (Node* curr = head; curr != nullptr; ) {
        int digit = getDigit(curr->score, exp);
        Node* nextNode = curr->next;
        curr->next = nullptr;
        if (!bucketHead[digit])
            bucketHead[digit] = bucketTail[digit] = curr;
        else {
            bucketTail[digit]->next = curr;
            bucketTail[digit] = curr;
        }
        curr = nextNode;
    }

    Node* newHead = nullptr;
    Node* newTail = nullptr;
    for (int i = 0; i < 10; i++) {
        if (bucketHead[i]) {
            if (!newHead)
                newHead = bucketHead[i];
            else
                newTail->next = bucketHead[i];
            newTail = bucketTail[i];
        }
    }
    return newHead;
}

void radixSort(Node*& head) {
    int maxVal = getMax(head);
    for (int exp = 1; maxVal / exp > 0; exp *= 10)
        head = radixPass(head, exp);
}

void display(Node* head) {
    cout << "\nSorted Student List:\n";
    cout << "--------------------------\n";
    cout << "Name\tScore\n";
    cout << "--------------------------\n";
    while (head) {
        cout << head->name << "\t" << head->score << "\n";
        head = head->next;
    }
}

int main() {
    Node* head = nullptr;
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        string name;
        int score;
        cout << "Enter name of student " << i + 1 << ": ";
        cin >> name;
        cout << "Enter score (0–100): ";
        cin >> score;
        insert(head, name, score);
    }

    cout << "\nSorting students by score using Radix Sort...\n";
    radixSort(head);
    display(head);
    return 0;
}
