/**
 * @brief Rotate n x n matrix 90 degrees clockwise in-place
 * @intuition First flip vertically, then transpose
 * @approach Two-step transformation using swap operations
 * @complexity Time: O(n^2), Space: O(1)
 */

class Solution final {
public:
  static auto rotate(std::vector<std::vector<int>>& matrix) -> void {
    const int n = static_cast<int>(matrix.size());

    for (int i = 0; i < n / 2; ++i) {
      for (int j = 0; j < n; ++j) {
        std::swap(matrix[i][j], matrix[n - i - 1][j]);
      }
    }

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < i; ++j) {
        std::swap(matrix[i][j], matrix[j][i]);
      }
    }
  }
};
