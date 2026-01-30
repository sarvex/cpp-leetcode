/**
 * @brief Search from top-right corner using matrix properties
 * @intuition Each row is sorted left-to-right, each column sorted top-to-bottom
 * @approach Start at top-right, go left if too large, down if too small
 * @complexity Time: O(m + n), Space: O(1)
 */

class Solution final {
public:
  [[nodiscard]] static auto searchMatrix(const std::vector<std::vector<int>>& matrix, const int target) -> bool {
    if (matrix.empty() || matrix[0].empty()) {
      return false;
    }
    
    const auto m = static_cast<int>(matrix.size());
    const auto n = static_cast<int>(matrix[0].size());
    int row = 0;
    int col = n - 1;
    
    while (row < m && col >= 0) {
      if (matrix[row][col] == target) {
        return true;
      }
      if (matrix[row][col] > target) {
        --col;
      } else {
        ++row;
      }
    }
    return false;
  }
};
