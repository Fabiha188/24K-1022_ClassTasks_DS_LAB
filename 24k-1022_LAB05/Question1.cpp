#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int num;

void game(int p, int t) {
    int g;
    cout << "Player " << p << ", enter guess (1-100): ";
    cin >> g;

    if (g == num) {
        cout << "Player " << p << " wins! Number was " << num << endl;
        return;
    }
    else if (g > num) {
        cout << "Too high!" << endl;
    }
    else {
        cout << "Too low!" << endl;
    }

    int np = (p % t) + 1;
    game(np, t);
}

int main() {
    srand(time(0));
    num = rand() % 100 + 1;

    int t;
    cout << "Enter players: ";
    cin >> t;

    game(1, t);
    return 0;
}
