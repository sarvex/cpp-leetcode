/**
 * @brief Set entire row and column to zero if an element is zero
 * @intuition First pass marks which rows/columns need zeroing, second pass applies
 * @approach Use auxiliary arrays to track rows and columns containing zeros
 * @complexity Time: O(m * n), Space: O(m + n)
 */

class Solution final {
public:
  static auto setZeroes(std::vector<std::vector<int>>& matrix) -> void {
    int const m = static_cast<int>(matrix.size());
    int const n = static_cast<int>(matrix[0].size());
    std::vector<bool> row(m);
    std::vector<bool> col(n);

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (matrix[i][j] == 0) {
          row[i] = col[j] = true;
        }
      }
    }

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (row[i] || col[j]) {
          matrix[i][j] = 0;
        }
      }
    }
  }
};
