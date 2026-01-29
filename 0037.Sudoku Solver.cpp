/**
 * @brief Solve a Sudoku puzzle using backtracking
 * @intuition Try each valid number for empty cells, backtrack on conflicts
 * @approach DFS with constraint tracking using boolean arrays
 * @complexity Time: O(9^m) where m is empty cells, Space: O(m)
 */

class Solution final {
public:
  static auto solveSudoku(std::vector<std::vector<char>>& board) -> void {
    bool row[9][9] = {false};
    bool col[9][9] = {false};
    bool box[3][3][9] = {false};
    std::vector<std::pair<int, int>> emptyCells;

    for (int i = 0; i < 9; ++i) {
      for (int j = 0; j < 9; ++j) {
        if (board[i][j] == '.') {
          emptyCells.emplace_back(i, j);
        } else {
          const int v = board[i][j] - '1';
          row[i][v] = col[j][v] = box[i / 3][j / 3][v] = true;
        }
      }
    }

    auto dfs = [&](auto&& self, size_t k) -> bool {
      if (k == emptyCells.size()) {
        return true;
      }

      const auto [i, j] = emptyCells[k];
      for (int v = 0; v < 9; ++v) {
        if (!row[i][v] && !col[j][v] && !box[i / 3][j / 3][v]) {
          row[i][v] = col[j][v] = box[i / 3][j / 3][v] = true;
          board[i][j] = static_cast<char>(v + '1');

          if (self(self, k + 1)) {
            return true;
          }

          row[i][v] = col[j][v] = box[i / 3][j / 3][v] = false;
        }
      }

      return false;
    };

    dfs(dfs, 0);
  }
};
