#include <iostream>
#include <string>
using namespace std;

struct Student {
    string name;
    int score;
    Student* next;
    Student(string n, int s) : name(n), score(s), next(nullptr) {}
};

void addStudent(Student*& head, string name, int score) {
    Student* newStudent = new Student(name, score);
    if (!head)
        head = newStudent;
    else {
        Student* current = head;
        while (current->next)
            current = current->next;
        current->next = newStudent;
    }
}

int findMaxScore(Student* head) {
    int highest = 0;
    while (head) {
        if (head->score > highest)
            highest = head->score;
        head = head->next;
    }
    return highest;
}

int extractDigit(int number, int place) {
    return (number / place) % 10;
}

Student* distributeToBuckets(Student* head, int place) {
    Student* bucketHead[10] = {nullptr};
    Student* bucketTail[10] = {nullptr};

    Student* current = head;
    while (current) {
        int digit = extractDigit(current->score, place);
        Student* nextNode = current->next;
        current->next = nullptr;

        if (!bucketHead[digit])
            bucketHead[digit] = bucketTail[digit] = current;
        else {
            bucketTail[digit]->next = current;
            bucketTail[digit] = current;
        }
        current = nextNode;
    }

    Student* newHead = nullptr;
    Student* newTail = nullptr;

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

void radixSort(Student*& head) {
    int maxScore = findMaxScore(head);
    for (int place = 1; maxScore / place > 0; place *= 10)
        head = distributeToBuckets(head, place);
}

void printStudents(Student* head) {
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
    Student* head = nullptr;
    int totalStudents;
    cout << "Enter number of students: ";
    cin >> totalStudents;

    for (int i = 0; i < totalStudents; i++) {
        string name;
        int score;
        cout << "Enter name of student " << i + 1 << ": ";
        cin >> name;
        cout << "Enter score (0–100): ";
        cin >> score;
        addStudent(head, name, score);
    }

    cout << "\nSorting students by score using Radix Sort...\n";
    radixSort(head);
    printStudents(head);

    return 0;
}
