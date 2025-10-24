#include <iostream>
#include <iomanip>
using namespace std;

void countingSort(int scores[], int studentNum[], int n, int exp) {
    int output[n];
    int numOutput[n];
    int count[10] = {0};

    for(int i = 0; i < n; i++)
        count[(scores[i] / exp) % 10]++;

    for(int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for(int i = n - 1; i >= 0; i--) {
        int index = (scores[i] / exp) % 10;
        output[count[index] - 1] = scores[i];
        numOutput[count[index] - 1] = studentNum[i];
        count[index]--;
    }

    for(int i = 0; i < n; i++) {
        scores[i] = output[i];
        studentNum[i] = numOutput[i];
    }
}

void radixSort(int scores[], int studentNum[], int n) {
    int maxVal = scores[0];
    for(int i = 1; i < n; i++)
        if(scores[i] > maxVal) maxVal = scores[i];

    for(int exp = 1; maxVal/exp > 0; exp *= 10)
        countingSort(scores, studentNum, n, exp);
}

int main() {
    int scores[50];
    int studentNum[50];
    
    for(int i = 0; i < 50; i++) {
        scores[i] = rand() % 101;
        studentNum[i] = i + 1;
    }

    radixSort(scores, studentNum, 50);

    cout << "=============================================\n";
    cout << "          STUDENT RANKING SYSTEM\n";
    cout << "=============================================\n";
    cout << setw(8) << "Rank" << setw(12) << "Student" << setw(8) << "Score" << endl;
    cout << "---------------------------------------------\n";

    for(int i = 49; i >= 0; i--) {
        int rank = 50 - i;
        cout << setw(8) << rank 
             << setw(12) << studentNum[i] 
             << setw(8) << scores[i] << "\n";
    }

    cout << "=============================================\n";
    
    cout << "\n*** TOP PERFORMERS ***\n";
    for(int i = 49; i >= 45; i--) {
        int rank = 50 - i;
        cout << "Rank " << rank << ": Student " << studentNum[i] 
             << " - Score: " << scores[i] << endl;
    }

    return 0;
}
