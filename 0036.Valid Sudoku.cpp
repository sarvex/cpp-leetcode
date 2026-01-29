/**
 * @brief Validate a 9x9 Sudoku board
 * @intuition Check each row, column, and 3x3 box for duplicates
 * @approach Use boolean arrays to track seen digits
 * @complexity Time: O(1), Space: O(1) - fixed 9x9 board
 */

class Solution final {
public:
  [[nodiscard]] static auto
  isValidSudoku(const std::vector<std::vector<char>>& board) -> bool {
    std::vector<std::vector<bool>> row(9, std::vector<bool>(9, false));
    std::vector<std::vector<bool>> col(9, std::vector<bool>(9, false));
    std::vector<std::vector<bool>> box(9, std::vector<bool>(9, false));

    for (int i = 0; i < 9; ++i) {
      for (int j = 0; j < 9; ++j) {
        const char c = board[i][j];
        if (c == '.') {
          continue;
        }

        const int num = c - '0' - 1;
        const int boxIndex = (i / 3) * 3 + j / 3;

        if (row[i][num] || col[j][num] || box[boxIndex][num]) {
          return false;
        }

        row[i][num] = true;
        col[j][num] = true;
        box[boxIndex][num] = true;
      }
    }

    return true;
  }
};
