#include <bits/stdc++.h>
#include <vector>
using namespace std;

void print_board(const vector<vector<int>>& board) {
    int N = board.size();
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            cout << (board[row][col] == 1 ? 'Q' : '.') << " ";
        }
        cout << endl;
    }
}

bool is_safe(const vector<vector<int>>& board, int row, int col, int init_row, int init_col) {
    int N = board.size();

    for (int i = 0; i < row; i++) {
        if (board[i][col] == 1) {
            return false;
        }
    }

    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    for (int i = row - 1, j = col + 1; i >= 0 && j < N; i--, j++) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    if (col == init_col || abs(row - init_row) == abs(col - init_col)) {
        return false;
    }

    return true; 
}

bool solve(vector<vector<int>>& board, int row, int init_row, int init_col) {
    int N = board.size();

    if (row == N) {
        print_board(board);
        return true;
    }

    // Skip the row with the initial queen
    if (row == init_row) {
        return solve(board, row + 1, init_row, init_col);
    }

    for (int col = 0; col < N; col++) {
        if (is_safe(board, row, col, init_row, init_col)) {
            board[row][col] = 1; // Place the queen
            if (solve(board, row + 1, init_row, init_col)) {
                return true; // Solution found
            }
            board[row][col] = 0; // Backtrack
        }
    }
    return false; 
}

int main() {
    int N, init_row, init_col;
    cout << "Enter the size of the board (N): ";
    cin >> N;
    vector<vector<int>> board(N, vector<int>(N, 0));

    cout << "Enter the position for the first queen (row and column, 0-indexed): ";
    cin >> init_row >> init_col;

    if (init_row >= N || init_col >= N || init_row < 0 || init_col < 0) {
        cout << "Invalid position for the first queen!" << endl;
        return 1;
    }

    board[init_row][init_col] = 1;
    cout << "\nPlacing the first queen at position (" << init_row << ", " << init_col << ")" << endl;
    cout << "The initial board setup is:" << endl;
    print_board(board);
    cout << endl;

    if (!solve(board, 0, init_row, init_col)) {
        cout << "\nNo solution exists for the given starting position." << endl;
    }

    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;

// void printBoard(const vector<string>& board) {
//     for (const string& row : board) {
//         for (char cell : row) {
//             cout << cell << " ";
//         }
//         cout << endl;
//     }
// }

// void solveNQueensHelper(int n, int row, vector<string>& board, vector<vector<string>>& solutions, set<int>& cols, set<int>& posDiags, set<int>& negDiags) {
//     if (row == n) {
//         solutions.push_back(board);
//         return;
//     }

//     for (int col = 0; col < n; ++col) {
//         if (cols.count(col) || posDiags.count(row + col) || negDiags.count(row - col))
//             continue;

//         board[row][col] = 'Q';
//         cols.insert(col);
//         posDiags.insert(row + col);
//         negDiags.insert(row - col);

//         solveNQueensHelper(n, row + 1, board, solutions, cols, posDiags, negDiags);

//         board[row][col] = '.';
//         cols.erase(col);
//         posDiags.erase(row + col);
//         negDiags.erase(row - col);
//     }
// }

// vector<vector<string>> solveNQueens(int n, int firstQueenRow, int firstQueenCol) {
//     vector<vector<string>> solutions;
//     vector<string> board(n, string(n, '.'));

//     set<int> cols, posDiags, negDiags;

//     // Place the first queen
//     board[firstQueenRow][firstQueenCol] = 'Q';
//     cols.insert(firstQueenCol);
//     posDiags.insert(firstQueenRow + firstQueenCol);
//     negDiags.insert(firstQueenRow - firstQueenCol);

//     // Start backtracking from the next row
//     solveNQueensHelper(n, firstQueenRow + 1, board, solutions, cols, posDiags, negDiags);

//     return solutions;
// }

// int main() {
//     int n, firstQueenRow, firstQueenCol;
//     cout << "Enter the size of the board (n): ";
//     cin >> n;
//     cout << "Enter the row and column for the first queen (0-indexed): ";
//     cin >> firstQueenRow >> firstQueenCol;

//     if (firstQueenRow >= n || firstQueenCol >= n) {
//         cout << "Invalid position for the first queen!" << endl;
//         return 1;
//     }

//     vector<vector<string>> solutions = solveNQueens(n, firstQueenRow, firstQueenCol);

//     if (solutions.empty()) {
//         cout << "No solution exists with the first queen placed at the specified position." << endl;
//     } else {
//         cout << "One of the solutions is:" << endl;
//         printBoard(solutions[0]);  // Display the first solution
//     }

//     return 0;
// }
