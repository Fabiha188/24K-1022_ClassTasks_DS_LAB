#include <iostream>
using namespace std;

int N;
int solCount = 0;

bool safe(int board[20][20], int row, int col) {
    for (int i = 0; i < col; i++)
        if (board[row][i]) return false;

    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j]) return false;

    for (int i = row, j = col; i < N && j >= 0; i++, j--)
        if (board[i][j]) return false;

    return true;
}

bool solve(int board[20][20], int col, bool printOne) {
    if (col >= N) {
        solCount++;
        if (printOne && solCount == 1) {
            cout << "One valid solution:\n";
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++)
                    cout << (board[i][j] ? "Q " : ". ");
                cout << endl;
            }
        }
        return true;
    }

    bool res = false;
    for (int i = 0; i < N; i++) {
        if (safe(board, i, col)) {
            board[i][col] = 1;
            res = solve(board, col + 1, printOne) || res;
            board[i][col] = 0;
        }
    }
    return res;
}

int main() {
    cout << "Enter value of N: ";
    cin >> N;

    int board[20][20] = {0};

    solve(board, 0, true);

    cout << "\nTotal number of solutions for N = " << N << " : " << solCount << endl;

    return 0;
}
