#include <iostream>
#include <string>
using namespace std;

class Employee {
public:
    string name;
    int id;
    double salary;
    
    Employee() {}
    
    Employee(string n, int i, double s) {
        name = n;
        id = i;
        salary = s;
    }
    
    void display() {
        cout << name << " (ID: " << id << ") - $" << salary << endl;
    }
};

void merge(Employee arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    Employee* leftArr = new Employee[n1];
    Employee* rightArr = new Employee[n2];
    
    for (int i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        rightArr[j] = arr[mid + 1 + j];
    
    int i = 0, j = 0, k = left;
    
    while (i < n1 && j < n2) {
        if (leftArr[i].salary >= rightArr[j].salary) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }
    
    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }
    
    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
    
    delete[] leftArr;
    delete[] rightArr;
}

void mergeSort(Employee arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        
        merge(arr, left, mid, right);
    }
}

int main() {
    Employee employees[12] = {
        Employee("John", 101, 75000),
        Employee("Alice", 102, 82000),
        Employee("Bob", 103, 68000),
        Employee("Carol", 104, 95000),
        Employee("David", 105, 72000),
        Employee("Eva", 106, 88000),
        Employee("Frank", 107, 79000),
        Employee("Grace", 108, 91000),
        Employee("Henry", 109, 65000),
        Employee("Ivy", 110, 83000),
        Employee("Jack", 111, 77000),
        Employee("Karen", 112, 89000)
    };
    
    mergeSort(employees, 0, 11);
    
    cout << "Top 3 Highest-Paid Employees:" << endl;
    for (int i = 0; i < 3; i++) {
        cout << i + 1 << ". ";
        employees[i].display();
    }
    
    return 0;
}
