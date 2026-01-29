/**
 * @brief Find minimum jumps to reach the end using greedy approach
 * @intuition Use the farthest reachable point in current jump range
 * @approach Greedily extend reachable range, increment jump count when needed
 * @complexity Time: O(n), Space: O(1)
 */

#include <algorithm>
#include <vector>

class Solution final {
public:
  [[nodiscard]] auto jump(const std::vector<int>& nums) const -> int {
    int jumpCount = 0;
    int currentJumpLimit = 0;
    int maxReachableIndex = 0;
    const int n = static_cast<int>(nums.size());

    for (int i = 0; i < n - 1; ++i) {
      maxReachableIndex = std::max(maxReachableIndex, i + nums[i]);
      if (i == currentJumpLimit) {
        ++jumpCount;
        currentJumpLimit = maxReachableIndex;
      }
    }

    return jumpCount;
  }
};
