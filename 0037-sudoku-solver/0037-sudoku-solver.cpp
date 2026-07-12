class Solution {
public:
    bool isSafe(vector<vector<char>>& board, int row, int col, char digit) {

        // Row and Column
        for (int i = 0; i < 9; i++) {

            if (board[row][i] == digit)
                return false;

            if (board[i][col] == digit)
                return false;
        }

        // 3 x 3 Box
        int sr = 3 * (row / 3);
        int sc = 3 * (col / 3);

        for (int i = sr; i < sr + 3; i++) {
            for (int j = sc; j < sc + 3; j++) {

                if (board[i][j] == digit)
                    return false;
            }
        }

        return true;
    }

    bool helper(vector<vector<char>>& board, int row, int col) {

        // Base Case
        if (row == 9)
            return true;

        int nextRow = row;
        int nextCol = col + 1;

        if (nextCol == 9) {
            nextRow = row + 1;
            nextCol = 0;
        }

        // Already filled cell
        if (board[row][col] != '.') {
            return helper(board, nextRow, nextCol);
        }

        // Try digits 1 to 9
        for (char digit = '1'; digit <= '9'; digit++) {

            if (isSafe(board, row, col, digit)) {

                board[row][col] = digit;

                if (helper(board, nextRow, nextCol))
                    return true;

                // Backtrack
                board[row][col] = '.';
            }
        }

        return false;
    }

    void solveSudoku(vector<vector<char>>& board) { helper(board, 0, 0); }
};