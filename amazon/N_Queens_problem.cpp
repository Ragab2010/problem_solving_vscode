#include <iostream>
#include <vector>
#include <string>

void backtrack(int n, int row, std::vector<std::string> &current, std::vector<std::vector<std::string>> &result) {
    if (row == n) {
        result.push_back(current);
        return;
    }

    for (int col = 0; col < n; col++) {
        bool isSafe = true;

        // Check if placing a queen at this position is safe
        for (int i = 0; i < row; i++) {
            if (current[i][col] == 'Q' || (col - (row - i) >= 0 && current[i][col - (row - i)] == 'Q') || (col + (row - i) < n && current[i][col + (row - i)] == 'Q')) {
                isSafe = false;
                break;
            }
        }

        if (isSafe) {
            // Place the queen
            current[row][col] = 'Q';

            // Recur for the next row
            backtrack(n, row + 1, current, result);

            // Backtrack: remove the queen to explore other possibilities
            current[row][col] = '.';
        }
    }
}

std::vector<std::vector<std::string>> solveNQueens(int n) {
    std::vector<std::vector<std::string>> result;
    std::vector<std::string> current(n, std::string(n, '.')); // Initialize the chessboard

    backtrack(n, 0, current, result);

    return result;
}

int main() {
    int n = 4;
    std::vector<std::vector<std::string>> result = solveNQueens(n);

    // Print the result
    for (const auto &solution : result) {
        for (const auto &row : solution) {
            std::cout << row << std::endl;
        }
        std::cout << std::endl;
    }

    return 0;
}
