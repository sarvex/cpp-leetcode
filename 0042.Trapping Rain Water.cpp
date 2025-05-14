#include <algorithm>
#include <vector>

class Solution final {
public:
  /**
   * @brief Calculates the total trapped rainwater using prefix maxima.
   * @intuition: For each bar, the trapped water depends on the min of the
   * tallest bars to its left and right.
   * @approach: Precompute left/right maxima for each index, then sum up the
   * water above each bar.
   * @complexity: Time O(n), Space O(n)
   */
  int trap(const std::vector<int> &height) const {
    const auto n = static_cast<int>(height.size());
    if (n == 0)
      return 0;
    std::vector<int> leftMax(n), rightMax(n);
    leftMax[0] = height[0];
    for (int i = 1; i < n; ++i) {
      leftMax[i] = std::max(leftMax[i - 1], height[i]);
    }
    rightMax[n - 1] = height[n - 1];
    for (int i = n - 2; i >= 0; --i) {
      rightMax[i] = std::max(rightMax[i + 1], height[i]);
    }
    int total = 0;
    for (int i = 0; i < n; ++i) {
      total += std::min(leftMax[i], rightMax[i]) - height[i];
    }
    return total;
  }
};
