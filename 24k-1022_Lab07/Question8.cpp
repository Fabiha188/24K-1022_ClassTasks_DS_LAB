#include <iostream>
#include <string>
using namespace std;

class Order {
public:
    int orderID;
    string customerName;
    double totalPrice;

    Order() {}
    Order(int id, string name, double price) : orderID(id), customerName(name), totalPrice(price) {}
};

int partition(Order arr[], int low, int high) {
    double pivot = arr[high].totalPrice;
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j].totalPrice < pivot) {
            i++;
            Order temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    Order temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return i + 1;
}

void quickSort(Order arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    Order orders[10] = {
        Order(101, "Alice", 250.50),
        Order(102, "Bob", 150.75),
        Order(103, "Charlie", 300.00),
        Order(104, "David", 120.25),
        Order(105, "Eva", 275.90),
        Order(106, "Frank", 180.60),
        Order(107, "Grace", 220.40),
        Order(108, "Hannah", 310.00),
        Order(109, "Ian", 199.99),
        Order(110, "Jack", 260.00)
    };

    quickSort(orders, 0, 9);

    cout << "Orders sorted by Total Price (Ascending):" << endl;
    for (int i = 0; i < 10; i++) {
        cout << "OrderID: " << orders[i].orderID
             << ", Customer: " << orders[i].customerName
             << ", Total Price: $" << orders[i].totalPrice << endl;
    }

    return 0;
}
