/**
 * @brief Calculate trapped rainwater using prefix maxima
 * @intuition Water above each bar is limited by min of left and right max heights
 * @approach Precompute left/right maxima, then sum water at each position
 * @complexity Time: O(n), Space: O(n)
 */

class Solution final {
public:
  [[nodiscard]] static auto trap(const std::vector<int>& height) -> int {
    const auto n = static_cast<int>(height.size());
    if (n == 0) {
      return 0;
    }

    std::vector<int> leftMax(n);
    std::vector<int> rightMax(n);

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
