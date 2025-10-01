
#include <iostream>
using namespace std;

int sumDigits(int n) {
    if (n == 0) return 0;
    return (n % 10) + sumDigits(n / 10);
}

int nestedSum(int n) {
    if (n < 10) return n;
    return nestedSum(sumDigits(n));
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    int result = nestedSum(n);
    cout << "Final single-digit result: " << result << endl;

    return 0;
}
