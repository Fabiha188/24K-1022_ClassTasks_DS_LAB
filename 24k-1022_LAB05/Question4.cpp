#include <iostream>
using namespace std;

int solutionCount = 0;

void printBoard(int board[20][20], int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j] == 1)
                cout << "Q ";
            else
                cout << ". ";
        }
        cout << endl;
    }
    cout << endl;
}

bool isSafe(int board[20][20], int row, int col, int N) {
    for (int i = 0; i < row; i++)
        if (board[i][col] == 1)
            return false;
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j] == 1)
            return false;
    for (int i = row, j = col; i >= 0 && j < N; i--, j++)
        if (board[i][j] == 1)
            return false;
    return true;
}

bool solveNQueens(int board[20][20], int row, int N) {
    if (row == N) {
        solutionCount++;
        cout << "Solution " << solutionCount << ":\n";
        printBoard(board, N);
        return true;
    }
    bool res = false;
    for (int col = 0; col < N; col++) {
        if (isSafe(board, row, col, N)) {
            board[row][col] = 1;
            res = solveNQueens(board, row + 1, N) || res;
            board[row][col] = 0;
        }
    }
    return res;
}

int main() {
    int N;
    cout << "Enter value of N: ";
    cin >> N;
    int board[20][20] = {0};
    if (!solveNQueens(board, 0, N)) {
        cout << "No solution exists!" << endl;
    } else {
        cout << "Total number of distinct solutions for N=" << N << " is: " << solutionCount << endl;
    }
    return 0;
}
