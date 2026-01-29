/**
 * @brief Binary search on each row for 2D matrix search
 * @intuition Each row is sorted, use binary search per row
 * @approach Apply lower_bound to each row to find target
 * @complexity Time: O(m log n), Space: O(1)
 */
#include <algorithm>
#include <vector>

class Solution final {
public:
  [[nodiscard]] auto searchMatrix(const std::vector<std::vector<int>>& matrix, int target) const -> bool {
    for (const auto& row : matrix) {
      auto it = std::lower_bound(row.begin(), row.end(), target);
      if (it != row.end() && *it == target) {
        return true;
      }
    }
    return false;
  }
};
