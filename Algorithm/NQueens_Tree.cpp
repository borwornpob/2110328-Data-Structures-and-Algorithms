#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    vector<vector<int>> board;
    int col;

    Node(int N, int col, vector<vector<int>> parentBoard) {
        this->board = parentBoard;
        this->col = col;
    }
};

bool CheckIfValid(vector<vector<int>> &board, int row, int col, int N) {
    for (int i = 0; i < col; i++)
        if (board[row][i])
            return false;

    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    for (int i = row, j = col; j >= 0 && i < N; i++, j--)
        if (board[i][j])
            return false;

    return true;
}

void solveNQueensDFS(Node* node, int N, int &solutionCount) {
    if (node->col == N) {
        solutionCount++;
        return;
    }

    for (int i = 0; i < N; i++) {
        if (CheckIfValid(node->board, i, node->col, N)) {
            vector<vector<int>> newBoard = node->board;
            newBoard[i][node->col] = 1;
            Node* childNode = new Node(N, node->col + 1, newBoard);
            solveNQueensDFS(childNode, N, solutionCount);
            delete childNode; // Cleanup
        }
    }
}

int main() {
    int N;
    cin >> N;

    vector<vector<int>> initialBoard(N, vector<int>(N, 0));
    Node* root = new Node(N, 0, initialBoard);
    int solutionCount = 0;

    solveNQueensDFS(root, N, solutionCount);

    cout << solutionCount << endl;
    delete root; // Cleanup
    return 0;
}
