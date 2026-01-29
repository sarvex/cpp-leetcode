/**
 * @brief Solve the N-Queens puzzle and return all solutions
 * @intuition Use backtracking with column and diagonal tracking to place queens safely
 * @approach Place queens row by row, track attacks using arrays for columns and diagonals
 * @complexity Time: O(n!), Space: O(n)
 */

class Solution final {
public:
  [[nodiscard]] static auto solveNQueens(int const n)
      -> std::vector<std::vector<std::string>> {
    std::vector<int> col(n, 0);
    std::vector<int> diag1(n * 2, 0);
    std::vector<int> diag2(n * 2, 0);
    std::vector<std::vector<std::string>> result;
    std::vector<std::string> board(n, std::string(n, '.'));

    auto dfs = [&](auto&& self, int const row) -> void {
      if (row == n) {
        result.push_back(board);
        return;
      }

      for (int j = 0; j < n; ++j) {
        if (col[j] + diag1[row + j] + diag2[n - row + j] == 0) {
          board[row][j] = 'Q';
          col[j] = diag1[row + j] = diag2[n - row + j] = 1;
          self(self, row + 1);
          col[j] = diag1[row + j] = diag2[n - row + j] = 0;
          board[row][j] = '.';
        }
      }
    };

    dfs(dfs, 0);
    return result;
  }
};
