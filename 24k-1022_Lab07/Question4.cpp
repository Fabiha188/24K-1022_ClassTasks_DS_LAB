#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->next = nullptr;
    return temp;
}

void append(Node*& head, int val) {
    if (!head) {
        head = newNode(val);
        return;
    }
    Node* curr = head;
    while (curr->next)
        curr = curr->next;
    curr->next = newNode(val);
}

void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

Node* getTail(Node* head) {
    while (head && head->next)
        head = head->next;
    return head;
}

Node* partition(Node* head, Node* end, Node** newHead, Node** newEnd) {
    Node* pivot = end;
    Node *prev = nullptr, *curr = head, *tail = pivot;
    while (curr != pivot) {
        if (curr->data < pivot->data) {
            if (!(*newHead))
                *newHead = curr;
            prev = curr;
            curr = curr->next;
        } else {
            if (prev)
                prev->next = curr->next;
            Node* tmp = curr->next;
            curr->next = nullptr;
            tail->next = curr;
            tail = curr;
            curr = tmp;
        }
    }
    if (!(*newHead))
        *newHead = pivot;
    *newEnd = tail;
    return pivot;
}

Node* quickSortRec(Node* head, Node* end) {
    if (!head || head == end)
        return head;
    Node *newHead = nullptr, *newEnd = nullptr;
    Node* pivot = partition(head, end, &newHead, &newEnd);
    if (newHead != pivot) {
        Node* tmp = newHead;
        while (tmp->next != pivot)
            tmp = tmp->next;
        tmp->next = nullptr;
        newHead = quickSortRec(newHead, tmp);
        tmp = getTail(newHead);
        tmp->next = pivot;
    }
    pivot->next = quickSortRec(pivot->next, newEnd);
    return newHead;
}

void quickSort(Node** headRef) {
    *headRef = quickSortRec(*headRef, getTail(*headRef));
}

int main() {
    Node* head = nullptr;
    int values[] = {10, 7, 8, 9, 1, 5, 3};
    for (int val : values)
        append(head, val);
    quickSort(&head);
    printList(head);
    return 0;
}
