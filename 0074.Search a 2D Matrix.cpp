/**
 * @brief Search for target in a sorted 2D matrix
 * @intuition Treat 2D matrix as a sorted 1D array for binary search
 * @approach Binary search on virtual 1D index, convert to row/column
 * @complexity Time: O(log(m * n)), Space: O(1)
 */

class Solution final {
public:
  [[nodiscard]] static auto searchMatrix(std::vector<std::vector<int>> const& matrix,
                                         int const target) -> bool {
    int const m = static_cast<int>(matrix.size());
    int const n = static_cast<int>(matrix[0].size());
    int left = 0;
    int right = m * n - 1;

    while (left < right) {
      int const mid = left + (right - left) / 2;
      int const x = mid / n;
      int const y = mid % n;

      if (matrix[x][y] >= target) {
        right = mid;
      } else {
        left = mid + 1;
      }
    }

    return matrix[left / n][left % n] == target;
  }
};
