#include <iostream>
#include <string>
using namespace std;

class Runner {
public:
    string name;
    int time;
    Runner() {}
    Runner(string n, int t) {
        name = n;
        time = t;
    }
};

void merge(Runner runners[], int left, int mid, int right) {
    int n1 = mid - left + 1;  
    int n2 = right - mid;
    Runner* L = new Runner[n1];
    Runner* R = new Runner[n2];

    //copy
    for (int i = 0; i < n1; i++)
        L[i] = runners[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = runners[mid + 1 + j];
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i].time <= R[j].time) {
            runners[k] = L[i];
            i++;
        } else {
            runners[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        runners[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        runners[k] = R[j];
        j++;
        k++;
    }
    delete[] L;
    delete[] R;
}

void mergeSort(Runner runners[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(runners, left, mid);
        mergeSort(runners, mid + 1, right);
        merge(runners, left, mid, right);
    }
}

int main() {
    const int N = 10;
    Runner runners[N] = {
        Runner("Alice", 3420),
        Runner("Bob", 3105),
        Runner("Charlie", 2980),
        Runner("Diana", 3300),
        Runner("Ethan", 2890),
        Runner("Fiona", 3555),
        Runner("George", 3050),
        Runner("Hannah", 3155),
        Runner("Ian", 3000),
        Runner("Julia", 2955)
    };
    mergeSort(runners, 0, N - 1);
    cout << " Top 5 Fastest Runners " << endl;
    for (int i = 0; i < 5; i++) {
        cout << i + 1 << ". " << runners[i].name << " — "
             << runners[i].time << " seconds" << endl;
    }
    return 0;
}






