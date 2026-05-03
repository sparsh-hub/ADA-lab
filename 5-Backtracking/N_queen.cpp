#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool isSafeQueen(vector<string>& board, int row, int col, int N) {
    // Check column upward
    for (int i = 0; i < row; i++)
        if (board[i][col] == 'Q') return false;

    // Check upper-left diagonal
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        if (board[i][j] == 'Q') return false;

    // Check upper-right diagonal
    for (int i = row - 1, j = col + 1; i >= 0 && j < N; i--, j++)
        if (board[i][j] == 'Q') return false;

    return true;
}

void nQueensUtil(vector<string>& board, int row, int N,
                 int& solutionCount) {
    if (row == N) {
        solutionCount++;
        if (solutionCount == 1) { // Print only the first solution
            cout << "  Solution #1:\n";
            for (auto& r : board) {
                cout << "    ";
                for (char c : r) cout << c << " ";
                cout << "\n";
            }
        }
        return;
    }

    for (int col = 0; col < N; col++) {
        if (isSafeQueen(board, row, col, N)) {
            board[row][col] = 'Q';
            nQueensUtil(board, row + 1, N, solutionCount);
            board[row][col] = '.'; // Backtrack
        }
    }
}

void nQueens(int N) {
    vector<string> board(N, string(N, '.'));
    int solutionCount = 0;
    nQueensUtil(board, 0, N, solutionCount);
    cout << "  Total solutions for " << N << "-Queens: " << solutionCount << endl;
}

void run_nqueens() {
    cout << "\n========== N-QUEENS PROBLEM ==========\n";
    nQueens(8); // Classic 8-queens
}

