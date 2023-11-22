#include <iostream>
#include <vector>

using namespace std;

bool checkIfValid(vector<vector<int>> &board, int row, int col, int N) {
    int i, j;

    for (i = 0; i < col; i++) {
        if (board[row][i])
            return false;
    }

    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    for (i = row, j = col; j >= 0 && i < N; i++, j--)
        if (board[i][j])
            return false;

    return true;
}

void solve(vector<vector<int>> &board, int col, int N, int &solutionCount) {
    if (col == N) {
        solutionCount++;
        return;
    }

    for (int i = 0; i < N; i++) {
        if (checkIfValid(board, i, col, N)) {
            board[i][col] = 1;
            solve(board, col + 1, N, solutionCount);
            board[i][col] = 0; // backtrack this shit
        }
    }
}

int main() {
    int N;
    cin >> N;

    int solutionCount = 0;
    vector<vector<int>> board(N, vector<int>(N, 0));
    solve(board, 0, N, solutionCount);

    cout << solutionCount << endl;

    return 0;
}