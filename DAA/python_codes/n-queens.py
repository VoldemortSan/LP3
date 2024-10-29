def print_board(board):
    for row in board:
        print(" ".join(row))
    print()

def solve_n_queens(n, first_queen_row, first_queen_col):
    col = set()
    pos_diag = set()
    neg_diag = set()
    solutions = []
    board = [["."] * n for _ in range(n)]

    def backtrack(row):
        if row == n:
            solutions.append(["".join(r) for r in board])
            return

        for c in range(n):
            if c in col or (row + c) in pos_diag or (row - c) in neg_diag:
                continue

            col.add(c)
            pos_diag.add(row + c)
            neg_diag.add(row - c)
            board[row][c] = "Q"

            backtrack(row + 1)

            col.remove(c)
            pos_diag.remove(row + c)
            neg_diag.remove(row - c)
            board[row][c] = "."

    board[first_queen_row][first_queen_col] = "Q"
    col.add(first_queen_col)
    pos_diag.add(first_queen_row + first_queen_col)
    neg_diag.add(first_queen_row - first_queen_col)

    backtrack(first_queen_row + 1)
    
    return solutions

if __name__ == "__main__":
    n = int(input("Enter the size of the board (n): "))
    first_queen_position = input("Enter the row and column for the first queen (0-indexed, separated by space): ")
    first_queen_row, first_queen_col = map(int, first_queen_position.split())

    if first_queen_row >= n or first_queen_col >= n:
        print("Invalid position for the first queen!")
    else:
        solutions = solve_n_queens(n, first_queen_row, first_queen_col)
        
        if not solutions:
            print("No solution exists with the first queen placed at the specified position.")
        else:
            print("One of the solutions is:")
            print_board(solutions[0]) 
