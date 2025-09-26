#include <iostream>
using namespace std;

#define N 5

int maze[N][N] = {
    {1, 0, 1, 1, 1},
    {1, 1, 1, 0, 1},
    {0, 1, 0, 1, 1},
    {1, 1, 0, 1, 0},
    {1, 0, 1, 1, 1}
};

int sol[N][N];

bool safe(int x, int y) {
    return (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1);
}

bool solve(int x, int y) {
    if (x == N - 1 && y == N - 1) {
        sol[x][y] = 1;
        return true;
    }

    if (safe(x, y)) {
        sol[x][y] = 1;

        if (solve(x + 1, y)) return true;
        if (solve(x, y + 1)) return true;

        sol[x][y] = 0;
        return false;
    }
    return false;
}

int main() {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            sol[i][j] = 0;

    if (solve(0, 0)) {
        cout << "Solution Path:\n";
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++)
                cout << sol[i][j] << " ";
            cout << endl;
        }
    }
    else {
        cout << "No path found!" << endl;
    }

    return 0;
}
