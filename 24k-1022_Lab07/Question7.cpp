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
    int output[n];
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
    for (int exp = 1; maxVal / exp > 0; exp *= 10)
        countingSort(arr, n, exp);
}

int main() {
    int scores[50] = {
        78, 85, 90, 66, 95, 88, 72, 81, 54, 60,
        82, 91, 73, 87, 69, 77, 84, 92, 70, 65,
        80, 93, 68, 74, 79, 86, 71, 67, 89, 76,
        83, 94, 75, 62, 55, 59, 61, 96, 64, 63,
        58, 57, 56, 97, 98, 99, 100, 53, 52, 51
    };
    int n = 50;

    radixSort(scores, n);

    for (int i = 0; i < n; i++)
        cout << "Rank " << i + 1 << ": " << scores[i] << endl;

    return 0;
}
