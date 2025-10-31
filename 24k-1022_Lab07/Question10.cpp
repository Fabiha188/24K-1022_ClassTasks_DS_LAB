#include <iostream>
using namespace std;

int getMax(int arr[], int n) {
    int maxVal = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > maxVal)
            maxVal = arr[i];
    return maxVal;
}

void countingSort(int arr[], int n, int exp) {
    int output[100];
    int count[10] = {0};

    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--) {
        int digit = (arr[i] / exp) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

void radixSort(int arr[], int n) {
    int maxVal = getMax(arr, n);
    int pass = 1;
    for (int exp = 1; maxVal / exp > 0; exp *= 10) {
        countingSort(arr, n, exp);
        cout << "\nAfter pass " << pass << " (sorting by " << exp << "'s place): ";
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        pass++;
    }
}

int main() {
    const int n = 20;
    int productIDs[n];

    cout << "Enter 20 product IDs (each a 5-digit number):\n";
    for (int i = 0; i < n; i++)
        cin >> productIDs[i];

    cout << "\nBefore Sorting:\n";
    for (int i = 0; i < n; i++)
        cout << productIDs[i] << " ";

    radixSort(productIDs, n);

    cout << "\n\nAfter Sorting:\n";
    for (int i = 0; i < n; i++)
        cout << productIDs[i] << " ";

    cout << endl;
    return 0;
}
