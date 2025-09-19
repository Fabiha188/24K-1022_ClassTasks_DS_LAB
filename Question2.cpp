#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void display(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void bubbleSort(int arr[], int n, int& count) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            count++;
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void insertionSort(int arr[], int n, int& count) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        count++;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
            count++;
        }
        arr[j + 1] = key;
    }
}

void selectionSort(int arr[], int n, int& count) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            count++;
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            int temp = arr[minIndex];
            arr[minIndex] = arr[i];
            arr[i] = temp;
        }
    }
}

void shellSort(int arr[], int n, int& count) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j = i;
            count++;
            while (j >= gap && arr[j - gap] > temp) {
                arr[j] = arr[j - gap];
                j -= gap;
                count++;
            }
            arr[j] = temp;
        }
    }
}

void generateRandomArray(int arr[], int n) {
    srand(time(0));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100 + 1;
    }
}

int main() {
    int arr[20], arr100[100];

    generateRandomArray(arr, 20);
    cout << "Original Array (20 elements):\n";
    display(arr, 20);

    int bubbleCount = 0;
    int arrBubble[20];
    copy(arr, arr + 20, arrBubble);
    bubbleSort(arrBubble, 20, bubbleCount);
    cout << "\nBubble Sorted Array:\n";
    display(arrBubble, 20);
    cout << "Bubble Sort Comparisons: " << bubbleCount << endl;

    int insertionCount = 0;
    int arrInsertion[20];
    copy(arr, arr + 20, arrInsertion);
    insertionSort(arrInsertion, 20, insertionCount);
    cout << "\nInsertion Sorted Array:\n";
    display(arrInsertion, 20);
    cout << "Insertion Sort Comparisons: " << insertionCount << endl;

    int selectionCount = 0;
    int arrSelection[20];
    copy(arr, arr + 20, arrSelection);
    selectionSort(arrSelection, 20, selectionCount);
    cout << "\nSelection Sorted Array:\n";
    display(arrSelection, 20);
    cout << "Selection Sort Comparisons: " << selectionCount << endl;

    int shellCount = 0;
    int arrShell[20];
    copy(arr, arr + 20, arrShell);
    shellSort(arrShell, 20, shellCount);
    cout << "\nShell Sorted Array:\n";
    display(arrShell, 20);
    cout << "Shell Sort Comparisons: " << shellCount << endl;

    generateRandomArray(arr100, 100);
    cout << "\nOriginal Array (100 elements):\n";
    display(arr100, 100);

    bubbleCount = 0;
    int arrBubble100[100];
    copy(arr100, arr100 + 100, arrBubble100);
    bubbleSort(arrBubble100, 100, bubbleCount);
    cout << "\nBubble Sorted Array (100 elements):\n";
    display(arrBubble100, 100);
    cout << "Bubble Sort Comparisons: " << bubbleCount << endl;

    insertionCount = 0;
    int arrInsertion100[100];
    copy(arr100, arr100 + 100, arrInsertion100);
    insertionSort(arrInsertion100, 100, insertionCount);
    cout << "\nInsertion Sorted Array (100 elements):\n";
    display(arrInsertion100, 100);
    cout << "Insertion Sort Comparisons: " << insertionCount << endl;

    selectionCount = 0;
    int arrSelection100[100];
    copy(arr100, arr100 + 100, arrSelection100);
    selectionSort(arrSelection100, 100, selectionCount);
    cout << "\nSelection Sorted Array (100 elements):\n";
    display(arrSelection100, 100);
    cout << "Selection Sort Comparisons: " << selectionCount << endl;

    shellCount = 0;
    int arrShell100[100];
    copy(arr100, arr100 + 100, arrShell100);
    shellSort(arrShell100, 100, shellCount);
    cout << "\nShell Sorted Array (100 elements):\n";
    display(arrShell100, 100);
    cout << "Shell Sort Comparisons: " << shellCount << endl;

    return 0;
}
