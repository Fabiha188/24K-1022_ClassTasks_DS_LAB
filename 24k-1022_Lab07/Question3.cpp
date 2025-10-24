#include <iostream>
#include <string>
using namespace std;

class Product {
public:
    string name;
    int price;
    string description;
    bool availability;
    
    Product() {}
    
    Product(string n, int p, string d, bool a) {
        name = n;
        price = p;
        description = d;
        availability = a;
    }
    
    void display() {
        cout << name << " - $" << price << " - " << description;
        cout << " - " << (availability ? "Available" : "Out of Stock") << endl;
    }
};

void swap(Product &a, Product &b) {
    Product temp = a;
    a = b;
    b = temp;
}

int partition(Product arr[], int low, int high) {
    int pivot = arr[high].price;
    int i = low - 1;
    
    for (int j = low; j < high; j++) {
        if (arr[j].price <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(Product arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    Product products[3] = {
        Product("Laptop", 999, "High-performance laptop", true),
        Product("Mouse", 25, "Wireless mouse", true),
        Product("Tablet", 450, "10-inch tablet", false)
    };
    
    cout << "Original products:" << endl;
    for (int i = 0; i < 3; i++) {
        products[i].display();
    }
    
    quickSort(products, 0, 2);
    
    cout << "\nSorted products by price:" << endl;
    for (int i = 0; i < 3; i++) {
        products[i].display();
    }
    
    return 0;
}
