#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int comparisons = 0;

void swapVals(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int partitionFirst(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low + 1, j = high;
    while (true) {
        while (i <= high && arr[i] <= pivot) { comparisons++; i++; }
        while (arr[j] > pivot) { comparisons++; j--; }
        if (i >= j) break;
        swapVals(arr[i], arr[j]);
    }
    swapVals(arr[low], arr[j]);
    return j;
}

int partitionMiddle(int arr[], int low, int high) {
    int mid = (low + high) / 2;
    swapVals(arr[low], arr[mid]);
    return partitionFirst(arr, low, high);
}

int partitionRandom(int arr[], int low, int high) {
    int randomIndex = low + rand() % (high - low + 1);
    swapVals(arr[low], arr[randomIndex]);
    return partitionFirst(arr, low, high);
}

int medianOfThree(int a, int b, int c) {
    if ((a > b) != (a > c)) return a;
    else if ((b > a) != (b > c)) return b;
    else return c;
}

int partitionMedianOfThree(int arr[], int low, int high) {
    int mid = (low + high) / 2;
    int median = medianOfThree(arr[low], arr[mid], arr[high]);
    if (median == arr[mid]) swapVals(arr[low], arr[mid]);
    else if (median == arr[high]) swapVals(arr[low], arr[high]);
    return partitionFirst(arr, low, high);
}

void quickSort(int arr[], int low, int high, int pivotType) {
    if (low < high) {
        int p;
        switch (pivotType) {
            case 1: p = partitionFirst(arr, low, high); break;
            case 2: p = partitionRandom(arr, low, high); break;
            case 3: p = partitionMiddle(arr, low, high); break;
            case 4: p = partitionMedianOfThree(arr, low, high); break;
        }
        quickSort(arr, low, p - 1, pivotType);
        quickSort(arr, p + 1, high, pivotType);
    }
}

void copyArray(int src[], int dest[], int n) {
    for (int i = 0; i < n; i++) dest[i] = src[i];
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}

int main() {
    srand(time(0));
    int arr[] = {10, 7, 8, 9, 1, 5, 3, 12, 4, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int temp[10];

    cout << "Original array: ";
    printArray(arr, n);

    int methods[4] = {1, 2, 3, 4};
    string names[4] = {"First Element", "Random Element", "Middle Element", "Median of Three"};

    for (int i = 0; i < 4; i++) {
        copyArray(arr, temp, n);
        comparisons = 0;
        quickSort(temp, 0, n - 1, methods[i]);
        cout << "\nPivot: " << names[i] << endl;
        cout << "Sorted: ";
        printArray(temp, n);
        cout << "Comparisons: " << comparisons << endl;
    }
    return 0;
}
