/**
 * @brief Count the number of distinct N-Queens solutions
 * @intuition Use bitsets to track column and diagonal attacks efficiently
 * @approach DFS with backtracking, counting solutions when board is filled
 * @complexity Time: O(n!), Space: O(n)
 */

class Solution final {
public:
  [[nodiscard]] static auto totalNQueens(int const n) -> int {
    constexpr std::size_t MAX_N = 20;
    std::bitset<MAX_N> cols;
    std::bitset<MAX_N> diag1;
    std::bitset<MAX_N> diag2;
    int count = 0;

    auto dfs = [&](auto&& self, int const row) -> void {
      if (row == n) {
        ++count;
        return;
      }

      for (int col = 0; col < n; ++col) {
        int const d1 = row - col + n;
        int const d2 = row + col;

        if (cols[col] || diag1[d1] || diag2[d2]) {
          continue;
        }

        cols[col] = diag1[d1] = diag2[d2] = true;
        self(self, row + 1);
        cols[col] = diag1[d1] = diag2[d2] = false;
      }
    };

    dfs(dfs, 0);
    return count;
  }
};
