/**
 * @brief Two-pointer approach to find maximum water container area
 * @intuition Move the shorter line inward since it limits the area
 * @approach Start from both ends and greedily move the shorter boundary
 * @complexity Time: O(n), Space: O(1)
 */

#include <algorithm>
#include <vector>

class Solution final {
public:
  [[nodiscard]] static auto maxArea(const std::vector<int>& height) -> int {
    int left = 0;
    int right = static_cast<int>(height.size()) - 1;
    int maxAreaFound = 0;

    while (left < right) {
      const int currentArea =
          std::min(height[left], height[right]) * (right - left);
      maxAreaFound = std::max(maxAreaFound, currentArea);

      if (height[left] < height[right]) {
        ++left;
      } else {
        --right;
      }
    }

    return maxAreaFound;
  }
};
