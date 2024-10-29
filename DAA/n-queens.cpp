#include <bits/stdc++.h>
using namespace std;

void printBoard(const vector<string>& board) {
    for (const string& row : board) {
        for (char cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
}

void solveNQueensHelper(int n, int row, vector<string>& board, vector<vector<string>>& solutions, set<int>& cols, set<int>& posDiags, set<int>& negDiags) {
    if (row == n) {
        solutions.push_back(board);
        return;
    }

    for (int col = 0; col < n; ++col) {
        if (cols.count(col) || posDiags.count(row + col) || negDiags.count(row - col))
            continue;

        board[row][col] = 'Q';
        cols.insert(col);
        posDiags.insert(row + col);
        negDiags.insert(row - col);

        solveNQueensHelper(n, row + 1, board, solutions, cols, posDiags, negDiags);

        board[row][col] = '.';
        cols.erase(col);
        posDiags.erase(row + col);
        negDiags.erase(row - col);
    }
}

vector<vector<string>> solveNQueens(int n, int firstQueenRow, int firstQueenCol) {
    vector<vector<string>> solutions;
    vector<string> board(n, string(n, '.'));

    set<int> cols, posDiags, negDiags;

    // Place the first queen
    board[firstQueenRow][firstQueenCol] = 'Q';
    cols.insert(firstQueenCol);
    posDiags.insert(firstQueenRow + firstQueenCol);
    negDiags.insert(firstQueenRow - firstQueenCol);

    // Start backtracking from the next row
    solveNQueensHelper(n, firstQueenRow + 1, board, solutions, cols, posDiags, negDiags);

    return solutions;
}

int main() {
    int n, firstQueenRow, firstQueenCol;
    cout << "Enter the size of the board (n): ";
    cin >> n;
    cout << "Enter the row and column for the first queen (0-indexed): ";
    cin >> firstQueenRow >> firstQueenCol;

    if (firstQueenRow >= n || firstQueenCol >= n) {
        cout << "Invalid position for the first queen!" << endl;
        return 1;
    }

    vector<vector<string>> solutions = solveNQueens(n, firstQueenRow, firstQueenCol);

    if (solutions.empty()) {
        cout << "No solution exists with the first queen placed at the specified position." << endl;
    } else {
        cout << "One of the solutions is:" << endl;
        printBoard(solutions[0]);  // Display the first solution
    }

    return 0;
}
